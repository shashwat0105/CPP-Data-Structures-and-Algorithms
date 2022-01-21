https://leetcode.com/problems/4sum/

// Why this fails for second example?
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        for(int i=0; i<n-3; ++i){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                for(int j=i+1; j<n-2; ++j){
                    if(j==1 || (j>1 && nums[j]!=nums[j-1])){
                        int newTarget = target - (nums[i] + nums[j]);
                        int s = j+1;
                        int e = n-1;
                    
                        while(s<e){
                            if(nums[s]+nums[e]==newTarget){
                                res.push_back({nums[i], nums[j], nums[s], nums[e]});  
                                while(s<e && nums[s]==nums[s+1]) s++;        
                                while(s<e && nums[e]==nums[e-1]) e--;        
                                s++;
                                e--;
                            }
                            else if(nums[s]+nums[e]>newTarget) e--;
                            else s++;
                        }
                    }
                }
            }
        }
        return res;
    }
};


THis also works:

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        if(nums.size()<4) return v;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                int start=j+1;
                int end=nums.size()-1;
                while(start<end){
                    int sum=nums[i]+nums[j]+nums[start]+nums[end];
                    if(sum>target) end--;
                    else if(sum<target) start++;
                    else{
                        v.push_back({nums[i], nums[j], nums[start], nums[end]});
                        while(start<end && nums[end]==nums[end-1]) end--;
                        while(start<end && nums[start]==nums[start+1]) start++;
                        start++;
                        end--;
                    }
                }
                while(j+1<nums.size() && nums[j+1]==nums[j]) j++;
            }
            while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
        }
        return v;
    }
};