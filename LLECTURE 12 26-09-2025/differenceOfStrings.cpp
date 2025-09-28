#include<iostream>
#include<vector>
using namespace std;

void differenceOfStrings(string s1,string s2){ // s1 - s2
    vector<bool> seen(256,false);
    for(char c:s1) if(!seen[c]) seen[c] = true;
    for(char c : s2) if(seen[c]) seen[c] = false;
    for(int i=0;i<256;i++)if(seen[i]) cout<<(char)i<<" ";

}
int main(){
    differenceOfStrings("RITAMBHARA","TECHNOLOGIES");
}