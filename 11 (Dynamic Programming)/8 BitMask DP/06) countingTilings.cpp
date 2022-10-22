https://cses.fi/problemset/task/2181/

https://youtu.be/lPLhmuWMRag

dp(i, mask) = number of ways to fill the column from ith to mth given that some positions are already filled.

mask = these positions are already filled for this column.
dp(1, 0) is the final ans.

// code

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
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
 
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
 
void generate_next_masks(int current_mask, int i, int next_mask, int n, vector<int>& next_masks){  // finds how many next masks can be formed.
      if(i == n + 1){
        next_masks.push_back(next_mask);
        return;
      }
      
      if((current_mask & (1 << i)) != 0)
          generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);
      
      if(i != n)
        if((current_mask & (1 << i)) == 0 && (current_mask & (1 << (i+1))) == 0)
          generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);      
      
      if((current_mask & (1 << i)) == 0)
          generate_next_masks
                (current_mask, i + 1, next_mask + (1 << i), n, next_masks);    
}
 
int dp[1001][1<<11];
int solve(int col, int mask, const int m, const int n){
    // BASE CASE
    if(col == m + 1){
        if(mask == 0)
          return 1;
        return 0;
    }
 
    if(dp[col][mask] != -1)
      return dp[col][mask];
 
    int answer = 0;
    vector<int> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);
 
    for(int next_mask: next_masks){
        answer = (answer + solve(col + 1, next_mask, m, n)) % mod;
    }
 
    return dp[col][mask] = answer;
}
 
int main() {
   init_code();
   int t = 1; //cin >> t;
   while(t--){
        read(n); read(m);
        memset(dp, -1, sizeof dp);
        cout << solve(1, 0, m, n); 
   }
   return 0;
}


// TC analysis.
// say ith column had no position filled after filling i-1 th column.
// now let us see number of possible config's for i+1 th column.

// if jth position of i+1 th col is to be left empty then j+1th position will also
//  be empty(as you will put a vertical tile at jth position of ith column). 

// what is count of valid masks for i+1th column?
// 0 means a position is not filed(vertical tile at ith column), 1 means position is filed(horizontal tile at ith column)

// f(N) = number of ways to fill N positions using 0s and 1s given that 0s occur in pairs.

// At leftmost position if you fill in a 1 then you get f(N-1) ways and if you fill in a 0 then

// immediate position to the right is also a 0 and you get f(N-2) ways.

// f(N) = f(N-1) + f(N-2)

// f(1) = 1, f(2) = 2

// f(10) = 89

// transition time is same as number of possible next masks.

// if ith column had some positions filled then i+1th column would have even lesser possible next masks.

// approximate upper bound on time complexity = 89*89*1000 ~ 10^7
