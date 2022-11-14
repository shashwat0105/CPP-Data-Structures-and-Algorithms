https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

TO UNDERSTAND this one solution, else understood of striver.

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k>=prices.size()/2){ // at most u will make n/2 transactions, if k>=n/2 then u can make max no of transactions
            int profit = 0;
            for(int i=1; i<prices.size(); ++i){
                if(prices[i]>prices[i-1]) profit += prices[i]-prices[i-1];
            }
            return profit;            
        } 
        vector<int> buy(k+1, INT_MAX);
        vector<int> sell(k+1, 0);
        
        for(int price: prices){
            for(int i=1; i<=k; ++i){
                buy[i] = min(buy[i], price - sell[i-1]);
                sell[i] = max(sell[i], price-buy[i]);
            }
        }
        return sell[k];
    }
};

//
we can at most make n/2 transactions in the worst case of stock alternating between going up and down everyday . As an example : 1 4 2 6 3 8 . We will buy and sell on alternate days .

If there is any stretch where the stock is increasing continuously or decreasing continuously , then we will only need lesser number of transactions as we can skip a day in between to sell or buy .
Ex. 1 2 3 6 4 2 8 . Here , we don't need to sell on the 2nd day and we can wait that day out . Similarly , we don't need to buy on day 5 . So these 'wait' days only further reduce the number of max transactions from k/2


buy[i] = min(buy[i], price-sell[i - 1]);
why we are subtracting last transaction sell ?
Think of it like that . Sell[i-1] is the profit we have so far after selling i-1 stocks . 
After buying the i th stock , we are now calculating the loss we have at the end of this buying . At every step , we are minimizing the loss so far on the 'buy' step and consequently maximizing the profit so far on the 'sell' step

// STRIVER

// Same as iii problem just there instead of 2 here is 'k'
// Using the same code
// replace with k

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(k+1, 0));
        vector<vector<int>> cur(2, vector<int>(k+1, 0));

        int profit = 0;
        for(int ind=n-1; ind>=0; --ind){
            for(int buy = 0; buy<=1; ++buy){
                for(int cap = 1; cap<=k; ++cap){
                    if(buy){
                        profit = max(-prices[ind] + after[0][cap], 0 + after[1][cap]);
                    }
                    else{
                        profit = max(prices[ind] + after[1][cap-1], 0 + after[0][cap]);
                    }
                    cur[buy][cap] = profit;
                }
            }
            after = cur;
        }

        return after[1][k];
    }
};

// Another method 
// Using transaction variable
// For k = 2: 0 1 2 3 ie to repreasent buy sell buy sell 
// For k values transNo goes upto 2*k elements

// memoised

class Solution {
public:
    int solve(int ind, int transNo, int k, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(ind==n || transNo == 2*k) return 0;  

        if(dp[ind][transNo]!= -1) return dp[ind][transNo];

        int profit = 0;
        if(transNo%2 == 0){ // buy
            profit = max(-prices[ind] + solve(ind+1, transNo+1, k, prices, dp), 0 + solve(ind+1, transNo, k, prices, dp));
        }
        else{
            profit = max(prices[ind] + solve(ind+1, transNo+1, k, prices, dp), 0 + solve(ind+1, transNo, k, prices, dp));
        }
        return dp[ind][transNo] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return solve(0, 0, k, prices, dp);
    }
};

// Tabulation

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));  // I am at n-1 and accessing ind+1 hence declare extra size, same for tranNo as well

        // base case
        // All matrix elements are already 0, no need to write

        for(int ind=n-1; ind>=0; --ind){  // ind==n already in base case
            for(int transNo = 2*k-1; transNo>=0; --transNo){  // transNo == 2*k already in base case
                int profit = 0;
                if(transNo%2 == 0){ // buy
                    profit = max(-prices[ind] + dp[ind+1][transNo+1], 0 + dp[ind+1][transNo]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+1][transNo+1], 0 + dp[ind+1][transNo]);
                }
                dp[ind][transNo] = profit;
            }
        }
        return dp[0][0];
    }
};

// Space optimised
// Just delete one dimension in matrix and use either after or cur accordingly

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2*k+1, 0), cur(2*k+1, 0);  

        for(int ind=n-1; ind>=0; --ind){  // ind==n already in base case
            for(int transNo = 2*k-1; transNo>=0; --transNo){  // transNo == 2*k already in base case
                int profit = 0;
                if(transNo%2 == 0){ // buy
                    profit = max(-prices[ind] + after[transNo+1], 0 + after[transNo]);
                }
                else{
                    profit = max(prices[ind] + after[transNo+1], 0 + after[transNo]);
                }
                cur[transNo] = profit;
            }
            after = cur;
        }
        return after[0];
    }
};





