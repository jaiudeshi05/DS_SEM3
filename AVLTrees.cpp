#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        height=1;
    }
};

Node* start=nullptr;

//Utility Functions
int height(Node* temp){
    if(temp==nullptr) return 0;
    return temp->height;
}

int BalanceFactor(Node* temp){
    if(temp==nullptr) return 0;
    return height(temp->left)-height(temp->right);
}

void Preorder(Node* temp=start){
    if(temp==nullptr) return;
    else{
        cout<<temp->data<<" ";
        Preorder(temp->left);
        Preorder(temp->right);
    }
}

Node* RightRotate(Node* temp){
    Node* temp1=temp->left;
    Node* temp2=temp1->right;
    temp1->right=temp;
    temp->left=temp2;
    temp1->height=1+max(height(temp1->left),height(temp1->right));
    temp2->height=1+max(height(temp2->left),height(temp2->right));
    return temp1;
}

Node* LeftRotate(Node* temp){
    Node* temp1=temp->right;
    Node* temp2=temp1->left;
    temp1->left=temp;
    temp->right=temp2;
    temp1->height=1+max(height(temp1->left),height(temp1->right));
    temp2->height=1+max(height(temp2->left),height(temp2->right));
    return temp1;
}

Node* insert(int data){
    Node* newNode=new Node(data);
    if(start==nullptr) {start=newNode;return start;}
    Node* temp=start;
    while(true){
        if(data<temp->data){
            if(temp->left==nullptr){
                temp->left=newNode;
                break;
            }
            else temp=temp->left;
        }
        else{
            if(temp->right==nullptr){
                temp->right=newNode;
                break;
            }
            else temp=temp->right;
        }
    }
    temp->height=1+max(height(temp->left),height(temp->right));
    if(BalanceFactor(temp)>1||BalanceFactor(temp)<-1){
        if(data<temp->right->data){
            temp->right=RightRotate(temp->right);
            return LeftRotate(temp);
        }
        else if(data>temp->left->data){
            temp->left=LeftRotate(temp->left);
            return RightRotate(temp);
        }
        else if(data<temp->left->data){
            return RightRotate(temp);
        }
        else{
            return LeftRotate(temp);
        }
    }
    return temp;
}

int main(){
    start=insert(5);
    start=insert(6);
    start=insert(77);
    start=insert(13);
    start=insert(29);
    start=insert(69);
    start=insert(42);

    Preorder();
}