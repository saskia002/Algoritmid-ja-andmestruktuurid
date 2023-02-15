#include <stdio.h>
#include <math.h>

double Hypotenuus(double ka1, double ka2) {
    return sqrt(pow(ka1, 2) + pow(ka2, 2));
}

double Pindala(double ka1, double ka2) {
    return (ka1 * ka2) / 2;
}

int main(void) {
    double ka1, ka2, hy, pind;

    printf("Tüki palun 1. kaatet : ");
    scanf("%lf", &ka1);
    printf("Tüki palun 2. kaatet : ");
    scanf("%lf", &ka2);

    hy = Hypotenuus(ka1, ka2);
    pind = Pindala(ka1, ka2);

    printf("Kolmnurga hüpotenuus on: %lf \n", hy);
    printf("Kolmnurga pindala on: %lf", pind);

    return 0;

}


