https://leetcode.com/problems/valid-parentheses/

// Insert opening any number of time.
// Jo closing wala hai wo adjacent hi ayega first time, then we can pop the pair and check for other closing.

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); ++i){
            if(s[i]=='(' or s[i]=='{' or s[i]=='[') st.push(s[i]);
            else{
                if(st.empty() or (st.top()=='(' and s[i]!=')') or (st.top()=='{' and s[i]!='}') or (st.top()=='[' and s[i]!=']')){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};


// For explanation with comments
https://leetcode.com/problems/valid-parentheses/discuss/728304/C%2B%2B-Easiest-solution-fully-Explained-takes-0ms-beats-100-49
