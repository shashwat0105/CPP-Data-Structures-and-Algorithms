https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// Using stack
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        string ans="";
        
        for(int i=0; i<n; ++i){
            if(st.empty() || st.top()!=s[i]){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// Without stack by just traversing(more intuitive)
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string ans="";
        
        for(auto i: s){
            if(ans.size()==0) ans.push_back(i);
            else if(i == ans.back()) ans.pop_back();
            else ans.push_back(i);
        }
        return ans;
    }
};

