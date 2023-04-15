#include <stdio.h>
#include <string.h>

main() {
 
    char password[10] = "kalasalat";
    char trayPasswd[10], newPasswd1[10], newPasswd2[10];
    char answer;
 
    printf("Sisesta parool ");
    scanf("%9s", trayPasswd);
    printf("%s\n", trayPasswd);
    getchar();   /* Loeb sisendpuhvrist ära reavahetuse, mida ta kuhugi ei pane.*/

    while (strcmp(trayPasswd, password)) {
        printf("Parool on vale. Programmi ei saa edasi kasutada.\n");
        printf("Sisesta parool uuesti \n");
        scanf("%9s", trayPasswd);
        getchar();
    }
 
    printf("Kas soovid parooli muuta [j/e]?");
    answer = getchar();   /* scanf("%c",&soov);*/
    getchar();
    if (answer == 'j') { 
        printf("Sisesta uus parool ");
        scanf("%9s", newPasswd1);
	    printf("Uue parooli pikkus on %d.\n", strlen(newPasswd1));
        printf("Sisesta uus parool teist korda ");
        scanf("%9s", newPasswd2);
        if (!strcmp(newPasswd1, newPasswd2)) {
            strcpy(password,newPasswd1);
            printf("Parool muudetud");
        }
        else {
        	printf("Paroolid olid erinevad");
		}
    }
    
}
