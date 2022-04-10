https://leetcode.com/problems/subsets/

https://youtu.be/u0e29JIdxZU


(Backtracking step is used)
// Recursion and backtracking method:
// TC = O(N*2^N), SC = O(2^N)

class Solution {
public:
    vector<vector<int>> ans;    //(Generally not a good practice to declare globally, pass it by refernce in the solve function and declare inside subsets function)

    void solve(int i, vector<int> &nums, vector<int> &op){     // here I am making changes in the same element. So, I need to backtrack
        if(i==nums.size()){
            ans.push_back(op);
            return;
        }
        
        // ith element not in subset
        solve(i+1, nums, op);

        // ith element in the subset
        op.push_back(nums[i]);
        solve(i+1, nums, op);
        op.pop_back();         // backtracking step (To undo the change that you have made while taking a particular decision)  (You pop in the case you have included it)
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        solve(0, nums, op);
        return ans;
    }
};


// using previous method by making copies (This one takes extra space as well as extra time, so above is better)
class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int> ip, vector<int> op){       // here, if you pass by refernce ie & you will get wrong ans and this code is solving by making copies.
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

