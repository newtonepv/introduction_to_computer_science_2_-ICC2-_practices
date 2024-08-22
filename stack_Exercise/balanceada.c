#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"item.h"
#include"Pilha.h"

int codifyChar(char caracter){

    if(caracter == '{'){
        return 1;
    }else if(caracter == '}'){
        return -1;
    }else if(caracter == '('){
        return 2;
    }else if(caracter == ')'){
        return -2;
    }else if(caracter == '['){
        return 3;
    }else if(caracter == ']'){
        return -3;
    }
}
size_t custom_strlen(const char* str) {
    size_t len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}


bool balanceada(char *sequencia){
    int largura = custom_strlen(sequencia);
    PILHA* pilha = pilha_criar();
    int tamanho=0;
    for (int i=0;i<largura;i++){

        int cdg = codifyChar(sequencia[i]);
        
        if(cdg<0){
            if(pilha_vazia(pilha)==true){
                return false;
            }
            int* ponteiro = (int*)item_get_dados(pilha_topo(pilha));
            if((cdg+*ponteiro)==0){
                ITEM* item = pilha_desempilhar(pilha);
                tamanho--;
                bool apagou = item_apagar(&item);
            }else{
                return false;
            }
            


        }else if(cdg>0){
            // Aloca memória para armazenar o valor de `cdg`
            int* novo_cdg = (int*)malloc(sizeof(int));
            *novo_cdg = cdg;

            // Empilha o valor
            pilha_empilhar(pilha, item_criar(0, novo_cdg));
            tamanho++;
        }
        
        if(tamanho>largura-(i+1)){

            return false;
        }
        
    }

    //depois de ler tudo
    if(tamanho>0){

        return false;
    }

    return true;
}



