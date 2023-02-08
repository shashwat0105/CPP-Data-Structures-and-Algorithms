https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

https://leetcode.com/problems/maximum-subarray

// max(element ko add kar dun, ya isi element ko leke nayi journey start kar dun)

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

// Isko ese bhi likh skte ho in just two lines:
sum = max(sum+nums[i], nums[i]); // sum mein yeh element add kar du ya nayi journey start kar dun
maxi = max(maxi, sum)

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

Follow Up:
https://leetcode.com/problems/maximum-sum-circular-subarray/

NOTE: we cannot take any element more than once.
Brute Force: har baar ek ek element ko rotate karo ar uspe kadane's laga do O(N^2)

Jab bhi circular ki baat hoti hai, say here or in sliding window, hamesha dekha gaya hai ki beech ki window ko opposite treat 
karke nikalna hota hai, mtlb corners ko maximise toh andar ki window ko minimise kar do ek hi baat hai.
// we find answer for both the cases and take whichever gives us the maximum
// Case 1: Simple kadane when subarray lies in the middle
// Case 2: Subarray is prefix, suffix with no element common, ese ques m it is easy to think in reverse(similar to circular sliding window) bahar ko maximise karna hai toh andar wali window(subarray) ko minimise kar do.
// Ek hi loop mein dono cases ka answer nikal lia.
Our ans: max(max_subarray_sum, total - min_subarray_sum)
// Edge case:
// {-1, -1, -1}
// sum = -3
// minSum = -3
// maxSum = -1 (case 1)
// cicularSum = -3-(-3) = 0 (case 2)
// max(0, -1) = 0,, we cannot return 0 as it doesnot exist, hence in this edge case we have to return maxSum only.

// CODE:

class Solution {
public:

    pair<int, int> kadane(vector<int> &nums){
        int globalMax = nums[0];  // max so far
        int globalMin = nums[0];  // min so far
        int curMax = 0;           // max ending here
        int curMin = 0;           // min ending here

        for(int i=0; i<nums.size(); ++i){
            curMax += nums[i];
            curMin += nums[i];
            globalMax = max(globalMax, curMax);
            globalMin = min(globalMin, curMin);
            if(curMax<0) curMax = 0; // curMax = max(0, curMax);
            if(curMin>0) curMin = 0; // curMin = min(0, curMin);  // tab tak subarray lete hai jab tak uska sum negative rahe
        }
        return {globalMax, globalMin};
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        auto sums = kadane(nums);
        // edge case when all array elements are negative, globalMin will store the sum of all elements, atleast one element which is min of the array must be returned instead 
        if(sums.second==total) return sums.first;
        return max(sums.first, total-sums.second);
    }
};


// Some alternate shorter codes:
    // int cur_max = 0, cur_min = 0, sum = 0, max_sum = nums[0], min_sum = nums[0];
    // for (int num : nums) {
    //     cur_max = max(cur_max, 0) + num;
    //     max_sum = max(max_sum, cur_max);
    //     cur_min = min(cur_min, 0) + num;
    //     min_sum = min(min_sum, cur_min);
    //     sum += num;
    // }
    // return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);

    // *******
    // int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
    // for (int& a : A) {
    //     curMax = max(curMax + a, a);  // chahe 0 se compare kar lo ya ese ek hi baat hai, yeh element add kar du ya nayi journey start kar du
    //     maxSum = max(maxSum, curMax);
    //     curMin = min(curMin + a, a);
    //     minSum = min(minSum, curMin);
    //     total += a;
    // }
    // return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;

// MIN SUBARRAY SUM : Nikalne ka ek ar tareeka:
// Poori array ko -1 se multiply kar do ar fr us array ka max subarray sum nikal lo.

