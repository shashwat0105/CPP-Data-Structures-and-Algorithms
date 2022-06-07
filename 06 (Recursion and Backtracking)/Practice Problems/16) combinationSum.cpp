https://leetcode.com/problems/combination-sum/

// If repetition of array elements was NOT allowed
// And array elements are unique then this code works well.
class Solution {
public:
    void solve(int i, vector<int> &ip, vector<int> &op, int s, int sum, vector<vector<int>> &ans){
        if(i==ip.size()){
            if(s==sum){
                ans.push_back(op);        // exponential * linear(of this step) = total time complexity
            }
            return;
        }
        
        // ith element not in subset
        solve(i+1, ip, op, s, sum, ans);
        
        // ith element in subset
        op.push_back(ip[i]);
        s+=ip[i];
        solve(i+1, ip, op, s, sum, ans);
        op.pop_back();
        s-=ip[i];
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        int s=0;
        solve(0, candidates,op, s, target, ans);
        return ans;
    }
};


// Original ques
// ie array elements can be used any number of times

class Solution {
public:
    void solve(int i, vector<int> &ip, vector<int> &op, int s, int sum, vector<vector<int>> &ans){   // we can also do this by using just sum ie by decreasing it
        if(i==ip.size()){
            if(s==sum){
                ans.push_back(op);
            }
            return;
        }
        
        // ith element not in subset
        solve(i+1, ip, op, s, sum, ans);
        
        // ith element in subset
        if(ip[i]<=sum-s){                   // since there is no terminating in stack calls, we call this function on in this if condition (to handle use of one element multiple times)
            op.push_back(ip[i]);
            s+=ip[i];
            solve(i, ip, op, s, sum, ans);
            op.pop_back();
            s-=ip[i];                       // this line doesn't matter as it is not passed by refernce and will not reflect. But if this block is used first then since s has to be used later we have to change it back.
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        int s=0;
        solve(0, candidates,op, s, target, ans);
        return ans;
    }
};


// using single variable sum

void solve(int i, vector<int> &ip, vector<int> &op, int sum, vector<vector<int>> &ans){   // we can also do this by using just sum ie by decreasing it
    if(i==ip.size()){
        if(sum==0){
            ans.push_back(op);
        }
        return;
    }
    
    // ith element not in subset
    solve(i+1, ip, op, sum, ans);
    
    // ith element in subset
    if(ip[i]<=sum){
        op.push_back(ip[i]);
        solve(i, ip, op, sum-ip[i], ans);   
        op.pop_back();
    }
    
}