#include "lista.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>
//lista0 = 1 tamanho = 1
//lista
	bool lista_inserir(LISTA *lista, ITEM *item){

        if(lista_cheia(lista)){return false;}
        if(lista_vazia(lista)){
            lista->lista[0] = item;
            lista->tamanho++;
            lista->fim++;
            return true;
        }
        //printf("chamou a funcao, tamanho da lista = %d\n", lista_tamanho(lista));
        //fflush(stdout);
        int index=0;
        int x=0;
        int inseriu=0;

        while (x <lista_tamanho(lista)) {
            //printf("procurando %d\n", x);
            //fflush(stdout);
            if(item_get_chave(lista->lista[x]) > item_get_chave(item)) {
                //printf("entrou no if\n");
                //fflush(stdout);

                for (int i = (lista->tamanho - 1); i >= x; i--) {
                    //printf("agora o %d vai na %d\n", item_get_chave(lista->lista[i]), i+1);
                    //fflush(stdout);
                    lista->lista[i + 1] = lista->lista[i];
                }
                lista->lista[x] = item;
                //printf("inseri na %d\n", x);
                //fflush(stdout);
                inseriu = 1;
                break;
            }
            x++;
        }
        if(inseriu==0){
            lista->lista[lista->tamanho] = item;
            //printf("inseri na %d\n", x);
            //fflush(stdout);
        }
        lista->tamanho++;
        lista->fim++;
        
        //imprimir lista
        /*for(int i=0; i<lista->tamanho; i++){
            printf("%d ", item_get_chave(lista->lista[i]));
        }
        lista_imprimir(lista);*/
        return true;
        
    }