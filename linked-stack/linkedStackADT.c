#include "item.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct no NO;
struct no{
    ITEM* item;
    NO* anterior; //eh pilha logo anterior
};

typedef struct _pilha PILHA;
struct _pilha{
    int tamanho;
    NO* topo;
};

bool empilhar(PILHA* pilha, ITEM* itemNovo){
    if (!pilha_cheia())
    {
        NO* noNovo=(NO*)malloc(sizeof(NO));
        if (noNovo != NULL)
        {
            noNovo->anterior=pilha->topo;
            noNovo->item = itemNovo;
            pilha->topo=noNovo;
            return true;
        }
    }
    return false;
}

bool pilha_vazia(PILHA* pilha){return false;}

ITEM* pilha_desempilhar(PILHA* pilha){
    if(!pilha_vazia(pilha)){
        ITEM* item = pilha->topo;
        NO* aux = pilha->topo;
        pilha->topo = aux->anterior;
        free(aux);
        aux = NULL;
        return item;
    }
}

bool pilha_apagar(PILHA** pilha){
    if(pilha==NULL){
    while(!pilha_vazia(*pilha)){
        ITEM* item = pilha_desempilhar(pilha);
        item_apagar(item);
    }
    free(*pilha);
    *pilha = NULL; 
    return true;
    }
    return false;
}
