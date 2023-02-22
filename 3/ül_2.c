#include <stdio.h>
#include <stdbool.h>
#define MaxN 6

main() {
    int numbers[MaxN] = {123, 3, 6, 1, 8, 10};
    int minNum, arrayLen, minNumId;
    bool arraySort = true;

    arrayLen = (int)(sizeof(numbers) / sizeof(numbers[0]));

    int i, j, minId;
    for (i=0; i < arrayLen-1; i++) {
        minId = i;
        for (j=i+1; j < arrayLen-1; j++) {
          if (numbers[j] < numbers[minId]) {
              minId = j;
          }
        }
        if (minId!=i) {
            int temp = numbers[i];
            numbers[i] = numbers[minId];
            numbers[minId] = temp;
        }
    }

    i = 0;
    printf("Jada on: ");
    while (i<arrayLen) {
        i++;
        // printf("%p ", &numbers[i]);
        printf("%d ", numbers[i]);
    }




}


