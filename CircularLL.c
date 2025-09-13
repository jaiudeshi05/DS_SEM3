#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


/*Only Change Code For Normal Linked Lists As Mentioned*/


struct node{
    int data;
    struct node* next;
};
struct node *start=NULL;

void insertionAtEnd(int n){
    struct node *newnode; 
    newnode=(struct node*)malloc(sizeof(struct node)); 
    newnode->data=n;
    newnode->next=start; //Change NULL to start
    if(start==NULL) {
        start=newnode;
        newnode->next=newnode;
        return;
    } //Boundary Condition(Not Compulsory To Be Written)
    struct node *temp; 
    temp=start;
    while(temp->next!=start){ //Change NULL to start
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertionAtStart(int n){
    struct node *newnode; 
    newnode=(struct node*)malloc(sizeof(struct node)); 
    newnode->data=n;
    if(start==NULL) {
        start=newnode;
        newnode->next=newnode;
    } //Boundary Condition(Not Compulsory To Be Written)
    else{
        newnode->next=start;
        //Add code from this line
        struct node *temp; 
        temp=start;
        while(temp->next!=start){ 
            temp=temp->next;
        }
        temp->next=newnode;
        //To this line
        start=newnode;
    }
}

void deletionFromStart(){
    if(start->next==start) start=NULL; //Change NULL to start
    //Change entire else block
    else {
        struct node *temp; 
        temp=start;
        while(temp->next!=start){ 
            temp=temp->next;
        }
        temp->next=temp->next->next;
        start=start->next;
    }
}

//Can write any of the two functions for deletion from end
void deletionFromEnd1(){
    struct node *temp=start;
    while(temp->next->next!=start){ //Change NULL to start
        temp=temp->next;
    }
    temp->next=start; //Change NULL to start
}
void deletionFromEnd2(){
    struct node *temp1,*temp2;
    temp1=start;
    temp2=start->next;
    if(temp2==start) start=NULL; //Change NULL to start //Boundary Condition(Not Compulsory To Be Written)
    else{
        while(temp2->next!=start){ //Change NULL to start
            temp1=temp2;
            temp2=temp2->next;
        }
        temp1->next=start; //Change NULL to start
    }
}

void display(){
    struct node *temp = start;
    if(temp == NULL){ //Boundary Condition(Not Compulsory To Be Written)
        printf("List is empty");
        return;
    }
    //Change while to do while loop
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!= start);
}

void main(){
    /*insertionAtEnd(1);
    display();
    printf("\n");
    insertionAtStart(2);
    display();
    printf("\n");
    deletionFromEnd1();
    display();
    printf("\n");
    insertionAtEnd(3);
    display();
    printf("\n");
    deletionFromStart();
    display();
    printf("\n");
    deletionFromEnd2();
    display();
    printf("\n");*/
}