#include <stdlib.h>
#include <stdio.h>

void main() {
    int k = 8;
    int *ptr;
    int *ptr1, *ptr2, *ptr3;

    ptr = &k;      /* Muutujasse ptr omistatakse muutuja k aadress. */
    printf("Muutujas k olev arv tema aadressi järgi %d\n", *ptr);
    *ptr = 12;
    printf("Muutuja k uuesti: %d\n", k);

    ptr1 = malloc(sizeof (int));
    *ptr1 = 20;   /* Aadressi ptr1 kaudu omistatakse 20 */
    printf("Muutuja ptr1 poolt viidatavasse kohta pandi %d\n", *ptr1);


    ptr2 = ptr1;
    printf("Viitmuutuja ptr2 kaudu leiame arvu %d.\n", *ptr2);

    printf("ptr1-s olev aadress on %p ja ptr2-s olev aadress on %p.\n", ptr1, ptr2);
    if (ptr1 == ptr2) {
        printf("Muutujad ptr1 ja ptr2 viitavad samasse kohta.\n");
    }
    else {
        printf("Muutujad ptr1 ja ptr2 ei viita samasse kohta.\n");
    }

    ptr3 = malloc(sizeof(int));
	printf("Sisesta ptr3: ");
	scanf("%d", ptr3);
	printf("Peeter 3. = %d\n", *ptr3);

    free(ptr1);
    ptr1 = malloc(8);
    ptr1 = ptr3;
    printf("ptr3: %p, ptr1: %p",  ptr1, ptr3);



}

