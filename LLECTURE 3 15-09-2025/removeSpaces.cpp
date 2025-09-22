#include<iostream>
using namespace std;

int main(){
    string str = "IT     IS   HOT";
    int i=0,j=0;
    while(j < str.size()){
        if(str[j] != ' '){
            swap(str[i], str[j]);
            i++;
        }
        j++;
    }
    cout << str.substr(0, i) << endl;
    return 0;
}
