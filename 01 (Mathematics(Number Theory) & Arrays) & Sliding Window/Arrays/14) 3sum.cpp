https://leetcode.com/problems/3sum/
// In this ques we have to return values.
// The sum could be anything here it is given 0

https://youtu.be/onLoX6Nhvmg

// We will fix 1 num & use modified 2 pointer approach used in 2 sum problem.
// Notice that the solution set must not contain duplicate triplets.

// Due to this our pointers will move left, right any no of steps till they become unequal to their past values.
// So that pas values are not considered again.

// TC = O(n^2)
// SC = O(1), storage space of ans is not considered

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        for(int i=0; i<n-2; ++i){
            
		    if (nums[i] > 0) break;  // all numbers from now on will be greater than 0, no point in continuing (for this ques)
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){   // to avoid repetition in 1st number
                int a = nums[i];
                int newTarget = 0-a;
                int s = i+1;
                int e = n-1;
                
                while(s<e){ 
                    if(nums[s]+nums[e]==newTarget){
                        res.push_back({nums[i], nums[s], nums[e]});  // Inserting a vector inside a vector
                        while(s<e && nums[s]==nums[s+1]) s++;        // to avoid repetition in 2nd number
                        while(s<e && nums[e]==nums[e-1]) e--;        // to avoid repetition in 3rd number (the code will work without this loop as well)
                        s++;
                        e--;
                    }
                    else if(nums[s]+nums[e]>newTarget) e--;
                    else s++;
                }
            }
        }
        return res;
    }
};
