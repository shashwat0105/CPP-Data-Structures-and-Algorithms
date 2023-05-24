https://leetcode.com/problems/subsets-ii/

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// TC = 2^n*2^n*logn  (Due to insertion of every element in map or set) (Interviewer wont be happy with this set/map approach)

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
        
        // not pick
        solve(i+1, ip, op, ans);
        
        // pick
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

// More optimised method for TC: (Similar to combination sum 2 // can see explanation there)
// 3X faster code:
https://youtu.be/RIn3gOkbhQE  (Striver)

// In this we do by size, ie possible subsets of size 0, then 1, then 2 and so on.

// TC = 2^N
// SC = 2^N*k

// First level of recursion make sure empty subset is generated
// Second level of recursion make sure all subsets of size 1 are generated
// Third level of recursion make sure all subsets of size 2 are generated...
// Base case:
// Ar har call pe hame ek subset mil rha hai toh use apan directly push kr dete hai.(Yaha pe leaf node pe sirf hamara ans nahi hota hai, har node pe ans hota hai)
// Combination sum m bhi har node m ans hota hai usko check krte hai

class Solution {
private:
    void findSubsets(int ind, vector<int> &ip, vector<int> &op, vector<vector<int>> &res){
        res.push_back(op);
        
        for(int i=ind; i<ip.size(); i++){
            if(i!=ind && ip[i]==ip[i-1]) continue;            // same level ko fill kr rhe hai, wo kisi different index pe ho ar equal ho toh usko pick nahi kr skte.
            op.push_back(ip[i]);
            findSubsets(i+1, ip, op, res);
            op.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> op;
        sort(nums.begin(), nums.end());                       // to get duplicates side by side.(come together)
        findSubsets(0, nums, op, res);
        return res;
    }
    
};

// In GFG
https://practice.geeksforgeeks.org/problems/subsets-1587115621/1

// Unique + lexicographical order
