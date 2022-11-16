https://leetcode.com/problems/partition-array-for-maximum-sum/description/

Tagda sawal!

Front partition logic will be used.

Various ways: try all the ways: take best

Try out all the partition from the index.

// Inside a partition I need to keep track of max element.
// And among various possible partitions 1, 2,,,,k-1, k I will keep track of maxAns.

TC = O(N*K)

// 

class Solution {
public:
    int solve(int ind, vector<int>& arr, int k, vector<int> &dp){
        int n = arr.size();
        if(ind==n) return 0;

        if(dp[ind]!= -1) return dp[ind];

        int len = 0; // number of elements inside a partition
        int maxi = -1e9;
        int maxAns = -1e9;
        for(int j=ind; j<min(n, ind+k); ++j){ // j either moves k steps or n so that it doesn't crosses boundary in last index
            len++;
            maxi = max(maxi, arr[j]);  // for every new partition
            int sum = len*maxi + solve(j+1, arr, k, dp); // new ind will become next element after the partition.
            maxAns = max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, k, dp);
    }
};

// Tabulation
same steps

//
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        dp[n] = 0;
        for(int ind=n-1; ind>=0; --ind){
            int len = 0; // number of elements inside a partition
            int maxi = -1e9;
            int maxAns = -1e9;
            for(int j=ind; j<min(n, ind+k); ++j){ // j either moves k steps or n so that it doesn't crosses boundary in last index
                len++;
                maxi = max(maxi, arr[j]);  // for every new partition
                int sum = len*maxi + dp[j+1]; // new ind will become next element after the partition.
                maxAns = max(maxAns, sum);
            }
            dp[ind] = maxAns;
        }
        return dp[0];
    }
};
