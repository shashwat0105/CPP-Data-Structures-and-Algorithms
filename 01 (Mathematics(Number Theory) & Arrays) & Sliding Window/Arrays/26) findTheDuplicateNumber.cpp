https://leetcode.com/problems/find-the-duplicate-number/

// Following is not allowed
// Brute force method:
// sort the array and linearly traverse to check
// TC = O(N log N), SC = O(1)

// Better:
// Using hashing storing the count
// TC = O(N), SC = O(N)

// Optimal implementation
// "Linked List Cycle Method"
// Or Floyd's Tortoise(slow) and Hare(fast) (Cycle Detection)
// https://youtu.be/wjYnzkAhcNk (neetcode vid) (v good)

// Two variable slow and fast.
// Inititally 
// Slow moves 1 step everytime
// Fast moves 2 steps everytime
// Till they dont become equal. (Thats why we use do while here)
// Make fast to the start
// Both moves one step till they dont become equal. The position at which they point is(beginning of the cycle) and is also the repeating number.

0 1 2 3 4
1 3 4 2 2   // 

0 points to 3 points to 2 points to 4 points to 4  (LinkedList)
2 is pointed by two elements 3 and 4 hence it is occuring twice.

0 1 2 3 4
2 2 1 3 4
0 points to 2 points to 1 points to 2
2 is pointed by 0 and 1 both

// TC = O(n), SC = O(1)
// CODE
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];             // can do either 0 or nums[0]
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        // int slow = nums[0];          // If you want to use a while loop.
		// int fast = nums[nums[0]];
		// while (slow != fast){        // slow==fast pe wo andar ni jaega na
		// 	slow = nums[slow];
		// 	fast = nums[nums[fast]];
		// }
        
        fast = nums[0];                 // can do either 0 or nums[0]
        
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// Other code
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        
        while(true){                  // type of a do while loop only
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast) break;
        }
        
        fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            if(slow==fast) break;
        }
        return slow;
    }
};

// Binary search solution (mast)
// TC = O(nlogn), SC = O(1)
// Lets say there is an separate array containing numbers [1, 2, 3, 4, .... N]
// we will apply binary search on "this" array! & shrink in the direction of repeated number
// Let's say n=10 and I select mid=5. Then I count all the numbers in the array which are less than equal mid. 
// If there are more than 5 numbers that are less than 5, one of them has occurred more than once. So I shrink the search space from [1 10] to [1 5]. 
// Otherwise the duplicate number is in the second half so for the next step the search space would be [6 10].
    
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int L = 1;
        int R = nums.size()-1;
        while(L<R){
            int M = L + (R-L)/2;
            int cnt = 0;
            for(int n: nums){
                if(n<=M) cnt+=1;     // count all the numbers <= mid
            }
            if(cnt <= M) L = M+1;
            else R = M;
        }
        return L;
    }
};


// 9 methods
https://leetcode.com/problems/find-the-duplicate-number/solutions/1892921/9-approaches-count-hash-in-place-marked-sort-binary-search-bit-mask-fast-slow-pointers/
