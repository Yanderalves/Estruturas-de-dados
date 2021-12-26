#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
      char *Nome_personagem;
      int num_vidas;
      struct No *prox;
      struct No *ant;
}No;

No *inicio = NULL;
int tam =0;

void adicionar(char *Nome_personagem, int num_vidas, int pos){
    
    if(pos>=0 && pos<=tam){
    
        No *Novo = malloc (sizeof (No));
        Novo->Nome_personagem = Nome_personagem;
        Novo->num_vidas = num_vidas;
        Novo->prox = NULL;
        Novo->ant = NULL;
     
        if(inicio == NULL){
            inicio = Novo;
        }else if(pos == 0){
            Novo->prox = inicio;
            inicio->ant = Novo;
            inicio = Novo;
        }else{
            No *aux = inicio;
            for (int i = 0; i < pos - 1; i++){
                aux = aux->prox;
            }
            if( pos == tam){
                aux->prox = Novo;
                Novo->ant = aux;
            }else{
                aux->ant->prox = Novo;
                Novo->ant = aux->ant;
                aux->ant = Novo;
                Novo->prox = aux;
            }
        }
        tam++;
    }else{
        printf("insercao invalida! :/");
    }
}

void imprimir_lista_personagem(){
    No *aux = inicio;
    do{
        printf("Personagem: %s || Vidas: %d\n", aux->Nome_personagem, aux->num_vidas);
        aux = aux->prox;
    }while(aux != NULL);
     
}

void remover(char *Nome_personagem){
            
    if(tam == 1 && inicio->Nome_personagem == Nome_personagem){
        No *lixo = inicio;
        inicio = NULL;
        free(lixo);
        tam --;
    }else if(tam > 1 && inicio->Nome_personagem == Nome_personagem){
        No *lixo = inicio;
        inicio = inicio->prox;
        inicio->ant = NULL;
        free(lixo);
        tam--;
    }else{
        No *aux = inicio;
        while (aux->prox != NULL){
            if(aux->Nome_personagem == Nome_personagem){
                break;
            }
            aux = aux->prox;
        }
        if(aux->prox == NULL){
            aux->ant->prox = NULL;
        }else{
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
        }
        free(aux);
        tam--;
    }
}
     

char* persMaisVidas(){
    int maior_num_vidas = -1;
    char *personagem = "";
    No *aux = inicio;
    while (aux != NULL){
        if(aux->num_vidas > maior_num_vidas){
            personagem = aux->Nome_personagem;
            maior_num_vidas = aux->num_vidas;
        }
        aux = aux->prox;
    }
  return personagem;
}

int string_to_inteiro(char string[]){
    int asc = 0;
    for (int i = 0; i < strlen(string); i++){
        asc += (int)(string[i]);
    }
    return asc;
    
    
}

int main(){
    string_to_inteiro();
    // adicionar("Mario", 2, 0);
    // adicionar("Luigi", 9, 1);
    // adicionar("Yoshi", 5, 2);
    // adicionar("Princesa", 7, 3);
    // adicionar("Bowser", 3, 4);
    // imprimir_lista_personagem();
    // printf("Testando remoção:\n");
    // remover("Mario");
    // imprimir_lista_personagem();
    // printf("Personagem c/ mais vidas: %s\n", persMaisVidas());
    return 0;
}

