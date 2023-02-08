https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res=0;
        
        int l = 0;
        int r = n-1;
        
        while(l<r){
            int left_height = height[l];
            int right_height = height[r];
            
            res = max(res, min(left_height, right_height)*(r-l));
            
            if(left_height < right_height) l+=1;   // we move that direction/pointer whose height was less. To have possibility of future better result.
            else r-=1;
        }
        return res;
    }
};

// https://youtu.be/ZHQg07n_tbg  (Can refer if you forget the thought process)

// We know that water container is a rectangle so area will be simply lxb = area so either we need to increase the length or the breadth to maximise the area . 
// Placing the pointer at two ends creates maximises the width now the interesting part if you move any of the two pointer then you are reducing the width so to balance it you must increase the height . 
// There are two pointer pointing to two different height now obviously we need to move that pointer which has less height among the two and
// we move the pointer unless it finds a height that is greater than its previous value and then calculates the area and store . 
// This proces is repeated to calculate the max area .

// Agar bade wale ko move kar dete toh kitna bhi move karte raho paani toh utna hi ayega.

// This ques has no width in the heights
// Trapping rainwater problem has widths ie Which is to get the total water for all the bars, so the ques is different.

