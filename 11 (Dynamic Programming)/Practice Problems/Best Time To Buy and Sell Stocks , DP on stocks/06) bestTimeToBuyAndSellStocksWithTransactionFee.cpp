https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// In this I can make any number of transactions.

at any ith day -> if u dont own a stock -> 2 options either u buy/ not buy
at any ith day -> if u own a stock -> 2 options either u sell/ not sell

as soon as I buy -> pay prices[i] + pay a transaction fee
as soon as I sell -> get prices[i]

dp[i][!own] = max profit I can make [i..N] given that I donot own a stock.
dp[i][own] = max profit I can make [i..N] given that I own a stock.

dp[1][!own] is my ans

dp[i][!own] = max(dp[i+1][!own], dp[i+1][own] - (prices[i]+fee))


// CODE
class Solution {
public:
    int dp[500001][2];
    
    int solve(int i, bool own, int fee, vector<int> &prices){
        if(i==prices.size()) return 0;
        
        if(dp[i][own] != -1) return dp[i][own];
        
        if(own){
            int op1 = prices[i] + solve(i+1, 0, fee, prices); // If i sell it 
            int op2 = solve(i+1, 1, fee, prices);             // Dont sell it
            return dp[i][own] = max(op1, op2);
        }
        else{  // I dont own it
            int op1 = -(prices[i]+fee) + solve(i+1, 1, fee, prices); // i buy it
            int op2 = solve(i+1, 0, fee, prices);                    // I dont buy it ie i will not own it
            return dp[i][own] = max(op1, op2);
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, fee, prices);
    }
};

// STRIVER

// You can do transactions any number of time but ever time a fee will be charged when u complete a transaction.


// Memoised 
// Same general code with 1 change only
// -fee when I decide to sell or -fee when I decide to pay upfront ie buy, just pay once

class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, int fee, vector<vector<int>> &dp){
        int n = prices.size();
        if(ind == n) return 0;

        if(dp[ind][buy]!= -1) return dp[ind][buy];
        
        if(buy){
            return dp[ind][buy] = max(-prices[ind] + solve(ind+1, 0, prices, fee, dp), 0 + solve(ind+1, 1, prices, fee, dp));
        }
        else {
            return dp[ind][buy] = max(prices[ind]-fee+solve(ind+1, 1, prices, fee, dp), 0 + solve(ind+1, 0, prices, fee, dp)); // change of -fee from the price obtained from selling
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(0, 1, prices, fee, dp);
    }
};


