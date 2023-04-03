https://leetcode.com/problems/subsets/
All the numbers of nums are unique.

https://youtu.be/u0e29JIdxZU  (LUV - Pick not pick method)


(Backtracking step is used)
// Recursion and backtracking method:
// TC = O(N*2^N) // This extra time is as we are putting one data structure inside another wo constant time m nahi ho jata hai
// SC = O(2^N)

class Solution {
public:

    void solve(int i, vector<int> &nums, vector<int> &op, vector<vector<int>> &ans){     // here I am making changes in the same element. So, I need to backtrack
        if(i==nums.size()){
            ans.push_back(op);
            return;
        }
        
        // ith element not in subset (Not Pick)
        solve(i+1, nums, op, ans);

        // ith element in the subset (Pick)
        op.push_back(nums[i]);
        solve(i+1, nums, op, ans);
        op.pop_back();         // backtracking step (To undo the change that you have made while taking a particular decision)  (You pop in the case you have included it)
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(0, nums, op, ans);
        return ans;
    }
};


// Using previous method by making copies (This one takes extra space as well as extra time, so above is better)
class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int> ip, vector<int> op){       // here, if you pass by refernce ie & you will get wrong ans as this code is solving by making copies.
        if(ip.size()==0){
            ans.push_back(op);
            return;
        }
        
        vector<int> op1 = op;
        vector<int> op2 = op;
        
        op2.push_back(ip[0]);
        ip.erase(ip.begin());
        
        solve(ip, op1);
        solve(ip, op2);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        solve(nums, op);
        return ans;
    }
};


// Approach 2: Recursive + Iterative: (explanantion in combination sum 2)
// TC = O(2^n*n)
// mtlb first element tmhra index 0 ka ho skta hai, index 1 ka, 2 ka so on. ie tree ki kai branches ban gyi so for loop.
// Base case: every recursion call node gives us a subset.(not just leaf nodes)

class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int>& op, vector<vector<int>> &ans){
        ans.push_back(op);

        for(int i=idx; i<nums.size(); ++i){
            op.push_back(nums[i]);
            solve(i+1, nums, op, ans);
            op.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(0, nums, op, ans);
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




