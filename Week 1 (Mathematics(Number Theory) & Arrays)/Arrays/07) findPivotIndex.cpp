https://leetcode.com/problems/find-pivot-index/submissions/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int leftsum = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        
        for(int i=0; i<nums.size(); i++){
            if(i!=0) leftsum += nums[i-1];
            
            if(leftsum == ((sum-nums[i])/2.0)){   // OR sum -leftsum - nums[i] = leftsum 
                return i;
            }
        }
        
        return -1;
    }
};

// OR

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0;           // will become the sum of left array
        int sum = 0;          // this will first become total sum then will be reduced gradually to become right array sum
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
    
        for(int i=0; i<n; i++){
            sum -= nums[i];
            if(sum==left) return i;
            left+=nums[i];
        }
        return -1;
    }
};

