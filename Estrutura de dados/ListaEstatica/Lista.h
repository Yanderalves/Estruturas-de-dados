#define MAX 100
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
// #include<stdbool.h>

typedef struct aluno{
    int key;

}Aluno;

typedef struct lista Lista;

Lista *cria_lista();
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);
void inserir_vazia(Lista *li, struct aluno);
int inserir_final(Lista *li, Aluno al);
int inserir_inicio(Lista *li, Aluno al);
int inserir_mid(Lista *li, Aluno al);
void imprimir_lista(Lista *li);
void preencher_randomicamente(Lista *li);
void remocao_inicio(Lista *li);
void remover_mid(Lista *li, int key);
int consulta_posicao(Lista *li, Aluno *al, int pos);
int consulta_valor(Lista *li, Aluno *al, int key);

