Famous Amazon Interview Ques:

Optimised:
O(N) time
O(1) space:

Thing to note:
n = size of the array
Any missing number will be in the range of 1 to n+1 only. (CRUX)
coz:
If an integer is missing it must be in the range [1..n], if an integer is not missing then the answer is n+1.
If extra space was not allowed then I can use a set to insert all elements and search from 1 to n+1

Or (range is upto just n+1 yahi sochne ka crux hai)
If extra space was allowed then I can use an n-size array and map the elements to the indices(make some changes) say negative.
Do the traversal again and find the element jisme change nahi hua.

Same we can do in the orginal array.(wolla)

To return the smallest positive integer that is not in the array]

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // 1. mark numbers (num <= 0)  with a special marker number (n+1) so that they will be out of the range
        for(int i=0; i<n; ++i){
            if(nums[i]<=0 || nums[i]>n) nums[i]=n+1;
        }

        // 2. note: all number in the array are now positive, and on the range 1..n+1
        // Then, for every one of the first n positive numbers in the array, we turn the value at their corresponding index negative.
        for(int i=0; i<n; ++i){
            int index = abs(nums[i])-1;
            if(abs(nums[i]) <= n && nums[index]>0)  // that number is less than n and its number at its index is not marked yet(so that baar baar mark karke -ve * -ve : +ve na ban jae)
                nums[index] *= -1;
        }

        // 3. Finally, all we need to do is check for the first positive value, which will give us the first missing positive. If we find no such index, then all natural numbers up to n are present, so we return n + 1. ie  we identify the index which is not negative and it will be the missing number
        for(int i=0; i<n; ++i){
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};

// Other ways:
We can also ignore the elements>n  too in the first loop:
https://leetcode.com/problems/first-missing-positive/solutions/17214/java-simple-solution-with-documentation/

// Another method by swapping
https://leetcode.com/problems/first-missing-positive/solutions/17214/java-simple-solution-with-documentation/

