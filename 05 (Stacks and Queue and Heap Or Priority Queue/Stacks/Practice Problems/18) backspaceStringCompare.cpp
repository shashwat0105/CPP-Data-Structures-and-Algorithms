https://leetcode.com/problems/backspace-string-compare/   

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        
        if(s[0]=='#' || t[0])
        
        for(int i=0; i<s.length(); i++){
            if(s[i]!='#'){
                st1.push(s[i]);
            }
            else if(!st1.empty()){        // (Imp to check else runtime error) Note that after backspacing an empty text, the text will continue empty.
                st1.pop();
            }
        }
        
        for(int i=0; i<t.length(); i++){
            if(t[i]!='#'){
                st2.push(t[i]);
            }
            else if(!st2.empty()){
                st2.pop();
            }
        }
        
        if(st1==st2) return true;
        else return false;
    }
};


// Method 2 (Tough)
// O(1) Space using Two Pointer
// Abhi yeh mujhe dhang se nahi samjha hai dry run karke hi samjhega
// https://youtu.be/tUxW1JwEb9M

// We will take two count variables which will be incremented on encountering a '#' and decremented on encountering an alphabet

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1;
        int j=t.size()-1;
        int countA=0;
        int countB=0;
        
        while(i>=0 || j>=0){
            while(i>=0 && (countA>0 || s[i]=='#')){
                if(s[i]=='#') countA++;
                else countA--;
                i--;
            }
            while(j>=0 && (countB>0 || t[j]=='#')){
                if(t[j]=='#') countB++;
                else countB--;
                j--;
            }
            
            if(i>=0 && j>=0){
                if(s[i]!=t[j]) return false;
                else i--, j--;
            }
            else{
                if(i>=0 || j>=0) return false;
            }
        }
        return true;
    }
};

//
// Can read comments
https://leetcode.com/problems/backspace-string-compare/solution/  
https://leetcode.com/problems/backspace-string-compare/discuss/135873/8-lines-C%2B%2B-O(1)-space-easy-to-understand
