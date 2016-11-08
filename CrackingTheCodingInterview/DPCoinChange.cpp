//
//  DPCoinChange.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 08/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-coin-change

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

/*!
 I didn't know anything about dynamic programming.
 
 Starting from here http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
 */
long long make_change(vector<int> coins, int money) {
    
    long long table[money + 1][coins.size()];
    
    for (int i = 0; i < coins.size(); i++) {
        
        table[0][i] = 1;
    }
    
    long long withCoin;
    long long withoutCoin;
    
    for (int i = 1; i <= money; i++) {
        
        for (int j = 0; j < coins.size(); j++) {
            
            withCoin = (i - coins[j] >= 0) ? table[i - coins[j]][j] : 0;
            withoutCoin = (j >= 1) ? table[i][j - 1] : 0;
            
            table[i][j] = withCoin + withoutCoin;
        }
    }
    
    return table[money][coins.size() - 1];
}

int main() {
    
    int n;
    int m;
    
    cin >> n >> m;
    
    vector<int> coins(m);
    
    for (int coins_i = 0; coins_i < m; coins_i++) {
        
        cin >> coins[coins_i];
    }
    
    cout << make_change(coins, n) << endl;
    
    return 0;
}
