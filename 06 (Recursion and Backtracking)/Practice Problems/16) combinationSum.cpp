https://leetcode.com/problems/combination-sum/

// Given array elements are unique.
// And we can use elements any number of time.

// If repetition of array elements was NOT allowed
// And array elements are unique then this code works well.
class Solution {
public:
    void solve(int i, vector<int> &ip, vector<int> &op, int target, vector<vector<int>> &ans){
        if(i==ip.size()){
            if(target==0){
                ans.push_back(op);        // exponential * linear(of this step) = total time complexity
            }
            return;
        }
        
        // ith element not in subset
        solve(i+1, ip, op, target, ans);
        
        // ith element in subset
        op.push_back(ip[i]);
        solve(i+1, ip, op, target-ip[i], ans);
        op.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(0, candidates, op, target, ans);
        return ans;
    }
};


// Original ques
// ie array elements can be used any number of times(repetition of array elements allowed)

class Solution {
public:
    void solve(int i, vector<int> &ip, vector<int> &op, int target, vector<vector<int>> &ans){   // we can also do this by using just sum ie by decreasing it
        if(target<0) return;                 // known as early stopping
        if(i==ip.size()){
            if(target==0){
                ans.push_back(op);
            }
            return;
        }
        
        // ith element not in subset
        solve(i+1, ip, op, target, ans);
        
        // ith element in subset
        if(ip[i]<=target){                   // since there is no terminating in stack calls, we call this function on in this if condition (to handle use of one element multiple times)
            op.push_back(ip[i]);
            solve(i, ip, op, target-ip[i], ans);
            op.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(0, candidates, op, target, ans);
        return ans;
    }
};

// Approach 2: 
// Interation Inside recursion solution(recursion + for loop)
https://leetcode.com/problems/combination-sum/solutions/1777569/full-explanation-with-state-space-tree-recursion-and-backtracking-well-explained-c/
// See the tree:
// I can start with 0th index, 1st Index, 2nd Index...

class Solution {
    void combination(vector<int>& ip, int target, vector<int> &op, int currIndex, vector<vector<int>>& ans){
        if(target<0) return; 
        if(target==0){
            ans.push_back(op); 
            return;
        }
        
        for(int i=currIndex; i<ip.size(); i++){ // try all possible options for the next level // currIndex is the level
            op.push_back(ip[i]);                // put 1 option into the combination // Yeh push krne se hi level badhegi
            combination(ip, target-ip[i], op, i, ans); // try with this combination, whether it gives a solution or not. // i is same because I can chose the same element again in the next level.
            op.pop_back();                      // when this option backtrack to here, remove this and go on to the next option.
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        combination(candidates, target, op, 0, ans);
        return ans;
    }
};
