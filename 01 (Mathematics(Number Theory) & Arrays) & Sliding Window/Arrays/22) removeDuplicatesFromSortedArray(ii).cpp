Remove duplicates 1
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// the intution behind this ->  go through all the elements, along with that check if the 
// current element has been included previously or not
// if included skip it, else add it

To keep only one instance

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        int left = 1;
        for (int r = 1; r < n; ++r)
            if (nums[r] != nums[left - 1]) nums[left++] = nums[r];

        return left;   // this will contain the no of unique elements in the array
    }
};

https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Allowed to keep atmost two instances

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int left = 2;
        for (int r = 2; r < n; ++r)
            if (nums[r] != nums[left - 2]) nums[left++] = nums[r];

        return left;  // this will contain the no of unique elements in the array
    }
};


