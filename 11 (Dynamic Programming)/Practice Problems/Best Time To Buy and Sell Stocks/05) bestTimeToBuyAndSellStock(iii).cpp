https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

General case for atmost k transactions.

best([1, 2, 3, 4, 5..N], 0, K)   // 0 means initially I dont own a stock.

dp[i][!own][j] : max profit from [i...N] given that -> no stock, at most can do j transactions
dp[i][own][j] : max profit from [i...N] given that -> stock, at most can do j transactions

sell means -> 1 transaction.

dp[1][own][k] will be my final ans.

dp[i][!own][j] = max(-price[i] + dp[i+1][own][j], dp[i+1][!own][j])
dp[i][own][j] = max(price[i] + dp[i+1][!own][j-1], dp[i+1][own][j]) // if I sell a stock then no of transactions decrease

//
For knowing i we need to know i+1
For knowing j we need to know j-1

// CODE
class Solution {
public:
    int dp[100001][2][3]; // [][own][k]
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0; 
        int k = 2;
        int n = (int)prices.size();
        for(int days = n-1; days>=0; --days){
            for(int trans = 0; trans<=k; ++trans){
                // base case
                if(days==n-1){
                    dp[days][0][trans] = 0;
                    dp[days][1][trans] = (trans>=1) ? prices[days] : 0;
                }
                else{
                    dp[days][0][trans] = max(-prices[days] + dp[days+1][1][trans], dp[days+1][0][trans]);
                    dp[days][1][trans] = max(((trans>=1)? prices[days]+dp[days+1][0][trans-1]: 0), dp[days+1][1][trans]);
                }
            }
        }
        return dp[0][0][k];
    }
};

// TC = O(n*k)

Here k is 2 so its fine but if k is large then there will be a TLE
