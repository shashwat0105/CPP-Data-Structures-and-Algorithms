https://leetcode.com/problems/subarray-sums-divisible-by-k/

https://youtu.be/7Xeorb721LQ (code story with mik)

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

---s1------
a b c d e f g h i
--s2---

Given that after dividing s1 with k remainder is x
as well as after dividing s2 with k remainder is x
Then we can say that s1-s2 is completely divisible by k

Proof:
// s1 = kn + x
// s2 = kn' + x
// s1-s2 = k(n-n') = kn'' ie divisible by k (hence proved)

Map:
remainder ->count 
0 -> 1  // Initially sum is 0 and 0%k is 0 ie 0 remainder apan dekh chuke starting m hi

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int res=0;                             // number of found subarray
        int pref = 0;                          // cumulated sum
        unordered_map<int, int> countPrefRemainder;     
        countPrefRemainder[0]++;                        
        
        for(int i=0; i<n; i++){
            pref += nums[i];
            int targetRemainder = (pref%k + k)%k;   
            
            res += countPrefRemainder[targetRemainder];
            countPrefRemainder[targetRemainder]++;
        }
        return res;
    }
};