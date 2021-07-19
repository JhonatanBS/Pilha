#include <stdio.h>
#include <stdlib.h>

struct pilha{
    int valor;
    struct pilha* prox;
};

typedef struct pilha Pilha;

Pilha* push(Pilha* p);
Pilha* pop(Pilha* p);
void imprime(Pilha* p);
void menu();

int main(){
     Pilha* P = NULL;
     int opcao;

         do{
             menu();
             printf("\nEscolha uma opção:");
             scanf("%d", &opcao);

 switch(opcao){
         case 0:
         printf("\nPilha encerrada!");
             break;
         case 1:
         P = push(P);
             break;
         case 2:
         P = pop(P);
             break;
         case 3:
         imprime(P);
             break;
              }
         }while(opcao != 0);

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

Pilha* pop(Pilha* p){
    if(p == NULL){
        printf("\nErro na remoção: A pilha está vazia!");
        return p;
    }
     Pilha* aux = p;
     p = p->prox;
     free(aux);
 return p;
}

void imprime(Pilha* p){
     Pilha *aux = p;
     if(p == NULL){
         printf("Pilha Vazia!\n");
         return p;
    }
         printf("\nPilha:\n");

     while(aux != NULL){
         printf("\n|%d|", aux->valor);
         aux = aux->prox;
    }
         printf("-> NULL");
}

void menu(){
    printf("\n\n Menu\n 0 - Sair\n 1 - Push\n 2 - Pop\n 3 - Imprime\n");
}
