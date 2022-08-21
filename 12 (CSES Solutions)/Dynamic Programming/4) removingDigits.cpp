https://cses.fi/problemset/task/1637

// Jo number subtract hoke banega fr uski digits use karni hogi.

// dp(i) will store min number of steps to go from i to 0 (DP State)

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
 
  vector<int> dp(n+1);
  dp[0] = 0;
  for(int i=1; i<=n; ++i){
    int temp = i;
    int minSteps = 1e6+2;
    while(temp!=0){
        int di = temp%10;
        temp /= 10;
        if(di==0) continue;
        minSteps = min(minSteps, 1+ dp[i-di]);
    }
    dp[i] = minSteps;
  }
 
  cout<<dp[n];
}

// Alternate Code
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n+1,1e9);
  dp[0] = 0;
  for (int i = 0; i <= n; i++) {
    for (char c : to_string(i)) {
      dp[i] = min(dp[i], dp[i-(c-'0')]+1);
    }
  }
  cout << dp[n] << endl;
}



// Another soln
// Note that the greedy solution of always subtracting the maximum digit is also correct, but we are practicing DP :)

 int minSteps(int n){
    int res = 0;
    while (n != 0){
        res++;
        int t = n, m = 0;
        while(t != 0){
            m = Math.max(m, t%10);
            t/=10;
        }
        n -= m;
    }
    return res;
}
