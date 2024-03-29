// DP on subsequence

// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
// Problem Statement arr[] : {1, 2, 7}, To split array into two parts such that absolute(Sum2 - Sum1) = min
// Here Output = 4

// CRUX: Here we have to utilise the last row of formed by the tabulation DP.

// This problem is most similar to equal sum partition ques where Sum2 - Sum1 = 0, say S2 & S1
// S1, S2 belongs to [0, sum of all array elements(range)] // We found the extreme values of S1 & S2 ie when subset is empty and completely fill
// Here S1, S2 belongs to [0, 10] ie {1,2,3,4,5,6,7,8,9,10}
// Since S1 + S2 = range -> S2 = range - S1 -> Problem reduces to (Range - 2*S1) = min
// Assuming S2>S1 -> S1 < (Range/2) , to make overall positive difference
// Hence S1 belongs to [0, 5] ie {1,2,3,4,5} , Now we filter out the sums which are not possible to make with given array
// How to filter? Ans: by using subset sum problem for example sum = 4 will exist or not for given {1,2,7} array
// Hence S1 belongs to {1,2,3}
//   0  1 2 3   4 5 6 7 8 9 10  -> j(Sum)
// 0 T  F F F   F F F F F F  F   
// 1 T
// 2 T
// 3 T  T T (T) F F F T T T  T   // This last row represents(smaller problems) when size of array is 3 & sum varies from 0 to 10 (which we want)
// i(n)

// ******* IMP *****
// for minimizing difference between two sets, we need to know a number that is just less than sum/2 (sum is sum of all elements in array) 
// and can be generated by addition of elements from array. 

// The idea is, sum of S1 is j and it should be closest to sum/2, i.e., 2*j should be closest to sum.  (T) shown in table
// So, we move from S/2 to 0 and as soon as we find a T we break the loop and calculate diff with the index of that T value.

// code

int findMin(int arr[], int n){
    int Range=0;
    for(int i=0; i<n; i++){
        Range+=arr[i];                             // All the possible sum values lies bw 1-Range
    }

    // Subset Sum making bottom up table
    bool t[n+1][Range+1];

    // base condition
    for(int i=0;i<=n;i++)
        t[i][0]=true;

    for(int j=1;j<=Range;j++)
        t[0][j]=false;

    // choice diagram
    for(int i=1;i<=n;i++){
        for(int j=1;j<=Range; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];         // Or means to chose if a particular sum is possible or not.
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    // Calculating the difference
    int diff = INT_MAX;

    for(int j = Range/2; j>=0; j--){
        if(t[n][j]==true){
            diff=Range-2*j;                      // one sum is j(here 3), other sum is Range - j(here 7),, Hence, diff = Sum - j - j = 4(here).
            break;                               // no need to check on other T values
        }
    }
    return diff;
}

// STRIVER // 
// GFG 
https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int minDifference(int arr[], int n)  { 
    // Your code goes here
    int totSum = 0;
    for(int i=0; i<n; ++i) totSum+= arr[i];
    int sum = totSum;
    
    // copy paste the subset sum code here
    vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
    for(int i=0; i<n; ++i) dp[i][0] = true;
    if(arr[0]<=sum) dp[0][arr[0]] = true;
    
    for(int ind=1; ind<n; ++ind){
        for(int target=1; target<=sum; ++target){
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = take | notTake;
        }
    }
    // DP table is now created : dp[n-1][col->0 to totSum]
    
    int mini = 1e9;
    for(int s1=0; s1<=totSum/2; ++s1){           // we can go till half of the array we are good to go.
        if(dp[n-1][s1]){
            mini = min(mini, abs(totSum-2*s1));
        }
    }
    return mini;
} 


// We can optimise space as well: dp[n-1][s1] will be prev[s1]  (because last row hi toh chahiye hai    )


// Follow up:
-ve numbers wala
We use meet in the middle approach for this.

https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/discuss/2721045/BEST-SOLUTION-oror-%22Tabulation%22-Failed-oror-(FULL-EXPLAINATION)-oror-C%2B%2B


https://www.youtube.com/results?search_query=2035.+Partition+Array+Into+Two+Arrays+to+Minimize+Sum+Difference

https://youtu.be/JUFHwaZjO_M  (Watch in future)