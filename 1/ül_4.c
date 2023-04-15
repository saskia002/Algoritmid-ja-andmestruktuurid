#include <stdio.h>

void main() {
    int arvud[10];
    int i = 0;
    int max, max2, temp;

    printf("Sisesta 10 arvu ja leian 2. suurima!\n");
    while(i < 10){
        scanf("%d", &arvud[i]);
        i++;
    }

    for(i=0; i<10; i++) {
        temp = arvud[i];

        if(temp > max) {
            max2 = max;
            max = temp;
        }

    }

    printf("2. suurim arv on %d\n", max2);

}


