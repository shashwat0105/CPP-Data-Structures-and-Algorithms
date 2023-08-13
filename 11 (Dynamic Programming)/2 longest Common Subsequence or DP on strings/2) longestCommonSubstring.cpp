// https://www.geeksforgeeks.org/longest-common-substring-dp-29/
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

// x = abcde, y = abfce -> Common substrings -> ab, c, e -> longest is ab -> length = 2 Ans
// ie it should be continuos, this is different from LCS
// Jaha bhi match na kare waha pe length = 0 kar dena hai ie fr se shuru se start


int LCSubStr(string x, string y, int n, int m){   // n = rows, m = column

    vector<vector<int>> t(n+1, vector<int>(m+1, 0));
    int result = 0;                            // (code variation) To store length of the longest common substring

    // base condition(Initialisation)
    for(int i=0; i<=n; ++i) t[i][0] = 0;
    for(int j=0; j<=m; ++j) t[0][j] = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            // choice diagram
            if(x[i-1] == y[j-1]){              // ie last element matches
                t[i][j] = 1 + t[i-1][j-1];     // Instead of value when the elements matches we add 1 (qki yahi toh chahiye hai for count of LCS)
                result = max(result, t[i][j]); // (code variation)
            }
            else                               // when the elements does not match
                t[i][j] = 0;                   // (code variation) no max nothing, if it is not equal then make it 0, as we have to start a new substring
            }
    }

    return result; // (code variation) we have to return the max value in the matrix and not t[n][m]. Cuz substring can exist anywhere in between. 
}

// SPACE OPTIMISED
// USing two vectors or a 2D array of 2*n

int longestCommonSubstr (string S1, string S2, int n, int m){  // n = rows, m = column
    vector<int>prev(m+1,0), curr(m+1, 0);   // Two rows having m elements  

    int result=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S1[i-1]==S2[j-1]){
                curr[j] = 1 + prev[j-1];
                result = max(result, curr[j]);
            }else curr[j]=0;
        }
        prev=curr;
    }
    return result;
}


// For writing recursive soln, there will be one more variable ie total 3 states, hence it is not recommended to do so.
