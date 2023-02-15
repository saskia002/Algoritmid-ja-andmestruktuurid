#include <stdio.h>

int main(void) {
    float arv1, arv2;
    int summa, n;

    printf("Tüki palun kaks arvu (x y): ");
    scanf("%f %f", &arv1, &arv2);

    n = 1;

    for (int i=0; i<n; i++) {
        summa += arv1 + arv2;
    }

    // summa = (int) arv1 + (int) arv2;
    printf("Arvude %d ja %d summa on: %d", (int) arv1, (int) arv2, summa);

    char str[] = "\nTerve!";
    printf(str);
    return 0;

}
