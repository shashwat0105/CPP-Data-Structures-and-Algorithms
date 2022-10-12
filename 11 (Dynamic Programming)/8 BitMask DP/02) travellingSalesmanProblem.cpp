// NP hard problem
// Best solution is still exponential.

// BRUTE FORCE:
// First we will have n-1 options, then n-2, then n-3, then n-4 and so on.
// TC = O((n-1)!)


// DP state:
// base case
dp(i, empty_set) = distance (i,1)

dp(i, S) : min distance needed to travel, currrently at city i and need to travel all the cities of set S and get back to city 1.

dp(i, S) = min among all valid j ( dist(i, j) + dp(j, S - {j}) )

SC = O(2^N * N)
TC = O(N^2 * 2^N)

****** Other reference videos for future *****
https://youtu.be/-JjA4BLQyqE
https://youtu.be/_51ot-Ri0ng

// As this ques can be asked by google in interviews.

// CODE:
https://leetcode.com/problems/find-the-shortest-superstring/discuss/194932/Travelling-Salesman-Problem

//Travelling Salesperson

#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define f(i,a,b) for(int i=a; i<b;i++) 
#define fr(i,a,b) for(int i=a; i>=b;i--)
typedef long long int ll;
typedef vector<int> vi;
#define pb push_back
int dp[22][1>>22];
int arr[22][22];
int n;

int shortest_path(int k, int mask) {
    if(mask == 1) return dp[k][0] = arr[k][0];
    
    if(dp[k][mask]) return dp[k][mask];
    
    int ans = INT_MAX;
    f(i,1,n+1) {
        if((1<<i) & mask) {
            ans = min(ans,arr[k][i] + shortest_path(i,mask ^ (1<<i)));
        }
    }
    return dp[k][mask] = ans; 
}

int main() {
    fastio;
    memset(dp,0,sizeof(dp));
    cin>>n;
    f(i,0,n) {
        f(j,0,n) {
            cin>>arr[i][j];
        }
    }
    
    cout<<shortest_path(0,(1<<n) - 1);
}

**************************** OR *******************************
int dp[10][1 << 10];
int recur(vector<vector<int>> &cost, int i , int mask , int n){
    if(mask == 0){
        return cost[i][0];
    }
    
    if(dp[i][mask] != -1){
        return dp[i][mask];
    }
    
    int ans = INT_MAX;
    for(int j = 0; j < n ; j++){
        if(mask & 1 << j){
            ans = min(ans, cost[i][j] + recur(cost , j, mask ^ (1 << j), n));
        }
    }
    
    return dp[i][mask] = ans;
}
int total_cost(vector<vector<int>>cost){
    int n = cost.size();
    memset(dp, -1 , sizeof(dp));
    int ans = recur(cost , 0 , ((1 << n) - 2) , n);
    return ans;
}


