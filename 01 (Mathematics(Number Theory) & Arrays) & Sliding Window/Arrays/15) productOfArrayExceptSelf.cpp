https://leetcode.com/problems/product-of-array-except-self/

https://leetcode.com/problems/product-of-array-except-self/solutions/1342916/3-minute-read-mimicking-an-interview/

// You can seggregate the problem in no of zeroes, then we can use the divide operation as well.
// ie ki ek zero hai ya ek se jada zero hai.

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

// Better code
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // using extra space (better code) // aage ar peeche 1 daal do, size n hi rahne do.
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        pre[0]=1;
        suf[n-1]=1;

        for(int i=1; i<n; ++i) pre[i]=pre[i-1]*nums[i-1];
        for(int i=n-2; i>=0; --i) suf[i]=suf[i+1]*nums[i+1];

        // nums: 1   2 3 4
        // pre:  1   1 2 6   // iske last product ki need nahi hai so size n m kaam chal gaya
        // suf:  24 12 4 1   // iske first product ka sense ni hai so size n m kaam chal gaya
        // Ans:  24 12 8 6

        vector<int> ans(n);
        for(int i=0; i<n; ++i) ans[i]=pre[i]*suf[i];
        return ans;
    }
};
// 2 Pass solution, no extra space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // no extra space 2 pass
        int n = nums.size();
        vector<int> res(n, 1);
        int cur = 1;

        for(int i=0; i<n; ++i){
            res[i]*=cur;
            cur *=nums[i];
        }
        for(auto x: res) cout<<x<<" ";
        cur = 1;
        for(int i=n-1; i>=0; --i){
            res[i]*=cur;
            cur*=nums[i];
        }
        return res;
    }
};

// One pass, no extra space solution
https://youtu.be/bNvIQI2wAjk (Better theory explanation)
https://leetcode.com/problems/product-of-array-except-self/discuss/65627/O(n)-time-and-O(1)-space-C%2B%2B-solution-with-explanation  (Code courtesy)

Directly store the product of prefix and suffix into the final answer array

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

// Python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans, suf, pre = [1]*len(nums), 1, 1
        for i in range(len(nums)):
            ans[i] *= pre
            pre *= nums[i]
            ans[-1-i] *= suf
            suf*=nums[-1-i]
        
        return ans

    

