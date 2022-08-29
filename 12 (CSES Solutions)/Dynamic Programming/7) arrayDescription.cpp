https://cses.fi/problemset/task/1746

// Good Question
https://youtu.be/d1H5JylYG4I


// DP State:

dp(i, x):  No of valid arrays of size i such that the last element of ith element is x.

// My ans will look like:
dp(N, 1) + dp(N, 2) + dp(N, 3) + ... dp(N, m);  // x is varying from 1 to m

//
DP definition DP[i][x], it says number of valid Arrays A[1..i] such that ith element = x.

If A[i] = 0 then I can change to it to x and then I can obtain some valid arrays where the ith Element is X.
If A[i] is already equal to x then also some valid arrays exist where the ith element is x but if its not possible to have x at the ith position then no valid array exist where the ith element = x

//
I am trying to find out how many arrays(that follow a given property) are there of length i such that ith element = x.
now if ith element is 0 this gives me ability to choose any value for the ith element(so I can make it x if I want)
if ith element is already x then also it is alright. however if ith element is something other than x(and 0) then there is no way for me to have an array of size i with ith element as x. 

//
i am trying to find out how many arrays(that follow a given property) are 
there of length i such that ith element = x.
if the ith element  is 'x' then which element can be at can be (i-1)th index
it can be x, x-1, x+1 according to the required condition.
but if the ith position is having '0' then i will make it 'x' and form answer acc. to
same logic stated above and this will also be the sequence of 'i' length ending at x element 
if the ith element is not '0' and 'x' then there is no way to form such a sequence.
and m is already given in input and we trying out all possibilities.

// Isko ar ache se tabulate karke ar samajhna hai!! (Array is 1-based indexed.)


#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int solve(int n, int m, vector<int> &v){
    int dp[n+2][m+2];
    memset(dp, 0, sizeof dp);   // this is handling some boundary cases.

    for(int i=1; i<=n; ++i){
        for(int x=1; x<=m; ++x){                      // for every 'i' I am trying x value to put.
            if(i==1){                                 // base case here, i==1 means size is 1
                if(v[i]==0 || v[i]==x) dp[i][x] = 1;  // If the element is either unknown or x then number of valid arrays of size 1, such that last element is x is 1.
                else dp[i][x] = 0;
            }
            else{
                if(v[i]==0 || v[i]==x){
                    dp[i][x] = ((dp[i-1][x-1]+dp[i-1][x])%mod + dp[i-1][x+1])%mod;
                }
                else dp[i][x] = 0;
            }
        }
    }
    int ans = 0;
    for(int x=1; x<=m; ++x){
        ans = (ans+dp[n][x]) %mod;
    }
    return ans;

}

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> v(n+1);
    for(int i=1; i<n+1; ++i) cin>>v[i];    // Note the array is 1-base indexed.

    cout<<solve(n, m, v);

    return 0;

}




