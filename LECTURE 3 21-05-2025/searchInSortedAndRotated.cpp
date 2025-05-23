#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0,high = nums.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>= nums[low]){ // left part is sorted and target may be found there
            if(nums[low]<=target && nums[mid]>=target) high = mid-1;
            else low = mid+1;
        }
        else{
            if(nums[high]>=target && nums[mid]<=target) low = mid + 1; // right part is sorted and target may be found there
            else high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int ans = search(nums,target);
    if(ans!=-1) cout<<target<<" is present at index "<<search(nums,target)<<endl;
    else cout<<target<<" is not present in the array"<<endl;
}