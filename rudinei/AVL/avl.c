#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "avl.h"
#include <stdbool.h>
typedef struct no NO;
struct no{
    NO* direita;
    NO* esquerda;
    ITEM* item;
    int balanceamento;
};

struct avl{
    NO* raiz;
};

NO* no_criar(ITEM* i){
    NO* no = malloc(sizeof(NO));
    no->balanceamento = 0;
    no->item = i;
    no->direita=NULL;
    no->esquerda=NULL;
    return no;
}

AVL* avl_criar(){
    AVL* avl = malloc(sizeof(AVL));
    avl->raiz=NULL;
    printf("\n[DEBUG] criar\n");
    return avl;
}

bool inserir_recursiva(NO** raiz,ITEM* i){
    if(*raiz==NULL){
        *raiz = no_criar(i);
        printf("[DEBUG] inseriu %d\n", item_get_chave(i));
        (*raiz)->balanceamento=0;
        return true;
    }
    if(item_get_chave((*raiz)->item)>item_get_chave(i)){
        if(inserir_recursiva(&((*raiz)->esquerda),i)){
            (*raiz)->balanceamento+=1;
            return true;
        }
    }
    if(item_get_chave((*raiz)->item)<item_get_chave(i)){
        if(inserir_recursiva(&((*raiz)->direita),i)){
            (*raiz)->balanceamento-=1;
            return true;
        }
    }
    printf("[DEBUG] ja tem o numero %d\n", item_get_chave(i));
    return false;
}

bool avl_inserir(AVL* avl, ITEM* i){
    if(avl!=NULL){
        return inserir_recursiva(&(avl->raiz),i);
    }
    return false;
}


int calcular_balanceamento_recursivo(NO* no){
    if(no==NULL){
        return -1;
    }
    int esquerda_balanceamento = calcular_balanceamento_recursivo(no->esquerda);
    int direita_balanceamento = calcular_balanceamento_recursivo(no->direita);
    no->balanceamento=esquerda_balanceamento-direita_balanceamento;
    printf("[DEBUG] balanceou o %d agora eh: %d (%d)-(%d)\n",item_get_chave(no->item), no->balanceamento,esquerda_balanceamento,direita_balanceamento);
    return no->balanceamento;
}
void calcular_balanceamento(AVL* avl){
    if(avl!=NULL){
        int balanceamento_da_raiz = calcular_balanceamento_recursivo(avl->raiz);
    }
}

void trocar(NO* a_ser_trocado, NO* por_no_lugar){
    NO aux = *a_ser_trocado;
    *a_ser_trocado = *por_no_lugar;
    *por_no_lugar = aux;
}
NO* mais_a_direita(NO* raiz){
    if(raiz->direita==NULL){
        return raiz;
    }
    return mais_a_direita(raiz->direita);
}
NO* mais_a_esquerda(NO* raiz){
    if(raiz->esquerda==NULL){
        return raiz;
    }
    return mais_a_esquerda(raiz->esquerda);
}



NO* procurar(NO* r, int n){
    if(r==NULL){
        return r;
    }
    if(item_get_chave(r->item)>n){
        return procurar(r->esquerda,n);
    }else if(item_get_chave(r->item)<n){
        return procurar(r->direita,n);
    }else{
        return r;
    }
}

bool avl_remover(AVL* avl, int n){
    if(avl!=NULL){
        NO* no_pra_remover = procurar(avl->raiz, n);
        if(no_pra_remover==NULL){
            return false;
        }
        if(no_pra_remover->esquerda!=NULL){
            NO* por_no_lugar;
            if(no_pra_remover->esquerda->direita!=NULL){
                por_no_lugar = mais_a_direita(no_pra_remover->esquerda);
            }else{
                por_no_lugar = no_pra_remover->esquerda;
            }
        }else if(no_pra_remover->direita!=NULL){
            //vai pegar o mais a esquerda do no da direita
            NO* por_no_lugar;
            if(no_pra_remover->direita->esquerda!=NULL){
                por_no_lugar = mais_a_esquerda(no_pra_remover->direita);
            }else{
                por_no_lugar = no_pra_remover->direita;
            }
        }else{
            free(no_pra_remover);
            no_pra_remover=NULL;
        }
    }
}

/*bool debug_achar_no(AVL* avl,int n){
    if(avl!=NULL){
        NO* no_procurado = procurar(avl->raiz,n);
        if(no_procurado==NULL){
            return false;
        }
        printf("\n[DEBUG] no_procurado: %d\n", item_get_chave(no_procurado->item));
        return true;
    }
    return false;
}*/

void debug_printar_pos_ordem_recursivo(NO* no){
    if(no!=NULL){
        debug_printar_pos_ordem_recursivo(no->esquerda);
        debug_printar_pos_ordem_recursivo(no->direita);
        printf("[DEBUG] numero %d\n", item_get_chave(no->item));
    }
}
void debug_printar_pos_ordem(AVL* avl){
    if(avl!=NULL){
        debug_printar_pos_ordem_recursivo(avl->raiz);
    }
}
void debug_printar_balanceamento_pos_ordem_recursivo(NO* no){
    if(no!=NULL){
        debug_printar_balanceamento_pos_ordem_recursivo(no->esquerda);
        debug_printar_balanceamento_pos_ordem_recursivo(no->direita);
        printf("[DEBUG] balancemaneto %d\n", no->balanceamento);
    }
}
void debug_printar_balanceamento_pos_ordem(AVL* avl){
    if(avl!=NULL){
        debug_printar_balanceamento_pos_ordem_recursivo(avl->raiz);
    }
}
/*
void avl_debug_raiz_nula(AVL* avl){
    if(avl->raiz==NULL){
        printf("avl->raiz==NULL\n");
    }else{
        printf("avl->raiz!=NULL\n");
    }
}*/