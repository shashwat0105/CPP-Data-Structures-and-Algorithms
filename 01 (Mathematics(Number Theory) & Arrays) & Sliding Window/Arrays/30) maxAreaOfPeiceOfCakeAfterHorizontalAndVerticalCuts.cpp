https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        // since the edges of the cake are not included in the cut vectors, I insert them simply.
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxHeightDiff=0;
        // int currHeightDiff=0;
        for(int i=0; i<horizontalCuts.size()-1; i++){
            // currHeightDiff = horizontalCuts[i+1]-horizontalCuts[i];
            maxHeightDiff = max(maxHeightDiff, horizontalCuts[i+1]-horizontalCuts[i]);
        }
        
        int maxWidthDiff=0;
        // int currWidthDiff=0;
        for(int i=0; i<verticalCuts.size()-1; i++){
            // currWidthDiff = verticalCuts[i+1]-verticalCuts[i];
            maxWidthDiff = max(maxWidthDiff, verticalCuts[i+1]-verticalCuts[i]);
        }
        return (int)((long)maxWidthDiff * maxHeightDiff % 1000000007);
    }
};


// Python

class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:

        horizontalCuts.append(0)
        horizontalCuts.append(h)
        verticalCuts.append(0)
        verticalCuts.append(w)

        horizontalCuts.sort()
        verticalCuts.sort()
        
        maxHDiff=0
        for i in range(0, len(horizontalCuts)-1):
            maxHDiff = max(maxHDiff, horizontalCuts[i+1]-horizontalCuts[i])

        maxWDiff=0
        for i in range(0, len(verticalCuts)-1):
            maxWDiff = max(maxWDiff, verticalCuts[i+1]-verticalCuts[i])

        return (maxWDiff * maxHDiff % 1000000007)
        