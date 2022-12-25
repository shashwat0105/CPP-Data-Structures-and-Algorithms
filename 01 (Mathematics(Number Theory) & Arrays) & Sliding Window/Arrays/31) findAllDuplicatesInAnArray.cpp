https://leetcode.com/problems/find-all-duplicates-in-an-array/

// without the given constraints the problem can be solved by sorting or some hashmap

// Thing to catch:
// all the integers of nums are in the range [1, n] & we know indices are in range of [0, n-1]
// Trick is how to use this thing?

// "If there is a repeating number, both of them will point to the same index as we move in the array."
// For ex:
// [4,3,2,7,8,2,3,1]
// As we move in the array the first 3 will point at position 3(index 2)(so we subtract 1), then second 3 will again point at position 3(index 2)
// We will make some changes first time we encounter a position so as to distinguish if it is encountered again in the future (here making it negative)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[abs(nums[i]) -1]>0){
                nums[abs(nums[i]) - 1]*=(-1);
            }
            else{
                res.push_back(abs(nums[i]));
            }
        }
        return res;
    }
};


