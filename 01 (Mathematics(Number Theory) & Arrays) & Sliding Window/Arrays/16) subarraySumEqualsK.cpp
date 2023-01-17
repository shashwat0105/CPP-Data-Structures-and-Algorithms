https://leetcode.com/problems/subarray-sum-equals-k/

// subarray[L ... R] = pref[R] - pref[L-1]
// Explanation: we keep an accumulator variable sum with the running total of the sum of numbers; 
// we then check if we have already met that values using our seen hashmap that acts more or less like a frequency table, 
// storing how many times we have encountered a specific value: sum - k.
// That is why if have met sum - k before and now the value is sum, the difference between those specific points and the current iteration is, by definiton, exactly k: 
// we are now at sum, so, the interval between the previous point(s) and now sums up to, by definition, sum - (sum - k), which equates k.
// We collect all those occurrences in count and finally we return it.

https://assets.leetcode.com/users/spyashu/image_1541604212.png

// Target is another small prefix sum, which checks if Bigger prefix sum - k exists in the hashmap.
// pref - target is the sum of that subarray
https://leetcode.com/problems/subarray-sum-equals-k/discuss/301242/General-summary-of-what-kind-of-problem-can-cannot-solved-by-Two-Pointers

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt=0;                             // number of found subarray
        int pref = 0;                          // cumulated sum
        unordered_map<int, int> countPref;     // prefix sum recorder
        countPref[0]++;                        // in the initial state , we already have a sum of 0, so we need to record this prefix sum of 0 in our map with an occurrence of 1 before we iterate thru the array.
                                               // yeh isliye kiya hai ki agar future m prefix sum = k ho ie target = 0 ho. yeh bhi ek valid ans hai. ie to detect subarrays with sum equal k and starting with 0 index.
                                               // nahi toh if(sum==k) cnt++ ek extra line likh dena
        for(int i=0; i<n; i++){
            pref += nums[i];
            int target = pref - k;
             
            cnt += countPref[target];
            countPref[pref]++;
        }   
        return cnt;
    }
};

// OR
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res=0;
        int sum = 0;
        unordered_map<int, int> m;
        // m[0]++;
        for(int i=0; i<n; ++i){
            sum+=nums[i];
            if(sum==k) res++;
            int target = sum-k;
            res+=m[target];
            m[sum]++;
        }
        return res;
    }
};
