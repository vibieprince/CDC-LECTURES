#include<iostream>
#include<vector>
using namespace std;

void intersectionOfStrings(string s1,string s2){
    vector<bool> seen(256,false);
    for(char c : s1)
        if(!seen[c])
            seen[c] = true;

    for(char c : s2)
        if(seen[c]) cout<<c<<" ";
}

int main(){
    intersectionOfStrings("RITAMBHARA","TECHNOLOGIES");
    return 0;
}