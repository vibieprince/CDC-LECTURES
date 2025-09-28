#include<iostream>
#include<vector>
using namespace std;

void mergeTwoArray(vector<int> &arr1,vector<int> &arr2){
    int i = arr1.size()-1;
    int j = arr2.size()-arr1.size()-1;
    int k = arr2.size()-1;

    while(i>=0 && j>=0){
        if(arr1[i]>arr2[j])
            arr2[k] = arr1[i--];
        else arr2[k] = arr2[j--];
        k--;
    }

    while(i>=0) arr2[k--] = arr1[i--];
}

int main(){
    vector<int> arr1 = {1,5,8,10};
    vector<int> arr2 = {2,4,6,12,15,0,0,0,0};

    mergeTwoArray(arr1,arr2);

    for(int i : arr2) cout<<i<<" ";
}