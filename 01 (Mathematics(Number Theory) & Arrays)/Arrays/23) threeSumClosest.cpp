https://leetcode.com/problems/3sum-closest/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i=0; i<n-2; ++i){
            int s = i+1;
            int e = n-1;

            while(s<e){
                int sumhere = nums[i] + nums[s] + nums[e];
                if(sumhere==target) return sumhere;          // works without this line as well, but makes the code fast as no need to compare further.
                if(abs(target-sumhere) < abs(target-res)){
                   res = sumhere;
                }
                else if(sumhere > target) e--;
                else s++;
            }
        }
        return res;
    }
};

