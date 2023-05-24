https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

Variable Sliding Window Problem. (Slightly difficult)

Jab given condition ie sum hit karega tab hame ans milega irrespective of size of window.

// It is better to solve this problem using concept of prefix sum.

Subarray with zero sum is also a very famous problem. 
https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

We check in unordered map that its counterpart exist or not!

Note: For the longest length we should remember the first occurence
5       5   5
^
| This 5 should be remembered to get the longest length.

// Similary for k
x and x+k are the counterparts we will search for.

//
int lenOfLongSubarr(int A[],  int n, int k) { 
    // Complete the function
    int len = 0;
    int prefixRunningSum = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;   // done this coz if u get  a prefix sum of k, then mp[k-k] will be mp[0] and i-(-1) = i+1 will the the len.  
    for(int i=0; i<n; ++i){
        prefixRunningSum+=A[i];
        // if(prefixRunningSum==k) len = i+1;
        if(mp.find(prefixRunningSum-k)!= mp.end()){
            len = max(len, i-mp[prefixRunningSum-k]);
        }
        if(mp.find(prefixRunningSum)==mp.end()){
            mp[prefixRunningSum] = i;           // ie the first occurence is stored when it didn't existed in the map
        }
    }
    return len;
} 

// Largest subarray with zero sum
https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

https://youtu.be/xmguZ6GbatA (Striver) 

Now since largest is asked, we need to store the index as well where that sum was found so that we can compute the subarray size.

int maxLen(vector<int>&A, int n){   
    unordered_map<int, int> mp;
    int maxi = 0;
    int sum = 0;
    
    for(int i=0; i<n; ++i){
        sum+=A[i];
        if(sum==0) maxi = i+1;
        else{
            if(mp.find(sum)!=mp.end()){
                maxi = max(maxi, i-mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
    }
    return maxi;
}
