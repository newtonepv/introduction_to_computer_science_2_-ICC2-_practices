#ifndef AVL_H
    #define AVL_H
    #include <stdbool.h>
    #include "item.h"
    typedef struct avl AVL;
    AVL* avl_criar();
    bool avl_inserir(AVL* avl, ITEM* i);
    void avl_debug_raiz_nula(AVL* avl);
    void debug_printar_pos_ordem(AVL* avl);
    void calcular_balanceamento(AVL* avl);
    void debug_printar_balanceamento_pos_ordem(AVL* avl);
    void debug_avl_trocar_30_com_45(AVL* avl);
    bool debug_achar_no(AVL* avl,int n);
    //bool avl_remover(AVL* avl, int n);
#endif
