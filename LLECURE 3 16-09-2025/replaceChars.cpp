#include<iostream>
using namespace std;

void printSequence(string &str,string s = "",int idx=0){
    if(idx>=str.length()){
        cout<<s<<" ";
        return;
    }

    // Choice 1 : Keep Original Character
    printSequence(str,s+str[idx],idx+1);
    
    // Choice 2 : Replace it with 1
    printSequence(str,s+'1',idx+1);

}
int  main(){
    string str = "ABC";
    printSequence(str);
    return 0;
}