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
    } while(nextchar != limitatorChar && (char*)realloc(line, (2 + (counter + 1)) * sizeof(char)) != NULL);
    /* Stops reallocating and reading when reads the limitator char or the EOF */
    printf(line);
    return line;
}

int getIndexOfChar(char* text, char searchingFor) {
    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == searchingFor) {
            return i;
        }
    }
    return -1;
}

/*void changeCharAtIndex(char* text, char newChar, int index) {
    text[index] = newChar;
}*/

int main() {
    FILE* filePointer;
    FILE* write;
    if((filePointer = fopen("textFile.txt", "a+")) != NULL&&(write= fopen("textFile.txt", "w")) != NULL) {
        /*char* line;
        char limitator = '\n';
            do{
                line = readUntil(limitator, filePointer);
                fprintUntilBar0OrEOF(line,write+strlen(line));
            //}while(getIndexOfChar(line, EOF)==-1);
            }while(1==0);
        fclose(filePointer); // Remember to close the file*/
        fseek(filePointer, 2, SEEK_SET);
        fputc('p',filePointer);
    } else {
        printf("\nError opening the file");
    }

    return 0;
}
