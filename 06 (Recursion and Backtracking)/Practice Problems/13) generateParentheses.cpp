https://leetcode.com/problems/generate-parentheses/

Aditya Verma
https://youtu.be/eyCj_u3PoJE

// We have choices at every position to take '(' or ')' and we have to such that to make it balanced.

n = 3 means we have 3 open bracket and 3 close brackets.

// Using recursive tree or IP, OP method

// Open hamesha insert ho skta hai.
// Close tabhi insert ho skta hai jab uska number open se jada ho.

class Solution {
public:
    vector<string> ans;
    
    void solve(int open, int close, string op){
        if(open==0 && close==0){
            ans.push_back(op);
            return;
        }
        
        if(open!=0){                            // yeh choice hamesha execute hogi
            solve(open-1, close, op+"(");       // cases when ( will be inserted
        }
        if(close>open){                         // yeh choice particular condition m execute hogi hence, kabhi sirf upar wala execute hoga kabhi dono.
            solve(open, close-1, op+")");     
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        string op = "";
        int open = n;
        int close = n;
        
        solve(open, close, op);
        return ans;
    }
};

// Other thought process

static void generateBalanceParathesis(String op, int o, int c) {

    if (o == 0 && c == 0) {
        System.out.println(op);
        return;
    }
    if (o == c) {
        generateBalanceParathesis(op + "(", o - 1, c);
    } 
    else {
        if (o != 0) {
            generateBalanceParathesis(op + "(", o - 1, c);
        }
        if (c != 0) {
            generateBalanceParathesis(op + ")", o, c - 1);
        }
    }
}
