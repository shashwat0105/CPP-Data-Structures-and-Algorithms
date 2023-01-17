https://leetcode.com/problems/number-of-ways-to-split-array/description/


class Solution {
public:
// Python implementation : https://leetcode.com/problems/number-of-ways-to-split-array/solutions/2038541/python-easily-explained-brute-force-to-optimized/

    // O(1) space solution
    // we are using a running sum here for efficiency.
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum =accumulate(nums.begin(),nums.end(),0LL);
        long long curSum = 0;
        int ans = 0;
        for(int i=0; i<nums.size()-1; ++i){
            curSum += nums[i];
            if(totalSum-curSum <= curSum) ans++;
        }
        return ans;
    }

// We will first store the sum in a variable (suffixSum). Now suppose if we are needed to check for a particular nums[i], we will calculate the sum of elements till that index i and store them in any variable (prefixSum). Now, we will first remove that nums[i] from suffixSum and then, if prefixSum >= suffixSum, we got our first validSplit....
// Similar code
//     int waysToSplitArray(vector<int>& nums) {
//         long long presum = 0, suffsum = 0;
//         int cnt = 0;
//         for(int i = 0; i < nums.size(); i++) suffsum+= nums[i];// Storing the sum of elements in suffixsum
//         for(int j = 0; j < nums.size()-1; j++){//Running the loop till n-2 to keep a element always on the right side
//             presum += nums[j];//Storing the sum of elements till index i in prefixsum (// sum of the first i + 1 elements)
//             suffsum -= nums[j]; //Removing num[j] from suffixSum (// sum of the last n - i - 1 elements.)
//         //Comparing if presum >= suffsum, increase count
//             if(presum >= suffsum) cnt++;
//         }
//         return cnt;
//     }
};

