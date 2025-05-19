#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {3,7,8,1,17,18,9,2};
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>first){
            third = second;
            second = first;
            first = arr[i];
        }
        else if(arr[i]>second){
            third = second;
            second = arr[i];
        }
        else if(arr[i]>third)
            third = arr[i];
    }
    cout<<"First Largest: "<<first<<endl;
    cout<<"Second Largest: "<<second<<endl;
    cout<<"Third Largest: "<<third<<endl;
}