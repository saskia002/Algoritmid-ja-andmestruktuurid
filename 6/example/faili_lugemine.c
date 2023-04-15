/*
 * N�ites loetakse failist tekst stringidena ja tr�kitakse ekraanile. Ridu v�ib olla mitu.
 */

#include <stdio.h>

main(){

/* Muutuja line on string rea kaupa lugemiseks ja lisaks deklareeritakse faili pide */

  	char line[128];
  	FILE *fm = NULL;

/* Faili jutt.txt avamine lugemiseks - fail peab loomulikult olemas olema!!*/

  	fm = fopen("jutt.txt", "r");

/* feof() - funktsioon, mis kontrollib faili l�pu tunnust. Tagastab t�ese v��rtuse, kui
 * faili l�pp saabud. Seega feof()-i eitus lubab ts�klil t��tada siis, kui l�ppu ei paista.
 */ 

  	while (!feof(fm)) {

/* fgets loeb failist etten�htud maksimaalse pikkusega stringi. Parameetrid vastavalt: loetav muutuja,
 * loetav maks pikkus ja failipide.
 * Reavahetus toimib �he lugemislause jaoks l�putunnusena.
 */ 
 
    	fgets(line, 128, fm);
    	printf("%s", line);
  }
  fclose(fm);
}

/* K�ivitamiseks �ra edaspidist juttu kopeeri */
--------------------------------------------------
Veel kommentaare:
fscanf(fm, "%s", rida);
on ka sobiv erinevat t��pi andmete lugemiseks ja kiireks teisendamiseks sobivasse andmet��pi.
Antud n�ide t��tab nii, et iga lugemisek�sk loeb failist j�rgmise t�hikuni (v�i ka real�pu tunnuseni).
Seega v�ib �hes reas toimuda mitu lugemist.

Vt n�idet faili_lugemine2.c fscanf()-i kasutamisest andmete lugemiseks ja sisendi konvertimiseks arvudeks.



