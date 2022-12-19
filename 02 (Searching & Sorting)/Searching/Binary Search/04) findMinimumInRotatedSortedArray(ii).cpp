https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

Elements are repeated
in worst case when all elements are nearly equal ie 1 1 1 1 0 1 1 1 1 1
linear search :

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        for(auto num: nums){
            if(num<ans) ans = num;
        }
        return ans;
    }
};

Binary search is not necessarily better. Let me list several advantages of plain linear search:

// Better spatial locality
// Trivial to parallelize
// Simple code, and thus easy to prove its correctness

// 1 and 2 bestow potential performance edge over binary search, while 3 means better maintainability in terms of software engineering.
// Those arguments are strong enough to show interviewers your solid understanding of computer science as well as practical engineering experience.


// For spatial locality, refer to https://en.wikipedia.org/wiki/Locality_of_reference as a short introduction. This book https://csapp.cs.cmu.edu/ gives an in-depth description and analysis.
// By saying trivial to parallelize, I mean it'd be easy to partition the array into multiple subarrays and to perform linear search on each of them at the same time. On the other hand, there is almost no point in performing multiple binary searches simultaneously. Therefore, it would take much less time for a parallelized linear search provided that modern CPU architecture and distributed systems are available.

// Now binary search implementation 

https://youtu.be/K0PjrikGKK4 (Best)

IF nums[mid]==nums[r] we actually cannot decide where to go?
So, we go linear and more thinking is required
////
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int l = 0, r=nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]>nums[r]) l = mid+1;
            else if(nums[mid]<nums[r]) r = mid;
           
            else if(nums[mid]==nums[r]){ // in distinct ques this scenario is not there
                if(nums[l]==nums[mid]){  // ie all three are equal
                    l++;
                    r--;
                }
                else{
                    r = mid;
                }
            }
        }
        return nums[l]; 
    }
};
