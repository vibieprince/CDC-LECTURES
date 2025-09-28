#include<iostream>
#include<algorithm>
using namespace std;

int partition(int arr[],int s,int e){
    int pivot = arr[s];
    int i = s+1;
    int j = e;

    while(true){
        while(i <= e && arr[i] <= pivot) i++;
        while(j >= s && arr[j] > pivot) j--;
        if(i<j) swap(arr[i],arr[j]);
        else break;
    }
    swap(arr[s],arr[j]); // place pivot at its right place
    return j;
}

void quickSort(int arr[],int s,int e){
    // Base Case
    if(s>=e) return;

    // Partition
    int p = partition(arr,s,e);

    // Solve the partition
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

bool binarySearch(int arr[],int low,int high,int target){
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==target) return true;
        else if(arr[mid]>target) high = mid-1;
        else low = mid+1;
    }
    return false;
}

pair<int,int> hasSumK(int *arr,int n,int k){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]==k-arr[i])
               return make_pair(arr[i],arr[j]);
        }
    }
    return {-1,-1};
}

pair<int,int> hasSumK2(int *arr,int n,int k){
    quickSort(arr,0,n-1);
    for(int i=0;i<n-1;i++){
        if(binarySearch(arr,i+1,n-1,k-arr[i]))
            return {arr[i],k-arr[i]};
    }
    return {-1,-1};
}

pair<int,int> hasSumK3(int arr[],int n,int k){
    quickSort(arr,0,n-1);
    int low = 0,high=n-1;
    while(low<high){
        if(arr[low]+arr[high]==k) return {arr[low],arr[high]};
        if(arr[low]+arr[high]<k) low++;
        else high--;
    }
    return {-1,-1};
}

int main(){
    int arr [7] = {5,3,8,1,6,4,10};
    pair<int,int> ans = hasSumK3(arr,7,11);
    cout<<ans.first<<" "<<ans.second<<endl;
    quickSort(arr,0,6);
    for(int i : arr)cout<<i<<" ";
    return 0;
}