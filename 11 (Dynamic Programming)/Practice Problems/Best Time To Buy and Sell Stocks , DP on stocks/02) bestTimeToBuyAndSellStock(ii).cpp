https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Greedy solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                profit += (prices[i] - prices[i-1]);
            }
        }
        return profit;
    }
};

// Dynamic Programming

// Trying all possibilities
// ie If I can buy I will buy/not buy irrespective of profit. same for sell.
// 1) Express everything in terms of index. f(ind, buy)
// I have to keep a variable buy which tells me If I can buy or not.
// 2) Explore possibilities on that day
// 3) Take the max of all profits made
// 4) Base case

If buy = 1 then I can either buy or not buy
If buy = 0 then I can either sell or not sell

// Memoised

class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(ind==n) return 0;  // either u have a stock or not you cannot make profit
        
        if(dp[ind][buy]!= -1) return dp[ind][buy];

        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + solve(ind+1, 0, prices,dp), 0 + solve(ind+1, 1, prices, dp));  // decides to buy, now u cannot buy so buy becomes 0 and so on
        }
        else{
            profit = max(prices[ind] + solve(ind+1, 1, prices, dp), 0 + solve(ind+1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);                // in staring I can buy so I pass buy = 1
    }
};

// Tabulation
// We write from back(reverse of memoise)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // base case (we start from back)
        dp[n][0] = dp[n][1] = 0;  // irrespective of both the values of buy

        for(int ind=n-1; ind>=0; --ind){
            for(int buy = 0; buy<=1; ++buy){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);  
                }
                else{
                    profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

// Space optimised
using [ind+1][0] and [ind+1][1] to fill ie we require just two variables

//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), cur(2, 0);  // 2 variable array (4 different variables)
        // base case (we start from back)
        ahead[0] = ahead[1] = 0;  // irrespective of both the values of buy

        for(int ind=n-1; ind>=0; --ind){
            for(int buy = 0; buy<=1; ++buy){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);  
                }
                else{
                    profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }
                cur[buy] = profit;
            }
            ahead = cur; // cur transfer its powers to ahead
        }
        return ahead[1];
    }
};

// Using variables explicitly

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadNotBuy, aheadBuy, curNotBuy, curBuy;

        // base case 
        aheadNotBuy = aheadBuy = 0;  

        for(int ind=n-1; ind>=0; --ind){
            curNotBuy = max(prices[ind] + aheadBuy, 0 + aheadNotBuy);
            curBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);  

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};


