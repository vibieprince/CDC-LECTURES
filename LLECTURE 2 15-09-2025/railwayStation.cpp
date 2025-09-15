// You have given arrival and departure of the each train, find the minimum number of platforms required.
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int minPlatform(vector<float> &arrival,vector<float> &departure){
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());
    int n = arrival.size();
    int i=0,j=0,count=0,maxCount=INT_MIN;
    while(i<n){
        if(arrival[i]<departure[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        if(count>maxCount) maxCount = count;
    }
    return maxCount;
}

int main(){
    vector<float> arrival = {9.0,9.25,10.0,10.15,10.30,9.15};
    vector<float> departure = {10.30,9.45,12.0,10.45,11.30,9.20};
    cout<<minPlatform(arrival,departure);
}