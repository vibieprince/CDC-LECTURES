#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        bool isSorted = true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSorted = false;
            }
        }
        if(isSorted) return;
    }
}

int main(){
    vector<int> arr = {5,3,8,1,7,4,10};
    bubbleSort(arr);
    for(int &i : arr) cout<<i<<" ";
    return 0;
}