https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Primarily a ques of recursion
// Digit: 2346 
// We will find ans for say 6 and let recursion do the remaining job

class Solution {
public:
    vector<string> recur(string &D, int i, map<int, string> &m){  // So that copies of the string is not made
        if(i==D.size()) return {""};           // base case return empty vector of string
        
        vector<string> temp = recur(D, i+1, m);   // will give me string of remaining part
        vector<string> ans;
        
        for(auto a: m[D[i]-'0']){   // for every element in say m[6]
            for(auto x: temp){      // for every string in temp
                ans.push_back(a+x);
            }
        }
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};                 // note here you can't do {""}
        map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        return recur(digits, 0, m);
    }
};

// Other code
// DFS view explanation
https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/1148310/JS-Python-Java-C%2B%2B-or-Easy-Recursive-DFS-Solution-w-Explanation
