#include <iostream>
#include <algorithm>

using namespace std;

//Declaration
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* start=nullptr;

//Traversal
void Preorder(Node* temp){
    if(temp==nullptr) return;
    else{
        cout<<temp->data<<" ";
        Preorder(temp->left);
        Preorder(temp->right);
    }
}

void Inorder(Node* temp){
    if(temp==nullptr) return;
    else{
        Inorder(temp->left);
        cout<<temp->data<<" ";
        Inorder(temp->right);
    }
}

void Postorder(Node* temp){
    if(temp==nullptr) return;
    else{
        Postorder(temp->left);
        Postorder(temp->right);
        cout<<temp->data<<" ";
    }
}

//Miscellaneous
Node* copyTree(Node* temp){
    if(temp==nullptr) return nullptr;
    Node* newNode=new Node(temp->data);
    newNode->left=copyTree(temp->left);
    newNode->right=copyTree(temp->right);
    return newNode;
}

int height(Node* temp){
    if(temp==nullptr) return 0;
    return max(height(temp->left),height(temp->right))+1;
}

Node* mirrorTree(Node* temp){
    if(temp==nullptr) return nullptr;
    Node* newNode=new Node(temp->data);
    newNode->left=mirrorTree(temp->right);
    newNode->right=mirrorTree(temp->left);
    return newNode;
}

int count(Node* temp){
    if(temp==nullptr) return 0;
    return count(temp->left)+count(temp->right)+1;
}

int countLeaf(Node* temp){
    if(temp==nullptr) return 0;
    if(temp->left==nullptr && temp->right==nullptr) return 1;
    return countLeaf(temp->left)+countLeaf(temp->right);
}

int main(){
    start=new Node(1);
    start->left=new Node(2);
    start->right=new Node(3);
    start->left->left=new Node(4);
    start->left->right=new Node(5);

    cout<<"Preorder Traversal: ";
    Preorder(start);
    cout<<"\nInorder Traversal: ";
    Inorder(start);
    cout<<"\nPostorder Traversal: ";
    Postorder(start);

    Node* copiedTree=copyTree(start);
    cout<<"\nHeight of Tree: "<<height(start);
    Node* mirroredTree=mirrorTree(start);
    cout<<"\nTotal Nodes: "<<count(start);
    cout<<"\nLeaf Nodes: "<<countLeaf(start);

    return 0;
}