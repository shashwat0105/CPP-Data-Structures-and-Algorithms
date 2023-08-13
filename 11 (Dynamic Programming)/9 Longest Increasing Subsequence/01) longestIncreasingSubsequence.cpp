https://leetcode.com/problems/longest-increasing-subsequence/description/

As we did in DP on subsequence
// Recurence
// 1) Express in terms of index
// 2) Explore all possibilities
// 3) Take the max length(take, notTake)

// In order to take a particular you need to keep track of previous element in order to compare.
// ie recurence f(ind, prev_ind)
// f(3, 0) means length of LIS starting from 3rd Index whose previous index is 0.

// notTake: prev_ind won't change and length has no increment
// take: 1) We can always take first element because it doesn't have previous.
//       2) For other elements you can only take after comparison.

// Memoisation:
// ind : 0 to n-1
// prev_ind: -1 to n-1, in 2D array how can we store -1 index
// So, I will do a coordinate right shift ie 0 to n
// ie dp[ind][prev_ind+1]

class Solution {
public:
    int solve(int ind, int prev_ind, vector<int>& nums, vector<vector<int>> &dp){
        int n = nums.size();
        if(ind>=n) return 0;

        if(dp[ind][prev_ind+1]!= -1) return dp[ind][prev_ind+1];

        // not take
        int len = 0 + solve(ind+1, prev_ind, nums, dp);
        // take
        if(prev_ind==-1 || nums[ind] > nums[prev_ind]){
            len = max(len, 1 + solve(ind+1, ind, nums, dp));  // the prev_ind will be the current ind when I take 
        }
        return dp[ind][prev_ind + 1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(0, -1, nums, dp);
    }
};

// Tabulation
// 1. Base case (Already all are zero no need to write)
// 2. ind = n-1 -> 0
//    prev_ind = ind-1 -> 0
// 3. Copy the recurence with coordinate shift

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int ind=n-1; ind>=0; --ind){
            for(int prev_ind=ind-1; prev_ind>=-1; --prev_ind){
                int len = 0 + dp[ind+1][prev_ind+1];  // whenever u do dp in prev_ind, coordinate shift so Prev_ind->prev_ind+1
                // take
                if(prev_ind==-1 || nums[ind] > nums[prev_ind]){
                    len = max(len, 1 + dp[ind+1][ind+1]);  // whenever u do dp in prev_ind, coordinate shift so ind->ind+1
                }
                dp[ind][prev_ind + 1] = len;
            }
        }
        return dp[0][-1+1];
    }
};

// Space optimised
// TC = O(N^2)
// SC = O(N) * 2

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1, 0), cur(n+1, 0);

        for(int ind=n-1; ind>=0; --ind){
            for(int prev_ind=ind-1; prev_ind>=-1; --prev_ind){
                int len = 0 + next[prev_ind+1];       // whenever u do dp in prev_ind, coordinate shift so Prev_ind->prev_ind+1
                // take
                if(prev_ind==-1 || nums[ind] > nums[prev_ind]){
                    len = max(len, 1 + next[ind+1]);  // whenever u do dp in prev_ind, coordinate shift so ind->ind+1
                }
                cur[prev_ind + 1] = len;
            }
            next = cur;
        }
        return next[-1+1];
    }
};

// A different tabulation method which is not intuitive

dp[i] = signifies the longest Increasing subsequence that ends at index i.
// Using two for loops and counting how many smaller numbers were there before this number

// LIS will be max of all dp[i]

// TC = O(n^2)
// Sc = O(n)

// THIS IS THE TEMPLATE CODE OF LIS WHICH IS USED IN OTHER VARIATIONS OF LIS

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // that number itself can atleast be part of LIS
        int maxi = 1;
        for(int i=0; i<n; ++i){
            for(int prev=0; prev<i; ++prev){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

// OR TEMPLATE

// nums[prev]<nums[i] changes according to condition.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); 
        int maxi = 1;
        for(int i=0; i<n; ++i){
            for(int prev=0; prev<i; ++prev){
                if(nums[prev] < nums[i] && 1+dp[prev]>dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};



// This solution will be required if u want to trace back LIS ie printing LIS

// Print LIS using backtrack hasharray that will store index of previous smaller element.
// Should watch DP. 42 video again while revising.

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n, 1); // that number itself can atleast be part of LIS
        int maxi = 1;
        int lastIndex = 0;

        for(int i=0; i<n; ++i){
            hash[i] = i;
            for(int prev=0; prev<i; ++prev){
                if(nums[prev] < nums[i] && 1 + dp[prev]> dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i]> maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        for(auto it: temp) cout<<it<<" ";
        cout<<endl;
        return maxi;
    }
};


// Best solution
// Binary search

https://takeuforward.org/data-structure/longest-increasing-subsequence-binary-search-dp-43/

// Should revise this video DP-43 as well

Intuition: We try inserting elements based on lower bound positions
// By replacing an element the size remains the same, though it is not an increasing subsequence now
// coz we are only concerned with size.

lower_bound: index of arr[i] or first index > arr[i]

// TC = O(N*logn)
// SC = O(N)  // Doesnot store LIS but length is same

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1; // instead of calling temp.size() at the end to save space
        for(int i=1; i<n; ++i){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);  // simply add it to LIS
                len++;
            }
            else{  // need to find its correct place
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();  // iterator needs to subtracted.
                temp[ind] = nums[i];  // gets replaced size remains the same // causes smaller elements to get inside the LIS vector
            }
        }
        return len;
    }
};
