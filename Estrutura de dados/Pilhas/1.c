#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node { 
    int value; 
    struct Node* prox;
} Node;

Node* top = NULL;



Node* createNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;

    return node;
}

void push(int value) {
    Node* node = createNode(value);

    if(top == NULL) {
        node->prox = NULL; 
        top = &node;
    } else { 
        node->prox = top;
    }

    top = node;
}

void showStack() { 
    Node* current = top; 

    do{ 
        printf("%d\n", current->value);
        current = current->prox;
    } while (current->prox != NULL);
}

int pop () {
    Node* temp = top; 

    int topValue = temp->value; 
    top = top->prox;
    free(temp);
}

int main () { 

    push(1);
    push(2);
    push(3);
    showStack();


    return 0;
}