https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Two pointers
// Left will keep track of the next position to be filled
// Right will move through the array (Here below i is the right pointer)

class Solution {    
public:
    int removeDuplicates(vector<int>& nums) {
//         int left=0;
        
//         if(nums.size() == 0){
//             return 0;
//         }
        
//         for(int i=1; i<nums.size(); i++){    
//             if(nums[i] != nums[i-1]){
//                 left++;
//                 nums[left] = nums[i];
//             }
//         }
//         return left+1;
//     }
// YOU CAN USE ANY OF THE CODE, JUST DEPENDING ON INITITIAL VALUE OF left.
        int left=1;
        
        if(nums.size() == 0){
            return 0;
        }
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){    // isko apan uske pehle element se compare kar rahe
                nums[left] = nums[i];
                left++;
            }
        }
        return left;
    }
};

Instead prefer this below
// the intution behind this ->  go through all the elements, along with that check if the 
// current element has been included previously or not
// if included skip it, else add it

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        int left = 1;
        for (int r = 1; r < n; ++r)
            if (nums[r] != nums[left - 1]) nums[left++] = nums[r];  

        return left;   // this will contain the no of unique elements in the array
    }
};
