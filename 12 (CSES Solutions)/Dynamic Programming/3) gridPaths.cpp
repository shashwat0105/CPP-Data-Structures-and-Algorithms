https://cses.fi/problemset/task/1638

Important Problem(Asked in Interviews)

// There are two ways to think.

// 0 to N bottom up (More intuitive to me)

https://youtu.be/V64F4wlodUM

// For the sample test case:
// DP Array: 
3 1 1 0
2 0 1 0
2 2 1 0
0 1 1 1(base)


#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    bool grid[n+1][n+1];
    
     for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            char ch;
            cin>>ch;
            if(ch=='.') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
      }

    int dp[n+1][n+1];
    for(int i = n; i >= 1; i--)
    {
        for(int j = n; j >= 1; j--)
        {
            dp[n][n] = 1;                           // Important to declare it inside, else dp[n][n] will become 0.
            
            int op1 = (j == n) ? 0 : dp[i][j+1];
            int op2 = (i == n) ? 0 : dp[i+1][j];
            dp[i][j] = (op1 + op2) % mod;
            if(grid[i][j])
                dp[i][j] = 0;
        }
    }
    if(grid[n][n])
        cout << 0;
    else cout << dp[1][1];

   return 0;
}


// N to 0. bottom up

dp[r][c] = number of ways to reach row r, column c.

We say there is one way to reach (0,0), dp[0][0] = 1.

When we are at some position with a ., we came either from the left or top. 
So the number of ways to get to there is the number of ways to get to the position above, plus the number of ways to get to the position to the left. 
We also need to make sure that the number of ways to get to any position with a # is 0.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
  vector<vector<int>> dp(n, vector<int>(n, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < n; j++) {
        if (row[j] == '.') {
            if (i > 0) {
                (dp[i][j] += dp[i-1][j]) %= mod;
            }
            if (j > 0) {
                (dp[i][j] += dp[i][j-1]) %= mod;
            }
        } 
        else {
            dp[i][j] = 0;
        }
    }
  }
  cout << dp[n-1][n-1] << endl;
}

