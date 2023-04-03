https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Two pointers
// Left will keep track of the next position to be filled
// Right will move through the array (Here below i is the right pointer)

// the intution behind this ->  go through all the elements, along with that check if the 
// current element has been included previously or not
// if included skip it, else add it

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return n;
        // pos is left ptr
        // i is right ptr
        int pos = 1;
        for (int i = 1; i < n; ++i)
            if (nums[i] != nums[pos - 1]) nums[pos++] = nums[i];

        return pos;   // number of unique elements in array.
    }
};