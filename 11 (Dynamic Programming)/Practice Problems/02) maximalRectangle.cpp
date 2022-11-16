https://leetcode.com/problems/maximal-rectangle/description/

Prerequisites: Area of larrgest rectangle in historgram.

DP on rectangles: Striver

https://imgur.com/NRUoyLw 

Treating this rectangle grid as having histograms.

If array element is 1 it will increase the previous height.
Else 0 will make the height 0.

//

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        int n = heights.size();
        
        for(int i=0; i<=n; ++i){ // we go one more step in heights ie ground level
            while(!s.empty() && (i==n || heights[s.top()] >= heights[i])){
                int h = heights[s.top()];
                s.pop();
                int width;
                if(s.empty()) width = i;
                else width = i-s.top()-1;
                maxArea = max(maxArea, width*h);
            }
            s.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;
        vector<int> height(m, 0);
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};

// The previous heights are memorised to find other heights so DP.

