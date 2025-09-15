// There are n pirates.

// Each pirate ranks by seniority: Pirate 1 is the boss, Pirate 2 below him, etc.

// The boss proposes a distribution of coins.

// All pirates (including the boss) vote: yes or no.

// If at least 50% agree, the proposal is accepted. Otherwise, the boss is killed, and the next pirate becomes the new boss.

// Pirates are rational:

// They prefer survival over death.

// They prefer more coins over fewer.

// If coins are equal, they prefer to kill the boss (because they’re bloodthirsty 😈).

#include<iostream>
#include<vector>
using namespace std;

vector<int> distributeCoins(int n,int coins){
    if(n==1) return vector<int> {coins};

    vector<int> smaller = distributeCoins(n-1,coins);

    int votesNeeded = (n+1)/2; // ceil(n/2)
    
    vector<int> dist(n,0);
    dist[0] = coins;
    int bribed = 0;
    
    for(int i=1;i<n && bribed < (votesNeeded-1);i++){
        if(smaller[i-1]==0){
            dist[i] = 1;
            dist[0] -= 1;
            bribed++;
        }
    }

    // If we still haven't bribed enough (rare if there are no zeroes), the boss would need to bribe some other pirates (but with our rational preferences and recursion this situation won't occur in the clasical pirate puzzle).
    return dist;
}

int main() {
    int n, coins;
    cout << "Enter number of pirates: ";
    cin >> n;
    cout << "Enter number of coins: ";
    cin >> coins;

    vector<int> result = distributeCoins(n, coins);

    cout << "Distribution of coins:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Pirate " << i+1 << ": " << result[i] << " coins" << endl;
    }

    return 0;
}