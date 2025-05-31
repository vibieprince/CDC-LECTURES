#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> result;
vector<int> ans;
void possibleSubsets(vector<int>& arr,int idx=0){
    result.push_back(ans);
    if(idx==arr.size()) return;
    for(int i=idx;i<arr.size();i++){
        ans.push_back(arr[i]);
        possibleSubsets(arr,i+1);
        ans.pop_back();
    }
}
int main(){
    vector<int> arr = {1,2,3};
    possibleSubsets(arr);
    for(auto& subset : result) {
        cout << "{ ";
        for(int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}