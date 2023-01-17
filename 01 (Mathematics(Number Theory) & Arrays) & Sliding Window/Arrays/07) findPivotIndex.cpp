https://leetcode.com/problems/find-pivot-index/submissions/

totalSum = t
x(left elements ka sum) y(current element) x(right elements ka sum) 
x+y+x=t

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

OR 

int pivotIndex(vector<int>& nums) {
    int tsum = accumulate(begin(nums), end(nums), 0);
    for (int i = 0, lsum = 0; i < nums.size(); lsum += nums[i++])
        if (lsum * 2 == tsum - nums[i])
            return i;
    return -1;
}

// OR (Better)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {        
        int n = nums.size();
        int leftSum=0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0); // this will first become total sum then will be reduced gradually to become right array sum
        for(int i=0; i<n; ++i){
            rightSum-=nums[i];
            if(leftSum==rightSum) return i;
            leftSum+=nums[i];
        }
        return -1;
    }
};

