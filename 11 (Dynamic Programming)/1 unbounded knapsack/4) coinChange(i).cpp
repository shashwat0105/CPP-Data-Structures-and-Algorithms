// Coin Change Problem - 
// Here I have to find Maximum Number of ways, I can make a change.
// https://www.geeksforgeeks.org/coin-change-dp-7/
https://leetcode.com/problems/coin-change-2/            (This is coin change 2 on leetcode)

// Given a value S, if we want to make change for S cents, and we have infinite supply of each of Coin = {C1, C2, .. , Cm} valued coins, 
// how many ways can we make the change? The order of coins doesn’t matter.
// Example:
// for Sum(S) = 4 and Coin = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
// So output should be 4. ie we need to count or find the number of solutions. So "+" will come in our code.
// Coins have choices hence knapsack & can be taken multiple times hence it is unbounded knapsack

// Matching :- wt[] -> coin[] (also we ignore the val[] array) & W -> Sum


int coinChangeI(int coin[], int Sum, int n)                     // if there is long long   // n is the size of coin array.
{

    int t[n + 1][Sum + 1];                    // Then do, long long int t[n+1][Sum+1];
    // base condition (Taken from count of subset sum problem)  // Better in separate loops.
    for(int i=0; i<=n; i++){
        t[i][0]=1;                                              // initilising the leftmost column
    }
    for(int j=1; j<=Sum; j++){                             
        t[0][j]=0;                                              // initilising the topmost row
    }

    // Choice Diagram
    // Build table K[][] in bottom up manner
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= Sum; j++){
            // choice diagram
            else if (coin[i - 1] <= j)
                t[i][j] = t[i][j - coin[i - 1]] + t[i - 1][j];  // remove the max, val & insert + in the knapsack code & i-1 -> i when choice is to take the coin unboundedly
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][Sum];
}

// Space optimised Bottom Up
class Solution {
  public:
    long long int count(int coins[], int n, int amount) {
       vector<long long int>dp(amount+1,0);
       dp[0]=1;
       for(int i=0;i<n;i++)
           for(int j=coins[i];j<=amount;j++)
               dp[j] += dp[j-coins[i]];
       return dp[amount];
   }
};

// Memoised solution:
long long int count_help(int i, int s[], int m, int sum,vector<vector<long long int>>& dp){
    if(i==m) return 0;
    if(sum<0) return 0;
    if(sum==0) return 1;
    if(dp[i][sum]!=-1) return dp[i][sum];
    
    long long int take = count_help(i,s,m,sum-s[i],dp);
    long long int notTake = count_help(i+1,s,m,sum,dp);
    
    return dp[i][sum] = take + notTake;
}
long long int count(int S[], int m, int sum){
    vector<vector<long long int>>dp(m+1,vector<long long int>(sum+1,-1));
    return count_help(0,S,m,sum,dp);
}
