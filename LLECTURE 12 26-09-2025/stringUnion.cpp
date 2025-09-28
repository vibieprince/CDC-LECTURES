#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Didn't gurantee the order
vector<char> unionOfStrings(string s1,string s2){
    unordered_set<char> set;
    for(char &c : s1) set.insert(c);

    for(char &c : s2) set.insert(c);

    vector<char> ans;
    for(auto &i : set) ans.push_back(i);

    return ans;
}

// Gurantee's for the order of characters
vector<char> unionOfStrings1(string s1,string s2){
    vector<bool> seen(256,false);

    vector<char> ans;
    for(char &c : s1){
        if(!seen[c]){
            seen[c] = true;
            ans.push_back(c);
        }
    }

    for(char &c : s2){
        if(!seen[c]){
            seen[c] = true;
            ans.push_back(c);
        }
    }
    return ans;
} 

int main(){
    vector<char> result = unionOfStrings("RITAMBHARA","TECHNOLOGIES");
    for(char &c : result) cout<<c<<" ";
    cout<<endl;

    vector<char> result1 = unionOfStrings1("RITAMBHARA","TECHNOLOGIES");
    for(char &c : result1) cout<<c<<" ";
}