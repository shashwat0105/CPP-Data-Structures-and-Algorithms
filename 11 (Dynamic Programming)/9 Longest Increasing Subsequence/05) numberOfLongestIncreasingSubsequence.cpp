https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

Explanation:
array:  1 5 4 3 2 6 7 10 8 9 
length: 1 2 2 2 2 3 4 5 5 6 
count:  1 1 1 1 1 4 4 4 4 4

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1); 
        int maxi=1;
        for(int i=0; i<n; ++i){
            for(int prev=0; prev<i; ++prev){
                if(nums[prev] < nums[i] && 1+dp[prev]>dp[i]){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];  // inherit the same
                }
                else if(nums[prev] <nums[i] && 1+dp[prev]==dp[i]){ // u got another guy that gives u the same value
                    cnt[i]+=cnt[prev];
                }
            }
            maxi=max(maxi, dp[i]);
        }
        int noOfLIS = 0;
        for(int i=0; i<n; ++i){
            if(dp[i]==maxi) noOfLIS+=cnt[i];
        }
        return noOfLIS;
    }
};
