https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxL(n);
        vector<int> maxR(n);
        
        maxL[0] = height[0];
        for(int i=1; i<n; ++i){
            maxL[i] = max(height[i], maxL[i-1]);  // height k current ko compare karenge maxL mein jo phle store tha usse
        }
        // for(auto it: maxL){
        //     cout<<it<<" ";
        // }
        
        maxR[n-1] = height[n-1];
        for(int i=n-2; i>=0; --i){
            maxR[i] = max(height[i], maxR[i+1]);
        }
        
        // for(auto it: maxR){
        //     cout<<it<<" ";
        // }
        
        vector<int> water(n);
        int totalWater=0;
        for(int i=0; i<n; ++i){
            water[i] = min(maxL[i], maxR[i]) - height[i];
            totalWater+=water[i];
        }
        return totalWater;
    }
};


https://www.geeksforgeeks.org/trapping-rain-water/



// OLD SOLUTION
// min(left boundary, right boundary) - arr[i]
#include <bits/stdc++.h>
using namespace std;
 
// time O(n*n) -- O(n)
int find_left_max(int arr[], int n , int i){
    int maximum =0;
    for(int j=0; j<=i; j++){
        maximum = max(maximum, arr[i]);
    }
    return maximum; 
}
 
int find_right_max(int arr[], int n , int i){
    int maximum =0;
    for(int j=n-1; j>=i; j--){
        maximum = max(maximum, arr[i]);
    }
    return maximum;
}
int find_total_water(int arr[], int n){
    int total_water = 0;
    for (int i=1; i<n; i++) // ignoring the 1st & last index as water can't be stored on them. -- O(n)
    {
        int left_max = find_left_max(arr, n, i);   // O(n) -to optimise it we think that if we can find this left max in constant time i.e. O(1)
        int right_max = find_right_max(arr, n, i);  // O(n)
        total_water = total_water + min(left_max, right_max) - arr[i];
    }
    return total_water;
}
 
int main()
{
    int arr[] = {1,0,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum water that can be accumulated is "
         << find_total_water(arr, n);    
    return 0;
}
