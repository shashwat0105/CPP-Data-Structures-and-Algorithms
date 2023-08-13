https://leetcode.com/problems/jump-game/

// Kadane's algo O(N) Time, O(1) space
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        
        for(int i=0; i<n; i++){
            if(farthest < i) return false;
            farthest = max(farthest, i+nums[i]);
        }
        return farthest>=n-1;
    }
};
