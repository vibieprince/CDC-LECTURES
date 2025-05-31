#include<iostream>
#include<queue>
using namespace std;

int main(){
    auto cmp = [](int a,int b){
        return a>b; // smaller element goes to the top i.e min heap
    };
    // Use decltype to specify comparator type
    priority_queue<int,vector<int>,decltype(cmp)>pq(cmp);
    pq.push(40);
    pq.push(60);
    
    pq.push(10);
    pq.push(30);
    pq.push(90);

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
}