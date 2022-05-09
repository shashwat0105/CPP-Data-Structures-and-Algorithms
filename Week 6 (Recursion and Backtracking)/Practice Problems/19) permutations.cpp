https://leetcode.com/problems/permutations/

// If we donot modify our array while going back, we will get wrong result.
// Restore our original array while going back (Backtracking)

// Method 1: With more space complexity

How will the recursion tree be?
Say [1,2,3]
// For first position we can chose either of the three (ie 3 recursive calls as will be done in loop)
// Say we have taken 1, then for the second position we can take either 2 or 3  (ie 2 sub recursive calls)
// Then for the last position we can take the remaining

// And so on for the other brances if we have taken 2 or 3

// We will take a map which will keep track of numbers which have already been taken. (Extra space that we will eliminate in future)

// TC = N!*N
// SC = O(2N)

class Solution {
public:
    void recurPermute(vector<int> &ip, vector<int> &op, vector<vector<int>> &ans, int freq[]){
        if(op.size()==ip.size()){
            ans.push_back(op);
            return;
        }
        for(int i=0; i<ip.size(); i++){
            if(!freq[i]){
                op.push_back(ip[i]);
                freq[i]=1;
                recurPermute(ip, op, ans, freq);
                freq[i]=0;                         // backtrack (while going back we unmark the frequency array)
                op.pop_back();                     // backtrack
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        // int freq[nums.size()] = {0};           // map or frequency array (pata ni yeh q nahi chal raha)
        int freq[nums.size()];                    // map or frequency array
        for(int i=0; i<nums.size(); i++) freq[i] = 0;
        recurPermute(nums, op, ans, freq);
        return ans;
    }
};


// Method 2: With lesser space complexity

https://youtu.be/f2ic2Rsc9pU

Using swapping technique
[1,2,3]
Swap 1 with 1: We get 1 at the start position
Swap 1 with 2: We get 2 at the start position

TC = O(N!*N)
SC = O(N)

class Solution {
public:
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans){
        if(index == nums.size()){              // index reaches the end
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            recurPermute(index+1, nums, ans);
            swap(nums[index], nums[i]);       // reswap ie backtracking step
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        recurPermute(0, nums, ans);
        return ans;
    }
};