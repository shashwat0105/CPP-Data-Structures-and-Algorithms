https://leetcode.com/problems/subarray-sums-divisible-by-k/




class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int res=0;                             // number of found subarray
        int pref = 0;                          // cumulated sum
        unordered_map<int, int> countPref;     
        countPref[0]++;                        
        
        for(int i=0; i<n; i++){
            pref += nums[i];
            int remainder = (pref%k + k)%k;
            
            res += countPref[target];
            countPref[target]++;
        }
        return res;
    }
};