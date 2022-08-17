// https://www.geeksforgeeks.org/longest-common-substring-dp-29/
// x = abcde, y = abfce -> Common substrings -> ab, c, e -> longest is ab -> length = 2 Ans
// ie it should be continuos, this is different from LCS
// Jaha bhi match na kare waha pe length = 0 kar dena hai ie fr se shuru se start


int LCSubStr(string x, string y, int m, int n){

    int t[m+1][n+1];                           // OR  vector<vector<int>> dp(m+1, vector<int>(n+1));
    int result = 0;                            // (code variation) To store length of the longest common substring


    // base condition(Initialisation)
    for(int i=0; i<=m; ++i) t[i][0] = 0;
    for(int j=0; j<=n; ++j) t[0][j] = 0;

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            // choice diagram
            if(x[i-1] == y[j-1]){              // ie last element matches
                t[i][j] = 1 + t[i-1][j-1];     // Instead of value when the elements matches we add 1 (qki yahi toh chahiye hai for count of LCS)
                result = max(result, t[i][j]); // (code variation)
            }
            else                               // when the elements does not match
                t[i][j] = 0;                   // (code variation)no max nothing, if it is not equal then make it 0
            }
    }

    return result; // (code variation) we have to return the max value in the matrix and not t[m][n]. Cuz substring can exist anywhere in between. 
}

// SPACE OPTIMISED
// USing two vectors or a 2D array of 2*n

// Yet to understand.

int longestCommonSubstr (string S1, string S2, int n, int m){
    vector<int>prev(m+1,0);
    vector<int>curr(m+1,0);
    int maxx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S1[i-1]==S2[j-1]){
                curr[j]=1+ prev[j-1];
                maxx=max(maxx,curr[j]);
            }else curr[j]=0;
        }
        prev=curr;
    }
    return maxx;
}
