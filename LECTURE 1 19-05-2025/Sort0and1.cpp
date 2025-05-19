#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {0,1,0,0,1,0,1,1,1,0,0,1,0,1};
    int j = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == 0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    for(int i : arr)
        cout<<i<<"";
}