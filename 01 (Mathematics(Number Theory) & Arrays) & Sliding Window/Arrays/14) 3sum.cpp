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
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; ++i){  // fixed pointer
            if(i!=0 && nums[i]==nums[i-1]) continue;   // for handling duplicate in first element.

            int s = i+1;  // 2 variable pointers
            int e = n-1;

            while(s<e){
                int sum = nums[i] + nums[s] + nums[e];

                if(sum<0){
                    s++;
                }
                else if(sum>0){
                    e--;
                }
                else{
                    vector<int> temp = {nums[i], nums[s], nums[e]};
                    ans.push_back(temp);
                    // skip duplicates
                    while(s<e && nums[s]==nums[s+1]) s++;  // in second variable
                    while(s<e && nums[e]==nums[e-1]) e--;  // in third variable
                    s++;
                    e--;
                }
            }
        }
        return ans;
    }
};
