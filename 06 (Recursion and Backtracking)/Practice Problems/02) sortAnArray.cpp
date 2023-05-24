https://leetcode.com/problems/sort-an-array

All (15+) Sorting Methods 
https://leetcode.com/problems/sort-an-array/discuss/1401412/C%2B%2B-Clean-Code-Solution-or-Fastest-or-All-(15%2B)-Sorting-Methods-or-Detailed


STL sort or merge sort: TC = O(nlogn)

Using recursion: TC = O(N^2)
https://youtu.be/AZ4jEY_JAVc  (Aditya verma)

// Can't think if we can take any decisions so we think for smaller inputs
Base condition  // smallest valid input
Hypothesis      // kaam kya karega
Induction       // kaam kaise karwaenge

// 1 5 0 2
// High Level Thinking
// Expectation: 1 5 0 2 sort ho jaega
// Faith:  1 5 0 sort ho jaega: ie 0 1 5 ban jaega
// Now: Relating faith with expectation: Insert 2 at correct place in 0 1 5.

// Low level thinking
// Dry run, stack, base case.

// Insertion sort using recursion (Gives TLE in leetcode, just learn for concept.)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // base case
        if(nums.size()==1) return nums;
        
        int temp = nums[nums.size()-1]; // storing the last element
        nums.pop_back();                // reducing the vector
        sortArray(nums);                // sort the remaining vector // wo keh raha hai pehle mujhe sort krke le aa uske baad jo mere paas hai use mai sahi jagah insert kr dunga
        insert(nums, temp);             // inserting the removed element in its correct position (this could also be done iteratively using loop but we will do recursively)
        return nums;
    }
    
    void insert(vector<int>& nums, int temp){
        // base case of this recursive function
        if(nums.size()==0 || nums[nums.size()-1]<=temp){  // last element remove krte jaenge(array is sorted) jaha pe temp bada mila(in rec calls) last element se ie yeh uski sahi position hai yaha insert kr denge nd return
            nums.push_back(temp);       // vector is empty or last element is <= temp
            return;
        } 
        
        // making the input vector small
        int val = nums[nums.size()-1];  // storing the last element
        nums.pop_back();
        insert(nums, temp);             // inserting temp in the reduced vector
        nums.push_back(val);            
        return;
    }
};
// Understanding insert recursion with exmple
1 3 5 and u want to insert 2
1 3   want to insert 2
1     want to insert 2, here the base case hits and 2 gets inserted
3 and 5 are push backed again. That is how it is done.

// Do merge sort instead.

class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high) {
        if (low >= high) return;
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);
        while (l <= mid and r <= high)
            sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        while (l <= mid) 
            sorted[k++] = nums[l++];
        while (r <= high) 
            sorted[k++] = nums[r++];
        for (k = 0; k < size; k++)
            nums[k + low] = sorted[k];
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if(low>=high) return;
        int mid = (low+high)>>1;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    
    vector<int> sortArray(vector<int>& nums) {
       int low = 0;
       int high = nums.size()-1;
      
       mergeSort(nums, low, high);
       return nums;
    }
};
