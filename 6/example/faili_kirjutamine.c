/* 
 * N�ide t��st tekstifailiga
 * Fail avatakse, siis kirjutatakse tekst ja see j�rel suletakse
 * P�rast on fail programmiga samas kataloogis ja k�ik on �nnelikud
 */

#include <stdio.h>

main(){

/* Faili pide (faili muutuja) deklareeritakse ja nullitakse. NULL-i kaudu peab saama
 * hiljem kontrollida, kas avamine �nnestus. */

  FILE *fm = NULL;
  
/* Faili avamine kirjutamiseks */

  fm = fopen("failinimi.txt", "w");

/* Faili tr�kitakse string */

  fprintf(fm, "Tere talv!\n");

/* Fail suletakse */

  fclose(fm);
}
