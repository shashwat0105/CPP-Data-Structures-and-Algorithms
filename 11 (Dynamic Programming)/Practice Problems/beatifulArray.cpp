https://codeforces.com/contest/1155/problem/D


https://youtu.be/IgBLv32QFoQ

// Revise Kadane's algo too. (Array folder) 

// Standard Approach:
// To find the largest subarray, or subsequence. 
// We should define our DP in such a way that : what is the best/required subarray that ends at ith element.
// It can start at any index before or at i.

// Using x:
1) dp(i) = i) v[i]                        // simply the ith element.
           ii) v[i] + max(dp(i-1, 0),     // subarray ending at i-1th, Either I stopped using x way before 
                           dp(i-1, 1, 1)) // subarray ending at i-1th, Or , I stopped using x 1 element before, ie x is usable and was being used.

2) dp(i, 1, 0)   // best subarray ending at ith element, x is usable, not currently in use, I may start using it whenever I want to.
3) dp(i, 1, 1)   // best subarray ending at ith element, x is usable, and I am using it too.
//
//**********
1) dp(i, 1, 0) = i) v[i]
                 ii) dp(i-1, 1, 0) + v[i]

2) dp(i, 1, 1) = i) x*v[i]
                 ii) x*v[i] + max(dp(i-1, 1, 0), dp(i-1, 1, 1))

/////////////////////////////
dp[ith index][x is usable(1) or not usable(0)][I am using it(1) or I am not using it(0)]

dp[i][0][0],, the last 0 is a dummy variable. If it not usable then aage ka sense hi ni banta.

// CODE:

#include<bits/stdc++.h>
using namespace std;
// #define ll long long

long long  solve(vector<int> &v, int n, long long x){
    long long dp[n+1][2][2];
    memset(dp, 0, sizeof(dp));

    dp[0][1][0] = v[0];
    dp[0][1][1] = x*v[0];

    long long ans = max(0LL, max(1LL*v[0], x*v[0]));

    for(int i=1; i<n; i++){
        dp[i][1][0] = max(1LL*v[i], v[i] + dp[i-1][1][0]);
        dp[i][1][1] = max(x*v[i], x*v[i] + max(dp[i-1][1][1], dp[i-1][1][0]));
        dp[i][0][0] = max(1LL*v[i], v[i] + max(dp[i-1][1][1], dp[i-1][0][0]));  // the last 0 is a dummy

        ans = max(ans, max({dp[i][1][0], dp[i][1][1], dp[i][0][0]}));
    }
    return ans;
}


int main(){
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<solve(v, n, x)<<'\n';
}


// Note: DP question m seedhe karte jao,
// Kab max hoga kab positve hoga kab negative hoga yeh sochna tmhre kaam nahi hai
// Yeh fr greedy ho jata


