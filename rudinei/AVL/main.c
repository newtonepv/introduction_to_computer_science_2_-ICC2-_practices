#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include <stdbool.h>
#include "item.h"

bool inserir_na_avl(AVL* avl, int n){
    
    ITEM* item = item_criar();
    item_set_chave(item,n);
    return avl_inserir(avl,item);
}

int main(){
    AVL* avl = avl_criar();
    inserir_na_avl(avl,30);
    inserir_na_avl(avl,15);
    inserir_na_avl(avl,45);
    inserir_na_avl(avl,45);
    inserir_na_avl(avl,35);
    //debug_printar_pos_ordem(avl);
    //debug_printar_balanceamento_pos_ordem(avl);
    //calcular_balanceamento(avl);
    //debug_achar_no(avl,45);
    return 0;
}