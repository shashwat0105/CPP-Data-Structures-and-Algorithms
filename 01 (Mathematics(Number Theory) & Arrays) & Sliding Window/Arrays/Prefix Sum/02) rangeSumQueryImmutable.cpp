https://leetcode.com/problems/range-sum-query-immutable/description/

Brute:
class NumArray {
public:
    // brute force
    NumArray(vector<int>& nums) {
        vec = nums;
    }
    
    int sumRange(int left, int right) {
        return accumulate(vec.begin()+left, vec.begin()+right+1, 0);
    }
private:
    vector<int> vec; // this I think creates an extra copy, we can reuse the nums
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// Optimals:
class NumArray {
public:
    // prefix sum
    NumArray(vector<int>& nums) {
        vec = nums;
        for(int i=1; i<nums.size(); ++i){
            vec[i] = nums[i]+vec[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return vec[right];
        return vec[right]-vec[left-1];
    }
private:
    vector<int> vec; 
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
*********************************************************

class NumArray { // 12 ms, faster than 99.87%
public:
    
    NumArray(vector<int>& nums) : preSum(nums) {
        for (int i = 1; i < preSum.size(); ++i)
            preSum[i] += preSum[i-1]; 
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return preSum[right];
        return preSum[right] - preSum[left-1];
    }
private:
    vector<int>& preSum; // `preSum` will reference to `nums` array, no copy at all!
};

*********************************************************
class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.push_back(0);  // agar ham start mein 0 store kar len toh right+1 - left return kar paenge
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];  // usual query ko ek se badha do toh edge case if else se bach jaoge (helpful in 2D ques)
    }
private:
    vector<int> accu;
};

*********************************************************

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2); 

class NumArray {
public:
    NumArray(vector<int> &nums) : psum(nums.size()+1, 0) {  
        partial_sum( nums.begin(), nums.end(), psum.begin()+1);  // partial_sum is inbuilt method
    }

    int sumRange(int i, int j) {
        return psum[j+1] - psum[i];
    }
private:
    vector<int> psum;    
};

*********************************************************
