#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Only for Array
int stack[100];
int top=-1;

//Only for Linked List
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;

void push(int n){
    //Array Implementation
    if(top==99) printf("Stack Overflow!");
    else{
        top++;
        stack[top]=n;
    }
    //Linked List Implementation
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=start;
    start=newnode;
}

void pop(){
    //Array Implementation
    top--;
    //Linked List Implementation
    start=start->next;
}

void peek(){
    //Array Implementation
    printf("%d\n",stack[top]);
    //Linked List Implementation
    printf("%d\n",start->data);
}

void displayStack(){
    //Array Implementation
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
    //Linked List Implementation
    struct node *temp;
    temp=start;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main(){
    /*push(1);
    displayStack();
    printf("\n");
    push(2);
    displayStack();
    printf("\n");
    peek();
    displayStack();
    printf("\n");
    pop();
    displayStack();
    printf("\n");*/
}