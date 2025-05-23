#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// class Person{
//     public:
//         string name;
//         Person(string name){
//             this->name = name;
//         }

//         void doSomething(){
//             Person p = new Person("Prince");
//             int a = 10;
//             cout<<p.name<<endl;
//             doSomethingMore();
//             a = 100;
//             cout<<p.name<<a<<endl;
//         }

// };

// int main(){
//     doSomething();
// }
// implicit return - stack frame out of the stack
int getSum(int n){
    if(n==0) return 0;
    return n%10 + getSum(n/10);;
}
void print(int n){
    cout<<n<<"->";
    if(n==5) return;
    print(n+1);
    cout<<n<<"->";
}
int getPatternSum(int n){
    if(n==1) return 4;
    return (n+n+2) * getPatternSum(n-1);
}
int printFibo(int n){
    if(n<=0) return 0; // handle neagtive numbers 
    if(n==1) return 0;
    if(n==2) return 1;

    return printFibo(n-1)+printFibo(n-2);
}
int printFact(int n){
    if(n==0 || n==1) 
        return 1;
    return n*printFact(n-1);;
}
void printReverseArray(const vector<int> &arr, int i = 0) {
    if (i == arr.size()) return;
    printReverseArray(arr, i + 1);
    cout << arr[i] << " ";
}
// void prinReverseArray2(vector<int> &arr,int i=0){
//     if(i==arr.size()/2) return;
//     swap(arr[i],arr[arr.size()-i-1]); // can't use with const vector
//     prinReverseArray2(arr,i+1);
// }

int main(){
    // print(1);
    // cout<<printFact(5);
    cout<<printFibo(0);
    // cout<<getSum(57829);
    // cout<<getPatternSum(5);
    // vector<int> arr = {1,2,3,4,5};
    // printReverseArray(arr);
    vector<int> arr;
    for(int i: arr)
       cout<<i<<" ";
    // prinReverseArray2(arr);
}