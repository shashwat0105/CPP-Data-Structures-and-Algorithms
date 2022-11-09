https://leetcode.com/problems/distinct-subsequences/description/

DP on strings

// Apart from LCS this is "String Matching" on DP on strings

// Count all ways ie recursion

// 1) Express in terms of index (i, j)
// 2) Explore all possible ways
// 3) Return summmation of all posssibilities.
// 4) Base case

// Recurence:
// f(i-1, j-1): no of distinct subsequence of s2[0...j] in s1[0...i]

s1 = babgbag
s2 = bag

If g==g then in s1 and s2 I have two choice ie to match this g of s1 with that of s2 or to not match it. 
If I match them then both will move back else I donot match them then j still needs to be matched so 
it will remain there itself and i will move back to get another character that could be matched with this j.

ie : return f(i-1, j-1) + f(i-1, j)

If they are not matching, I will reduce the first string and keep on searching ie return f(i-1, j)

I have taken all the possibilities
Base case:
In count ways, has to return either 0 or 1. When 1 and when 0?
If I have some portion of second string remaining and first gets exhausted return 0 
If all characters of s2 match then return 1

// Memoised
// (ind1, ind2) ~ (i, j)

class Solution {
private:
   int solve(string &s1, string &s2, int ind1, int ind2, vector<vector<int>>& dp){
        if(ind2<0 && ind1>=0) return 1;   // If second string gets exhausted ie all matched
        if(ind1<0) return 0;   // If first larger string gets exhausted ie cannot be matched now
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2] = solve(s1,s2,ind1-1,ind2-1,dp) + solve(s1,s2,ind1-1,ind2,dp);
        }
        return dp[ind1][ind2] = solve(s1,s2,ind1-1,ind2,dp);
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
            
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,t,n-1,m-1,dp);
    }
};

// Tabulated

// In writing base case again there will be issue of 0 based indexing as <0 cannot be accessed.
// Hence we change it to 1 based indexing.
// ie right shift
// Since it is shifted right, i-1 and j-1 will be compared.

// Right shifted memoised code

class Solution {
private:
   int solve(string &s1, string &s2, int ind1, int ind2, vector<vector<int>>& dp){
        if(ind2 == 0) return 1;
        if(ind1 == 0) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s1[ind1-1]==s2[ind2-1]){
            return dp[ind1][ind2] = solve(s1,s2,ind1-1,ind2-1,dp) + solve(s1,s2,ind1-1,ind2,dp);
        }
        return dp[ind1][ind2] = solve(s1,s2,ind1-1,ind2,dp);
    }

public:
    
    int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
         
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return solve(s,t,n,m,dp);
    }
};

// Tabulated

class Solution {
public:
    int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<vector<double>> dp(n+1,vector<double>(m+1,0));  // To avoid integer overflow 

    for(int i=0; i<=n; ++i) dp[i][0] = 1;
    for(int j=1; j<=m; ++j) dp[0][j] = 0;  // start from 1 else it will overwrite 1 written by i

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i-1]==t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];   // can cause integer overflow so use double and type cast to int
            }
            else dp[i][j] = dp[i-1][j];  // I forget to add else, In recursion if above was working then below won't work. But here this will definitely work along with if, If I dont write else
        }
    }
    return (int)dp[n][m];
    }
};

// Or can %MOD to avoid integer overflow

class Solution {
public:
   int numDistinct(string s, string t) {
        static int MOD = (int)1e9 + 7;            // To avoid Integer Overflow on some cases
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=0; i<n; i++) dp[i][0] = 1;   // dp table is already filled with 0, so no need of  using another for loop in base case

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][m];
    }
};

// Space optimised
// 2 arrays

class Solution {
public:
   int numDistinct(string s, string t) {
        static int MOD = (int)1e9 + 7;            // To avoid Integer Overflow on some cases or can use double and typecast
        int n = s.size(), m = t.size();

        vector<int> prev(m+1, 0), cur(m+1, 0);

        prev[0] = cur[0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == t[j-1])
                    cur[j] = (prev[j] + prev[j-1]) % MOD;
                else 
                    cur[j] = prev[j];
            }
            prev = cur;
        }

        return prev[m];
    }
};

// 1 array
// Similar to knapsack 1D array space optimization

// can traverse from back too.
class Solution {
public:
   int numDistinct(string s, string t) {
        static int MOD = (int)1e9 + 7;            // To avoid Integer Overflow on some cases
        int n = s.size(), m = t.size();

        vector<int> prev(m+1, 0);

        prev[0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=m; j>=1; j--)   // reverse the loop
            {
                if(s[i-1] == t[j-1])
                    prev[j] = (prev[j] + prev[j-1]) % MOD;  // ie just one liner code DAMN ese likh dete hai log
                // else 
                //     prev[j] = prev[j];
            }
        }

        return prev[m];
    }
};

