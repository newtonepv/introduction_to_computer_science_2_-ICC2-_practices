#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fprintUntilBar0OrEOF(char* text, FILE* filePointer) {
    int i = 0;
    char* tempString = (char*)malloc(sizeof(char));
    while(text[i] != '\0'&&text[i] != EOF) {
        tempString[0]=text[i];

        fprintf(filePointer, tempString);
        i++;
    }
    tempString[0]='\0';
    fprintf(filePointer, tempString);
}

char* readUntil(char limitatorChar, FILE* filePointer) {
    /* Returns the read chars until the limitator char, or until the EOF */
    char* line = (char*)malloc(sizeof(char));
    char nextchar = fgetc(filePointer);
    
    int counter = 0;
    do {
        line = (char*)realloc(line, (3 + counter) * sizeof(char)); /* Reallocates the line string */
        line[counter] = nextchar;
        line[counter + 1] = '\n';
        line[counter + 2] = '\0';
        counter++;
        if(nextchar == EOF){
            break;
        }
        nextchar = fgetc(filePointer);
    } while(nextchar != limitatorChar && (char*)realloc(line, (3 + counter) * sizeof(char)) != NULL);
    /* Stops reallocating and reading when reads the limitator char or the EOF */
    return line;
}

int getIndexOfChar(char* text, char searchingFor) {
    int len = strlen(text);
    for(int i = 0; i < len; i++) {
        if(text[i] == searchingFor) {
            return i;
        }
    }
    return -1;
}

/*void changeCharAtIndex(char* text, char newChar, int index) {
    text[index] = newChar;
}*/

void append(char* text, char* text_to_append){
    int text_length = strlen(text);
    int length_of_text_to_append = strlen(text_to_append);
    for(int i=0; i<length_of_text_to_append;i++){
        text[text_length+i]=text_to_append[i];
    }

}

char* removeAt(char*text, int index){
    //loop starts at where we want to shift
    //loops ends before the \0 (strlen)
    for(int i=index; i<strlen(text);i++){
        text[i] = i+1;
    } 
    //text[(int)strlen(text)+2]=NULL;
    text = (char*)realloc(text,sizeof(char)*(strlen(text)+1));
    return text;
}

int main() {
    FILE* filePointer;
    FILE* write;

    if((filePointer = fopen("textFile.txt", "r+")) != NULL) {
    
        fseek(filePointer, 0, SEEK_END);
        int sizeOfFile = ftell(filePointer);
        fseek(filePointer,0,SEEK_SET);
        
        char* newFile = malloc(sizeOfFile*2*sizeof(char));
        newFile[0]='\0';
        
        int indexOfEOF = 0;
        
        char* nextLine;
        do{
            nextLine = readUntil('\n',filePointer);
            if((indexOfEOF=getIndexOfChar(nextLine, EOF))!=-1){
                removeAt(nextLine,indexOfEOF);
                /*printf("past file: \n");
                printf(newFile);
                printf("\nnew line:\n");
                printf(nextLine);
                append(newFile,nextLine);
                printf("\nNOW WITH ONE LINE\n");
                printf(newFile);
                append(newFile,nextLine);*/
            break;
            }
            append(newFile,nextLine);
            append(newFile,nextLine);
        }while(1);
        
        fseek(filePointer, 0, SEEK_SET);
        fprintf(filePointer,newFile);
        fclose(filePointer);
    } else {
        printf("\nError opening the file");
    }

    return 0;
}
