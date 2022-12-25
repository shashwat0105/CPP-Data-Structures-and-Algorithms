https://leetcode.com/problems/jump-game/

// Greedy O(n)
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


// OR
// we move from last element and shift it to left accordingly and check if we can reach at the start position
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n-1;
        for(int i=n-2; i>=0; i--){
           if(i+nums[i]>=goal){        // from a left element we can reach an element right to it ie the goal
               goal = i;
           }
        }
        // if(goal==0) return true;
        // return false;
        return goal==0;
    }
};

