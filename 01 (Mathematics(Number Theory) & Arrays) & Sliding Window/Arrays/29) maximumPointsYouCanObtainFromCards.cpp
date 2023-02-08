https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

https://youtu.be/1DkVU2i3sOA

// Using sliding window in the cards which we not have to select (Big breins) ie we will minimise them!.
// TC = O(k)
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int w = n-k;
        int res = 0;
        int totSum  =0;
        int minSum = 0;
        int curSum = 0;
        
        for(int i=0; i<n; i++){
            totSum+=nums[i];
        }
        
        // sum of first window
        for(int i=0; i<w; i++){
            minSum += nums[i];
        }
        
        // calculating sum of further windows.
        curSum = minSum;
        for(int i=w; i<n; i++){
            curSum = curSum + nums[i] - nums[i-w];
            minSum = min(minSum, curSum);                  
        }
        res = totSum-minSum;
            
        return res;
    }
};

// Another method by storing sums of start sum, end sum, add them and taking maximum
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int s = 0;
        int e = k;
        
        int s_sum=0;
        int e_sum=0;
        
        e_sum = accumulate(nums.begin()+n-k, nums.end(), 0);   // sum of last k terms
        
        while(e!=-1){
            res = max(res, s_sum+e_sum);
            
            s_sum+=nums[s];
            if(n-e<n)
            e_sum-=nums[n-e];
            
            s++;
            e--;
        }
        return res;
    }
};