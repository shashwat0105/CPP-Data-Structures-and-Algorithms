https://leetcode.com/problems/subarray-sum-equals-k/

// subarray[L ... R] = pref[R] - pref[L-1]
// Explanation: we keep an accumulator variable sum with the running total of the sum of numbers; 
// we then check if we have already met that values using our seen hashmap that acts more or less like a frequency table, 
// storing how many times we have encountered a specific value: sum - k.
// That is why if have met sum - k before and now the value is sum, the difference between those specific points and the current iteration is, by definiton, exactly k: 
// we are now at sum, so, the interval between the previous point(s) and now sums up to, by definition, sum - (sum - k), which equates k.
// We collect all those occurrences in count and finally we return it.

https://leetcode.com/problems/subarray-sum-equals-k/discuss/301242/General-summary-of-what-kind-of-problem-can-cannot-solved-by-Two-Pointers

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res=0;                             // number of found subarray
        int pref = 0;                          // cumulated sum
        unordered_map<int, int> countPref;     // prefix sum recorder
        countPref[0]++;
        
        for(int i=0; i<n; i++){
            pref += nums[i];
            int target = pref - k;
            res += countPref[target];
            countPref[pref]++;
        }
        return res;
    }
};
