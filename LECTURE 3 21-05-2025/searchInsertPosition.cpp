#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                ans = mid+1;
                low = mid+1;
            }
            else high = mid-1,ans = mid;
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,3,5,6};
    int target = 5;
    cout << s.searchInsert(nums,target) << endl; // Output: 2
    target = 2;
    cout << s.searchInsert(nums,target) << endl; // Output: 1
    target = 7;
    cout << s.searchInsert(nums,target) << endl; // Output: 4
    target = 0;
    cout << s.searchInsert(nums,target) << endl; // Output: 0
    return 0;
}