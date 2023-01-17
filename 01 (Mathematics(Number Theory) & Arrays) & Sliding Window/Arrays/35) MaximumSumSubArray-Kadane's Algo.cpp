https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {  // maxi = max sum so far, sum = sum ending here
        int maxi= nums[0], sum=0;         // atleast one element should be in the subarray, maxi can be INT_MIN as well 
        int n = nums.size();
        for(int i=0; i<n; ++i){
            sum = sum+nums[i];
            maxi = max(maxi, sum);
            sum = max(0, sum);  // we carry a subarray as long as it gives a positive sum (crux of kadane)
        }
        return maxi;
    }
};

https://leetcode.com/problems/maximum-subarray/discuss/1595195/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-DP-%2B-Kadane-%2B-Divide-and-Conquer

// Print the subarray:
// And also print that subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = nums[0];
        int start = 0, end = 0; // the final start and end position of the maximum sum subarray
        
        int sum = 0;
        int s = 0, // the temporary start position
        
        for(int i=0;i<n;i++){
            sum += nums[i];
            
            if(sum > maxi){
                maxi = sum;
                start = s;
                end = i;
            }
            if(sum < 0){
                sum = 0;
                s = i+1;
            }   
        }
        cout<<"Maximum Sum Subarray from nums["<<start<<"] = "<<nums[start]<<" till nums["<<end<<"] = "<<nums[end]<<endl;
        
        return maxi; 
    }
};
// another implementation is using if else can check
