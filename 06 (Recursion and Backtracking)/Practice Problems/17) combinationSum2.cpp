https://leetcode.com/problems/combination-sum-ii/

// Candidate array has repeated elements.
// And we can use 1 element once.

https://youtu.be/G1fRTGRxXU8 (Striver)

// (On modifying code from previous problem there is time complexity issue ie TLE) The extra log insertion in map causes TLE
class Solution {
public:
    map<vector<int>,int> m;
    void solve(int i, vector<int> &ip, vector<int> &op, int sum, vector<vector<int>> &ans){
        if(sum<0) return;
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


// To solve array problems there are 2 patterns, one is pick and not pick that is above. Other is below
// OPTIMISED APPROACH TC = 2^n * k
// recursion + for loop
// Instead of pick, not pick we will try to pick subsequences.
// I can start with 0th index, 1st Index, 2nd Index...  as first element.
// ie our tree will look like:
// [1 1 1 2 2]
        f(0, 4, ds)
      /     /    \    \ 
    0th    1st   2nd   3rd
   index  Index Index  Index  as first element.

// Is for loop ka mtlb levels hai
// Level means I am at which index.
// Level 1: I am filling the 0th index in op, can I pick the 0th index from ip, can I pick the 1st index, 2nd index and so on.
// Level 2: I am filling the 1st index in op, can I pick the 1st index from ip, can I pick the 2nd index, 3rd index.  
// Level 3: I am filling the 2nd index in op, can I pick 3rd, 4th...
// Level 4: I am filling the 3rd index in op, can I pick 4th, ...

// Base case: ip==size hone pe ie leaf node pe sirf ans nahi hota, har node pe ans hota hai is approach mein. Toh har node pe apan dekhte hai ki kya target 0 ho gya is subset se.

class Solution {
public:
    void solve(int ind, vector<int> &ip, vector<int> &op, int sum, vector<vector<int>> &ans){
        if(sum==0){
            ans.push_back(op);
            return;
        }
        
        for(int i=ind; i<ip.size(); i++){             // Ki which one I can pick as next element(levels)       
            if(i!=ind && ip[i]==ip[i-1]) continue;     // [1 1 1 2 2] If I pick first 1 as first element then I skip other 1s as first element because that will give me repetitive ans. i!=ind : say ind = 0 and u are filling i=0 I can chose 1(i==ind) but again for i=1 I cannot chose 1(i!=ind) again ki first element qki 1 ho gya na baar baar thodi na lenge ek hi level k liye. ie  // same level ko fill kr rhe hai, agra element kisi different index pe ho ar equal ho toh usko pick nahi kr skte.
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
// The revursive component tries the elements after the current one and also tries duplicate elements. So we can get correct answer for cases like [1 1] 2.
// The iterative component checks duplicate combinations and skip it if it is. So we can get correct answer for cases like [1 1 1] 2.
