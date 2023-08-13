https://leetcode.com/problems/house-robber-ii/

First n last are also adjacent

Remove the last element and solve as previous ques
Remove the first element and solve as previous ques
Take the max, as both cannot come in our ans together.

// CODE

class Solution {
public:
    int solve(vector<int> &nums){
        int n = nums.size();
        int prev = nums[0]; // because If u are standing at i=0 then better u pick it as all values are +ve
        int prev2 = 0;      // index < 0
        for(int i=1; i<n; ++i){
            int pick = nums[i]; 
            if(i>1) pick += prev2;
            int notPick = 0 + prev;
            int curi = max(pick, notPick);
            prev2 = prev;
            prev = curi;
        }        
        return prev;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];  // edge case
        vector<int> temp1, temp2;
        int n = nums.size();
        for(int i=0; i<n; ++i){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(solve(temp1), solve(temp2));
    }
};
