https://cses.fi/problemset/task/1635

// This is similar to dice combination as:
// In this problem too: 1+2 and 2+1 are considered to be different.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n, target;
  cin >> n>> target;
  vector<int> coin(n);
  for(int i=0; i<n; ++i){
    cin>>coin[i];
  }
  vector<int> dp(target+1,0);
  dp[0] = 1;
  for (int i = 1; i <= target; i++){
    for(auto x: coin){                                 // In dice there was 1 to 6, here it is in form of an array.
        if(i-x>=0) dp[i] = (dp[i]+dp[i-x])%mod;
    }
  }
  cout << dp[target] << endl;
}

//
SC = O(X)
TC = O(NX)
