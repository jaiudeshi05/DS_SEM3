#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Helpers
//Swap Elements
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
//Print Array
void printArray(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

//Bubble Sort- O(n^2)
void BubbleSort(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
        //Extra------------------------------------------------
        cout<<"Iteration "<<i+1<<": ";
        printArray(v);
        //Extra------------------------------------------------
    }
}

//Selection Sort- O(n^2)
void SelectionSort(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[minIndex]){
                minIndex=j;
            }
        }
        swap(v[i],v[minIndex]);
        //Extra------------------------------------------------
        cout<<"Iteration "<<i+1<<": ";
        printArray(v);
        //Extra------------------------------------------------
    }
}

//Insertion Sort- O(n^2)
void InsertionSort(vector<int> &v){
    int n=v.size();
    for(int i=1;i<n;i++){
        int key=v[i];
        int j=i-1;
        while(j>=0 && v[j]>key){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
        //Extra------------------------------------------------
        cout<<"Iteration "<<i<<": ";
        printArray(v);
        //Extra------------------------------------------------
    }
}

//Merge Sort- O(nlog n)
void merge(vector<int> &v, int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i=0;i<n1;i++) L[i]=v[left+i];
    for(int j=0;j<n2;j++) R[j]=v[mid+1+j];
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) {v[k]=L[i];i++;} 
        else {v[k]=R[j];j++;}
        k++;
    }
    //Extra------------------------------------------------
    cout<<"Left: ";
    printArray(L);
    cout<<"Right: ";
    printArray(R);
    cout<<endl;
    //Extra------------------------------------------------
    while(i<n1){
        v[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        v[k]=R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int> &v, int left, int right){
    if(left<right){
        int mid=left+(right-left)/2;
        MergeSort(v,left,mid);
        MergeSort(v,mid+1,right);
        merge(v,left,mid,right);
    }
}

//Quick Sort- O(nlog n)
int partition(vector<int> &v, int low, int high){
    int pivot=v[high];//Taking last element as pivot
    int i=low-1;
    for(int j=low;j<high;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[high]);
    //Extra------------------------------------------------
    cout<<"New Array: ";
    printArray(v);
    //Extra------------------------------------------------
    return i+1;
}
void QuickSort(vector<int> &v, int low, int high){
    if(low<high){
        int pi=partition(v,low,high);
        QuickSort(v,low,pi-1);
        QuickSort(v,pi+1,high);
    }
}

//Radix Sort- O(nk)
int getMax(vector<int> &v){
    int max=v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]>max) max=v[i];
    }
    return max;
}
void RadixSort(vector<int> &v, int exp){
    int n=v.size();
    vector<int> output(n);
    vector<int> count(10,0);
    for(int i=0;i<n;i++) count[(v[i]/exp)%10]++;
    for(int i=1;i<10;i++) count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--){
        output[count[(v[i]/exp)%10]-1]=v[i];
        count[(v[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++) v[i]=output[i];
}
void RadixSort(vector<int> &v){
    int mx=getMax(v);
    for(int exp=1; mx/exp>0; exp*=10){
        RadixSort(v,exp);
        //Extra------------------------------------------------
        cout<<"Iteration "<<(int)log10(exp)+1<<": ";
        printArray(v);
        //Extra------------------------------------------------
    }
}

int main(){
    vector<int> v={170,45,75,90,802,24,2,66};
    cout<<"\nBubble Sort:\n";
    cout<<"Original Array: ";
    printArray(v);
    BubbleSort(v);
    cout<<"Sorted Array: ";
    printArray(v);

    v={170,45,75,90,802,24,2,66};
    cout<<"\nSelection Sort:\n";
    cout<<"Original Array: ";
    printArray(v);
    SelectionSort(v);
    cout<<"Sorted Array: ";
    printArray(v);

    v={170,45,75,90,802,24,2,66};
    cout<<"\nInsertion Sort:\n";
    cout<<"Original Array: ";
    printArray(v);
    InsertionSort(v);
    cout<<"Sorted Array: ";
    printArray(v);

    v={170,45,75,90,802,24,2,66};
    cout<<"\nMerge Sort:\n";
    cout<<"Original Array: ";
    printArray(v);
    MergeSort(v,0,v.size()-1);
    cout<<"Sorted Array: ";
    printArray(v);

    v={170,45,75,90,802,24,2,66};
    cout<<"\nQuick Sort:\n";
    cout<<"Original Array: ";
    printArray(v);
    QuickSort(v,0,v.size()-1);
    cout<<"Sorted Array: ";
    printArray(v);

    v={170,45,75,90,802,24,2,66};
    cout<<"\nRadix Sort:\n";
    cout<<"Original Array: ";
    printArray(v);
    RadixSort(v);
    cout<<"Sorted Array: ";
    printArray(v);

    return 0;
}