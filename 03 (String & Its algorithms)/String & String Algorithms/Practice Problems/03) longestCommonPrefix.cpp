https://leetcode.com/problems/longest-common-prefix/

// Yet to brainstorm on this more

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.size()==0) return prefix;
        
        for(int i=0; i<strs[0].size(); i++){
            int j=1;
            for(; j< strs.size(); j++){
                if(strs[j][i] != strs[0][i]){
                    return prefix;   
                }
            }
            if(j==strs.size()) prefix.push_back(strs[0][i]);
        }
        return prefix;
        
    }
};