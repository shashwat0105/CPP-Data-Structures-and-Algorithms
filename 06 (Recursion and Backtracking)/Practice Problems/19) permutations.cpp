https://leetcode.com/problems/permutations/

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
    void recurPermute(vector<int> &ip, vector<int> &op, vector<vector<int>> &ans, vector<int> &freq){
        if(op.size()==ip.size()){
            ans.push_back(op);
            return;
        }
        for(int i=0; i<ip.size(); i++){            // Here If I take 2 as first element we can take 1 and 3 ie peeche ja skte hai so for loop 0 se start hoga.(can pick any element at any stage)
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
        int n = nums.size();
        vector<int> freq(n, 0); // map or frequency array
        recurPermute(nums, op, ans, freq);
        return ans;
    }
};

// Method 2: With lesser space complexity

https://youtu.be/f2ic2Rsc9pU  (Striver)

Using swapping technique
[1,2,3]
Swap 1 with 1: We get 1 at the start position: Swap 2 with 2(123) or Swap 2 with 3(132)
Swap 1 with 2: We get 2 at the start position: Swap 1 with 1(213) or Swap 1 with 3(231)
Swap 1 with 3: We get 3 at the start position: Swap 2 with 2(321) or Swap 2 with 1(312)

TC = O(N!*N)
SC = O(N)

class Solution {
public:
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans){
        if(index == nums.size()){              // index reaches the end
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){ // I will start swapping from current index to last.
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
