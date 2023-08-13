// https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/
// Multiple occurences of same item is allowed

// For example:- The item is icecream:- 
// 1) I dont like icecream -> So, I WON'T take it regardless of the number of times you offer me. (Processed)
// 2) I like icecream -> I can take it any number of times you offer me. (Unprocessed)

// 0/1 -> Item -> 1) Taken -> Processed -> n-1 -> i-1
//                2) Not Taken -> Processed -> n-1 -> i-1
// unbounded -> Item -> 1) Taken -> Unprocessed -> n -> i  (Here is the code variation only) ie agar lena hai toh hm usko apni array se nahi hataenge
//                      2) Not Taken -> Processed -> n-1 -> i-1    ie agar nahi lena hai toh hata denge array se


#include <bits/stdc++.h>
using namespace std;

int unboundedKnapSack(int wt[], int val[], int W, int n)
{
    int t[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            // base condition
            if (i == 0 || j == 0)    // In this base condition I do when i==0 means there is no element. Striver taught base case when ind==0 ie there is one element what will be scenario
                t[i][j] = 0;
            // choice diagram
            else if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] +
                                t[i][j - wt[i - 1]],  // the only change i-1 -> i
                                t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][W];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
     
    cout << unboundedKnapSack(wt, val, W, n);
     
    return 0;
}

*************************************************************************
// STRIVER

// Memoised: 

// base case:
// ind==0 . Think what will be the scenario?
// You have some bag limit and unlimited supply of one item. So i will fill as much as I can of that item.

int solve(int ind, int w, vector<int> &weight, vector<int> &profit, vector<vector<int>> &dp){
    if(ind==0){
        return ((int)(w/weight[0]))*profit[0]; // this much profit I can generate using 1 element
    }
    
    if(dp[ind][w]!= -1) return dp[ind][w];
    
    int notTake = solve(ind-1, w, weight, profit, dp);
    int take = -1e9;
    if(weight[ind]<=w){
        take = profit[ind] + solve(ind, w-weight[ind], weight, profit, dp);
    }
    return dp[ind][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int maxw, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int> (maxw+1, -1));
    return solve(n-1, maxw, weight, profit, dp);
}

// Tabulated

int unboundedKnapsack(int n, int maxw, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int> (maxw+1, 0));
    
    // base case
    for(int w=0; w<=maxw; w++){
        dp[0][w] = ((int)(w/weight[0]))*profit[0];   // copy paste from memo base case
    }
    
    for(int ind=1; ind<n; ++ind){                   // number of loops = number of states(changing parameters)
        for(int w=0; w<=maxw; ++w){                 
            int notTake = dp[ind-1][w];             // copy paste from above 6 lines
            int take = -1e9;
            if(weight[ind]<=w){
                take = profit[ind] + dp[ind][w-weight[ind]];
            }
            dp[ind][w] = max(take, notTake);
        }
    }
    return dp[n-1][maxw];
}

// Space optimised

int unboundedKnapsack(int n, int maxw, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> prev(maxw+1, 0), cur(maxw+1, 0);
    // base case
    for(int w=0; w<=maxw; w++){
        prev[w] = ((int)(w/weight[0]))*profit[0];   // copy paste from memo base case
    }
    
    for(int ind=1; ind<n; ++ind){
        for(int w=0; w<=maxw; ++w){   // copy paste from above 
            int notTake = prev[w];
            int take = -1e9;
            if(weight[ind]<=w){
                take = profit[ind] + cur[w-weight[ind]];
            }
            cur[w] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[maxw];
}

// 1 array only
// We need one element from prev ie prev[w] and some element to the left of same row.

int unboundedKnapsack(int n, int maxw, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> prev(maxw+1, 0);
    // base case
    for(int w=0; w<=maxw; w++){
        prev[w] = ((int)(w/weight[0]))*profit[0];   // copy paste from memo base case
    }
    
    for(int ind=1; ind<n; ++ind){
        for(int w=0; w<=maxw; ++w){   // copy paste from above 
            int notTake = prev[w];
            int take = -1e9;
            if(weight[ind]<=w){
                take = profit[ind] + prev[w-weight[ind]];
            }
            prev[w] = max(take, notTake);
        }
    }
    return prev[maxw];
}

