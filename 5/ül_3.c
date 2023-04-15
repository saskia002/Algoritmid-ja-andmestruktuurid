#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

static struct node *front, *rear;

void createQ(){
    front = rear = NULL;
}

void enq(int info){
    struct node *newNode;
    newNode = malloc(sizeof(*newNode));
    newNode->info = info; newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear = newNode;
    
}

char deq() {
    
    if(front == NULL) { return ' '; }

    struct node *temp = front;

    front = temp->next;

    int nodeInfo = temp->info;

    if(front == NULL) { rear = NULL; }

    return (char) nodeInfo;

    // free(temp);

}



int isEmpty(void) { 
	if (front == NULL || rear == NULL) { return 1; }
    else { 	return 0; }
}


void main() {
 
    createQ();
    enq(1);
    enq(2);
    enq(2);
    enq(2);
    enq(2);


    printf("deq: %c", deq());
     printf("deq: %c", deq());
      printf("deq: %c", deq());



    printf("\n");

}
