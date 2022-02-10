https://leetcode.com/problems/subarray-sums-divisible-by-k/

// The ques is different from subarray sum as k in two ways:
// 1) According to question:
    //   (pref - targetRemainder)%k = 0
    //    pref = mk + targetRemainder
    //    targetRemainder = pref%k

    //    Now, if pref is negative:
    //    targetRemainder = pref%k + k
    //    To make it in range of <k for positive numbers finally:
    //    targetRemainder = (pref%k + k)%k

// 2) We will store targetRemainder instead of pref sum in our map.

// We can also say the conclusion as two pref having same remainders contains the desired subarray.


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
            int targetRemainder = (pref%k + k)%k;   
            
            res += countPref[targetRemainder];
            countPref[targetRemainder]++;
        }
        return res;
    }
};