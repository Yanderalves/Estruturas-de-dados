#include<stdio.h>
#include<stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
};

typedef struct elemento* Lista;

Lista* cria_lista();

void libera_lista(Lista *li);