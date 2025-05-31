#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> result;
vector<int> ans;
void possibleSubsets(vector<int>& arr,int i=0){
    if(i==arr.size()){
        result.push_back(ans);
        return;
    }
    ans.push_back(arr[i]);
    possibleSubsets(arr,i+1);

    ans.pop_back();
    possibleSubsets(arr,i+1);
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