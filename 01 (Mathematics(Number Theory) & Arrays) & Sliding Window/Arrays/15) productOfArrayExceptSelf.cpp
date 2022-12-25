https://leetcode.com/problems/product-of-array-except-self/

// You can seggregate the problem in no of zeroes, then we can use the divide operation as well.

https://youtu.be/E0FqAbHjf4E  (GOLD)

// My first solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProduct(n);
        vector<int> suffixProduct(n);
        vector<int> res(n);
        
        for(int i=1; i<n; ++i){
            prefixProduct[0] = nums[0];
            prefixProduct[i] = prefixProduct[i-1] * nums[i];
        }
        
        for(int j=n-2; j>=0; j--){
            suffixProduct[n-1] = nums[n-1];
            suffixProduct[j] = suffixProduct[j+1] * nums[j];
        }
        
        res[0] = suffixProduct[1];
        res[n-1] = prefixProduct[n-2];
        
        if(n>2){
            for(int k=1; k<n-1; ++k){
                res[k] = prefixProduct[k-1]*suffixProduct[k+1];
            }
        }
        
        return res;
    }
};


// One pass, no extra space solution
https://youtu.be/bNvIQI2wAjk (Better theory explanation)
https://leetcode.com/problems/product-of-array-except-self/discuss/65627/O(n)-time-and-O(1)-space-C%2B%2B-solution-with-explanation  (Code courtesy)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        int preProduct = 1;
        int postProduct = 1;
        for(int i=0; i<n; i++){
            res[i] *= preProduct;
            preProduct *= nums[i];
            
            int j=n-i-1;
            res[j] *= postProduct;
            postProduct *= nums[j];
        }
        return res;
    }
};


