https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

https://leetcode.com/problems/search-in-rotated-sorted-array-ii/solutions/1890199/c-algorithm-binary-search/

{3, 1, 2, 3, 3, 3, 3}
For this case we deal separately and before other normal case
as arr[mid] == arr[l] == arr[r]

Rest logic remains same as previous question
ie we pick the sorted part depending on whether target lies there or not.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)>>1;
            if(nums[mid]==target) return true;
            // with duplicates we have this condition just update left and right
            if(nums[mid]==nums[l] && nums[mid]==nums[r]){
                l++;
                r--;
            }
            // first half is sorted
            else if(nums[l]<=nums[mid]){
                // target in first half
                if(nums[l]<=target && target<=nums[mid]) r = mid-1;
                else l = mid+1;
            }
            // second half
            // second half is sorted
            // target is in second half
            else{
                if(nums[mid]<=target && target<=nums[r]) l = mid+1;
                else r = mid-1;
            }
        }
        return false;
    }
};

// pivot approach
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/solutions/1890619/an-unique-intuitive-approach-logn/
