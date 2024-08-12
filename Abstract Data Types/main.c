#include <stdio.h>
#include "item.h"

int main(void){
    ITEM* item = item_criar(0,"loça");
    printf("%d\n",item_get_id(item));
    item_remove_self(&item);
    return 0;
}