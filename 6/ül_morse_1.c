#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "readFromFile.c"

struct MorseTree {
    char letter;
    struct MorseTree *dot, *dash;
};

static int i;    
char LETTERS[30]={' ','E','I','S','H','V','U','F','Y','A','R','L','2','W','P','J','T','N','D','B','X','K','C','Y','M','G','Z','Q','O','6'};

struct MorseTree *BuildTree(int N) {
    struct MorseTree *newNode;
    int nl, nr;
    if (N==0) {
        return NULL;
    }
    else {
        nl = N / 2;
        nr = N-nl-1;
        newNode = malloc(sizeof *newNode);
        newNode->letter = LETTERS[i];
        i++;
        newNode->dot = NULL;
        newNode->dash = NULL;
        newNode->dot = BuildTree(nl);
        newNode->dash =  BuildTree(nr);
        return newNode;
    }
}

void Preorder(struct MorseTree *RPointer) {
    // printf("%c", RPointer->letter);
    if (RPointer->dot != NULL) {
        Preorder(RPointer->dot);
        // printf("%c",RPointer->letter); //  Siin oleks Inorder
    }
    if (RPointer->dash != NULL) {
        Preorder(RPointer->dash);
    }
}

void main() {

    struct MorseTree *morse, *current;
    i = 0;

    morse = BuildTree(30);
    Preorder(morse);

    // failist lugemine
    char* fileData = readFile();
    // printf("%s \n", fileData);

    // saadud char for loop kaudu puust teisendamine
    // liikumis fnc puud mööda. . vasakule - paremale ja / tähe lõpp
    int fileDataLenght = strlen(fileData);
    // printf("Saadud faili pikkus on: %d\n", fileDataLenght);

    current = morse;

    for(int i=0; i<fileDataLenght; i++) {
        char symbol = fileData[i];

        switch(symbol) {
            case '.': // left
                current = current->dot;
                break;
            case '-': // right
                current = current->dash;
                break;
            case '/': // break
                printf("%c", current->letter);
                current = morse;
                break;
            default:
                break;
        }

    }

    printf("\n");

}

