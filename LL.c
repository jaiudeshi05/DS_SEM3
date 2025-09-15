#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *start=NULL;

void insertionAtEnd(int n){
    struct node *newnode; 
    newnode=(struct node*)malloc(sizeof(struct node)); 
    newnode->data=n;
    newnode->next=NULL;
    if(start==NULL) {start=newnode;return;} //Boundary Condition(Not Compulsory To Be Written)
    struct node *temp; 
    temp=start;
    while(temp->next!=NULL){ 
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertionAtStart(int n){
    struct node *newnode; 
    newnode=(struct node*)malloc(sizeof(struct node)); 
    newnode->data=n;
    if(start==NULL) start=newnode; //Boundary Condition(Not Compulsory To Be Written)
    else{
        newnode->next=start;
        start=newnode;
    }
}

void insertionAfterElementX(int n,int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node)); 
    newnode->data=n;
    struct node *temp=start;
    while(temp->data!=x&&temp->next!=NULL){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void insertionBeforeElementX(int n,int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node)); 
    newnode->data=n;
    struct node *temp=start;
    while(temp->next->data!=x&&temp->next!=NULL){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void insertionAfterPositionX(int n,int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node)); 
    newnode->data=n;
    struct node *temp=start;
    for(int i=1;i<x;i++){
        if(temp->next==NULL){
            insertionAtEnd(n);
            return;
        }
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void deletionFromStart(){
    if(start->next==NULL) start=NULL;
    else start=start->next;
}

//Can write any of the two functions for deletion from end
void deletionFromEnd1(){
    struct node *temp=start;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
}
void deletionFromEnd2(){
    struct node *temp1,*temp2;
    temp1=start;
    temp2=start->next;
    if(temp2==NULL) start=NULL; //Boundary Condition(Not Compulsory To Be Written)
    else{
        while(temp2->next!=NULL){
            temp1=temp2;
            temp2=temp2->next;
        }
        temp1->next=NULL;
    }
}

void deletionAfterElementX(int x){
    struct node *temp=start;
    while(temp->data!=x&&temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

void deletionAfterPositionX(int x){
    struct node *temp=start;
    for(int i=1;i<x;i++){
        if(temp->next==NULL){
            deletionFromEnd1();
            return;
        }
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

void deletionOfElementX(int x){
    struct node *temp=start;
    while(temp->next->data!=x&&temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

void display(){
    struct node *temp = start;
    if(temp == NULL){ //Boundary Condition(Not Compulsory To Be Written)
        printf("List is empty");
        return;
    }
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int len(){
    int length=0;
    struct node *temp = start;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void average(){
    int length=len();
    int sum=0;
    struct node *temp = start;
    while(temp != NULL){
        sum+=temp->data;
        temp = temp->next;
    }
    printf("Average of linked list: %f",sum/length);
}

void main(){
    /*insertionAtEnd(1);
    display();
    printf("\n");
    insertionAtStart(2);
    display();
    printf("\n");
    insertionAfterPositionX(3,1);
    display();
    printf("\n");
    insertionAfterElementX(3,3);
    display();
    printf("\n");
    deletionAfterElementX(2);
    display();
    printf("\n");
    deletionFromEnd1();
    display();
    printf("\n");
    deletionFromStart();
    display();
    printf("\n");
    deletionFromEnd2();
    display();
    printf("\n");*/
}