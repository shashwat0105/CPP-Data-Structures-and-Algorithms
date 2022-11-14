https://leetcode.com/problems/largest-divisible-subset/descriptio

"subset"
// Order doesn't matter ie "I can sort the array as well" :CRUX

"Print any ans"

{1, 4, 7, 8 , 16}
// If {1, 4, 8} : I pick 16 and it is divisible by 8 then it is divisible by 4, 1 as well ie all previous elements as the array is sorted

// After sorting: Longest divisible subsequence
// Now instead of picking greater element, I will check if its divisible.

// LIS Code
for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
        if(arr[j]<arr[i] && dp[i]<dp[j] + 1){  // Instead of arr[j]>arr[i] I will check for divisible ie arr[i]%arr[j]==0
            dp[i] = dp[j] + 1;
            hash[i] = j;
        }
    }
}

// Since we want to print hence we will use the hash code of LIS

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n, 1);
        int maxi = 1;
        int lastIndex = 0;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; ++i){
            hash[i] = i;
            for(int prev = 0; prev<i; ++prev){
                if(nums[i]%nums[prev]==0 && 1 + dp[prev]>dp[i]){  // change here
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// TC = O(n^2 + n + nlogn)


