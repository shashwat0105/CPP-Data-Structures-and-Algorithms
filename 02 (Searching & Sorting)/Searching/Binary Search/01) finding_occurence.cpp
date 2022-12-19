// Finding first & last occurence of a number in an array

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int findFirst(vector<int>& nums, int x){
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(x == nums[mid]){
                ans = mid;  // (only change that we have to continue our search)if we get an occurence we store it as it is a possible ans, and check in left part whether this is the first occurence if found we will update it
                r = mid-1;
            } 
            else if(x < nums[mid]) r = mid-1;
            else l = mid+1;
        }
        return ans;
    }

    int findLast(vector<int>& nums, int x){
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(x == nums[mid]){
                ans = mid;  // if we get an occurence we store it, and check in right part whether this is the last occurence if found we will update it
                l = mid+1;  
            } 
            else if(x < nums[mid]) r = mid-1;
            else l = mid+1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(findFirst(nums, target));
        ans.push_back(findLast(nums, target));
        return ans;
    }
};


count = last_occ - first_occ + 1;


// Using STL lower and upper bound

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/solutions/2020403/binary-search-lower-bound-upper-bound-c-stl/

