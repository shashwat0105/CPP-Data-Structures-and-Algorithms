// Select the minimum and swap

// repeatedly finding(selecting) the minimum element (considering ascending order) 
// from unsorted part and putting it at the beginning(of unsorted part of array).

class Solution {
public:
    // selection sort
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int min_idx;
        for(int i=0; i<n-1; ++i){     // I am not swapping for the last guy
            min_idx = i;
            for(int j=i+1; j<n; ++j){ // I need to traverse the unsorted part completely first
                if(nums[j] < nums[min_idx]){
                    min_idx = j;
                }
            }
            swap(nums[min_idx], nums[i]);
        }
        return nums;
    }
};

TC = O(N^2)