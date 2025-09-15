#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *insertEnd(int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

struct node* reverseList(struct node *start) {
    struct node *stack[100];
    int top = -1;
    struct node *temp = start;
    // push all nodes into stack
    while (temp != NULL) {
        stack[++top] = temp;
        temp = temp->next;
    }
    // make the last node as new head of the linked list
    if (top >= 0) {
        start = stack[top];
        temp = start;
        // pop all the nodes and append to the linked list
        while (top > 0) {
            // append the top value of stack in list
            temp->next = stack[--top];

            temp = temp->next;
        }
        // update the next pointer of last node of stack to null
        temp->next = NULL;
    }
    return start;
}

void display(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct node *start = insertEnd(1);
    start->next = insertEnd(2);
    start->next->next = insertEnd(3);
    start->next->next->next = insertEnd(4);
    start->next->next->next->next = insertEnd(5);
    display(start);
    start = reverseList(start);
    display(start);

    return 0;
}