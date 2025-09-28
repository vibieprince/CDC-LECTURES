#include<iostream>
using namespace std;

void mergeWithin(int arr[],int L,int M,int H){
    int i = L;
    int j = M+1;

    while(i<=M && j<=H){
        if(arr[i]<arr[j]) i++;
        else{
            swap(arr[i],arr[j]);
            int key = arr[j];
            int k = j+1;
            while(k<=H && arr[k]<key){
                arr[k-1] = arr[k];
                k++;
            }
            arr[k-1]=key;
            i++;
        }
    }
}

int main(){
    int arr[] = {0,0,0,0,0,0,0,0,0,1,5,8,10,2,3,6,9,12,15,0,0,0,0,0,0,0,0};
    mergeWithin(arr,9,12,18);
    for(int i : arr) cout<<i<<" ";
}