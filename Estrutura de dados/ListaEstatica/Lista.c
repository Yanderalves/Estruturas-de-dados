#include "Lista.h"
// #include <stdio.h>
// #include<stdlib.h>

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista *cria_lista(){
    Lista *li;
    li = malloc(sizeof(Lista));
    if( li != NULL){
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista *li){
    free(li);
}

int tamanho_lista(Lista *li){
    if (li == NULL){
        return -1;
    }else{
        return li->qtd;
    }
}

int lista_cheia(Lista *li){
    if(li == NULL)
        printf("Lista não alocada\n");
    else
        return li->qtd == MAX;
    
}

int lista_vazia(Lista *li){
    if(li == NULL)
        printf("Lista não alocada\n");
    else
        return li->qtd == 0;
}


void inserir_vazia(Lista *li, Aluno al){
    li->dados[0].key = al.key;
    li->qtd++;
}

int inserir_final(Lista *li, Aluno al){
    if (li == NULL)
        return 0;
    if (lista_cheia(li))
        return 0;
    else{
        // printf(" --- %d\n", al.key);
        li->dados[li->qtd].key = al.key;
        li->qtd++;
        return 1;
    }
}

int inserir_inicio(Lista *li, Aluno alu){
    if (li == NULL)
        return 0;
    if (lista_cheia(li))
        return 0; 
    else{
        for(int i = li->qtd - 1; i >= 0; i--){
            li->dados[i+1].key = li->dados[i].key;
        }
        li->dados[0].key = alu.key;
        // printf("→ %d\n", li->dados[0].key);
        li->qtd++;
        return 1;
    }
}

int inserir_mid(Lista *li, Aluno al){
    if (li == NULL){
        return 0;
    }if (lista_cheia(li)){
        return 0; 
    }else{
        int i = 0;
        int k = 0;
        while (i < li->qtd && li->dados[i].key < al.key){
            i++;
        }
        for (k = li->qtd - 1; k >= 0; k--){
            li->dados[k+1].key = li->dados[k].key; 
        }
        // printf("%d", li->dados[i].key);
        li->dados[i].key = al.key; 
        li->qtd++;
        return 1;
    }
}

void imprimir_lista(Lista *li){
    for (int i = 0; i < li->qtd; i++){
        printf("%d\n", li->dados[i].key);
    }
    
}

void remocao_inicio(Lista *li){
    if (li != NULL && li->qtd !=0){
        for(int i = 0; i < li->qtd; i++){
            li->dados[i].key = li->dados[i+1].key; 
        }
        li->qtd--;
    }
    else{
        return 0;
    }
}

void remocao_final(Lista *li){
    if(lista_vazia(li)){
        return 0;
    }if (li->qtd == 0){
        return 0;
    }else{
        li->qtd--;
    }
}

void remover_mid(Lista *li, int key){
    if (li == NULL || li->qtd == 0){
        return 0;
    }else{
        int i = 0;
        while (i != li->qtd &&  key != li->dados[i].key){
            i++;
        }
        if (i == li->qtd){
            return 0;
        }
        printf("i = %d\n", i);
        for(int k = i; k < li->qtd - 1; k++){
            li->dados[k].key = li->dados[k+1].key;
        }
        li->qtd--;
    }
}

int consulta_posicao(Lista *li, Aluno *al, int pos){
    if(li == NULL || li->qtd <= 0 || pos > li->qtd){
        return 0;
    }else{
        *al = li->dados[pos-1];
    }
}

int consulta_valor(Lista *li, Aluno *al, int key){
    if(li == NULL || li->qtd <= 0){
        return 0;
    }else{
        for(int i = 0; i < li->qtd; i++){
            if (key == li->dados[i].key){
                *al = li->dados[i];
            }
        }
        return 1;
    }
}

void main(){
    Lista *li = cria_lista();
    Aluno aluno, aluno2, aluno3, alunoX;
    aluno.key = 3;
    aluno2.key = 5;
    aluno3.key = 4;

    inserir_vazia(li, aluno2);
    inserir_inicio(li, aluno);
    inserir_mid(li, aluno3);
    imprimir_lista(li);

    int x = consulta_posicao(li, &alunoX, 3);
    printf("→ %d\n", alunoX.key);
    
}
