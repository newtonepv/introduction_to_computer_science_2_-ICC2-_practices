#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item{
    int chave;
    void* dados;
};

ITEM* item_criar(){
    ITEM* item = malloc(sizeof(ITEM));
    return item;
}
void item_set_chave(ITEM* item, int chave){
    item->chave=chave;
}
int item_get_chave(ITEM* item){
    return item->chave;
}