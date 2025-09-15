#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minSwaps(vector<int> &arr){
    int n = arr.size();
    vector<int> prefix(n);
    int k = 0;
    int zero = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) zero++;
        else k++;
        prefix[i] = zero;
    }
    int i=0,j=k;
    int minSwap = INT_MAX;
    while(j<n){
        minSwap = min(prefix[j]-prefix[i],minSwap);
        i++;
        j++;
    }
    return minSwap;
}
int main(){
    vector<int> arr = {0,0,1,0,0,1,0,0,1,0};
    cout<<minSwaps(arr);
}