https://leetcode.com/problems/search-insert-position/

STL

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }

};

// method 1

// l, r wali condition apan ese lagate hai ki mid mera search space m rehna chahiye ya nahi rehna chahiye

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r = nums.size()-1;
        // I should store a possible index
        // I need to find the greatest number available but less than this number
        int ans = -1;
        while(l<=r){        // ek bhi element na bache tab bahar ae, l<r means ek element bache tab bahar ae
            int mid = (l+r)>>1;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                ans = mid;  // possible ans can be mid
                r = mid-1;
            } 
            else{
                l = mid+1;
                ans = mid+1; 
            } 
        }
        return ans;
    }

};


// method 2
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r = nums.size()-1;
        
        while(l<r){
            int mid = (l+r)>>1;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r = mid;  // right could be the result
            else l = mid+1; 
        }
        // at this stage only one element is remaining in the array l, mid, r all poiting there
        return nums[l]<target? l+1: l;   // [5] target is 7
    }
};


//
l<r means it will exit and one element will remain in the array
l<=r means it will exit and no element will remain in the array

// Another better you can write:
r-l > 1 ie jab array mein do element bache hai tab hi exit kar lo ar un do element k beech decide krna toh easy hai, dikkat nahi ayegi.
