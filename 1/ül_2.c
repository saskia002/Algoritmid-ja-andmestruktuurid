#include <stdio.h>
#include <math.h>


ruutv6rrand(double a, double b, double c, int type){
    double ruudus, v22rtus;

    ruudus = sqrt(pow(b, 2) - 4*a*c);

    if (ruudus >= 0) {
        if (type == 1){
            v22rtus = (-b + ruudus) / (2*a);
        } else if (type == 2){
            v22rtus = (-b - ruudus) / (2*a);
        }
        printf("x%d: %lf", type, v22rtus);

    }else{
        printf("x%d: Reaalarvulised lahendid puuduvad", type);
    }
    printf("\n");

}

main(void) {
    double a, b, c, x1, x2;
    // ax^s + bx + c = 0

   // printf("T�ki palun a: ");
   // scanf("%lf", &a);
   // printf("T�ki palun b: ");
   // scanf("%lf", &b);
   // printf("T�ki palun c: ");
   //scanf("%lf", &c);

    printf("T�ki palun valem (ax2 + bx + c = 0): ");
    scanf("%lfx2 + %lfx + %lf = 0", &a, &b, &c);

    printf("\n");

    x1 = ruutv6rrand(a, b, c, 1);
    x2 = ruutv6rrand(a, b, c, 2);

}


