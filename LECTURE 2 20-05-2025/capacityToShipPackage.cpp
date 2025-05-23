#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
class Solution {
    int getDays(int capacity, vector<int>& weights) {
        int sum = 0, days = 1; // start with day 1
        for(int i = 0; i < weights.size(); i++) {
            if(sum + weights[i] <= capacity) {
                sum += weights[i];
            } else {
                days++;
                sum = weights[i];
            }
        }
        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while(low <= high) {
            int capacity = low + (high - low) / 2;
            int currDays = getDays(capacity, weights);

            if(currDays <= days) {
                ans = capacity;
                high = capacity - 1;
            } else {
                low = capacity + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << "Minimum capacity to ship within " << days << " days is: " << s.shipWithinDays(weights, days) << endl;
    return 0;
}