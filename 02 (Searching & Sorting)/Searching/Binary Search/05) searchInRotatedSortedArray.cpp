https://leetcode.com/problems/search-in-rotated-sorted-array/

Array has distinct elements.

// Method 1 : By finding the pivot(minimum element) then solving for both the parts.

https://youtu.be/r3pMQ8-Ad5s (Striver)

Left half and right half sorted comparison
[s, mid]      [mid, e]    // including the mid elements we do the comparison.

4 5 6 7  0 1 2  , target = 0
     mid
Now one half is sorted other half is unsorted.
To check if left half is sorted 4 <= 7
To figure out if 0 lies in left half: then 4<=0<=7 not the case, so we move to the right half.

We try to check either one half is sorted or not. If one half is sorted then we check if our target lies in that range or not.
If not we do searching in other half.
In rotated sorted array one half is always sorted.
Pivot is the minimum element of the array about which both directions is sorted.

// Mind m sochte jao ki abhi kaha ja rahe ho kaha comparisons ho rahe hai easily ho jaega

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)>>1;  // a cool way of finding mid
            if(nums[mid]==target) return mid;

            if(nums[low]<=nums[mid]){ // left half is sorted
                // check in left half whether our target lies here or not
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;  // ie the element doesn;t lie in between the left sorted part
                }
            }
            else{ // right part is sorted
                if(nums[mid]<=target && target<=nums[high]){  // lies in that right part
                    low = mid+1;  // left part will be elimated
                }
                else{
                    high = mid-1; // right part is eliminated or doesn't exist ho jaega low will pass high
                }
            }
        }
        return -1;
    }
};

// 
[5,1,3], target=5
Right half m gaya but right half m mila nahi toh dobara left half m chala gaya

// if left half is not sorted, then we are going to right half (which then would be sorted), 
// But if element is not present in right half we are going on else, which means eventually we went to left half :)


// Method 1: using pivot code:


class Solution {
public:
    int getPivot(vector<int>& nums, int n) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2 ;

    while(s<e) {
        if(nums[mid] >= nums[0])
            s = mid+1;
        else
            e = mid;

        mid = s + (e-s)/2 ;        
    }
    return s;
}
 int binarySearch(vector<int>& nums, int s, int e, int key){
    int start=s;
    int end=e;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(nums[mid] == key){
            return mid;
        }
        if(nums[mid] < key){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
    
    int search(vector<int>& nums, int target) {
 
        int s = getPivot(nums,nums.size());
        
        //now pivot index is stored in s
        if(target >= nums[s] && target <= nums[nums.size()-1]){
            //apply binary search in second half
            return binarySearch(nums, s, nums.size()-1, target);
        }
        else{
            return binarySearch(nums,0,s-1,target);
        }
    }
};


// aditya verma style
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int piv=pivot(nums);
        // cout<<piv<<endl;
        if(target==nums[piv]){
            return piv;
        }
        else if(target<nums[0]){
            //binary search after pivot to end
            int a= bs(nums,piv+1,nums.size()-1,target);
            return a;
        }
        else{

            int a=bs(nums,0,piv-1,target);
            return a;
            //binary search from 0 to before pivot 
        }
        return 9;
        
    }
    int bs(vector<int> &nums,int l,int h,int t){
        while(h>=l){
            int m= (h+l)/2;
            if(nums[m]==t){
                return m;
            }
            else if(t>nums[m]){

                l=m+1;
            }
            else{

                h=m-1;
            }
        }
        return -1;

    }
    int pivot(vector<int>& nums){
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(h>=l){
            
            int m = l + (h-l)/2;
            if(nums[m]>=nums[l] && nums[m]<=nums[h]){
                return h;
            }
            if(nums[m]>=nums[l] && nums[m]>=nums[h]){
                l=m+1;   
                if(nums[l]<nums[m]){
                    return m;
                }
            }
            if(nums[m]<=nums[l] && nums[m]<=nums[h]){
                h=m-1;
                if(nums[h]>nums[m]){
                    return m;
                }
            }
        }
        return h;
    }
};
