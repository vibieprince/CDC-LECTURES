#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return true;
            else if(nums[low]==nums[mid] && nums[mid]==nums[high]){ // we can't decide where our target could be because the array is containing duplicates
                low++;
                high--;
            }
            else if(nums[mid]>=nums[low]){
                if(nums[low]<=target && nums[mid]>=target) high = mid-1;
                else low = mid+1;
            }
            else{
                if(nums[high]>=target && nums[mid]<=target) low = mid+1;
                else high = mid -1;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;
    cout << s.search(nums,target) << endl; // Output: 1
    target = 3;
    cout << s.search(nums,target) << endl; // Output: 0
    return 0;
}