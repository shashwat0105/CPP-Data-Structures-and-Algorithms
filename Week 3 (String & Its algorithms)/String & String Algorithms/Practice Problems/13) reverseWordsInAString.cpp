https://leetcode.com/problems/reverse-words-in-a-string/

TC = O(n)

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res;
        
        int i = 0;
        while(i<n){
            while(i<n && s[i]==' ') i++;                // i will move in spaces
            if(i>=n) break;
            
            int j = i+1;
            
            while(j<n-1 && s[j]!=' ') j++;              // j will move in non space characters
            string curstring = s.substr(i, j-i);        // substr(start index, length of the substring),, In java and python (start, end index)
            
            if(res.size() == 0) res = curstring;
            else res = curstring + " " + res;
            i = j+1;
        }
        return res;
    }
};

