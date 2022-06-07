https://leetcode.com/problems/evaluate-reverse-polish-notation/


// string to int conversion
// https://www.freecodecamp.org/news/string-to-int-in-c-how-to-convert-a-string-to-an-integer-example/
// NOTE: you cant do int j = (int) i;
// Using " " instead of ' ' for comparison (nahi toh error ayegi)

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

