https://leetcode.com/problems/trapping-rain-water/

https://youtu.be/m18Hntz4go8 (Striver)

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
            totalWater += water[i];
        }
        return totalWater;
    }
};

// Dont do with stack as it is difficult to explain.

// Without extra space:
https://leetcode.com/problems/trapping-rain-water/solutions/1374608/c-java-python-maxleft-maxright-so-far-with-picture-o-1-space-clean-concise/?orderBy=most_votes

Another Genius:
https://leetcode.com/problems/trapping-rain-water/solutions/17403/c-two-pointers/?orderBy=most_votes

2 pointer approach. total 4 variables
l = 0
r = n-1
leftMax = 0;
rightMax = 0;

// In above approach
min(leftMax, rightMax) - a[i];
either u are taking leftMax-a[i] or rightMax-a[i]
Konsa lena hai iske liye usi direction m move kr rhe jiski height choti hai.

//
class Solution {
public:
// without extra space
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) return 0;
        int l=0, r=n-1;
        int res = 0;
        int maxL = 0, maxR = 0;

        while(l<=r){
            if(height[l]<=height[r]){                 // left wali wall se ans nikal skte hai isliye left side se move karenge
                if(height[l]>=maxL) maxL = height[l]; // need to update it as water cannot be trapped here
                else res += maxL - height[l];         // It can trap some water so we calculate it
                l++;
            }
            else{
                if(height[r]>=maxR) maxR = height[r];
                else res += maxR - height[r];
                r--;
            }
        }
        return res;
    }
};

