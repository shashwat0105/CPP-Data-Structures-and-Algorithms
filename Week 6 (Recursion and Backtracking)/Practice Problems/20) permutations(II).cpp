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

