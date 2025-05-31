#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int findKthLargest(vector<int>&nums,int k){
    auto comp = [&](int a,int b){
        return a>b;
    };
    priority_queue<int,vector<int>,decltype(comp)> pq(comp); // min-heap
    for(int i=0;i<k;i++)
       pq.push(nums[i]);
    
    int i=1;
    while(!pq.empty() && i<k){
        pq.pop();
        i++;
    }
    return pq.top();
}
int main(){
    vector<int> nums = {2,5,6,9,1,4,8,11,67,23};
    cout<<findKthLargest(nums,3);
    return 0;
}