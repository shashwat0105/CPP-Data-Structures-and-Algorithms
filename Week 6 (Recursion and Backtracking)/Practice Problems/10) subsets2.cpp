https://leetcode.com/problems/subsets-ii/

// TC = 2^n*2^n*logn  (Due to insertion of every element in map or set)

class Solution {
public:
    map<vector<int>, int> m; 
    void solve(int i, vector<int> &ip, vector<int> &op, vector<vector<int>> &ans){
        if(i==ip.size()){
            m[op]++;
            if(m[op]==1){
                ans.push_back(op);
            }
            return;
        }
        
        solve(i+1, ip, op, ans);
        
        op.push_back(ip[i]);
        solve(i+1, ip, op, ans);
        op.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        sort(nums.begin(), nums.end());          // sorting is imp so that map stores unique.
        solve(0, nums, op, ans);
        return ans;
    }
};

// this ques is same as string given aab wala ques

// More optimised method for TC:


