#include <stdio.h>
#include <math.h>


arvuta(double arv1, double arv2, int type){

    switch(type){
        case 1:
            printf("liidetud arv on: %lf\n", (arv1 + arv2));
            break;
        case 2:
            printf("lahutatud arv on: %lf\n", (arv1 - arv2));
            break;
        case 3:
            printf("korrutatud arv on: %lf\n", (arv1 * arv2));
            break;
        case 4:
            printf("jagatud arv on: %lf\n", (arv1 / arv2));
            break;
        default:
            printf("Tekkis arvutamisel viga");
            break;
    }

}

main(void) {
    double arv1, arv2;
    int type;

    printf("Tüki palun arv 1: ");
    scanf("%lf", &arv1);
    printf("Tüki palun arv 2: ");
    scanf("%lf", &arv2);
    printf("\n");

    printf("1 - liitmine\n2 - lahutamine\n3 - korrutamine\n4 - jagamine\n");
    printf("\n");
    printf("Vali tehte valik: ");
    scanf("%d", &type);
    printf("\n");

    arvuta(arv1, arv2, type);

}


