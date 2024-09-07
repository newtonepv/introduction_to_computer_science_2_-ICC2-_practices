#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct deque_{
    int tamanho;
    int inicio;
    int fim;
    ITEM* itens[MAX_TAMANHO];
};

DEQUE* deque_criar(){
    DEQUE* deque = (DEQUE*)malloc(sizeof(DEQUE));
    if(deque){
        deque->tamanho=0;
        deque->inicio=0;
        deque->fim = 0;
    }
    return deque;
}
void deque_apagar(DEQUE** deque){
    while(!deque_vazia(*deque)){
        ITEM*item=deque_remover_inicio(*deque);
        free(item);
        item = NULL;
    }
}

bool deque_inserir_inicio(DEQUE* deque, ITEM* item){
    if(!deque_cheia(deque)){
        
        deque->itens[deque->inicio] = item;
        deque->inicio

    }
}
bool deque_inserir_fim(DEQUE* deque, ITEM* item);


ITEM* deque_remover_inicio(DEQUE* deque);
ITEM* deque_remover_fim(DEQUE* deque);

ITEM* deque_primeiro(DEQUE* deque);
ITEM* deque_ultimo(DEQUE* deque);

int deque_contar(DEQUE* deque);
bool deque_vazia(DEQUE* deque);
bool deque_cheia(DEQUE* deque);
