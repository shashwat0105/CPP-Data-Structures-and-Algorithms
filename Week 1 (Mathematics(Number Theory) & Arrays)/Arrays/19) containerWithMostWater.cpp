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
            
            int min_h = min(left_height, right_height);
            res = max(res, min_h*(r-l));
            
            if(left_height < right_height) l+=1;   // we move that direction/pointer whose height was less. To have possibility of future better result.
            else r-=1;
        }
        return res;
    }
};

// https://youtu.be/ZHQg07n_tbg  (Can refer if you forget the thought process)

// This ques has no width in the heights
// Trapping rainwater problem has widths so the ques is different.
