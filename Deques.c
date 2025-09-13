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

void enqueueBack(int n){
    //Array Implementation
    if(front==-1){
        front=50;
        back=49;
    }
    back++;
    queue[back]=n;
    //Linked List Implementation
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=start;
    start=newnode;
}

void enqueueFront(int n){
    //Array Implementation
    if(front==-1){
        front=51;
        back=50;
    }
    front--;
    queue[front]=n;
    //Linked List Implementation
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    if(start==NULL) start=newnode;
    else{
        struct node *temp;
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void dequeueBack(){
    //Array Implementation
    if(front==-1) printf("Queue is Empty");
    else if(front==back){
        front=-1;
        back=-1;
    }
    else{
        back--;
    }
    //Linked List Implementation
    start=start->next;
}

void dequeueFront(){
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

void peekBack(){
    //Array Implementation
    if(front==-1) printf("Queue is Empty");
    else printf("%d \n",queue[back]);
    //Linked List Implementation
    printf("%d \n",start->data);
}

void peekFront(){
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
    /*enqueueBack(1);
    display();
    printf("\n");
    dequeueFront();
    display();
    printf("\n");
    enqueueFront(1);
    display();
    printf("\n");
    enqueueFront(2);
    peekBack();
    printf("\n");
    peekFront();
    display();
    printf("\n");
    enqueueFront(3);
    dequeueBack();
    display();
    printf("\n");*/
}