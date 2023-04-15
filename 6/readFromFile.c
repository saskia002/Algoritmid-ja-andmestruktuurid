#include <stdio.h>
#include <string.h>

char* readFile() {
    static char data[1000];
  	char line[255]; // buffer rea pikkuseks.

  	FILE *fail;
  	fail = fopen("./data/morse1.txt", "r");

    while (!feof(fail)) {
        fgets(line, sizeof(line) / sizeof(line[0]), fail);
        strcat(data, line);
        
    }

    fclose(fail);

    return data;
    
}
