https://www.geeksforgeeks.org/permute-string-changing-case/
// Numbers are not there in the string. And the string consist of upper/lower case letter.
// If only lowercase were there then either we make them upper case or do nothing to it.

Aditya verma (By making copy method) // learn logic, not his coding style.
https://youtu.be/J2Er5XceU_I
https://youtu.be/4eOPYDOiwFo


class Solution {
public:
    vector<string> ans;   // you can also declare this inside the original function and pass by & in solve function
    
    void solve(string ip, string op){
        if(ip.size()==0){
            ans.push_back(op);
            return;
        }
        
        // pick lower and uppercase
        char ch = tolower(ip[0]);
        char ch2 = toupper(ip[0]);
        ip = ip.substr(1);         // ip.erase(ip.begin()+0);
    
        solve(ip, op + ch);
        solve(ip, op + ch2);

        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        string op = "";
        
        solve(s, op);
        return ans;
    }
};


https://leetcode.com/problems/letter-case-permutation/

class Solution {
public:
    void solve(string ip, string op, vector<string> &ans){
        if(ip.size()==0){
            ans.push_back(op);
            return;
        }
        
        if(isalpha(ip[0])){
            char ch = tolower(ip[0]);
            char ch2 = toupper(ip[0]);
            ip = ip.substr(1) ;

            solve(ip, op+ch, ans);
            solve(ip, op+ch2, ans);
        }
        
        else{  // if it is a digit just include it
            char ch3 = ip[0];
            ip = ip.substr(1) ;
            solve(ip, op+ch3, ans);
        }
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        string op = "";
        vector<string> ans;    
        solve(s, op, ans);
        
        return ans;
    }
};

// You can also do it by taking an index variable i.

https://www.cplusplus.com/reference/cctype/isalpha/
