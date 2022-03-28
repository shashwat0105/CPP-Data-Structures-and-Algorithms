// Permutation of string letters is not involved in this ques.

https://practice.geeksforgeeks.org/problems/permutation-with-spaces3627/1

S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)

// Aditya verma 
https://youtu.be/1cspuQ6qHW0


// Isme yeh backtracking kaha lag rahi hai yeh bihari se discuss krna hai ya bina uske ho rha hai

class Solution{
public:
    vector<string> ans;
    
    void solve(string ip, string op){
        if(ip.size()==0){
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        // to include B with a space ie _B
        op1.push_back(' ');
        op1.push_back(ip[0]);
        
        // to not include B with space ie B
        op2.push_back(ip[0]);
        
        ip.erase(ip.begin()+0);
        
        // recursively calling 
        solve(ip, op1);
        solve(ip, op2);
        return;
    }
    
    vector<string> permutation(string S){
        // Code Here
        string op = "";
        op.push_back(S[0]);  // op = "A"     // A k phle space daalna hi nahi hai qki so we exclude it beforehand.
        S.erase(S.begin()+0); // ip = "BC"
        solve(S, op);
        return ans;
    }
};

// In theory:
https://www.geeksforgeeks.org/print-possible-strings-can-made-placing-spaces/

