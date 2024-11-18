#include "item.h"
#include "ab.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct no NO;
struct no{
    ITEM* item;
    NO* direita;
    NO* esquerda;
};

struct arv_bin{
    NO* raiz;
};

AB* ab_criar(void){
    AB* arv = malloc(sizeof(AB));
    arv->raiz = NULL;
}

NO* buscar(int chave, NO* no){
    if(no==NULL){
        return NULL;
    }
    if(item_get_chave(no->item)==chave){
        return no;
    }
    NO* direita = buscar(chave, no->direita);
    NO* esquerda = buscar(chave, no->esquerda);
    if(direita==NULL){
        return esquerda;
    }else{
        return direita;
    }
}

NO* busca_no_nao_binario(NO* no){
    if(no->esquerda==NULL && no->direita==NULL)
    {//for binario mas nao pouder continuar a busca
        return NULL;
    }
    if(no->esquerda!=NULL && no->direita!=NULL)
    {//for binario continua a busca
        NO* esquerda = busca_no_nao_binario(no->esquerda);
        NO* direita = busca_no_nao_binario(no->direita);
        if(esquerda==NULL){//se nao achou na esquerda
            return direita;
        }
        return esquerda;//se achou ou nao na direita
    }
    //se nao for binario
    return no;
}


bool ab_inserir (AB *T, ITEM *item, int lado, int chave){
    NO* novoNo = malloc(sizeof(NO));
    if(novoNo){
        novoNo->item = item;

        if(chave == 0 && T->raiz==NULL){
            T->raiz = novoNo;
            return true;
        }
        NO* pai = buscar(chave,T->raiz);
        if(pai!=NULL){

            if(lado ==FILHO_ESQ){
                pai->esquerda=novoNo;
            }else{
                pai->direita=novoNo;
            }

        return true;
        }
    
    printf("nao achou o pai: %d ", chave);
    return false;
    }
}

void pre_consulta(NO* no){
    if(no){
        printf("%d ", item_get_chave(no->item));
        pre_consulta(no->esquerda);
        pre_consulta(no->direita);
    }
}
void ab_imprimir (AB *T){
    pre_consulta(T->raiz);
}

int ab_estritamente_binaria (AB *T){
    if(T->raiz){
        if(busca_no_nao_binario(T->raiz)!=NULL){
            return 1;
        }
    }
    return 0;
}



int busca_no_errado(NO* no){
    if(no==NULL){
        return 0;//caso eu tiver chamado a função em um nó nulo, pra nao ter que ficar verificando antes de chamar só assumo que esse esta certo
    }


    if(no->esquerda!=NULL){
        if(item_get_chave(no->esquerda->item) > item_get_chave(no->item)){
            return 1;//achou o no errado
        }
    }
    if(no->direita!=NULL){
        if(item_get_chave(no->direita->item) < item_get_chave(no->item)){
            return 1;//achou o no errado
        }
    }


    //se esse nao ta errado ele procura nos de baixo
    if(busca_no_errado(no->esquerda)==1){
        return 1;
    }
    if(busca_no_errado(no->direita)==1){
        return 1;
    }
    //se ano achou, ele retorna falso
    return false;
}





int ab_checar_busca (AB *T){
    if(T!=NULL){
        return busca_no_errado(T->raiz);
    }
}
