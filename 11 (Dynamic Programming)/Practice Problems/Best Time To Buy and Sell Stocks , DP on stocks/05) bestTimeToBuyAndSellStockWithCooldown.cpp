https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

If u sell the stock on ith day u cannot buy it on i+1 th day ie if u dont have a stock then u have a cooldown.

dp[i][!own][!cooldown] = max profit from day i to to day N, such that no stock owned and no cooldown
dp[i][!own][cooldown] = max profit from day i to day N, such that no stock owned and under cooldown.
dp[i][own][X] = if u own a stock then cooldown ki baat hi nahi hai.

// CODE

class Solution {
public:
    int dp[500001][2][2];
    int solve(int i, bool own, bool cool, vector<int> &prices){
        if(i==prices.size()) return 0;
        
        if(dp[i][own][cool] != -1) return dp[i][own][cool];
        
        if(own){
            int op1 = prices[i] + solve(i+1, 0, 1, prices); // If i sell it, then cooldown will be set to 1 
            int op2 = solve(i+1, 1, 0, prices);             // Dont sell it, there will not be a cooldown
            return dp[i][own][cool] = max(op1, op2);
        }
        else{  // I dont own it
            int op1 = (cool) ? 0 : (-prices[i] + solve(i+1, 1, 0, prices)); // i cannot buy in cooldown.
            int op2 = solve(i+1, 0, 0, prices); // I dont buy it ie i will not own it, In buying there is no sense of cooldown.
            return dp[i][own][cool] = max(op1, op2);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, 0, prices);
    }
};
