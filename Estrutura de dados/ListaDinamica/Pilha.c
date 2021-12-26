#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int id;
    struct No *prox;
}No;

No *topo = NULL;
int tam = 0;

void inserir(int id){
    No *novo = malloc(sizeof(No));
    novo->prox = topo;
    novo->id = id;
    topo = novo;
    tam++;
}

int remover(){
    if(tam > 0){
        No *lixo = topo;
        topo = topo->prox;
        int ret = lixo->id;
        free(lixo);
        return ret;
    }else
        printf("Vai meter essa de tentar remover em pilha vazia, doidão?!?!\n");
}

void imprimir(){
    No *aux = topo;
    while(aux != NULL){
        printf("%d\n", aux->id);
        aux = aux->prox;
    }
}

void main(){

    int vet[] = {12, 14, 17, 78};
    int n = 4;

    for (int i = 0; i < n; i++)
        inserir(vet[i]);

    imprimir();
    printf("Teste remoção....\n");
    int removido = remover();
    printf("Item removido: %d\n", removido);
    imprimir();
}