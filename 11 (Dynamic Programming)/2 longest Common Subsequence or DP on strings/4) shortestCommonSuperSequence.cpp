// https://www.geeksforgeeks.org/shortest-common-supersequence/
// Given Input:   str1 = "geek",  str2 = "eke" -> merge & we should get a string that has both st1 & str2 as a substring.
// Output: length of "geeke" ie 5

// We merge 2 strings and make a supersequence.
// For example:- "geekeke" is a supersequence containing both geek and eke but it's not the shortest
// "geeke" contains both geek & eke as well as is shortest too.

// In superstring sequence of alphabets = order maintain + not necessary continuos
// for ex:- "AGGTAB" m = 6, "GXTXAYB" n = 7 -> "AGGTGXABTXAYB"  is a valid supersequence but not the shortest

// The common alphabets can be written once to get the shortest supersequence
// Shortest is :- AGGXTXAYB :- 9 Ans
// Common alphabets are :- G T A B :- which is nothing but longest common substring(LCS) = 4
// Worst case of supersequence is adding both strings "AGGTABGXTXAYB" = 13 (GTAB is repetited twice so we will remove it once to get ans)

// 1) Length of SCS is to be found:

// Hence, Worst case length = m + n
// Best case(length of shortest supersequence) = (m+n) - LCS   // Ans

return m + n - LCS(x, y);

// Hence, the code will look like:
int LCS(string x, string y)
{
    int m = x.size();
    int n = y.size();
    int t[m + 1][n + 1];

    for (int i = 0; i <= m; ++i)
        t[i][0] = 0;
    for (int j = 0; j <= n; ++j)
        t[0][j] = 0;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[m][n];
}

int shortestCommonSupersequence(string x, string y, int m, int n)
{
    // code here
    return m + n - LCS(x, y);
}

// Method 2:
// Yet to understand (Refer Yt or GFG explanation)
int shortestCommonSupersequence(string x, string y, int n, int m)
{
    // dp[i][j] -> length of common shortest subsequnce from x till i
    // and from y till j
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
