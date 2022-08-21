https://cses.fi/problemset/task/1636/

// Note: In this problem, 2+1 and 1+2 will be considered one case only (So, you cannot use the coding format of dice combination problem.)
// distinct ordered ways

// Also the supply of coins is infinite (Unbounded Knapsack)
// Same as coin change problem of finding number of ways.

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int mod = 1e9+7;
    int n, Sum;
    cin >> n>> Sum;
    vector<int> coin(n);
    for(int i=0; i<n; ++i){
        cin>>coin[i];
    }
 
    vector<vector<int>> t(n+1,vector<int>(Sum+1,0));
 
    for(int i=0; i<=n; i++) t[i][0]=1;                                              
    
    for(int j=1; j<=Sum; j++) t[0][j]=0;                                              
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= Sum; j++){
            if (coin[i - 1] <= j)
                t[i][j] = (t[i][j - coin[i - 1]] + t[i - 1][j])%mod;  
            else
                t[i][j] = t[i - 1][j];
        }
    }
 
    cout << t[n][Sum] << endl;
}


