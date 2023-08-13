https://atcoder.jp/contests/dp/tasks/dp_b

Follow up of previous problem.
Allowed jumps are:
i+1, i+2, i+3,... i+k
In previous prob k = 2.

// Atcoder soln
// memoised

#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1; j<=k; j++){
        if(ind-j>=0){
            int jump = solve(ind-j, height, dp, k) + abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;
    
}

int main() {
  int n, k;
  cin>>n>>k;
  vector<int> height(n);       // NOTE: Here declaring size (n) is VVIMP else it will give SIGSEV error.
  for(int i=0; i<n; ++i){
      cin>>height[i];
  }
  vector<int> dp(n,-1);
  cout<<solve(n-1, height, dp ,k);
}

// TABULATION

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0] = 0;
    
    for(int i=1; i<n; ++i){
        int mmSteps = INT_MAX;
        
        for(int j=1; j<=k; ++j){
            if(i-j>=0){
                int jump = dp[i-j] + abs(height[i-j] - height[i]);
                mmSteps = min(mmSteps, jump);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n-1];
}

int main() {
  int n, k;
  cin>>n>>k;
  vector<int> height(n);     
  for(int i=0; i<n; ++i){
      cin>>height[i];
  }
  vector<int> dp(n,0);
  cout<<solve(n,height, dp ,k);
}


// Space optimised
// Cannot do O(N) to O(1)
// But can do O(N) to O(K) space
// If k = n then this code is not required actually.

int frog_k_dp_opt(int n,vector<int> &arr,int k){
    
    vector<int> dp(k+1,0);    // to carry k last values
    
    for(int i=1;i<n;i++){
        int min_energy= INT_MAX;
        for(int j=1;j<=k && i>=j;j++){
            int jump = dp[j] + abs(arr[i]-arr[i-j]);
            
            min_energy= min(jump, min_energy);
            for(int x=1;x<k;x++){
                dp[x]=dp[x+1];       // transfering the variable values.
            }
            
        }
        dp[k]=min_energy;
        
    }
    return dp[k];
}
