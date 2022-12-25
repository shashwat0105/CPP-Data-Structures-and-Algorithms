https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

i = start of window
j = end of window

first we move j till it not reaches window size, then we maintain the window size.

// Code 1 (Aditya Verma)
long maximumSumSubarray(int k, vector<int> &arr , int n){
    // code here 
    int i=0; // start of window // 
    int j=0; // end of window   // j will be upto n-1
    
    long maxi = INT_MIN;
    long curSum = 0;
    while(j<n){
        curSum+=arr[j];    // j is always added no matter what
        
        // currently window size <k
        if(j-i+1 < k){
            j++;
        }
        // window size == k, maintain it
        else if(j-i+1==k){  // j grows and window size ie j-i+1 hits k
            maxi = max(maxi, curSum);
            curSum -= arr[i];
            j++;
            i++;
        }
    }
    return maxi;
}


// CODE 2

long maximumSumSubarray(int k, vector<int> &arr , int n){
    long maxi=0;

    for(int i=0;i<k;i++){
        maxi+=arr[i]; 
    }
    
    long  curSum = maxi;
    
    for(int i=k;i<n;i++){
        curSum += arr[i]-arr[i-k];
        maxi = max(maxi,curSum);
    }
    return maxi;
}

