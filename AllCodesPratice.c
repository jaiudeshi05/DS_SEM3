#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

/*--------------------------STACKS----------------------------*/
//Declaration
int stack[100];
int top=-1;
//Push
void push(int n){
    top++;
    if(top==100) printf("Stack Full");
    else stack[top]=n;
}
//Pop
void pop(){
    if(top==-1) printf("Stack Empty");
    else top--;
}
//Peek
int peek(){
    if(top==-1) printf("Stack Empty");
    else return stack[top];
    return -1;
}
//Display
void displayStack(){
    for(int i=0;i<top;i++){
        printf("%d ",stack[i]);
    }
}
/*--------------------------QUEUES----------------------------*/
//Declaration
int queue[100], front=-1,rear=-1;
//--------------------------Linear Queue
//Enqueue
void enqueue(int n){
    if(rear=99) printf("Queue Full");
    else{
        if(front==-1) front++;
        rear++;
        queue[rear]=n;
    }
}
//Dequeue
void dequeue(){
    if(front==-1) printf("Queue Empty");
    else{
        if(front==rear) {
            front=-1;
            rear=-1;
        }
        else front++;
    }
}
//Display
void displayLinQueue(){
    for(int i=front;i<=rear;i++){
        printf("%d",queue[i]);
    }
}

//--------------------------Circular Queue
//Enqueue
void circenqueue(int n){
    if(rear+1==front) printf("Queue Full");
    else{
        if(front==-1) front++;
        rear=(rear+1)%100;
        queue[rear]=n;
    }
}
//Dequeue
void circdequeue(){
    if(front==-1) printf("Queue Empty");
    else{
        if(front==rear) {
            front=-1;
            rear=-1;
        }
        else front=(front+1)%100;
    }
}
//Display
void displayCircQueue(){
    int i=front;
    while(i!=(rear+1)%100){
        printf("%d",queue[i]);
        i++;
        i=i%100;
    }
}
//--------------------------Doubly Ended Queue
//Insert Front
void insertFrontDeque(int n){
    if(front==(rear-1)%100) printf("Queue Full");
    else{
        front++;
        front=front%100;
        queue[front]=n;
    } 
}
//Insert Rear
void insertRearDeque(int n){
    if(rear==(front+1)%100) printf("Queue Full");
    else{
        if(rear==-1) rear=100;
        rear--;
        queue[rear]=n;
    }
}
//Delete Front
void deleteFrontDeque(){
    if(front==-1) printf("Queue Empty");
    else{
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front--;
            front=front%100;
        }
    }
}
//Delete Rear
void deleteRearDeque(){
    if(rear==-1) printf("Queue Empty");
    else{
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            rear++;
            rear=rear%100;
        }
    }
}
//Display
void displayDeque(){
    int i=front;
    while(i!=rear){
        printf("%d",queue[i]);
        i--;
        if(i==-1) i=99;
    }
}

/*-----------------------LINKED LISTS-------------------------*/
//Declaration of Node
struct LLnode{
    int data;
    struct LLnode* next;
};
struct LLnode* start=NULL;
//Insertion Before node
void insertBefore(int n,int tgt){
    struct LLnode *temp1,*temp2,*newNode;
    temp1=start;
    temp2=start->next;
    newNode=(struct LLnode*) malloc(sizeof(struct LLnode));
    newNode->data=n;
    if(start==NULL) start=newNode;
    else{
        while(temp2!=NULL&&temp2->data!=tgt){
            temp1=temp2;
            temp2=temp2->next;
        }
        if(temp2==NULL) printf("Target Element Not Found");
        else{
            newNode->next=temp2;
            temp1->next=newNode;
        }
    }
}
//Insertion After node
void insertAfter(int n,int tgt){
    struct LLnode *temp,*newNode;
    temp=start;
    newNode=(struct LLnode*) malloc(sizeof(struct LLnode));
    newNode->data=n;
    if(start==NULL) start=newNode;
    else{
        while(temp!=NULL&&temp->data!=tgt){
            temp=temp->next;
        }
        if(temp==NULL) printf("Target Element Not Found");
        else{
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
}
//Insertion At Beginning
void insertBeg(int n){
    struct LLnode* newNode=(struct LLnode*)malloc(sizeof(struct LLnode));
    newNode->data=n;
    newNode->next=start;
    start=newNode;
}
//Insertion At End
void insertEnd(int n){
    struct LLnode *temp,*newNode;
    newNode=(struct LLnode*) malloc(sizeof(struct LLnode));
    newNode->data=n;
    newNode->next=NULL;
    if(start==NULL) start=newNode;
    else{
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
//Deletion of node
void deleteTgt(int tgt){
    struct LLnode *temp1,*temp2;
    temp1=start;
    temp2=start->next;
    if(start==NULL) printf("List Empty");
    else if(start->data==tgt){
        start=start->next;
    }
    else{
        while(temp2!=NULL&&temp2->data!=tgt){
            temp1=temp2;
            temp2=temp2->next;
        }
        if(temp2==NULL) printf("Target Element Not Found");
        else{
            temp1->next=temp2->next;
            free(temp2);
        }
    }
}
//Deletion At Beginning
void deleteBeg(){
    if(start==NULL) printf("List Empty");
    else start=start->next;
}
//Deletion At End
void deleteEnd(){
    struct LLnode *temp;
    temp=start;
    if(start==NULL) printf("List Empty");
    else if(start->next==NULL) start=NULL;
    else{
        while(temp->next->next!=NULL) temp=temp->next;
    }
    temp->next=NULL;
}
//Display
void displayLL(){
    struct LLnode* temp;
    temp=start;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
//Copy LL
struct LLnode* copyLL(struct LLnode* temp){
    struct LLnode *newNode;
    newNode->data=temp->data;
    if(temp->next!=NULL) newNode->next=copyLL(temp->next);
    else newNode->next=NULL;
}
//Reverse LL
void reverseLL(){
    struct LLnode *temp1,*temp2,*temp3;
    temp1=start;
    temp2=start->next;
    temp3=temp2->next;
    temp1->next=NULL;
    if(temp3==NULL){
        temp2->next=temp1;
        start=temp2;
        return;
    }
    while(temp3!=NULL){
        temp2->next=temp1;
        temp1=temp2;
        temp2=temp3;
        temp3=temp3->next;
    }
    start=temp2;
}
//Count Nodes
int countLL(){
    struct LLnode* temp;
    int count=0;
    temp=start;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
/*------------------------Doubly Linked Lists-------------------------*/
//Declaration of Node
struct DLnode{
    int data;
    struct DLnode* next;
    struct DLnode* prev;
};
struct DLnode* dstart=NULL;
//Insertion Before node
void insertBeforeDLL(int n,int tgt){
    struct DLnode *temp,*newNode;
    temp=dstart;
    newNode=(struct DLnode*) malloc(sizeof(struct DLnode));
    newNode->data=n;
    if(dstart==NULL) dstart=newNode;
    else{
        while(temp!=NULL&&temp->data!=tgt){
            temp=temp->next;
        }
        if(temp==NULL) printf("Target Element Not Found");
        else{
            newNode->next=temp;
            newNode->prev=temp->prev;
            if(temp->prev!=NULL) temp->prev->next=newNode;
            temp->prev=newNode;
            if(temp==dstart) dstart=newNode;
        }
    }
}
//Insertion After node
void insertAfterDLL(int n,int tgt){
    struct DLnode *temp,*newNode;
    temp=dstart;
    newNode=(struct DLnode*) malloc(sizeof(struct DLnode));
    newNode->data=n;
    if(dstart==NULL) dstart=newNode;
    else{
        while(temp!=NULL&&temp->data!=tgt){
            temp=temp->next;
        }
        if(temp==NULL) printf("Target Element Not Found");
        else{
            newNode->prev=temp;
            newNode->next=temp->next;
            if(temp->next!=NULL) temp->next->prev=newNode;
            temp->next=newNode;
        }
    }
}
//Insertion At Beginning
void insertBegDLL(int n){
    struct DLnode* newNode=(struct DLnode*)malloc(sizeof(struct DLnode));
    newNode->data=n;
    newNode->next=dstart;
    newNode->prev=NULL;
    if(dstart!=NULL) dstart->prev=newNode;
    dstart=newNode;
}
//Insertion At End
void insertEndDLL(int n){
    struct DLnode *temp,*newNode;
    newNode=(struct DLnode*) malloc(sizeof(struct DLnode));
    newNode->data=n;
    newNode->next=NULL;
    if(dstart==NULL) {
        newNode->prev=NULL;
        dstart=newNode;
    }
    else{
        temp=dstart;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}
//Deletion of node
void deleteTgtDLL(int tgt){
    struct DLnode *temp;
    temp=dstart;
    if(dstart==NULL) printf("List Empty");
    else if(dstart->data==tgt){
        dstart=dstart->next;
        if(dstart!=NULL) dstart->prev=NULL;
    }
    else{
        while(temp!=NULL&&temp->data!=tgt){
            temp=temp->next;
        }
        if(temp==NULL) printf("Target Element Not Found");
        else{
            if(temp->next!=NULL) temp->next->prev=temp->prev;
            if(temp->prev!=NULL) temp->prev->next=temp->next;
            free(temp);
        }
    }
}
//Deletion At Beginning
void deleteBegDLL(){
    if(dstart==NULL) printf("List Empty");
    else{
        dstart=dstart->next;
        if(dstart!=NULL) dstart->prev=NULL;
    }
}
//Deletion At End
void deleteEndDLL(){
    struct DLnode *temp;
    temp=dstart;
    if(dstart==NULL) printf("List Empty");
    else if(dstart->next==NULL) dstart=NULL;
    else{
        while(temp->next!=NULL) temp=temp->next;
        temp->prev->next=NULL;
    }
}
//Display
void displayDLL(){
    struct DLnode* temp;
    temp=dstart;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

/*------------------------BINARY TREE-------------------------*/
//Declaration of Node
struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* root=NULL;
//Traversal
void preorder(struct TreeNode* temp){
    printf("%d",temp->data);
    if(temp->left!=NULL) preorder(temp->left);
    if(temp->right!=NULL) preorder(temp->right);
}
void inorder(struct TreeNode* temp){
    if(temp->left!=NULL) inorder(temp->left);
    printf("%d",temp->data);
    if(temp->right!=NULL) inorder(temp->right);
}
void postorder(struct TreeNode* temp){
    if(temp->left!=NULL) postorder(temp->left);
    if(temp->right!=NULL) postorder(temp->right);
    printf("%d",temp->data);
}
//Copy Tree
struct TreeNode* copyTree(struct TreeNode* temp){
    struct TreeNode* newNode;
    newNode=(struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->data=temp->data;
    if(temp->left!=NULL) newNode->left=copyTree(temp->left);
    else newNode->left=NULL;
    if(temp->right!=NULL) newNode->right=copyTree(temp->right);
    else newNode->right=NULL;
    return newNode;
}
//Height of Tree
int heightOfTree(struct TreeNode* temp){
    if(temp==NULL) return 0;
    return max(heightOfTree(temp->left),heightOfTree(temp->right))+1;
}
//Mirror Tree
struct TreeNode* MirrorTree(struct TreeNode* temp){
    struct TreeNode* newNode;
    if(temp==NULL) return NULL;
    newNode=(struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->left=MirrorTree(temp->right);
    newNode->right=MirrorTree(temp->left);
}
//Count Nodes
int countTreeNodes(struct TreeNode* temp){
    if(temp==NULL) return 0;
    return countTreeNodes(temp->left)+countTreeNodes(temp->right)+1;
}
/*------------------------GRAPH-------------------------*/
int graph[100][100];
//BFS
int bfsqueue[100];
void enq(int n){
    if(rear=99) printf("Queue Full");
    else{
        if(front==-1) front++;
        rear++;
        bfsqueue[rear]=n;
    }
}
void deq(){
    if(front==-1) printf("Queue Empty");
    else{
        if(front==rear) {
            front=-1;
            rear=-1;
        }
        else front++;
    }
}
void bfs(int start,int size){
    bool visited[100]={false};
    enq(start);
    visited[start]=true;
    while(front<=rear){
        int curr=bfsqueue[front];
        deq();
        printf("%d ",curr);
        for(int i=0;i<size;i++){
            if(graph[curr][i]==1&&visited[i]==false){
                enq(i);
                visited[i]=true;
            }
        }
    }
}
//DFS
int dfsstack[100];
void bfspush(int n){
    top++;
    if(top==100) printf("Stack Full");
    else dfsstack[top]=n;
}
int bfspeek(){
    if(top==-1) printf("Stack Empty");
    else return dfsstack[top];
    return -1;
}
void dfs(int start,int size){
    bool visited[100]={false};
    dfspush(start);
    visited[start]=true;
    while(top>=0){
        int curr=dfspeek();
        pop();
        printf("%d",curr);
        for(int i=0;i<size;i++){
            if(graph[curr][i]==1&&visited[i]==false){
                dfspush(i);
                visited[i]=true;
            }
        }
    }
}

/*------------------------SORTING-------------------------*/
//Bubble Sort
void bubble(int arr[]){
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
//Selection Sort
void selection(int arr[]){
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}
//Insertion Sort
void insertion(int arr[]){
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
//Merge Sort
void merge(int arr[], int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int L[100], R[100];
    for(int i=0;i<n1;i++) L[i]=arr[left+i];
    for(int j=0;j<n2;j++) R[j]=arr[mid+1+j];
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
//Quick Sort
int partition(int arr[], int low, int high){
    int pivot=arr[high];//Taking last element as pivot
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
//Radix Sort
void radix(int arr[]){
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max) max=arr[i];
    }
    for(int exp=1; max/exp>0; exp*=10){
        int output[100];
        int count[10]={0};
        for(int i=0;i<n;i++) count[(arr[i]/exp)%10]++;
        for(int i=1;i<10;i++) count[i]+=count[i-1];
        for(int i=n-1;i>=0;i--){
            output[count[(arr[i]/exp)%10]-1]=arr[i];
            count[(arr[i]/exp)%10]--;
        }
        for(int i=0;i<n;i++) arr[i]=output[i];
    }
}

/*------------------------MISC-------------------------*/
//Balanced Parenthesis
bool ParenthesisCheck(char s[]){
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            push(s[i]);
        }
        else if(s[i]==')'||s[i]=='}'||s[i]==']'){
            if(s[i]=='}'&&peek()=='{') pop();
            else if(s[i]==']'&&peek()=='[') pop();
            else if(s[i]==')'&&peek()=='(') pop();
            else return false;
        }
    }
    if(isEmpty()) return true;
    else return false;
}

//Infix To Postfix
char infix[100], postfix[100], stack[100];
int size=0;
void infixToPostfix() {
    int len = strlen(infix);
    for(int i = 0; i < len; i++) {
        char ch = infix[i];
        if(isspace(ch)) continue;
        if(isalnum(ch)) postfix[size++] = ch;
        else if(ch == '(') push(ch);
        else if(ch == ')') {
            while(!isEmpty() && peek() != '(') {
                postfix[size++] = peek();
                pop();
            }
            if(!isEmpty()) pop(); // Remove '('
        }
        else {
            while(!isEmpty() && peek() != '(' && 
                  priority(peek()) >= priority(ch)) {
                postfix[size++] = peek();
                pop();
            }
            push(ch);
        }
    }
    while(!isEmpty()) {postfix[size++] = peek();pop();}
    postfix[size] = '\0';
}

//Reverse LL Using Stacks
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

int main(){
    return 0;
}