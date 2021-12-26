#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Ponto.h"

typedef struct ponto{
    float x;
    float y;
}Ponto;

Ponto *criaPonto(float x, float y){
    Ponto *p = malloc(sizeof(Ponto));
    if(p != NULL){
        p->x = x;
        p->y = y;
    }   
    return p;
}

void liberaPonto(Ponto *p){
    free(p);
}

void atribuiPonto(Ponto *p, float x, float y){
    p->x = x;
    p->y = y;
}

void acessaPonto(Ponto *p){
    printf("x = %f, y = %f\n", p->x, p->y);
}

float distanciaPonto(Ponto *p1, Ponto *p2){
    float dist =  sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
    printf("%f", dist);

}