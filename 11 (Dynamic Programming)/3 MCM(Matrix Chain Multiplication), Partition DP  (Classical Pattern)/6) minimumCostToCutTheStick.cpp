https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

In the first cut at any position, the cost will be the length of the stick.

Also need to sort the array so that the cuts become independent of the partition.

Cuts array 
0 1 3 4 5 7
  i     j
If I want to make a cut at 7, then cost will be cuts[j+1]-cuts[i-1] ie 7-0=7

i      ind-1  ind ind+1    j   // made a partition at ind

// Memoised

class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j]!= -1) return dp[i][j];

        long mini = 1e9;
        for(int k=i; k<=j; ++k){
            long totCost = cuts[j+1]-cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp);
            mini = min(mini, totCost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();          // better to calculate in the start itself.

        cuts.push_back(n);            // last partition   
        cuts.insert(cuts.begin(), 0); // first partition
        // cuts now has 2 extra elements
        sort(cuts.begin(), cuts.end());

        // vector<vector<int>> dp(n+4,vector<int> (n+4,-1)); ⭐ 
        vector<vector<int>> dp(c+1,vector<int> (c+1,-1));
        return solve(1, c, cuts, dp);
    }
};

// TC = O(N^3)

// Tabulated:

f(1, c) is called in memoised
  i  j

Memoised
i: 1 to c
Tabulation
i: c to 1
j: 1 to c

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();  

        cuts.push_back(n);            // last partition   
        cuts.insert(cuts.begin(), 0); // first partition
        // cuts now has 2 extra elements
        sort(cuts.begin(), cuts.end());
        // vector<vector<int>> dp(n+4,vector<int> (n+4,-1)); ⭐ 
        vector<vector<int>> dp(c+2,vector<int> (c+2,0)); // to increase the size for safety

        // base case no need everything 0(karna padega handle)
        // i>j = 0; // there can be multiple values of i and j. // we will handle this later

        for(int i=c; i>=1; --i){
            for(int j=1; j<=c; ++j){
                if(i>j) continue;       // Note this is important to write else error
                long mini = 1e9;
                for(int k=i; k<=j; ++k){
                    long totCost = cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, totCost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};


// 
TC = O(N^3)
SC = O(N^2)
