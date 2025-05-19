#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {0,1,0,2,1,1,0,2,0,2,1,2,1};
    int j = 0,i=0,k=arr.size()-1;
    while(i <= k){
        if(arr[i]==0)
            swap(arr[i++],arr[j++]);
        else if(arr[i]==2)
            swap(arr[i],arr[k--]);
        else
            i++;
    }
    for(int i : arr)
        cout<<i<<" ";
}