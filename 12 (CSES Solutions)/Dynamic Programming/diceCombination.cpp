https://cses.fi/problemset/task/1633/ 

// Bottom Up

#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
  vector<int> dp(n+1,0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++){
    for (int x = 1; x <= 6 && i-x >= 0; x++){
        (dp[i] += dp[i-x]) %= mod;                // dp[i] = (dp[i]+dp[i-x])%mod;
    }
  }
  cout << dp[n] << endl;
}

// Recursive:

#include <bits/stdc++.h>
using namespace std;

int compute (int left) {
    if(left==0) return 1;
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        if (left - i >= 0) {
            ans += compute(left - i);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << compute(n) << endl;
}


// Memoised or TopDown.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 1000001
#define MOD 1000000007

int DP[MAXN], n;
int compute (int left) {
    if(left==0) return 1;

    if (DP[left] != 0) {
        return DP[left];
    }
    for (int i = 1; i <= 6; i++) {
        if (left - i >= 0) {
            DP[left] += compute(left - i);
            DP[left] %= MOD;
        }
    }
    return DP[left];
}

int main() {
    cin >> n;
    memset(DP, 0, sizeof(DP));
    cout << compute(n) << endl;
}
