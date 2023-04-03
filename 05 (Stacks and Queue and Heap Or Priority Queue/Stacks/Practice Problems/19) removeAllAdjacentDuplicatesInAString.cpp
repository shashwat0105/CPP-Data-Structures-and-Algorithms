https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// Using stack
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        string ans="";
        
        for(auto &c: s){
            if(st.empty() || st.top()!=c) st.push(c);
            else st.pop(); 
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// Without stack by just traversing(more intuitive) // using ans string as a kind of stack
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string ans="";
        
        for(auto &c: s){
            if(ans.size()==0) ans.push_back(c);
            else if(ans.back()==c) ans.pop_back();
            else ans.push_back(c);
        }
        return ans;
    }
};
