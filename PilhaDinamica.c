#include <stdio.h>
#include <stdlib.h>

struct pilha{
    int valor;
    struct pilha* prox;
};

typedef struct pilha Pilha;

Pilha* push(Pilha* p);
Pilha* pop(Pilha* p);
Pilha* remover(Pilha* p, int numero);
void imprime(Pilha* p);
void tamanho(Pilha* p);
void menu();

int main(){
     Pilha* P = NULL;
     int opcao,num;

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
             printf("Digite o número para remover:");
             scanf("%d", &num);
         P = remover(P,num);   
             break;
         case 4:
         tamanho(P);
             break;
         case 5:
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

Pilha* remover(Pilha* p, int numero){
   if(p == NULL){
       printf("Pilha Vazia!");
       return p;
   }
   Pilha* aux = p;
   //remove o ultimo elemento da Pilha
   if(aux->valor == numero){
       p = p->prox;
       free(aux);
       return p;
   }
   Pilha* atual = p, *ant = atual;

   while(atual != NULL && atual->valor != numero){
       ant = atual;
       atual = atual->prox;
   }
   
   if(atual == NULL){
       printf("Elemento não encontrado!");
       return p;
   }
   else if(atual->prox != NULL){
       ant->prox = atual->prox;
       return p;
   }else if(atual->prox == NULL){
        ant->prox = NULL;
        free(atual);
        return p;
   }
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

void tamanho(Pilha* p){
    Pilha* aux = p;
    int tamanho = 0;

    while(aux != NULL){
     aux = aux->prox;
     tamanho++;
    }
    printf("\nO tamanho da Pilha é %d",tamanho);
}

void menu(){
    printf("\n\n Menu\n 0 - Sair\n 1 - Push\n 2 - Pop\n 3 - Remover qualquer elemento\n 4 - Tamanho\n 5 - Imprime\n");
}
