https://leetcode.com/problems/next-permutation/

// GOOD QUESTION

// Inbuilt C++ library for this task
// next_permutation
// https://www.geeksforgeeks.org/stdnext_permutation-prev_permutation-c/
void nextPermutation(vector<int>& nums) {
    next_permutation(begin(nums), end(nums));
}
// The complexity of the code is O(n*n!) which also includes printing all the permutations.
// But works for this ques as well.

// Optimised approach time complexity is: O(3*n)=O(n).

https://youtu.be/LuLCLgMElus

// Good image with explanation: 
https://www.nayuki.io/res/next-lexicographical-permutation-algorithm/next-permutation-algorithm.svg

// From comments of leetcode discuss of this ques.
// I don't think any one can understand this solution without seeing an example, here is an example:
// [1, 3, 5, 4, 2]

//      5
//  i=3   4 = j
// 1       2 
//           
// Explanation:
 
// Consider nums[] = [1, 3, 5, 4, 2].
// Traverse from back and find a breakpoint(first number which not increase in a ascending order). Here, index breakPoint = 1 and nums[breakPoint] = 3
// Here we can have two situations:
// 1) We cannot find the number, all the numbers increasing in a ascending order. 
// This means this permutation is the last permutation, we need to rotate back to the first permutation. So we reverse the whole array, for example, 6,5,4,3,2,1 we turn it to 1,2,3,4,5,6.

// 2) Traverse from back to leftward and find the first number which is larger than this breakpoint. Here this number is: nums[j] = 4
// Swap nums[breakPoint] and nums[j]. Value after swapping: nums[] = [1, "4", 5, "3", 2].
// Reverse array from breakPoint + 1 to nums.size() i.e. these elements: [1, 4, "5, 3, 2"]
// Final answer = [1, 4, 2, 3, 5].


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakpoint=-1;
       
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){       // In array left element < right element
                breakpoint = i;
                break;                   
            }
        }

        // if no breakpoint
        if(breakpoint<0){                         
            reverse(nums.begin(), nums.end());
        }
        // if found a breakpoint
        else{
            for(int j=n-1; j > breakpoint; j--){                          // j position is the first number greater than i, when we move from back
                if(nums[j] > nums[breakpoint]){
                    swap(nums[breakpoint], nums[j]);                      // swap the breakpoint & j positions
                    reverse(nums.begin() + breakpoint + 1, nums.end());   // reverse all the numbers after now breakpoint position, without inbuilt function we can use swap N/2 elements O(n) time :- for(i in 0 to n/2) swap(nums[i], nums[n-i-1]); 
                    break;
                }
            }
        }
    }
};

