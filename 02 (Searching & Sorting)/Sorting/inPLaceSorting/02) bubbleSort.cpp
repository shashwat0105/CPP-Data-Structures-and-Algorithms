// Time complexity O(n^2)

// Push the max to the last position by "adjacent swaps".
// After every pass the max element will be at the rightmost position
// After 2 pass, 3 pass how the array will look like ??
// And how many swappings will be required ?

// If number of elements are 10, we will have 9 passes irrespective whether the array gets sorted in 9th pass or 3rd pass
class Solution {
public:
    // bubble sort
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // for number of pass
        for(int i=0; i<n-1; ++i){  // we check 2nd last with last element, so our passes go till 2nd last element
            // for comparison in each pass
            for(int j=0; j<n-1-i; ++j){  // to decrease number of comparision as right most part of size i is sorted already
                if(nums[j] > nums[j+1]){ // if left element is greater than right we swap
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return nums;
    }
};


// Optimised(Adaptive) bubble sort, to keep a check if we get sorted array in less number of passes.
// If we get a pass in which no swapping is there then break the loop
void bubbleSort(int arr[], int n)
{
    int i, j, flag;
    for(i=0; i<n-1; i++)
        flag=1;
        {
            for(j=0; j<n-1-i; j++)
                if(arr[j]>arr[j+1])
                    swap(arr[j], arr[j+1]);
                    flag=0;
        }
        if(flag){  // becomes true the loop breaks
            return;
        }
}

Best TC = O(N) for adaptive bubble sort when the array is already sorted.
