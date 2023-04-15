#include <stdio.h>
#include <stdlib.h>

void main() {
   
    int arrLen, i, j=0;
    double temp, input;

    printf("Mitu arvu tahad sisestada?\n");
    scanf("%d", &arrLen);

    double array[arrLen];

    while(i < arrLen) {

        printf("Sisesta float: ");
        scanf("%lf", &input);
 
        j=i-1;
        while(j >= 0 && array[j] > input) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = input;

        i++;
    }

    for(i = 0; i < arrLen; i++) {
        printf("%lf ", array[i]);
    } 

    printf("\n");

}