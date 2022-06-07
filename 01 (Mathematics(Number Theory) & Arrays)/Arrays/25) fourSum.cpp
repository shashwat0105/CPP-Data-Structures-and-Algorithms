https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        if(n < 4) return res;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; ++i){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){                     // to avoid repetition in 1st number
                for(int j=i+1; j<n-2; ++j){
                    if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1])){           // to avoid repetition in 2nd number
                        int newTarget = target - (nums[i] + nums[j]);
                        int s = j+1;
                        int e = n-1;
                    
                        while(s<e){
                            if(nums[s]+nums[e]==newTarget){
                                res.push_back({nums[i], nums[j], nums[s], nums[e]});  
                                while(s<e && nums[s]==nums[s+1]) s++;    // to avoid repetition in 3rd number       
                                while(s<e && nums[e]==nums[e-1]) e--;    // to avoid repetition in 4th number (the code will work without this loop as well)      
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


// This also works:
// 1) using two while for first two numbers
// or
// 2) using two if with continue statements for first two numbers

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        if(nums.size()<4) return v;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-3;i++){
        // if (i > 0 && A[i] == A[i - 1]) continue;
            for(int j=i+1;j<nums.size()-2;j++){
        // if (j > i + 1 && A[j] == A[j - 1]) continue;
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

// K-Sum
// BEST from discuss
// https://leetcode.com/problems/4sum/discuss/1341213/C%2B%2BPython-2-solutions-Clean-and-Concise-Follow-up%3A-K-Sum



