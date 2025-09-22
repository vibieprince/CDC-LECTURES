#include<iostream>
#include<vector>
using namespace std;

void evenAtLeft(vector<int> &arr){
    int s=0,e=0;
    while(e<arr.size()){
        if(arr[e]%2==0){
            swap(arr[s],arr[e]);
            s++;
        }
        e++;
    }
}
int main(){
    vector<int> arr = {4,2,3,1,8,4,1,7};
    evenAtLeft(arr);
    for(int &i : arr) cout<<i<<" ";
}