#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> result;
void printSubSequence(vector<int> &arr,vector<int>ans,int idx=0){
    if(idx>=arr.size()){
        result.push_back(ans);
        return;
    }

    // Include
    ans.push_back(arr[idx]);
    printSubSequence(arr,ans,idx+1);

    // Exclude
    ans.pop_back();
    printSubSequence(arr,ans,idx+1);
}
int main(){
    vector<int> arr = {1,2,3};
    printSubSequence(arr,{});
    for (auto &subseq : result) {
        cout << "{ ";
        for (auto &num : subseq)
            cout << num << " ";
        cout << "}\n";
    }
}