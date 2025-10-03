#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr,int low,int high){
    int p = low;
    int i = low+1;
    int j = high;

    while(i<=j){
        while(i <= high && arr[i] <= arr[p]) i++;
        while(j >= low && arr[j] > arr[p]) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

int findKthLargest(vector<int>arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    
    while(low<=high){
        int mid = partition(arr,low,high);
        if(mid == n-k) return arr[mid];
        else if(mid<n-k) low = mid+1;
        else high = mid-1;
    }
    return -1;
}
int main(){
    vector<int> arr = {9,1,3,8,2,4,7,6,5,10};
    int k = 3;
    int kthLargest = findKthLargest(arr,k);
    cout<<kthLargest;
}