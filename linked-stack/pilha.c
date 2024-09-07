#include "item.h"
#include "Pilha.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct no NO;
struct no{
    ITEM* item;
    NO* anterior; //eh pilha logo anterior
};

struct _pilha{
    int tamanho;
    NO* topo;
};

PILHA* pilha_criar(){
    PILHA* pilha = (PILHA*)malloc(sizeof(PILHA));
    if(pilha){
        pilha->tamanho = 0;
        pilha->topo =NULL;
        return pilha;
    }
    return NULL;
}

ITEM* pilha_desempilhar(PILHA* pilha){
    if(!pilha_vazia(pilha)){
        NO* aux = pilha->topo;          // Salva o nó atual do topo
        ITEM* item = aux->item;         // Extrai o item do nó
        pilha->topo = pilha->topo->anterior; // Move o topo para o nó anterior
        free(aux);                      // Libera o nó desempilhado
        aux = NULL;                     // Evita ponteiros pendentes
        pilha->tamanho--;               // Decrementa o tamanho da pilha
        return item;                    // Retorna o item desempilhado
    }
    return NULL;                        // Retorna NULL se a pilha estiver vazia
}

bool pilha_empilhar(PILHA* pilha, ITEM* itemNovo){
    if (!pilha_cheia(pilha))
    {
        NO* noNovo=(NO*)malloc(sizeof(NO));
        if (noNovo != NULL)
        {
            noNovo->anterior=pilha->topo;
            noNovo->item = itemNovo;
            pilha->topo=noNovo;
            pilha->tamanho++;
            return true;
        }
    }
    return false;
}


bool pilha_apagar(PILHA** pilha){
    if(*pilha==NULL){
        while(!pilha_vazia(*pilha)){
            ITEM* item = pilha_desempilhar(*pilha);
            item_apagar(&item);
        }
        free(*pilha);
        *pilha = NULL; 
        return true;
    }
    return false;
}
ITEM* pilha_topo(PILHA* pilha){
    if(!pilha_vazia(pilha)){
        return pilha->topo->item;
    }
    return NULL;
}
int pilha_tamanho(PILHA* pilha){
    if(pilha){
        return pilha->tamanho;
    }
    return -1;
}
bool pilha_cheia(PILHA* pilha){
    if(pilha){
        NO* aux = (NO*) malloc(sizeof(NO));
        if(aux){
            return false;
        }
    }
    return false;
}



bool pilha_vazia(PILHA* pilha){
    if(pilha!=NULL){
        if(pilha->tamanho==0){
            return true;
        }
        return false;
    }
    return true;
}
