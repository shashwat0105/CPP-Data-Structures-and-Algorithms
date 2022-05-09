https://leetcode.com/problems/combinations/

class Solution {
public:
    void solve(int idx, int n, int k, vector<int> &op, vector<vector<int>> &ans){
        if(op.size()==k){
            ans.push_back(op);
            return;
        }
        
        for(int i=idx; i<=n; ++i){
            op.push_back(i);
            solve(i+1, n, k, op, ans);
            op.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> op;
        
        solve(1, n, k, op, ans);
        return ans;
    }
};
