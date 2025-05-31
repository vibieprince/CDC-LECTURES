#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void solve(vector<int>&nums){
    auto comp = [&](int a,int b){
        if(a%2==0 && b%2!=0) return false;
        else if(a%2 !=0 && b%2 == 0) return true;
        else return a>b;
    };
    priority_queue<int,vector<int>,decltype(comp)> pq(comp);
    for(int i :nums)
       pq.push(i);

    nums.clear();

    while(!pq.empty()){
        nums.push_back(pq.top());
        pq.pop();
    }
};

int main(){
    vector<int> nums = {50,61,31,90};
    solve(nums);
    for(int i:nums)
       cout<<i<<" ";
}