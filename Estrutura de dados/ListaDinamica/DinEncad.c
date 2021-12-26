#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox; 
}No;

No *inicio = NULL;
No *fim = NULL;
int tam = 0;

void add(int valor, int pos){
    if(pos >= 0 && pos <= tam){
        No *novo = malloc(sizeof(No)); 
        novo->valor = valor;
        novo->prox = NULL;
        if(inicio == NULL){
            inicio = novo;
            fim = novo;
        }else if(pos == 0){
            novo->prox = inicio; // Faço o novo nó apontar pro antigo inicio
            inicio = novo; // Atualizo o novo inicio
        }else if(pos == tam){
                fim->prox = novo;
                fim = novo;
        }else{
            No *aux = inicio;
            for(int i = 0; i < tam - 1; i++)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        tam++;
    }
}

int remover(int pos){
    if(pos>=0 && pos < tam){
        No *lixo;
        int ret;
        if(pos == 0){
            lixo = inicio;
            inicio = inicio->prox;
        }else{
            No *aux = inicio;
            for(int i = 0; i < pos; i++)
                aux = aux->prox;
            lixo = aux->prox;
            aux->prox = aux->prox->prox;
        }
    ret = lixo->valor;
    free(lixo);
    tam--;
    return ret;

    }else
        printf("Ocorreu um erro ao remover!\n");
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
    printf("tam = %d\n", tam);
    imprime();
}