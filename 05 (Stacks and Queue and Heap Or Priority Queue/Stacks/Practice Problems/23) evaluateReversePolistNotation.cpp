https://leetcode.com/problems/evaluate-reverse-polish-notation/

// string to int conversion
// https://www.freecodecamp.org/news/string-to-int-in-c-how-to-convert-a-string-to-an-integer-example/
// NOTE: you cant do int j = (int) i;
// Using " " instead of ' ' for comparison (nahi toh error ayegi)

// Hamko operation perform krne k liye do numbers chahiye toh jo stack m do latest numbers hai unhe nikalo ar calculate krke result dobara daal do stack mein.
// Here x1 and x2.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(auto i: tokens){
            if(i!="+" && i!="-" && i!="*" && i!="/"){
                int j = std::stoi( i );                    // string to int conversion
                s.push(j);
            }
            else{
                int x2 = s.top();
                s.pop();
                int x1 = s.top();
                s.pop();
                if(i=="+"){
                    s.push(x1+x2);
                }
                if(i=="-"){
                    s.push(x1-x2);
                }
                if(i=="*"){
                    s.push(x1*x2);
                }
                if(i=="/"){
                    s.push(x1/x2);
                }
            }
        }
        
        return s.top();
    }
};

// Another fancy lambda method (not much necessary just for learning and fun)
// Using fancy lambda, unordered_map
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        
        unordered_map<string, function<int (int, int)> > mp = {
            {"+", [](int a, int b) {return a + b; } },
            {"-", [](int a, int b) {return a - b; } },
            {"*", [](int a, int b) {return (long)a * (long)b; } },
            {"/", [](int a, int b) {return a / b; } },
        };
        
        for(const string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                result = mp[s](a, b);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
