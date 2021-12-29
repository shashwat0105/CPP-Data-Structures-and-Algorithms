https://leetcode.com/problems/squares-of-a-sorted-array/

// TC : O(nlogn)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums[i] = nums[i] * nums[i];
        }
        
        sort(nums.begin(), nums.end());
        
        return nums;
    }
};

// TC = O(n)
// https://leetcode.com/problems/squares-of-a-sorted-array/discuss/495394/C%2B%2B%3A-Simplest-one-pass-two-pointers

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        int l=0;
        int r=n-1;
        
        for(int i=0; i<n; i++){
            if(abs(nums[l]) > abs(nums[r])){
                res[n-i-1] = nums[l] * nums[l++];
                // l++;                                   // to clear doubt why this is wrong
            }
            else
                res[n-i-1] = nums[r] * nums[r--];
                // r--;
        }
        return res;
    }
};

