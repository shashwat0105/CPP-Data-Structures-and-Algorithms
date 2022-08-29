https://leetcode.com/problems/longest-increasing-subsequence/

// Classical Problem!! (LIS)

// Till date the best discuss I guess
https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326552/Optimization-From-Brute-Force-to-Dynamic-Programming-Explained!


// Kartik Arora (Other than binary search solution is there too)
https://youtu.be/wqLwv7E1GF0

// Striver has also taught this.


// Recursive 
// Take, Not take   // traversing from back
class Solution {
public:
    int util( vector<int> nums, int index, int cv){   // cv is current min value
        // end condition
        if( index == 0 ){                           // if( index < 0 ) return 0;  // Alternate base condition
            if( nums[index] < cv ) return 1;
            else return 0;
        }
        
        // logic
        int q1 = 0, q2 = 0;
        if( nums[index] < cv ){
            q1 = 1 + util(nums, index-1, nums[index]);
        }
        q2 = util( nums, index-1, cv);
        return max(q1, q2);
    }
    int lengthOfLIS(vector<int>& nums) {
        return util(nums,nums.size()-1, INT_MAX);
    }
};

// DP

dp[i] denotes the LIS ending at index i

