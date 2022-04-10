https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

// To interviewer
// Brute force using bit manipulation TC = O(2^N*k)

// Optimised using our known recursion
class Solution{
public:
    void solve(int i, vector<int> &ip, vector<int> &op, vector<int> &ans){
        if(i==ip.size()){
            int sum=0;
            for(auto it: op) sum+=it;
            ans.push_back(sum);
            return;
        }
        
        // not pick
        solve(i+1, ip, op, ans);
        
        // pick
        op.push_back(ip[i]);
        solve(i+1, ip, op, ans);
        op.pop_back();
    }

    vector<int> subsetSums(vector<int> arr, int N){
        // Write Your Code here
        vector<int> ans;
        vector<int> op;
        solve(0, arr, op, ans);
        return ans;
    }
};

