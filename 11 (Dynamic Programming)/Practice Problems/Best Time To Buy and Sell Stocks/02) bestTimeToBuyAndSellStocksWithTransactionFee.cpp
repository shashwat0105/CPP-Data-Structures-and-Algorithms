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
