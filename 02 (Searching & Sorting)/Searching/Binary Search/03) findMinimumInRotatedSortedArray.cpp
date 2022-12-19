https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Previous ques we have to return the index of the min element.
Here we have to return the min element itself.

// Aditya verma method
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = n-1;
        
        while(s<=e){
            if(nums[s]<=nums[e]) return nums[s];
            int mid = s+(e-s)/2;
            int next = (mid+1)%n;    // next element of last element is the first element
            int prev = (mid-1+n)%n;  // previous element of first element is the last element
            
            // elements given are unique 
            // Used = sign everywhere (IMPORTANT)
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev]) return nums[mid];
            if(nums[s]<=nums[mid]) s = mid+1;       // right is the unsorted array
            else if(nums[mid]<=nums[e]) e = mid-1;  // left is the unsorted array
        }
        return nums[0];
    }
};


// OTHER thinking (Yahi best hai)

array kaisi ho skti hai????
jada elements rotate hue ho
11 12 13 14 15 16 1 2 3
Toh jo mid element hai wo r element se bada ho jaega hence jo minimum element hai wo right side m paya jaega, yaha mid ko preserve krne ki jaroorat nahi hai qki usse chota toh r hi hai
kam elements rotate hue ho
11 12 13 1 2 3 4 5 6 7
TO jo mid hai wo r se chota hoga hence jo minimum element hai wo left side m paya jaega, ar ho skta hai ki jo mid element hai wo hi minimum ho, 
so we donot loose it so we make r == mid not r == mid-1.

Iterative:

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int l = 0, r=nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]>nums[r]) l = mid+1;
            if(nums[mid]<nums[r]) r = mid;
        }
        return nums[l];  // the ans will be stored in nums[l] or nums[r] coz ther is only one element left.
    }
};

Recursive:

class Solution {
public:
    int search(vector<int> &nums, int l, int r){
        if(l==r) return nums[l];
        int mid = l + (r-l)/2;
        if(nums[mid]>nums[r]) return search(nums, mid+1, r);
        if(nums[mid]<nums[r]) return search(nums, l, mid);
        return nums[l]; // l== mid = r   // return mid for index of minimum element
    }

    int findMin(vector<int>& nums) {
        return search(nums, 0, nums.size()-1);
    }
};

// These codes fail for [1, 1] type of input ie repeated

// Using STL (not for interview)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = *min_element(nums.begin(), nums.end());
        return res;
    }
};
