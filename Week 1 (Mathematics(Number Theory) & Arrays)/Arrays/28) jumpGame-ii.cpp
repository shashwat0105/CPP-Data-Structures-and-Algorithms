https://leetcode.com/problems/jump-game-ii/

// https://youtu.be/dJ7sWiOoK7g

// By Dynamic programming O(n^2)
// By greedy bfs O(n)

// Two pointers left and right that record the current range of the starting nodes. ie range of the current jump is [left, right]
// Farthest is the farthest point that all points in [left, right] can reach
// Each time after we make a move, update left to be right + 1 and 
// right to be the farthest index that can be reached in 1 move from the current [left, right].


class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        
        while(right<n-1){
            int farthest = 0;
            for(int i=left; i<right+1; i++){
                farthest = max(farthest, i+nums[i]);
            }
            left = right+1;
            right = farthest;
            res++;
        }
        return res;
    }
};


// Other code that passes
// Once the current point reaches right, then trigger another jump, and set the new right with farthest

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int right = 0;
        int n = nums.size();
        int farthest = 0;
        
        for(int i=0; i<n-1; i++){
            farthest = max(farthest, i+nums[i]);
            if(i==right){
                res++;
                right = farthest;
            }
        }
        return res;
    }
};

