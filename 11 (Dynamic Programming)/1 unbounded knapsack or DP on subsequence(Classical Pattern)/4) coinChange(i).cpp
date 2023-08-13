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


// Here coins[i] >= 1  (No zero case to be bothered of)

int coinChangeI(int coin[], int Sum, int n)                     // if there is long long   // n is the size of coin array.
{
    int t[n + 1][Sum + 1];                                      // Then do, long long int t[n+1][Sum+1];
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
            if (coin[i - 1] <= j)
                t[i][j] = t[i][j - coin[i - 1]] + t[i - 1][j];  // remove the max, val & insert + in the knapsack code & i-1 -> i when choice is to take the coin unboundedly
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][Sum];
}

// Space optimised Bottom Up:

class Solution {
  public:
    long long int count(int coins[], int n, int amount) {
       vector<long long int>dp(amount+1,0);
       dp[0]=1;
       for(int i=0;i<n;i++)
           for(int j=coins[i]; j<=amount; j++)
               dp[j] += dp[j-coins[i]];
       return dp[amount];
   }
};

****************************************************************************************************
// STRIVER:
// Memoised solution: (Leetcode)

int solve(int ind, int target, vector<int> &coins, vector<vector<int>> &dp){
    if(ind==0){
        return (target%coins[0]==0);                   // whenever u come to zero index, u can pick it any number of times if it completely divides the target
    }

    if(dp[ind][target]!= -1) return dp[ind][target];

    int notTake = solve(ind-1, target, coins, dp);
    int take = 0;
    if(coins[ind]<=target){
        take = solve(ind, target-coins[ind], coins, dp);
    }
    return dp[ind][target] = take + notTake;
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>>dp(n, vector<int>(amount+1, -1));
    return solve(n-1, amount, coins, dp);
}

// Tabulated of above memoised

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));

        // for any given target which I was returning I will take it and store it in my state
        // base case
        for(int t=0; t<=amount; t++) dp[0][t] = (t%coins[0]==0);

        for(int ind=1; ind<n; ++ind){
            for(int t=0; t<=amount; ++t){
                int notTake = dp[ind-1][t];
                int take = 0;
                if(coins[ind]<=t){
                    take = dp[ind][t-coins[ind]];
                }
                dp[ind][t] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};

// Space optimised
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), cur(amount+1, 0);

        // for any given target which I was returning I will take it and store it in my state
        // base case
        for(int t=0; t<=amount; t++) prev[t] = (t%coins[0]==0);

        for(int ind=1; ind<n; ++ind){
            for(int t=0; t<=amount; ++t){
                int notTake = prev[t];
                int take = 0;
                if(coins[ind]<=t){
                    take = cur[t-coins[ind]];
                }
                cur[t] = take + notTake;
            }
            prev = cur;
        }
        return prev[amount];
    }
};
