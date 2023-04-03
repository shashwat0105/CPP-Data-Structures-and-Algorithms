https://leetcode.com/problems/valid-parentheses/

// https://youtu.be/wkDfsKijrZ8  (Striver)

// Insert opening any number of time.
// Jo closing wala hai wo adjacent hi ayega first time, then we can pop the pair and check for other closing.
// ie jo abhi daal rahe ho uska counterpart stack k top m bhi hona chahiye.

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
                st.pop();  // yaha pahucha mtlb pair mila hence pop it.
            }
        }
        return st.empty();
    }
};

// You always need to st.empty() check before st.top() to avoid RTE.

// For explanation with comments
https://leetcode.com/problems/valid-parentheses/discuss/728304/C%2B%2B-Easiest-solution-fully-Explained-takes-0ms-beats-100-49


// Another approach
class Solution {
public:
    bool isValid(string s) {
        string st;             // using this string as a form of stack 
        map<char,char>mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        st.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if(mp[st.back()] == s[i])             // closing bracket matches with opening
                st.pop_back();
            else
                st.push_back(s[i]);
        }
        return st.empty();
    }
};


// Another approach using ASCII
40 	( 	Left round bracket
41 	) 	Right round bracket 
91 	[ 	Left square bracket
93 	] 	Right square bracket 
123 	{ 	Left curly bracket
125 	} 	Right curly bracket 

class Solution {
public:
    bool isValid(string s) {
        if(s.empty())return true;
        int n=s.length();
        stack<char> st;
        int i=0;
        for(auto &c: s){
            if(st.empty()) st.push(c);
            else if(st.top()==c-1 || st.top()==c-2) st.pop();
            else st.push(c);
        }
        return st.empty();
    }
};
