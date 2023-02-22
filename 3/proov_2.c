/* Programm moodustab t�isarvuliste v��rtuste jaoks ahela.
 * Vaata, millises j�rjekorras andmeid lisatakse ehk lisa v�ljatr�kk
 * eelmisest n�itest l�htudes
 */

#include <stdio.h>
#include <stdlib.h>

struct element {
       int info;
       struct element *next;
};

int getArrayLength(struct element *node) {
    struct element *current;
    int i = 0;

    current = node;
    while(current != NULL) {
        printf("{%d, %d}\n", current->info, current->next);
        current = current->next;
        i++;
    }

    return i;

}


int main(void){

    struct element *head, *node;
    int arv;

    printf("Sisesta arv! (L�petamiseks 0)");
    scanf("%d",&arv);

    head = NULL;
    while(arv != 0) {
          node = malloc(sizeof *node);
          node->next = head;
          node->info = arv;
          head = node;
          //printf("%d - node next\n%d - node info\n", node->next, node->info);
          printf("Sisesta arv! (L�petamiseks 0)");
          scanf("%d",&arv);
    }

    printf("arr len on: %d\n", getArrayLength(node));





}
