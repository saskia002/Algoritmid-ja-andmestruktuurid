#include <stdio.h>
#include <string.h>
#define maxN 10

void main() {
   FILE *tf=NULL;
   int m, n, i, j, o, 😡;
   int matrix[maxN][maxN] = {0};

   tf = fopen("./data/graaf_topo.txt","r");  

   // 1. osa
    while (!feof(tf)) {
        fscanf(tf,"%d %d",&m,&n);
        matrix[m][n] = 1;
    }

    printf("\n");
	printf("😎");
    for(i=0; i<maxN; i++){
        if(i==0) {
            printf(" %d", i);
        }else {
            printf("  %d", i); 
        }
    }
    printf("\n");

	for ( i = 0; i < maxN; i++) {
        printf("%d", i);
        for (j = 0; j < maxN; j++) {
        	printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    // 2. osa
    printf("\nSisesta tipu nr mille naabritega tahad tutvuda: ");
    scanf("%d", &o);

    printf("%d naabrid on: ", o);

    for(i=0; i<maxN; i++) {
        if(matrix[o][i] == 1){ 
            printf("%d ", i);
        }
    }
    printf("\n");

}
