https://www.geeksforgeeks.org/permute-string-changing-case/
// Numbers are not there in the string. And the string consist of upper/lower case letter.
// If only lowercase were there then either we make them upper case or do nothing to it.

Aditya verma
https://youtu.be/J2Er5XceU_I

class Solution {
public:
    vector<string> ans;   // you can also declare this inside the original function and pass by & in solve function
    
    void solve(string ip, string op){
        if(ip.size()==0){
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        // for a particular letter either it will remain same or its case will be changed.
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin()+0);  // or ip = ip.substr(1) ;
        
        solve(ip, op1);
        solve(ip, op2);
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        string op = "";
        
        solve(s, op);
        return ans;
    }
};




https://leetcode.com/problems/letter-case-permutation/


// It included numbers and since I was not handling numbers, it printed every output twice ie
// digits were to be ignored initially, so I used set data structure to get an AC(HAHAHA)
// HACK SOLUTION (MINE) inspired from above.
class Solution {
public:
     set<string> help;                   // you can also declare this inside the original function and pass by & in solve function
    
    void solve(string ip, string op){
        if(ip.size()==0){
            help.insert(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin()+0);           // or ip = ip.substr(1) ;
        
        solve(ip, op1);
        solve(ip, op2);
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        string op = "";
        vector<string> ans; 
        solve(s, op);
        
        for (auto itr: help) {             // pushing elements from set to vector.
            ans.push_back(itr);
        }
        return ans;
    }
};

Aditya Verma:
https://youtu.be/4eOPYDOiwFo

https://www.cplusplus.com/reference/cctype/isalpha/

// Handling the digits inside the code:
class Solution {
public:

    void solve(string ip, string op, vector<string> &ans){
        if(ip.size()==0){
            ans.push_back(op);
            return;
        }
        
        if(isalpha(ip[0])){
            string op1 = op;
            string op2 = op;
            
            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            ip.erase(ip.begin()+0);             // or ip = ip.substr(1) ;

            solve(ip, op1, ans);
            solve(ip, op2, ans);
        }
        
        else{
            string op1 = op;                    // for digits there is only choice to just include it.
            op1.push_back(ip[0]);
            ip.erase(ip.begin()+0);             // or ip = ip.substr(1) ;
            solve(ip, op1, ans);                // hence there will be only one recursive call for digits.
        }
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        string op = "";
        vector<string> ans;    // sample code that we can also do without declaring globally.

        solve(s, op, ans);
        
        return ans;
    }
};

