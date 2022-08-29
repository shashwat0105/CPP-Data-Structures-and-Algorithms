https://cses.fi/problemset/task/1639

// Classic DP problem.

DP State:

dp(i, j) = edit distance(min operations) for [si... sn] and [pj....pm]
dp(1, 1) = required ans for [s1...sn] and [p1...pn]

// TOP_DOWN

// warning: comparison between signed and unsigned integer expressions

#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];


// strings are to be always passed by reference as everytime copying is O(N) time operation in itself, and overtall TC will be O(N^3)
int solve(int i, int j, string &s1, string &s2){   // i to last character of s1 and j to last character of s2 are to be matched. 
    
    // base case
    if(i==s1.length() || j==s2.length()){                    // either of the string got exhausted
        return max((int)s2.length()-j, (int)s1.length()-i);  // It is always better to convert unsigned integers to integers
    }

    if(dp[i][j]!= -1) return dp[i][j];

    int ans;
    if(s1[i]==s2[j]){
        ans = solve(i+1, j+1, s1, s2);
    }
    else{
        int op1 = 1 + solve(i, j+1, s1, s2);    // insert an element before i to match jth element // i remains the same, j moves forward(was matched)
        int op2 = 1 + solve(i+1, j, s1, s2);    // remove // remove an element i, without knowing whether it will get matched or not
        int op3 = 1 + solve(i+1, j+1, s1, s2);  // replace  // replace ith character with jth character, both will move forward
        ans = min({op1, op2, op3}); 
    }
   
    return dp[i][j] = ans;

}

int main() {
    memset(dp, -1, sizeof dp);
    string s1, s2;
    cin>>s1>>s2;

    cout<<solve(0, 0, s1, s2);

    return 0;
}


// BOTTOM UP

int main(){
    string str1,str2;
    cin>>str1>>str2;
    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>> dp(n1+2,vector<int> (n2+2,0));

    for(int i=0;i<=n2;i++){
        dp[0][i]=i;
    }

    for(int i=0;i<=n1;i++){
        dp[i][0]=i;
    }

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(1+dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
            }
        }
    }
    cout<<dp[n1][n2]<<endl;
    return 0;
}

