#include<iostream>
using namespace std;
int count = 0;
void diceRoll(string ans,int sum,int target){
    if(target==sum){
        cout<<ans<<endl;
        count++;
        return;
    }
    for(int i=1;i<=6;i++){
        if(sum+i>target) break;
        diceRoll(ans+(char)(i+'0'),sum+i,target);
    }
}
int main(){
    diceRoll("",0,5);
    cout<<count;
    return 0;
    // 1155
    // 1223
}