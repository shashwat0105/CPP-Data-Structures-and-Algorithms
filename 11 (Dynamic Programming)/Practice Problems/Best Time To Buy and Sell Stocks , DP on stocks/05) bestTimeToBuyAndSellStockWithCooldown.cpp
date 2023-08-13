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


**************** STRIVER *****************

// COOLDOWN: CANNOT BUY RIGHT AFTER SELL

// Changes: Hence when u sell, directly jump to ind+2 index instead of ind+1(cannot buy on next day)
// Since you are trying to access ind+2, when n-1 is called it will be out of bound.
// So in base case ind>=n return 0

// Use memoised code of stock ii problem (only two changes)

class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(ind>=n) return 0;  // 1. change here to >
        
        if(dp[ind][buy]!= -1) return dp[ind][buy];

        int profit = 0;
        if(buy){ 
            // dp[ind][buy] = max(...stuff) can also be written no issue // we can then eliminate this loop as well by hardcoding the value of buy
            profit = max(-prices[ind] + solve(ind+1, 0, prices,dp), 0 + solve(ind+1, 1, prices, dp));  
        }
        else{
            profit = max(prices[ind] + solve(ind+2, 1, prices, dp), 0 + solve(ind+1, 0, prices, dp));  // 2. change here to ind+2 when u decide to sell
        }
        return dp[ind][buy] = profit;

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);                
    }
};

// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));     // dealing with ind+2 so n-1 + 2 we have to use that size of array
        // need not to initilise the base case as already 0

        for(int ind=n-1; ind>=0; --ind){
            for(int buy = 0; buy<=1; ++buy){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);  
                }
                else{
                    profit = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];                
    }
};

// Space optimisation

// Before that we can omit the internal loop, as buy is taking just two values 0 and 1 lets hardcode them.
// dp[ind][buy] => dp[ind][1] and dp[ind][1]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for(int ind=n-1; ind>=0; --ind){
            dp[ind][1] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);  
            dp[ind][0] = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
        }
        return dp[0][1];                
    }
};

// Now
// Have to deal with [ind+1] and [ind+2] as well ie 3 arrays ie 6 variables LOL
// TC = O(N), SC = O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front2(2, 0), front1(2, 0), cur(2, 0);

        for(int ind=n-1; ind>=0; --ind){
            cur[1] = max(-prices[ind] + front1[0], 0 + front1[1]);  
            cur[0] = max(prices[ind] + front2[1], 0 + front1[0]);

            front2 = front1;
            front1 = cur;
        }
        return cur[1];                
    }
};
