#include <stdio.h>
#define MaxN 5

main() {
    int numbers[MaxN];
    int sum, prevNum, arrayLen;

    for (int i=0; i < MaxN; i++) {
       printf("Sisesta element nr %d >> ", i);
       scanf("%d", &numbers[i]);
    }

    arrayLen = (int)(sizeof(numbers) / sizeof(numbers[0]));

    printf("Array pikkus on: %d\n", arrayLen);

    for (int i=1; i < arrayLen; i++) {
        prevNum = numbers[i-1];
        if(prevNum >= 0) {
            sum += numbers[i];
        }
    }

    printf("Pos arvude summa on: %d", sum);




}


