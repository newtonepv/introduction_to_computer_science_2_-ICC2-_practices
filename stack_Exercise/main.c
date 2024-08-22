#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"item.h"
#include"Pilha.h"

int main(void){
    printf("debuggin main(void)");
    int qtd;
    scanf("%d", &qtd);
    for(int i=0; i<qtd; i++){
        char input[1000];
        fgets(input, 1000, stdin);
        //last char will be a '\n'

        bool a = balanceada(input);
    }

    return 0;
}