#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printUntilBar0(char * text){
    int i=0;
    while(text[i]!='\0'){
        printf("%c", text[i]);
        i++;
    }
}

int main(void){
FILE* filePointer;

if(filePointer = fopen("textFile.txt","a+")){
    size_t buffersize = 255;
    char* line = (char*)malloc(buffersize*sizeof(char));

    char nextchar = fgetc(filePointer);

    if(nextchar!=EOF && strlen(line)<buffersize){
        int counter = 0;
        do{
        line[counter]=nextchar;
        line[counter+1]='\n';
        line[counter+2]='\0';
        counter++;
        nextchar = fgetc(filePointer);
        }
        while(nextchar!=EOF && strlen(line)<buffersize);
    }

    printUntilBar0(line);
}else{
    printf("\n erro ao abrir o arquivo");
}



return 0;
}