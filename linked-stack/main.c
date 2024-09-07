#include "Pilha.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

float rpn (char* sequencia){
    PILHA* pilha = pilha_criar();

    for(int i = 0; i < strlen(sequencia); i++) {
        if(sequencia[i] == '+'){
            float num1 = *((float*)item_get_dados(pilha_desempilhar(pilha)));
            float num2 = *((float*)item_get_dados(pilha_desempilhar(pilha)));
            float* resultado = (float*)malloc(sizeof(float));
            *resultado = num1 + num2;
            ITEM* item = item_criar(0, resultado);
            pilha_empilhar(pilha, item);
        }
        else if(sequencia[i] == '-'){
            float num1 = *(float*)item_get_dados(pilha_desempilhar(pilha));
            float num2 = *(float*)item_get_dados(pilha_desempilhar(pilha));
            float* resultado = (float*)malloc(sizeof(float));
            *resultado = num2 - num1;
            ITEM* item = item_criar(0, resultado);
            pilha_empilhar(pilha, item);
        }
        else if(sequencia[i] == '/'){
            float num1 = *(float*)item_get_dados(pilha_desempilhar(pilha));
            float num2 = *(float*)item_get_dados(pilha_desempilhar(pilha));
            float* resultado = (float*)malloc(sizeof(float));
            *resultado = num2/num1;
            ITEM* item = item_criar(0, resultado);
            pilha_empilhar(pilha, item);
        }
        else if(sequencia[i] == '*'){
            float num1 = *(float*)item_get_dados(pilha_desempilhar(pilha));
            float num2 = *(float*)item_get_dados(pilha_desempilhar(pilha));
            float* resultado = (float*)malloc(sizeof(float));
            *resultado = num1 * num2;
            ITEM* item = item_criar(0, resultado);
            pilha_empilhar(pilha, item);
        } else {
            float* numero = (float*)malloc(sizeof(float));
            *numero = (float)(sequencia[i] - '0');
            ITEM* item = item_criar(0, numero);
            pilha_empilhar(pilha, item);
        }
    }
    float retorno = *(float*)item_get_dados(pilha_desempilhar(pilha));
    pilha_apagar(&pilha);
    return retorno;
}
int main(){
    printf("%.2f\n", rpn("12+"));
    printf("%.2f\n", rpn("34*5+6/"));
    printf("%.2f\n", rpn("11+12++34*11+++"));
    return 0;
}