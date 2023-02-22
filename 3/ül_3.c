#include <stdio.h>
#include <stdlib.h>

main() {
    char input[] = "y";
    int inputVal, count = 0, whereToVal;
    int *ptr = NULL;

    while(strcmp(&input, "y") == 0) {
        printf("Vali kuhu arv lsiada:\n   1 - Massiivi algusesse\n   2 - Massiivi l6ppu\n   3 - Massiivi keskele soovitud kohale \n");
        printf("Sisesta arv: ");
        scanf("%d", &whereToVal);

        printf("\nSisesta arv mida soovid lisada: ");
        scanf("%d", &inputVal);
        count++;
        ptr = (int*) realloc(ptr, count * sizeof(int));
        if (ptr == NULL) {
            puts("Error (re)allocating memory");
            exit(0);
        }

        switch(whereToVal) {
            case 1:
                for(int i=count; i>=0; i--) {
                    int temp = ptr[i];
                    ptr[i] = ptr[i-1];
                    ptr[i-1] = temp;
                    if(i=0){
                        ptr[0] = inputVal;
                        break;
                    }
                }
                break;
            case 2:
                ptr[count-1] = inputVal;
                break;
            case 3:
                break;
            default:
                break;
        }



        printf("\nKas soovid numbreid jurude lisada? (y/n): ");
        scanf("%s", &input);

    }


    printf("\nSisestatud numbrid: ");
    for(int n=0;n<count;n++) { printf ("%d ", ptr[n]); }
    free(ptr);

}


