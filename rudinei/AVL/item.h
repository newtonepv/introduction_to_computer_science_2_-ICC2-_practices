#ifndef ITEM_H
    #define ITEM_H
    typedef struct item ITEM;
    ITEM* item_criar();
    void item_set_chave(ITEM* item, int chave);
    int item_get_chave(ITEM* item);
#endif