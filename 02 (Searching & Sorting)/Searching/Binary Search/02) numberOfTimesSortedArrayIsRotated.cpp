https://practice.geeksforgeeks.org/problems/rotation4723/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// 1) = index of the minimum element in rotated sorted array. (This is the no of times it is rotated)
// Later think about direction of the rotation(clockwise or anticlockwise)
// Here the last element is bought to the front.

// without using linear search we have to do.

// 2) the smallest element is the only element that is smaller than both of its neighbour

// 3)  min element lies in the unsorted part of the array.

// 4) In this we compare the mid element to "start" and "end" elements to find the sorted and unsorted parts of the array.

int findKRotation(int arr[], int n) {
    // code here
    int s = 0;
    int e = n-1;
    // to return the index of the smallest element
    while(s<=e){
        if(arr[s]<=arr[e]) return s;
        int mid = s+(e-s)/2;
        int next = (mid+1)%n;    // next element of last element is the first element
        int prev = (mid-1+n)%n;  // previous element of first element is the last element
        
        // elements given are unique 
        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]) return mid;
        if(arr[s]<=arr[mid]) s = mid+1;       // right is the unsorted array
        else if(arr[mid]<=arr[e]) e = mid-1;  // left is the unsorted array
    }
    return 0;
}

One place worth noticing is the termination conditions. 
Whenever our window has only one element, its value is the answer. 
When our window has two elements, and the first element is larger than the second one, the second element is our answer. 
This case falls into the num[mid]>=num[start] condition in the code below. (given that there is no duplicates in the array)

Any equalties we can remove:
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = n-1;
        
        while(s<=e){
            if(nums[s]<nums[e]) return nums[s];
            int mid = s+(e-s)/2;
            int next = (mid+1)%n;  // next element of last element is the first element
            int prev = (mid-1+n)%n;  // previous element of first element is the last element
            
            // elements given are unique 
            if(nums[mid]<nums[next] && nums[mid]<nums[prev]) return nums[mid];
            if(nums[s]<=nums[mid]) s = mid+1;      // right is the unsorted array to deal with [2, 1] case
            else if(nums[mid]<nums[e]) e = mid-1;  // left is the unsorted array
        }
        return nums[0];
    }
};


// THE BASIC CRUX is to compare with end and start element ONLY [Rest is your logic]

OR 

int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size()-1;
    while(high - low > 1)
    {
        int middle = (high + low)/2;
        if(nums[middle] < nums[high])
            high = middle;
        else
            low = middle;
    }
    return min(nums[low], nums[high]);        
}

