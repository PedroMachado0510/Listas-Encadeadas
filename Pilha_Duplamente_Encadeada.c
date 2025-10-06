/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct dupla {
    int dado;
    struct dupla *elink, *dlink;
} no;

no* crialde(int n) {
    no *ini = NULL, *p;
    int valor;
    for(int i = 1; i <= n; i++) {
        printf("\nDigite o valor %d da lista: ", i);
        scanf("%d", valor);
        p = (no*) malloc(sizeof(no));
        p->dado = valor;
        
        p->elink = ini; // próximo nó é o antigo primeiro
        p->dlink = NULL; // anterior é NULL (novo início)
        
        if(ini != NULL)
        ini->dlink = p; // antigo primeiro nó aponta para o novo anterior
        
        ini = p; // atualiza  o inicio da lista
    }
    
    return ini;
}
void escrevelista(no *p){
    printf("\nLista: ");
    while(p != NULL){
        printf("%d\t", p->dado);
        p = p->elink; //percorrendo do inicio ao fim
    }
}

int main() {
    no *primeira;
    int n;
    printf("Criando uma lista duplamente encadeada");
    
    do {
        printf("\nEntre com o numero de nos: ");
        scanf("%d", &n);
    } while(n < 0);
    
    primeira = crialde(n);
    
    if(primeira != NULL) {
        printf("\nLista criada\n");
        escrevelista(primeira);
    } else {
        printf("\nLista vazia");
    }
    
    return 0;
}