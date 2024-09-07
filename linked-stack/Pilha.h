#ifndef PILHA_H
    #define PILHA_H
    #include <stdlib.h>
    #include "item.h"

    typedef struct _pilha PILHA;

    PILHA* pilha_criar();
    ITEM* pilha_desempilhar(PILHA* pilha);
    bool pilha_empilhar(PILHA* pilha, ITEM* item);
    bool pilha_apagar(PILHA** pilha);
    ITEM* pilha_topo(PILHA* pilha);
    int pilha_tamanho(PILHA* pilha);
    bool pilha_vazia(PILHA* pilha);
    bool pilha_cheia(PILHA* pilha);
    float rpn(char* sequencia);
#endif
