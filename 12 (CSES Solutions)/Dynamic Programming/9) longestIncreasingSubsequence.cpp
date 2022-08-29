https://cses.fi/problemset/task/1145

// Classical Problem!! (LIS)

// In ques that ask to find required subsequence or subarrays.

// Standard way of thinking: What is best possible subarray that ends at ith element of the array.


// Kartik Arora (Other than binary search solution is there too)
https://youtu.be/wqLwv7E1GF0

// O(N^2) solution

DP State:

dp(i) = length of the longest increasing subsequence ending at ith element of the array.
Ans = max dp(i) , for every i = 1 to N

// How will we evaluate length of the longest increasing subsequence ending at ith element

dp(i) = 1 + max(dp[j]) 
j should be valid means: 1) j<i 2) A[j] < A[i] // New element getting added should be greater obviously


// Working code: O(nlogn) will pass only.

#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& A) {
    int len = 0;
    for(auto cur : A) 
        if(len == 0 || A[len-1] < cur) A[len++] = cur;             // extend
        else *lower_bound(begin(A), begin(A) + len, cur) = cur;    // replace
    return len;
}

int main() {
    // your code goes here
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; ++i){
        cin>>A[i];
    }
    cout<<lengthOfLIS(A);
    return 0;
}


