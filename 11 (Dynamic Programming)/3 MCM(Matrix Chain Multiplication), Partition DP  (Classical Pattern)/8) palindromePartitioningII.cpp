https://leetcode.com/problems/palindrome-partitioning-ii/description/

Palindrome partitioning 1 is in recursion topic

// Concept of front partition.
// Make a partition from the front if that part is a palindrome, 1 + remaining part.

// Writing a recurence:
// 1) Express everything in terms of index. 
// 2) Express all possibilities.
// 3) Take the min of all possibilities
// 4) Base case


// ind = 0 to some j will be part of a temp string.
// If this temp string is a palindrome then I can make a partition at this place.

// Memoised

class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i]!= s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, string &s, vector<int> &dp){
        int n = s.size();
        if(i==n) return 0;

        if(dp[i]!= -1) return dp[i];

        int minCost = 1e9;
        // string will be always from i...j 
        for(int j=i; j<n; ++j){
            if(isPalindrome(i, j, s)){
                int cost = 1 + solve(j+1, s, dp);
                minCost = min(cost, minCost);
            }
        }
        return dp[i] = minCost;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, s, dp) -1; // A|B|C| it actuallly does an extra partition at the end as well which is not required
    }
};

// Tabulated:

// Base case:
i==n return 0
ie dp[n] = 0;

here we will go from n-1 to 0.

//
class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i]!= s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0); // coz assigning dp[n] = 0
        // base case
        dp[n] = 0;
        for(int i=n-1; i>=0; --i){
            int minCost = 1e9;
            // string will be always from i...j 
            for(int j=i; j<n; ++j){
                if(isPalindrome(i, j, s)){
                    int cost = 1 + dp[j+1];
                    minCost = min(cost, minCost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] -1; // A|B|C| it actuallly does an extra partition at the end as well which is not required
    }
};
