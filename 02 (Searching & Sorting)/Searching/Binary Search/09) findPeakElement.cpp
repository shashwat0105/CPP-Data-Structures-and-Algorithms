https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // if there is only one element
        if(n==1) return 0;
        // if(n==2){
        //     if(nums[0]>nums[1]) return 0;
        //     else return 1;
        // }
        int l = 0, r = n-1; // agar array mein do element hi honge toh wo while k andar hi nahi jaega ie n==2 jo hai wo simple while k baad se execute ho jaegi
        while(r-l>1){       // array mein do element bachenge tab while break ho jaega  // bhadiya hai no run time error
            int mid = (l+r)>>1;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid; 
            else if(nums[mid]<nums[mid-1]) r = mid-1; // go to that side jis side bada element tha waha peak hoga hi hoga.
            else l = mid+1;
        }
        // now our array has two elements [l, r]
        if(nums[l]>nums[r]) return l;
        else return r;
    }
};

// Jaye kis side??

What we are essentially doing is going in the direction of the rising slope(by choosing the element which is greater than current). 
How does that guarantee the result? Think about it, there are 2 possibilities. a) rising slope has to keep rising till end of the array 
b) rising slope will encounter a lesser element and go down.
In both scenarios, we will have an answer. In a) the answer is the end element because we take the boundary as -INFINITY 
b) the answer is the largest element before the slope falls. 

