#include<iostream>
using namespace std;

void preorderTraversalOfHeap(char arr[],int n,int r){
    if(r>=n) return;
    cout<<arr[r]<<" ";
    preorderTraversalOfHeap(arr,n,2*r+1);
    preorderTraversalOfHeap(arr,n,2*r+2);
}
int main(){
    char arr[] = {'A','B','C','D','E','F','G','H'};
    preorderTraversalOfHeap(arr,8,0);
}