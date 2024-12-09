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
    int altura;
};

struct avl{
    NO* raiz;
};

NO* no_criar(ITEM* i){
    NO* no = malloc(sizeof(NO));
    no->balanceamento = 0;
    no->altura = 0;
    no->item = i;
    no->direita=NULL;
    no->esquerda=NULL;
    return no;
}

void no_apagar(NO** no){
    item_apagar((*no)->item);
    free(*no);
    *no = NULL;

}
AVL* avl_criar(){
    AVL* avl = malloc(sizeof(AVL));
    avl->raiz=NULL;
    //printf("\n[DEBUG] criar\n");
    return avl;
}

int maximo(int n1, int n2){
    if(n1>n2){
        return n1;
    }
    return n2;
}
int altura(NO* no){
    if(no==NULL){
        return -1;
    }
    return no->altura;
}
NO** inserir_recursiva(NO** raiz ,ITEM* i){
    if(*raiz==NULL){
        *raiz = no_criar(i);
        //printf("[DEBUG] inseriu %d\n", item_get_chave(i));
        (*raiz)->balanceamento=0;
        (*raiz)->altura=0;
        printf("botou o %d\n", item_get_chave(i));
        return NULL; //nao ta desbalanceado

    }else if(item_get_chave((*raiz)->item)>item_get_chave(i)){
        NO** mais_jov_desb = inserir_recursiva(&((*raiz)->esquerda),i);

        int alturae = altura((*raiz)->esquerda);
        int alturad = altura((*raiz)->direita);

        (*raiz)->altura=1+maximo(alturae,alturad);
        (*raiz)->balanceamento = alturae-alturad;

        if(mais_jov_desb == NULL){
            if((*raiz)->balanceamento>1||(*raiz)->balanceamento<-1){
                return raiz;
            }
        }
        return mais_jov_desb;
        
    }else if(item_get_chave((*raiz)->item)<item_get_chave(i)){
        NO** mais_jov_desb = inserir_recursiva(&(*raiz)->direita,i);
        int alturae = altura((*raiz)->esquerda);
        int alturad = altura((*raiz)->direita);

        (*raiz)->altura = 1+maximo(alturae, alturad);
        (*raiz)->balanceamento = alturae-alturad;
        if(mais_jov_desb==NULL){
            if((*raiz)->balanceamento>1||(*raiz)->balanceamento<-1){
                return raiz;
            }
        }
        return mais_jov_desb;
    }else{
        printf("[DEBUG] ja tem o numero %d\n", item_get_chave(i));
        return NULL;
    }
}

NO* rotacao_direita(NO** r){
    NO* aux = (*r);
    (*r)=(*r)->esquerda;
    aux->esquerda = (*r)->direita;
    (*r)->direita = aux;
    return *r;
}

NO* rotacao_esquerda(NO** r){
    NO* aux = *r;
    *r = (*r)->direita;
    aux->direita = (*r)->esquerda;
    (*r)->esquerda = aux;
    return *r;
}

bool avl_inserir(AVL* avl, ITEM* i){
    if(avl!=NULL){
        NO** mais_jov_desb = inserir_recursiva(&(avl->raiz),i);
        

        if(mais_jov_desb){
            if((*mais_jov_desb)->balanceamento>0){
                printf("[DEBUG] mais jovem desbalanceado e o %d, fv = %d\n", item_get_chave((*mais_jov_desb)->item),(*mais_jov_desb)->balanceamento);
                if((*mais_jov_desb)->esquerda->balanceamento>=0){

                    (*mais_jov_desb) = rotacao_direita(mais_jov_desb);

                }else if((*mais_jov_desb)->esquerda->balanceamento<0){

                    (*mais_jov_desb)->esquerda = rotacao_esquerda(&((*mais_jov_desb)->esquerda));

                    (*mais_jov_desb) = rotacao_direita(mais_jov_desb);

                }
            }//simetria
            else if((*mais_jov_desb)->balanceamento<0){
                printf("[DEBUG] mais jovem desbalanceado e o %d, fv = %d\n", item_get_chave((*mais_jov_desb)->item),(*mais_jov_desb)->balanceamento);

                if((*mais_jov_desb)->direita<=0){
                    *mais_jov_desb = rotacao_esquerda(mais_jov_desb);
                }else if((*mais_jov_desb)->direita>0){
                    (*mais_jov_desb)->direita = rotacao_direita(&((*mais_jov_desb)->direita));
                    *mais_jov_desb = rotacao_esquerda(mais_jov_desb);
                }
            }
        }
    }
    return false;
}

void troca_max_esq(NO* raiz, NO* atual, NO* ant){
    if(atual->direita==NULL){
        if(raiz == ant){
            raiz->esquerda=atual->esquerda;
        }else{
            ant->direita=atual->esquerda;
        }
        ITEM* apagar = raiz->item;
        raiz->item = atual->item;
        item_apagar(apagar);
        free(atual);
        atual=NULL;

    }else{
        troca_max_esq(raiz,atual->direita,atual);
    }
}

bool avl_remover(AVL* avl, int chave){
    NO* no = avl_remover_rec(&(avl->raiz), chave);
    if(no!=NULL){
    printf("[DEBUG] removeu o nó %d",item_get_chave(no->item));
    }
}
NO* avl_remover_rec(NO** no, int chave){
    if(no==NULL){
        return NULL;
    }
    if(chave==item_get_chave((*no)->item)){
        //remover
    }
    if(chave<item_get_chave((*no)->item)){
        (*no)->esquerda = avl_remover_rec(&((*no)->esquerda),chave);
    }else if(item_get_chave((*no)->item)>chave){
        (*no)->direita = avl_remover_rec(&((*no)->direita),chave);
    }


    if((*no)->item->balanceamento>1||(*no)->item->balanceamento<-1){
        if((*no)->balanceamento>0){
            if((*no)->esquerda->balanceamento>=0){
                (*no) = rotacao_direita(no);
            }else if((*no)->esquerda->balanceamento<0){
                (*no)->esquerda = rotacao_esquerda(&((*no)->esquerda));
                (*no) = rotacao_direita(no);
            }
        }//simetria
        else if((*no)->balanceamento<0){

            if((*no)->direita<=0){
                *no = rotacao_esquerda(no);
            }else if((*no)->direita>0){
                (*no)->direita = rotacao_direita(&((*no)->direita));
                *no = rotacao_esquerda(no);
            }
        }
    }

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
bool no_remover(NO** no){
    if((*no)!=NULL){
        free(*no);
        (*no)=NULL;
        return true;
    }
    return false;
}


NO** mais_a_direita(NO* raiz){
    if(raiz->direita==NULL){
        return &raiz;
    }
    return mais_a_direita(raiz->direita);
}
NO** mais_a_esquerda(NO* raiz){
    if(raiz->esquerda==NULL){
        return &raiz;
    }
    return mais_a_esquerda(raiz->esquerda);
}
NO** procurar(NO* r, int n){
    if(r==NULL){
        return NULL;
    }
    if(item_get_chave(r->item)>n){
        return procurar(r->esquerda,n);
    }else if(item_get_chave(r->item)<n){
        return procurar(r->direita,n);
    }else{
        return &r;
    }
}




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