#include<iostream>
using namespace std;

void permutation(string option,string ans){
    if(ans.length()==option.length()){
        cout<<ans<<" ";
        return;
    }
    for(int i=0;i<option.length();i++)
        permutation(option,ans+option[i]);
}

void permutation2(string option,string ans){
    if(option.length()==0){
        cout<<ans<<" ";
        return;
    }
    for(int i=0;i<option.length();i++)
        permutation2(option.substr(0, i) + option.substr(i + 1),ans+option[i]);
}
int main(){
    string option = "abc";
    // permutation(option,"");
    permutation2(option,"");
}
// 22
// 17 
// 39 
// 40
// 46 
// 47
// 31
// 78
// 90
// 131
// 93
// 79
// 698