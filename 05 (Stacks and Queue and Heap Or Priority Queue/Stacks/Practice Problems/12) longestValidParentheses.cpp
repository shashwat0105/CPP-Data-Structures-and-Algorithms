https://leetcode.com/problems/longest-valid-parentheses/

DP(see editorial) and Stack ques

class Solution {
public:
// Method 1: Using stack (extra space)
// https://leetcode.com/problems/longest-valid-parentheses/solutions/1139990/longest-valid-parentheses-short-easy-w-explanation-using-stack/?orderBy=most_votes
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxi=0;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else maxi = max(maxi, i-st.top());
            }
        }
        return maxi;
    }
};


//

class Solution {
public:
// Method 2: O(1) space
// First we traverse left to right then right to left
    int longestValidParentheses(string s) {
        int n = s.size();
        int open = 0, close = 0, maxLen = 0;  // count variables
        for(int i=0; i<n; ++i){
            if(s[i]=='(') open++;
            else close++;
            if(open==close) maxLen = max(maxLen, 2*close); // yaha hame pair complete hua hence get a possible ans
            else if(close>open) open=0, close=0; // while going from left to right we expect more oepn bracket than close bracket agar esa na ho toh dono ka count reset kr do.
        }
        open = 0, close = 0;
        for(int i=n-1; i>=0; --i){
            if(s[i]=='(') open++;
            else close++;
            if(open==close) maxLen = max(maxLen, 2*open); // yaha hame pair complete hua hence get a possible ans
            else if(open>close) open=0, close=0; // while going from right to left we expect more close bracket than open bracket agar esa na ho toh dono ka count reset kr do.
        }
        return maxLen;
    }
};

// Test case such as:
(()  // In this case ending se traverse krne pe hi ans milega isliye dono direction se traverse krke dekhna jaroori hai
