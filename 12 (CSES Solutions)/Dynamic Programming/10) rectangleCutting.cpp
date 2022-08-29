https://cses.fi/problemset/task/1744

// dp[w][h] = minimum number of cuts needed to cut a w x h piece into squares.

#include <bits/stdc++.h>
using namespace std;

int numOfCuts(int w, int h) {
    int dp[w+1][h+1];
    for(int i=0; i<w; ++i) dp[i][0]=0;   // either width or height is 0 then 0.
    for(int j=0; j<h; ++j) dp[0][0]=0;
 
    for(int i=1; i<=w; ++i){        // i is current total width, j is current total height
        for(int j=1; j<=h; ++j){
            if(i==j) dp[i][j]=0;    // already a square
            else{                   // else every integral cut either horizontally or vertically will give ans.
                dp[i][j] = 1e9;
                for(int k=1; k<i; ++k){                               // trying all the vertical cuts // cutting the width or base
                    dp[i][j] = min(dp[i][j], 1+dp[i-k][j]+dp[k][j]);
                }
                for(int k=1; k<j; ++k){                               // horizontal cuts
                    dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
                }
            }
        }
    }
    return dp[w][h];
}

int main() {
    // your code goes here
    int w, h;
    cin>>w>>h;
    cout<<numOfCuts(w, h);
    return 0;
}


//
SC = O(AB)
TC = O(A^2B + AB^2)
