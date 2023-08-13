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


********************************************* STRIVER *****************************************************

// From buy and sell 2
// I add one more state "cap"   // cap means these many trasactions I can do
// f(ind, buy, cap){
//     if(buy)

//     else  // sell
// }

// If I do sell then only I am completing a transaction ie no of transactions left will get reduced by 1

dp[ind][buy][cap] = [n][2][3]
// cap can be 0 1 or 2

// Memoised 

class Solution {
public:
    int solve(int ind, int buy, int cap, vector<int>& prices,  vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(cap==0) return 0; // should be executed first
        if(ind==n) return 0;

        if(dp[ind][buy][cap]!= -1) return dp[ind][buy][cap];

        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + solve(ind+1, 0, cap, prices, dp), 0 + solve(ind+1, 1, cap, prices, dp));
        }
        else{
            profit = max(prices[ind] + solve(ind+1, 1, cap-1, prices, dp), 0 + solve(ind+1, 0, cap, prices, dp));
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};

// Tabulated
// base case
// when cap is 0, ind and buy can be anything
// when ind is n, buy and cap can be anything

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3, 0)));

        // first base case // practically writing base case doesn't make any sense coz we are again assigning zero.
        // for(int ind=0; ind<n; ++ind){
        //     for(int buy=0; buy<=1; ++buy){
        //         dp[ind][buy][0] = 0;
        //     }
        // }
        // // second base case
        // for(int buy = 0; buy<=1; ++buy){
        //     for(int cap = 0; cap<=2; ++cap){
        //         dp[n][buy][cap] = 0;
        //     }
        // }

        int profit = 0;
        for(int ind=n-1; ind>=0; --ind){
            for(int buy = 0; buy<=1; ++buy){
                for(int cap = 1; cap<=2; ++cap){
                    if(buy){
                        profit = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                    }
                    else{
                        profit = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};

// Space optimised
// TC = O(N*2*3)
// SC = O(1)

[ind+1] needs to be optimized

//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));

        int profit = 0;
        for(int ind=n-1; ind>=0; --ind){
            for(int buy = 0; buy<=1; ++buy){
                for(int cap = 1; cap<=2; ++cap){
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

        return after[1][2];
    }
};

// METHOD 2
// NOT Intuitive 4 variables solution

// Method 3
// dp[N][4]

// B S B S
// 0 1 2 3
  even even

f(ind, transactions){
    if(ind==n || transactions== 4) return 0;

    if(transactions %2 ==0) // buy : max: -prices[ind] + f(ind+1, trans+1), 0 + f(ind+1, trans)
    else                    // sell : max: prices[ind] + f(ind+1, trans+1) , 0 + f(ind+1, trans)
}

// You can write code for this as well similar to above
// Memo


// Tabulated


// Space optimization

