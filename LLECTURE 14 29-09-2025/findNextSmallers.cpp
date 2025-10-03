#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &arr,vector<pair<int,int>> &numsPair,int left,int mid,int right){
    vector<pair<int,int>> temp(right-left+1);
    int i = left,j=mid+1;
    int k = 0;

    while(i<=mid && j<=right){
        if(numsPair[i].first <= numsPair[j].first)
            temp[k++] = numsPair[j++];
        else{
            
        }

    }
}
vector<int> findNextSmallers(vector<int> arr){
    
}

int main(){
    vector<int> arr = {5,3,8,1,4,2,9,6,7};
    //                 4 2 4 0 1 0 2 0 0 
}