#include<iostream>
#include<vector>
using namespace std;

int dp[1000]; // assuming target <= 1000

int diceRollCount(int sum, int target) {
    if (sum == target) return 1;
    if (sum > target) return 0;

    if (dp[sum] != -1) return dp[sum];

    int ways = 0;
    for (int i = 1; i <= 6; i++) {
        ways += diceRollCount(sum + i, target);
    }
    return dp[sum] = ways;
}

int main() {
    int target = 5;
    fill(dp, dp + 1000, -1);  // initialize DP with -1
    cout << diceRollCount(0, target);
    return 0;
}
