#include<iostream>
#include<vector>
using namespace std;
vector<int> ans;
vector<vector<int>> result;
void coinSum(vector<int> &coins,int sum,int target){
    if(sum==target){
        result.push_back(ans);
        return;
    }
    if(sum>target) return;
    for(int i=0;i<coins.size();i++){
        ans.push_back(coins[i]);
        coinSum(coins,sum+coins[i],target);
        ans.pop_back();
    }
}

int main(){
    vector<int> coins = {1,2,3};
    coinSum(coins,0,8);
    cout<<"[";
    for (auto &comb : result) {
        cout<<"[";
        for (int c : comb) cout << c << " ";
        cout <<"]";
    }
    cout<<"]";
    return 0;
}