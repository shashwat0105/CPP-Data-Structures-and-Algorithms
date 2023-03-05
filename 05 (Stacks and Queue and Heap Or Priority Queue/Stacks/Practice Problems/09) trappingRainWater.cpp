https://leetcode.com/problems/trapping-rain-water/


// Total unit of water = Sum of water trapped above each building

// No use of NGL or NGR here (Hence dont confuse with max area of histogram MAH problem)

// Kisi bhi building k upar ka paani
// Left array ki heighest building, Right array ki heighest building
// In dono ka minimum will give me height of water level.
// Water trapped = water level - height of building

// water[i] = min(maxL, maxR) - height[i];
// Total water = sum of water[i]

// To find maxL and maxR

//Height: 0 1 0 1 2 1 0 1 3 2 1 2 1
// maxL : 0 1 1 1 2 2 2 2 3 3 3 3 3  // traverse from left and compare
// maxR : 3 3 3 3 3 3 3 3 3 2 2 2 1  // traverse from right and compare
// min  : 0 1 1 1 2 2 2 2 3 2 2 2 1
// Water: 0 0 1....


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxL(n);
        vector<int> maxR(n);
        
        maxL[0] = height[0];
        for(int i=1; i<n; ++i){
            maxL[i] = max(height[i], maxL[i-1]);            // height k current ko compare karenge maxL mein jo phle store tha usse (Yeh kisko kisse compare karna hai isme galti kar di thi)
        }
        
        maxR[n-1] = height[n-1];
        for(int i=n-2; i>=0; --i){
            maxR[i] = max(height[i], maxR[i+1]);
        }
        
        vector<int> water(n);
        int totalWater=0;
        for(int i=0; i<n; ++i){
            water[i] = min(maxL[i], maxR[i]) - height[i];
            totalWater+=water[i];
        }
        return totalWater;
    }
};

