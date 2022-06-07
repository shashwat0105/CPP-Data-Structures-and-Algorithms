https://leetcode.com/problems/combination-sum-ii/

https://youtu.be/G1fRTGRxXU8

// (On modifying code from previous problem there is also time complexity issue ie TLE)
class Solution {
public:
    map<vector<int>,int> m;
    void solve(int i, vector<int> &ip, vector<int> &op, int sum, vector<vector<int>> &ans){
        if(i==ip.size()){
            if(sum==0){
                //sort(op.begin(), op.end());  (op is passed by reference and i was changing op by sorting it that is causing problem) (this line caused wrong ans, instead I sorted candidates vector in primary function itself)
                m[op]++;                         // map ya set mein daalne se time ar badh rha hai
                if(m[op]==1){
                    ans.push_back(op);
                }
            }
            return;
        }
        
        // ith element not in subset
        solve(i+1, ip, op, sum, ans);
        
        // ith element in subset
        op.push_back(ip[i]);
        solve(i+1, ip, op, sum-ip[i], ans);
        op.pop_back();
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, op, target, ans);
        return ans;
    }
};


// To solve array problems one is pick and not pick that is above. Other is below
// OPTIMISED APPROACH
// recursion + for loop

class Solution {
public:
    map<vector<int>,int> m;
    void solve(int ind, vector<int> &ip, vector<int> &op, int sum, vector<vector<int>> &ans){
        if(sum==0){
            ans.push_back(op);
            return;
        }
        
        for(int i=ind; i<ip.size(); i++){
            if(i>ind && ip[i]==ip[i-1]) continue;     // yaha ka reason likhna hai
            if(ip[i]>sum) break;
            op.push_back(ip[i]);
            solve(i+1,ip, op, sum-ip[i], ans);       // we move to i+1 not ind+1(declared in fn call), because we are picking the ith element.
            op.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, op, target, ans);
        return ans;
    }
};


// this kind of backtracking contains a iterative component and a resursive component so 
// I'd like to give more details to help beginners save time. 
// The revursive component tries the elements after the current one and also tries duplicate elements.  So we can get correct answer for cases like [1 1] 2.
// The iterative component checks duplicate combinations and skip it if it is. So we can get correct answer for cases like [1 1 1] 2.
