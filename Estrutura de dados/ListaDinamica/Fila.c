#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int id;
    struct No *prox;
}No;

int tam = 0;
No *inicio = NULL;
No *fim = NULL;

void adicionar(int id){
    No *novo = malloc(sizeof(No));
    novo->id = id;
    novo->prox = NULL;
    if(tam == 0){
        inicio = novo;
        fim = novo;
    }else{
        fim->prox = novo;
        fim = novo;
    }
    tam++;
}

void imprimir(){
    No *aux = inicio;
    while(aux != NULL){
        printf("%d → ", aux->id);
        aux = aux->prox;
    }
    printf("\n");
}

int remover(){
    if(tam > 0){
        No *lixo = inicio;
        int ret = lixo->id;
        inicio = inicio->prox;
        free(lixo);
        tam --;
        return ret;
    }else{
        printf("IH! Tua fila tá vazia, doidão\n");
    }
}

void main(){
    int vet[] = {12, 14, 18, 19, 22, 78};
    int n = 6;
    
    for (int i = 0; i < n; i++)
        adicionar(vet[i]);

    imprimir();
    printf("Removendo: \n");
    remover();
    // remover();
    // remover();
    imprimir();
}
