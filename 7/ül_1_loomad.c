#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct animalTree {
    char *nodeText; 
    struct animalTree *yes, *no;
};

struct animalTree *makeRoot(char *text) {
	struct animalTree *temp;
    temp = malloc(sizeof *temp);
    temp->nodeText = text;
    temp->yes = NULL;
    temp->no = NULL;
    return temp;       
}

void insertNo(struct animalTree *location, struct animalTree *node) {
    location->no = node;       
}

void insertYes(struct animalTree *location, struct animalTree *node) {
    location->yes = node;       
}

void main() {
    struct animalTree *Temp, *Suur, *Hiir, *Elevant, *Karvane, *Karu;
    bool status = true;

    Suur = makeRoot("Kas ta on suur?");
    Karvane = makeRoot("Kas ta on karvane?");

    Hiir = makeRoot("HIIR");
    Elevant = makeRoot("ELEVANT");
    Karu = makeRoot("KARU");

    insertNo(Suur, Hiir);
    insertYes(Suur, Karvane);
    
    insertNo(Karvane, Karu);
    insertYes(Karvane, Elevant);

    printf("Loomapuu: \n\n");
    Temp = Suur;

    while(status) {
        if(Temp->yes == NULL && Temp->no == NULL) { 
            printf("Kas m6tlesid %s peale?", Temp->nodeText);
            char c2 = getchar(); getchar();
             switch(c2) {
                case 'y': // no
                    printf("Arvasin ära! :D\n");
                    printf("Kas soovid uuesti mängida? (y, n)\n");
                    char c4 = getchar(); getchar();
                    if(c4 == 'y') {
                        Temp = Suur;
                        break;
                    }else {
                        status = false;
                    }
                    break;
                case 'n': // yes
                    printf("Mis looma peale mõtlesid? \n");
                    char c3 = getchar(); getchar();
                    printf("Millise küsimuse küsiksid looma %c kohta, mis teda loomast %s eristaks?", c3, Temp->nodeText);
                    char c5 = getchar(); getchar();
                    // UUS LOOGIKA JUURDE LISAMISEKS

                    // * 

                    printf("Kas soovid uuesti mängida? (y, n)\n");
                    char c6 = getchar(); getchar();
                    if(c6 == 'y') {
                        Temp = Suur;
                        break;
                    }else {
                        status = false;
                    }

                    break;
                default:
                    break;
            }
            continue;
        }

        printf("y - jah, n - no \n");
        printf("%s\n", Temp->nodeText);

        char c = getchar(); getchar();
                
        switch(c) {
            case 'y': // no
                Temp = Temp->yes;
                break;
            case 'n': // yes
                Temp = Temp->no;
                break;
            default:
                break;
        }

    }
       
}
