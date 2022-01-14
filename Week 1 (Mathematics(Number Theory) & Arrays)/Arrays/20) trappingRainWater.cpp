https://leetcode.com/problems/trapping-rain-water/

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
