#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct element {
    char info;
    struct element *next;
};

static struct element *top;

void stackInit() { 
    top = NULL; 
}

int stackEmpty(void) { 
	if (top == NULL) { return 1; }
    else { 	return 0; }
}

void stackPush(char item) { 
	struct element *node;
    node = malloc(sizeof *node);
    node->info = item;
    node->next = top;
    top = node;
}

char stackPop(void) {
    struct element *node;
    node = top;
    top = top->next;
    char nodeInfo = node->info;
    free(node);
    return nodeInfo;
}


void main() {
 
   
    char expression[1000];
    char newExp[1000];
    char newTop;
    int i, lenght, j=0;

    printf("Sisesta mingi tehe: ");
    scanf("%99s", &expression);
    lenght = strlen(expression);

    stackInit(lenght);

    for (i=0; i<lenght; i++) {
        if(expression[i] == '(') { continue; }

        if(expression[i] == ')'){
            char operator = stackPop();
            newExp[j] = operator;
            j++;
            continue;
        }

        if (
            isdigit(expression[i]) || isalpha(expression[i])
        ) {
            newExp[j] = expression[i];
            j++;
            continue;
        }
         
       if (
            expression[i] == '*' || expression[i] == '/' ||
            expression[i] == '+' || expression[i] == '-' 
        ) {
            stackPush(expression[i]);
            continue;
        }

    }

    newExp[j] = '\0';

    printf("Uus tehe: %s \n", newExp);

    // (2*a)/((a+b)*(a-c))
    // (5*((9*8)+(7*(4+6))))

    printf("Sümbolid stackis: ");
    while (!stackEmpty()) {
       printf("%c", stackPop()); 
    }

    printf("\n");

}
