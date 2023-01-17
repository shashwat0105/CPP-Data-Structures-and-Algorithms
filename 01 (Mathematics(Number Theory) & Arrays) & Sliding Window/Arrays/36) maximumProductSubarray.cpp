https://leetcode.com/problems/maximum-product-subarray/

// dry run karke ar samajh lena

// Method 1
// imin isliye ki future m ek  badi negative value mil jae toh uska use kar lenge

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // method 1
        int n = nums.size();
        int ans = nums[0];
        int imax = nums[0], imin = nums[0]; // imax and imin stores the max/min product of the subarray that ends with current nums[i]
        for(int i=1; i<n; ++i){
            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extremums by swapping them
            if(nums[i]<0) swap(imax, imin);

            // max/min product for the current number is either the current number itself
            // or the max/min by the previous number times the current one
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);

            // the newly computed max value is a candidate for our global result
            ans = max(ans, imax);
        }
        return ans;
    }
};

// Method 2

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_overall = nums[0];
        int max_ending_here = nums[0], min_ending_here = nums[0];
        
        for(int i = 1; i < nums.size(); ++i){
            int tmp = max_ending_here;
            max_ending_here = max({nums[i], nums[i]*max_ending_here, nums[i]*min_ending_here});
            min_ending_here = min({nums[i], nums[i]*tmp, nums[i]*min_ending_here});
            max_overall = max(max_overall, max_ending_here);
        }
        return max_overall;
    }
};

// Method 3:
// negative numbers even honge toh poori array lelo
// odd honge toh ya toh first -ve element ko hataenge ya last -ve ko
// prefix suffix method
the max product is the bigger of:

a) product of all excluding elements on the left, up to the first negative element.

b) product of all excluding elements on the right, up to the last negative element.

so the solution is calculate product, first from left to right, then from right to left; 
during the process we are guaranteed to encounter the max product; and whenever 0 is encountered, 
reset product to 1 and continue.

public int maxProduct(int[] A) {
    // edge case
    if (A == null || A.length == 0)
        return 0;
        
    int max = Integer.MIN_VALUE;
    int product = 1;
    // first go from left to right
    for (int i = 0; i < A.length; i++) {
        product *= A[i];
        if (product > max)
            max = product;
        if (product == 0)
            product = 1; // reset if encounter 0
    }
    
    // then go from right to left
    product = 1;
    for (int i = A.length - 1; i >= 0; i--) {
        product *= A[i];
        if (product > max)
            max = product;
        if (product == 0)
            product = 1; // reset if encounter 0
    }

    return max;
}

// Method 4: DP
