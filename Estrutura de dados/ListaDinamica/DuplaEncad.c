#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox; 
    struct No *ant;
}No;

No *inicio = NULL;
No *fim = NULL;
int tam = 0;

void add(int valor, int pos){
    if(pos >= 0 && pos <= tam){
        No *novo = malloc(sizeof(No)); 
        novo->valor = valor;
        novo->prox = NULL;
        novo->ant = NULL;
        if(inicio == NULL){
            inicio = novo;
            fim = novo;
        }else if(pos == 0){
            inicio->ant= novo;
            novo->prox = inicio; // Faço o novo nó apontar pro antigo inicio
            inicio = novo; // Atualizo o novo inicio
        }else if(pos == tam){
                fim->prox = novo;
                novo->ant = fim;
                fim = novo;
        }else{
            No *aux = inicio;
            for(int i = 0; i < tam; i++)
                aux = aux->prox;
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
        }
        tam++;
    }
}

int remover(int pos){
    int ret = -1;
    if(pos>=0 && pos < tam){
        No *lixo;
        if(pos == 0){
            lixo = inicio;
            inicio = inicio->prox;
            inicio->ant = NULL;
        }else if(pos == tam - 1){
            lixo = fim;
            fim = fim->ant;
            fim->prox = NULL;
        }else{
            No *aux = inicio;
            for (int i = 0; i < tam; i++){
                aux = aux->prox;
            }
            lixo = aux;
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(aux);
        }
    ret = lixo->valor;
    free(lixo);
    tam--;
    }
    return ret;
}

void imprime(){
    No *aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

void main(){
    add(15,0);
    add(14,1);
    add(18, 2);
    add(17, 3);
    remover(3);
    // printf("tam = %d\n", tam);
    imprime();
}