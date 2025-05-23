#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int low = 0,high = nums.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) low = mid+1;
        else high = mid-1;
    }
    return -1;
}
int main(){
    vector<int> nums = {2,5,7,10,12,15,18,27};
    int target = 18;
    int ans = search(nums,target);
    if(ans!=-1) cout<<target<<" is present at index "<<search(nums,target)<<endl;
    else cout<<target<<" is not present in the array"<<endl;
}

// 875
// 1482
// 33
// 153
