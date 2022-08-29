https://cses.fi/problemset/task/1158

// Tight Constraints.

// This is a case of the classical problem called 0-1 knapsack.

#include <bits/stdc++.h>
using namespace std;

int main() {
    //int mod = 1e9+7;
    int n, x;
    cin >> n >> x;
    vector<int> price(n+1), pages(n+1);

    for(int i=0; i<n; ++i) cin>> price[i];
    for(int i=0; i<n; ++i) cin>> pages[i];

    int dp[n+1][x+1];

    for(int i=0; i<=n; ++i) dp[i][0]=0;
    for(int money=0; money<=x; ++money) dp[0][money]=0;

    for(int i=1; i<=n; ++i){
        for(int money=0; money<=x; ++money){   // Using i numbers and "money" in hand solving the subproblems. 
            if(price[i-1]<=money){
                dp[i][money] = max(pages[i-1]+ dp[i-1][money-price[i-1]], dp[i-1][money]);
            }
            else{
                dp[i][money] = dp[i-1][money];
            }
        }
    }
  
    cout<<dp[n][x];
}
