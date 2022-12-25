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
            if(nums[i] != nums[i-1]){
                nums[left] = nums[i];
                left++;
            }
        }
        return left;
    }
};