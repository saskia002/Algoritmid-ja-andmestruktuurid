#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct element {
    int info;
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

void stackPush(int item) { 
	struct element *node;
    node = malloc(sizeof *node);
    node->info = item;
    node->next = top;
    top = node;
}

int stackPop(void) {
    struct element *node;
    node = top;
    top = top->next;
    int nodeInfo = node->info;
    free(node);
    return nodeInfo;
}


void main() {
 
    char exp[1000];
    int i, lenght;

    printf("Sisesta mingi tehe: ");
    scanf("%99[^\n]s", &exp);
    lenght = strlen(exp);

    stackInit(lenght);

    for (i=0; i<lenght; i++) {
        if(exp[i] == ' ' || isspace(exp[i]) || exp[i] == '\n') { continue; }
        // if(lenght == 0) { break; } 

        // 1. kui num siis push stack
        if (isdigit(exp[i])) {
            stackPush((int) exp[i] - '0');
            // printf("+stack: %d\n", atoi(exp[i]));
            printf("+stack: %d\n", (int) exp[i] - '0');
            continue;
        }

        // 2. kui märk siis popime kas numbrit stackist
        if (
            exp[i] == '*' || exp[i] == '/' ||
            exp[i] == '+' || exp[i] == '-' 
        ) {

            if(stackEmpty()){ break; }

            char oper = exp[i];
            int num2 = stackPop();
            int num1 = stackPop();
            printf("%d%c%d\n", num1, oper, num2);

            stackPush(oper == '*' ? num1 * num2 : (oper == '/' ? num1 / num2 : (oper == '+' ? num1 + num2 : (oper == '-' ? num1 - num2 : 0))));

            continue;
        }

    }

    if(stackEmpty()){
         printf("Summa on: 0 \n");
    }else{
        printf("Summa on: %d \n", stackPop());
    }


    // 53*132-++
    // 5 3 * 1 3 2 - + +
    // 5 9 * 8 7 4 6 + * 2 1 3 * + * + *

    printf("Stackis: ");
    while (!stackEmpty()) {
       printf("%c", stackPop()); 
    }

    printf("\n");

}
