#include<iostream>
#include<vector>
using namespace std;
void storeFibo(vector<int> &arr,int n){
    if(n<=0) return;
    if(arr.size()==0) arr.push_back(0);
    if(n==1) return;
    if(arr.size()==1) arr.push_back(1);
    if(arr.size()<n){
        storeFibo(arr,n-1); // Ensure previous values are filled
        arr.push_back(arr[arr.size()-2]+arr[arr.size()-1]); // Add next fibonacci number
    }
}


int main(){
    vector<int> arr;
    storeFibo(arr,5);
    for(int i: arr)
        cout<<i<<" ";
}