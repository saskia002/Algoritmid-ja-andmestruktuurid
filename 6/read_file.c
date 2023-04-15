#include <stdio.h>

void main(){

  	char line[127]; // buffer rea pikkuseks.
  	FILE *fail;

  	fail = fopen("./data/morse1.txt", "r");

    while (!feof(fail)) {
        fgets(line, sizeof(line) / sizeof(line[0]), fail);
        printf("%s", line);
    }

    printf("\n");

    fclose(fail);

}
