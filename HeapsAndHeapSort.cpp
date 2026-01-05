#include <iostream>
#include <vector>

using namespace std;

vector<int> heap;

void insert(int data){
    heap.push_back(data);
    int index=heap.size()-1;
    while(index>0){
        int parentIndex=(index-1)/2;
        if(heap[parentIndex]<heap[index]){
            swap(heap[parentIndex],heap[index]);
            index=parentIndex;
        }
        else break;
    }
}

void deleteFromHeap(int data){
    int n=heap.size();
    int index=-1;
    for(int i=0;i<n;i++){
        if(heap[i]==data){
            index=i;
            break;
        }
    }
    if(index==-1) {
        cout<<data<<" not found in heap\n";
        return;
    }
    swap(heap[index],heap[n-1]);
    heap.pop_back();
    n--;
    int parentIndex=index;
    while(true){
        int leftChild=2*parentIndex+1;
        int rightChild=2*parentIndex+2;
        int largest=parentIndex;
        if(leftChild<n && heap[leftChild]>heap[largest]) largest=leftChild;
        if(rightChild<n && heap[rightChild]>heap[largest]) largest=rightChild;
        if(largest!=parentIndex){
            swap(heap[parentIndex],heap[largest]);
            parentIndex=largest;
        }
        else break;
    }
}

void printHeap(){
    for(int val : heap){
        cout<<val<<" ";
    }
    cout<<"\n";
}

void heapify(int * arr){
    int n=6;
    for(int i=n/2-1;i>=0;i--){
        int parentIndex=i;
        while(true){
            int leftChild=2*parentIndex+1;
            int rightChild=2*parentIndex+2;
            int largest=parentIndex;
            if(leftChild<n && heap[leftChild]>heap[largest]) largest=leftChild;
            if(rightChild<n && heap[rightChild]>heap[largest]) largest=rightChild;
            if(largest!=parentIndex){
                swap(heap[parentIndex],heap[largest]);
                parentIndex=largest;
            }
            else break;
        }
    }
}

int main(){
    insert(10);
    insert(20);
    insert(5);
    insert(30);
    insert(15);
    cout<<"Heap after insertions: ";
    printHeap();
    int arr[] = {1,2,3,4,5,6};
    heapify(arr);
    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<"\n";
    
    deleteFromHeap(20);
    cout<<"Heap after deleting 20: ";
    printHeap();

    heapify();
    cout<<"Heap after heapify: ";
    printHeap();

    return 0;
}