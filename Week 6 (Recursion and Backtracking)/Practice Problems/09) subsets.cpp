https://leetcode.com/problems/subsets/

https://youtu.be/u0e29JIdxZU


(Backtracking step is used)
// Recursion and backtracking method:
// TC = O(N*2^N), SC = O(2^N)
(Have to compare both the questions)

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int> &nums, vector<int> &op){
        if(i==nums.size()){
            ans.push_back(op);
            return;
        }
        
        // ith element not in subset
        solve(i+1, nums, op);
        // ith element in the subset
        op.push_back(nums[i]);
        solve(i+1, nums, op);
        op.pop_back();         // backtracking step
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        solve(0, nums, op);
        return ans;
    }
};

// Another video for future:
https://youtu.be/1BbeOUkUOak
(Recursive and iterative solution)

https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation

// Iterative code

// Using Bit Manipulation 
https://youtu.be/gUxpKm0btH0
















// Other variation
https://practice.geeksforgeeks.org/problems/subsets-1587115621/1

// Unique + lexicographical order

