https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++){
            nums[i] = nums[i] + nums[i-1];
        }
        return nums;
    }
};


or 
// In below approach I was getting buffer overflow due to mistake in limits of n, when I first solved it.
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=0; i<nums.size() - 1; i++){
            nums[i+1] = nums[i] + nums[i+1];
        }
        return nums;
    }
};
