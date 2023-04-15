#include <stdio.h>
#include <string.h>

void main(int argc, char **argv) {

    // printf("%c\n", argv);
 
    char expression[100];
    int i, lenght;

    printf("Sisesta midagigigigigigi: ");
    scanf("%99[^\n]s", &expression);

    lenght = strlen(expression);

    for (i=0; i<lenght; i++) {
        printf("%c ", expression[i]);
        if (i+1 == lenght) {
            printf("\n");
        }
    }

}
