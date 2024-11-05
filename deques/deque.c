#include "deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct deque_{
    int tamanho;
    int inicio;
    int fim;
    ITEM* itens[MAX_TAMANHO];
};

deque_criar(){

}