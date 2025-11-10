#include <iostream>

using namespace std;

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

void insertion(int data){
    Node* newNode=new Node(data);
    if(start==nullptr) {start=newNode;return;}
    Node* temp=start;
    while(true){
        if(data<temp->data){
            if(temp->left==nullptr){
                temp->left=newNode;
                return;
            }
            else temp=temp->left;
        }
        else{
            if(temp->right==nullptr){
                temp->right=newNode;
                return;
            }
            else temp=temp->right;
        }
    }
}

bool search(int data){
    Node* temp=start;
    while(temp!=nullptr){
        if(data==temp->data) return true;
        else if(data<temp->data) temp=temp->left;
        else temp=temp->right;
    }
    return false;
}

void deletion(int data){
    /*To maintain the BST property, we need to find a replacement node for the target. The replacement can be either:
    -The inorder successor — the smallest value in the right subtree, which is the next greater value than the target node.
    -The inorder predecessor — the largest value in the left subtree, which is the next smaller value than the target node.*/
    Node* temp=start;
    Node* parent=nullptr;
    bool found=false;
    while(temp!=nullptr){
        if(data==temp->data) {
            found=true;
            break;
        }
        else if(data<temp->data) {
            parent=temp;
            temp=temp->left;
        }
        else {
            parent=temp;
            temp=temp->right;
        }
    }
    if(!found) {cout<<data+" was not found.\n";return;} //Data Not Found
    if(parent==nullptr) start=nullptr;
    else if(temp->left==nullptr&&temp->right==nullptr){
        if(parent->left->data=data) parent->left=nullptr;
        else parent->right=nullptr;
    }
    else if(temp->left==nullptr||temp->right==nullptr){
        Node* child=(temp->left!=nullptr)?temp->left:temp->right;
        if(parent->left->data==data) parent->left=child;
        else parent->right=child;
    }
    else{
        Node* successorParent=temp;
        //Find inorder successor(check start of function)
        Node* successor=temp->right;
        while(successor->left!=nullptr){
            successorParent=successor;
            successor=successor->left;
        }
        temp->data=successor->data;
        if(successorParent->left==successor) successorParent->left=successor->right;
        else successorParent->right=successor->right;
    }
    cout<<data<<" deleted Successfully.\n";
    return;
}

int main(){
    insertion(50);
    insertion(30);
    insertion(20);
    insertion(40);
    insertion(70);
    insertion(60);
    insertion(80);

    cout<<"Searching 40: "<<(search(40)?"Found":"Not Found")<<endl;
    cout<<"Searching 90: "<<(search(90)?"Found":"Not Found")<<endl;

    deletion(20);
    deletion(30);
    deletion(50);

    cout<<"Searching 50: "<<(search(50)?"Found":"Not Found")<<endl;

    return 0;
}