#include <stdio.h>
#include <stdlib.h>

struct pilha{
    int valor;
    struct pilha* prox;
};

typedef struct pilha Pilha;

Pilha* push(Pilha* p);
void imprime(Pilha* p);

int main(){
    Pilha* P = NULL;
    P = push(P);
    P = push(P);
    imprime(P);
    return 1;
}

Pilha* push(Pilha* p){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));

    if(novo == NULL){
        printf("Erro na alocação de Memória!");
        return 0;
    }

    novo->prox=p;
    
    printf("Digite um valor:");
    scanf("%d", &novo->valor);
    
    return novo;

}

void imprime(Pilha* p){
    Pilha *aux = p;

    printf("\nPilha:\n");

    while(aux != NULL){
        printf("\n|%d|", aux->valor);
        aux = aux->prox;
    }
    printf("-> NULL");

}