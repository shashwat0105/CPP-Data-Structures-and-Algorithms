https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans){
        if(index == nums.size()){                   // index reaches the end
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> s;                       // this set will contain the number we have already used at a particular location(Since the repeating numbers may not be continuos)
        
        for(int i=index; i<nums.size(); i++){
            if(s.find(nums[i])!=s.end()) continue;  // ie the number has already occured
            s.insert(nums[i]);                      // otherwise we will insert this number in our set
            swap(nums[index], nums[i]);
            recurPermute(index+1, nums, ans);
            swap(nums[index], nums[i]);             // reswap ie backtracking step
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        recurPermute(0, nums, ans);
        return ans;
    }
};

TC:
It takes N steps to generate a single permutation. 
Since there are in total N! possible permutations, at most it would take O(N * N!) steps to generate all permutations. 
Multiply Horizontal vs Vertical

This set approach is better.
If you avoid set then it will become more difficult to uderstand for you.
Reference:
// pass by value also no swapping back 
https://leetcode.com/problems/permutations-ii/solutions/18596/a-simple-c-solution-in-only-20-lines/
// Set method
https://leetcode.com/problems/permutations-ii/solutions/18632/Short-40ms-C++-solution-similar-to-Permutation-I-solution/


// Similar ques
https://leetcode.com/problems/letter-tile-possibilities/
