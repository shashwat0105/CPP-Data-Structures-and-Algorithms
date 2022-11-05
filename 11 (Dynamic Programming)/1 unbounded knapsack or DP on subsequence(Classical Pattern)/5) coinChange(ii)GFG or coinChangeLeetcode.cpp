// Coin Change Problem - Minimum Number of coins
// Here I have to find minimum number of coins that will be required to add up to a given value.
// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
// https://leetcode.com/problems/coin-change/

// Coin[] = {3, 4, 5}, Sum = 5

// In this we extra initilise the 2nd row as well depending upon whether the sub problem sum is divisible by arr[0]

//         0          1           2           3         4             5   -> j(Sum)
// 0 | INT_MAX-1  INT_MAX-1   INT_MAX-1  INT_MAX-1  INT_MAX-1    INT_MAX-1       // We want sum >= 0 & coin[] ={ } array is empty ie infinite no of coins will be required mathematically
// 1 |     0      INT_MAX-1   INT_MAX-1       1     INT_MAX-1    INT_MAX-1       // For sum = 0 & no of coins > 0, we need min coins = 0
// 2 |     0
// 3 |     0
// i(n)

// infinite = INT_MAX, for safety we take INT_MAX-1 because in code we do + 1 when we take coin -> INT_MAX-1+1 can be stored but INT_MAX+1 cannot be stored in Int as it will become negative

for(int i = 1; j < sum+1; j++){
    if(j% arr[0] ==0){
        t[i][j] = j/arr[0];
    }
    else
        t[i][j] = INT_MAX-1;
}

// for rest i = 2, j = 1 ... unbounded knapsack code & max -> min coz here we want min & instead of adding value we add 1 when we are including the coin ie number of coin is increased by 1
if(coin[]<=j){
    t[i][j] = min(t[i][j-coin[i - 1]] + 1, t[i-1][j])
}
else
    t[i][j] = t[i-1][j];

// *******************************
// CODE:

class Solution {
public:    
    int dp[12 + 1][10001];
    
    int findLowestCoins(vector<int> &coins, int n, int amount) {
        for (int i = 0; i <=n; i++)
            for (int j = 0; j <= amount; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;
        
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] > j)
                    dp[i][j] = 0 + dp[i - 1][j];
                else
                    dp[i][j] = min(0 + dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
        
        return dp[n][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int res = findLowestCoins(coins, coins.size(), amount);
        return (res == INT_MAX - 1) ? -1 : res;
    }
};

****************************************************
// Aditya verma solution to these problems:
// https://leetcode.com/problems/coin-change/discuss/1371738/C%2B%2B-Recursion-greater-DP-Memoization-greater-DP-Tabulation

// LUV
https://youtu.be/PoTE56n_It8

// Leetcode
[1, 2, 5]
// We can use 1 coin -> 1 or 2 or 5, 2 coin -> 1 or 2 or 5, 5 coin -> 1 or 2 or 5.... and so on (Recursion tree)
// Recursive
class Solution {
public:
    int solve(int amount, vector<int>& coins){
        if(amount==0) return 0;
        
        int ans = INT_MAX;                                              
        for(int coin: coins){
            if(amount-coin>=0){                                        // to avoid handling amount<0 base case
                ans = min(ans + 0LL, solve(amount-coin, coins)+1LL);   // Long long is used to avoid overflow and, min compares both same data types. 
            }
        }
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(amount, coins);
        return ans == INT_MAX ? -1 : ans;  
    }
};

// Memoised
class Solution {
public:
    int dp[10010];
    int solve(int amount, vector<int>& coins){
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        
        int ans = INT_MAX;
        for(int coin: coins){
            if(amount-coin>=0){   
                ans = min(ans + 0LL, solve(amount-coin, coins)+1LL);
            }
        }
        return dp[amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(amount, coins);
        return ans == INT_MAX ? -1 : ans;  
    }
};





// 1D DP Code: Refer discuss section


// Striver ka Gyan:
1) Express in terms of  f(ind, Target)
2) Perform all stuffs
3) return min

Base case for memoised:
If target is say 12
arr[0] is 4. 
If this target is divisible by 4 then only it is possible to make up this target. Else it is not.

Base case for bottom up:
When the index is 0, the target call could be anything from 0 to T.

// Memoised

int solve(int ind, vector<int>& coins, int amount, vector<vector<int>> &dp){
    if(ind==0){
        if(amount%coins[0] == 0){
            return amount/coins[0];
        }
        else return 1e9;  // ie sum is not possible
    }
    
    if(dp[ind][amount]!= -1) return dp[ind][amount];
    
    int notTake = solve(ind-1, coins, amount, dp);
    int take = 1e9;
    if(coins[ind]<=amount){
        take = 1 + solve(ind, coins, amount-coins[ind], dp);
    }
    return dp[ind][amount] = min(take,notTake);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    int ans = solve(n-1, coins, amount, dp);
    if(ans>=1e9) return -1;                           // Important to do else wrong ans
    else return ans;
}

// Tabulated

 int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, 0));
    
    for(int sum=0; sum<=amount; sum++){
        if(sum%coins[0]==0) dp[0][sum] = sum/coins[0];
        else dp[0][sum] = 1e9;
    }
    
    for(int ind = 1; ind<n; ++ind){
        for(int sum=0; sum<=amount; ++sum){
            int notTake = dp[ind-1][sum];
            int take = 1e9;
            if(coins[ind]<=sum){
                take = 1 + dp[ind][sum-coins[ind]];
            }
            dp[ind][sum] = min(take, notTake);
        }
    }
    
    int ans = dp[n-1][amount];
    if(ans>=1e9) return -1;
    else return ans;
}

// Space optimised

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> prev(amount+1, 0), cur(amount+1, 0);
    
    for(int sum=0; sum<=amount; sum++){
        if(sum%coins[0]==0) prev[sum] = sum/coins[0];
        else prev[sum] = 1e9;
    }
    
    for(int ind = 1; ind<n; ++ind){
        for(int sum=0; sum<=amount; ++sum){
            int notTake = prev[sum];
            int take = 1e9;
            if(coins[ind]<=sum){
                take = 1 + cur[sum-coins[ind]];   // ind-1 ki jagah ind hai so yeh cur m save hoga
            }
            cur[sum] = min(take, notTake);
        }
        prev = cur;
    }
    
    int ans = prev[amount];
    if(ans>=1e9) return -1;
    else return ans;
}
