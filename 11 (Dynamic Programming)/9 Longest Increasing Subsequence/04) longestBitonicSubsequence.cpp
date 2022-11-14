https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
LBS

ie increase then decrease

Also it can just increase or just decrease.
ie LIS is also a LBS

Find LIS from start of array and store in dp1[]
Find LIS from back of array and store in dp2[]
Find LBS using dp1[i] + dp2[i] -1

Visualisation
https://imgur.com/qurPvtT

int LongestBitonicSequence(vector<int>nums){
    // code 
    int n = nums.size();

    vector<int> dp1(n, 1);
    for(int i=0; i<n; ++i){
        for(int prev = 0; prev<i; ++prev){
            if(nums[prev]<nums[i] && 1 + dp1[prev]> dp1[i]){
                dp1[i] = 1 + dp1[prev];
            }
        }
    }
    
    vector<int> dp2(n, 1);
    for(int i=n-1; i>=0; --i){
        for(int prev = n-1; prev>i; --prev){
            if(nums[prev]<nums[i] && 1 + dp2[prev]> dp2[i]){
                dp2[i] = 1 + dp2[prev];
            }
        }
    }
    
    int maxi=0;
    for(int i=0; i<n; ++i){
        maxi = max(maxi, dp1[i]+dp2[i]-1);
    }
    return maxi;
}
