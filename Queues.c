#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

//Only for Array
int queue[100];
int front=-1,back=-1;

//Only for Linked List
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;

void isEmpty(){
    //Array Implementation
    if(front==-1&&back==-1) printf("Queue is Empty");
    else printf("Queue is not Empty");
    //Linked List Implementation
    if(start==NULL) printf("Queue is Empty");
    else printf("Queue is not Empty");
}

void enqueue(int n){
    //Array Implementation
    if(back==99) printf("Insufficient Space");
    else{
        if(front==-1) front++;
        back++;
        queue[back]=n;
    }
    //Linked List Implementation
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=start;
    start=newnode;
}

void dequeue(){
    //Array Implementation
    if(front==-1) printf("Queue is Empty");
    else if(front==back){
        front=-1;
        back=-1;
    }
    else{
        front++;
    }
    //Linked List Implementation
    struct node *temp;
    temp=start;
    if(start==NULL) printf("Queue is Empty");
    else if(start->next==NULL) start=NULL;
    else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
    }
}

void peek(){
    //Array Implementation
    if(front==-1) printf("Queue is Empty");
    else printf("%d \n",queue[front]);
    //Linked List Implementation
    struct node *temp;
    temp=start;
    if(temp==NULL) printf("Queue is Empty");
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        printf("%d \n",temp->data);
    }
}

void display(){
    //Array Implemetation
    if(front==-1) printf("Queue is Empty");
    else{
        for(int i=front;i<=back;i++){
            printf("%d ",queue[i]);
        }
    }
    printf("\n");
    //Linked List Implementation
    struct node *temp;
    temp=start;
    if(temp==NULL) printf("Queue is Empty");
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void main(){
    /*enqueue(1);
    display();
    printf("\n");
    enqueue(2);
    display();
    printf("\n");
    enqueue(3);
    display();
    printf("\n");
    peek();
    printf("\n");
    display();
    printf("\n");
    dequeue();
    peek();
    printf("\n");
    display();
    printf("\n");
    dequeue();
    peek();
    printf("\n");
    dequeue();
    display();
    printf("\n");*/
}