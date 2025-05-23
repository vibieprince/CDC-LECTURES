#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    bool canEat(vector<int>&piles,int mid,int h){
        int HOUR = 0;
        for(int &i : piles){
            HOUR += i/mid;
            if(i%mid!=0) HOUR++;
        }
        return HOUR <=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        while(left < right){
            int mid = left + (right-left)/2;
            if(canEat(piles,mid,h)) right = mid;
            else left = mid+1; // increase banana per hour
        }
        return left;
    }
};
int main(){
    Solution s;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout << "Minimum eating speed to finish in " << h << " hours is: " << s.minEatingSpeed(piles, h) << endl;
    return 0;
}