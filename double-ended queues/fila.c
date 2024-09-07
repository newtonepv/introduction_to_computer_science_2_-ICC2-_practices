#include "fila.h"
#include "item.h"
#include <stdbool.h>
#include <stdlib.h>
#define TAM_MAX 100
typedef struct no NO;

struct no{
    ITEM* item;
    NO* prox;
};

struct _fila{
    ITEM* array;
    int inicio;
    int fim;
    int tamanho;
};

FILA* fila_criar(){
    FILA* fila;
    fila = (FILA*)malloc(sizeof(FILA));
    if(fila !=NULL){
        fila->fim, fila->inicio = 0;
        fila->tamanho=0;
    }
    return fila;
}

bool fila_adicionar(FILA* fila, ITEM* item){

}

