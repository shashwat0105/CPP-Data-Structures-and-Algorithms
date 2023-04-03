https://leetcode.com/problems/backspace-string-compare/   

// Method 1: Using stack extra space:
// A data structure jisme agar # encounter ho then we pop the element.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;

        for(auto &c: s){
            if(c!='#') st1.push(c);
            else if(!st1.empty()) st1.pop(); // (Imp to check else runtime error) Note that after backspacing an empty text, the text will continue empty.
        }                                    // error for testcase like: t = ##cd#e  ie starting m hi # aa jae

        for(auto &d: t){
            if(d!='#') st2.push(d);
            else if(!st2.empty()) st2.pop();
        }

        return st1==st2;
    }
};

// Method 2 (Tough)
// O(1) Space using Two Pointer
// https://youtu.be/tUxW1JwEb9M

// Approach:
// We will traverse from the back. (back space se relate karo back traversal)
// If we encounter a backspace we count how many backspaces are there. ie increment the count
// If we encounter a alphabet we decrement the count.
// We will take two count variables which will be incremented on encountering a '#' and decremented on encountering an alphabet

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1;
        int j=t.size()-1;
        int countA=0;
        int countB=0;
        
        while(i>=0 || j>=0){                         // agar koi bhi string bachi ho toh bhi dekhna hoga ki kahi uski net value "" hai ya nahi yeh case bhi ho skta
            while(i>=0 && (countA>0 || s[i]=='#')){  // hash milega toh mai andar chala jaunga, alphabet mile with some count of pending hash toh andar jaunga
                if(s[i]=='#') countA++;
                else countA--;
                i--;
            }
            while(j>=0 && (countB>0 || t[j]=='#')){
                if(t[j]=='#') countB++;
                else countB--;
                j--;
            }
            
            if(i>=0 && j>=0){                        // sirf alphabets mile ne pending counts of hash to I need to compare
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

// Dry run on:
s = nzp#om##g
t = b#nzp#op##g

// Can read comments
https://leetcode.com/problems/backspace-string-compare/solution/  
