#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static char *stack;
static char top;

void stackInit(int maxSize) { 
	stack = malloc(maxSize*sizeof(char)); 
    top = 0; 
}

int stackEmpty(void) { 
	if (top == 0) { return 1; }
    else { 	return 0; }
}

void stackPush(char item) { 
	stack[top] = item; 
    top++;
}

char stackPop(void) { 
	top--;
    return stack[top];
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

    printf("len: %d", strlen(newExp));

    newExp[j] = 'x';

    printf("Uus tehe: %s", newExp);

    // (2*a)/((a+b)*(a-c))
    // (5*((9*8)+(7*(4+6))))

    printf("Sümbolid stackis: ");
    while (!stackEmpty()) {
       printf("%c", stackPop()); 
    }

    printf("\n");

}
