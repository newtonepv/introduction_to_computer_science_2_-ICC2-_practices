#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item{
    int id;
    char* nome;
};
ITEM* item_criar(int id, char* nome){
    ITEM* item = (ITEM*)malloc(sizeof(ITEM));
    item->id = id;
    item->nome = nome;
    return  item;
}
void item_set_id(ITEM* item, int id){
    item->id=id;
}
int item_get_id(ITEM* item){
    return item->id;
}
void item_set_nome(ITEM* item, char* nome){
    item->nome=nome;
}
char* item_get_nome(ITEM* item){
    return item->nome;
}
void item_remove_self(ITEM** item_pointer){
    *item_pointer = NULL;
    free(*item_pointer);
}
