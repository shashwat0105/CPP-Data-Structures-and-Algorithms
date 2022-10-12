https://codeforces.com/contest/16/problem/E

https://youtu.be/d7kvyp6dfz8

Space Complexity: O(2^N)
Time Complexity: O(N^2 * 2^N)

/*
    author: kartik8800
*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

double prob[20][20];
double dp[(1<<19)];

double pMove(int prev_bitMask, int j, int& n)
{
    int k = __builtin_popcount(prev_bitMask);
    ll den = (k * (k - 1))/2;
    double moveProbab = 0;
    for(int fish = 0; fish < n; fish++)
    {
        if((1<<fish)&prev_bitMask)
            moveProbab += prob[fish + 1][j+1];
    }
    return moveProbab/(1.0*den);
}

double solve(int bitMask, int& n)
{
    int alive = __builtin_popcount(bitMask);

    if(alive == n)
        return 1;
    if(dp[bitMask] > -0.9)
        return dp[bitMask];

    double answer = 0;
    for(int fish = 0; fish < n; fish++)
    {
        if(!(bitMask & (1<<fish))){
            int prev_bitMask = bitMask^(1<<fish);
            double prev_day = solve(prev_bitMask, n);
            answer += prev_day*pMove(prev_bitMask, fish, n);
        }
    }
    return dp[bitMask] = answer;
}

int main() {
   fast_io;
   int t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
       cin >> n;
       memset(dp, -1, sizeof dp);
       rep(i,1,n+1)rep(j,1,n+1)cin >> prob[i][j];
       rep(i,0,n)
       prDouble(solve((1 << i), n)) << ' ';        // A macro used to print double.

   }

   return 0;
}
