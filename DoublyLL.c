#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


/*Only Change Code For Normal Linked Lists As Mentioned*/


struct node{
    int data;
    struct node* next;
    struct node* prev;
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
    newnode->prev=temp; //Add Line
}

void insertionAtStart(int n){
    struct node *newnode; 
    newnode=(struct node*)malloc(sizeof(struct node)); 
    newnode->data=n;
    if(start==NULL) start=newnode; //Boundary Condition(Not Compulsory To Be Written)
    else{
        start->prev=newnode; //Add Line
        newnode->next=start;
        start=newnode;
        newnode->prev=NULL; //Add Line
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
    newnode->prev=temp; //Add Line
    temp->next->prev=newnode; //Add Line
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
    newnode->prev=temp; //Add Line
    temp->next->prev=newnode; //Add Line
    temp->next=newnode;
}

void deletionFromStart(){
    if(start->next==NULL) start=NULL;
    else {
        start=start->next;
        start->prev=NULL; //Add Line
    }
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
    temp->next->prev=temp; //Add Line
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
    temp->next->prev=temp; //Add Line
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