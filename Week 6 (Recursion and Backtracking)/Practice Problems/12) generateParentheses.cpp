https://leetcode.com/problems/generate-parentheses/

Aditya Verma
https://youtu.be/eyCj_u3PoJE

// We have choices at every position to take '(' or ')' and we have to such that to make it balanced.

n = 3 means we have 3 open bracket and 3 close brackets.

// Using recursive tree or IP, OP method

// If the no of Open and Closed brackets left are same, then we have only 1 choice ie to use Open bracket. or when there are non-zero number of open brackets left.
// else ie on observing tree when the no of closed are more than open bracket we can use both the brackets to fill a particular position.

// Close-- and --close will update the value of the variable close itself, 
// however if you do close-1 tere function call me 1 subtracted value pass hoga but close ki value itself will not change
// Basically it's the difference between a statement and an expression
// Close-- is like saying close=close-1  (Close-- will give memory limit exceeded, as it will not change the value of close duing recursion calls)

// Isme se hamko bas close-1 waala part chahiye
// = Waala nahi chahiye



class Solution {
public:
    vector<string> ans;
    
    void solve(int open, int close, string op){
        if(open==0 && close==0){
            ans.push_back(op);
            return;
        }
        
        if(open!=0){                            // yeh choice hamesha execute hogi
            string op1 = op;                    // making a copy
            op1.push_back('(');                 // cases when ( will be inserted
            solve(open-1, close, op1);
        }
    
        if(close>open){                         // yeh choice particular condition m execute hogi hence, kabhi sirf upar wala execute hoga kabhi dono.
            string op1 = op;
            op1.push_back(')');                 // cases when ) will be inserted
            solve(open,close-1, op1);
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



// other way of writing the code (if conditions and one liners)
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
