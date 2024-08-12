#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE* filePointer;

    if((filePointer = fopen("text.txt", "w")) != NULL) {
        
        char* text = (char*)malloc(sizeof(char)*5);
        text[0]='c';
        text[1]='b';
        text[2]='\0';
        text[3]='a';
        text[4]=EOF;
        
        fprintf(filePointer, text);
        printf(text);

    } else {
        printf("\nError opening the file");
    }

    return 0;
}