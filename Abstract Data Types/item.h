#ifndef ITEM_H
    #define ITEM_H

    typedef struct item ITEM;

    ITEM* item_criar(int id, char* nome);
    void item_set_id(ITEM*item, int id);
    int item_get_id(ITEM*item);
    void item_set_nome(ITEM*item, char* nome);
    char* item_get_nome(ITEM*item);
    void item_remove_self(ITEM**item);

#endif