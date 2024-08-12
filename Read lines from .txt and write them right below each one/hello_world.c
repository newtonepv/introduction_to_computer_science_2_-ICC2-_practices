#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fprintUntilBar0OrEOF(char* text, FILE* filePointer) {
    int i = 0;
    while(text[i] != '\0'&&text[i] != EOF) {
        char* tempString = (char*)malloc(sizeof(char)*2);
        tempString[0]=text[i];
        tempString[1]='\0';
        fprintf(filePointer, tempString);
        i++;
    }
}
int main() {
    FILE* filePointer;

    if((filePointer = fopen("textFile.txt", "a+")) != NULL) {
        
        fprintUntilBar0OrEOF("oooaiaaaio",filePointer);

    } else {
        printf("\nError opening the file");
    }

    return 0;
}