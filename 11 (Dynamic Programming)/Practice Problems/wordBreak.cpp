https://leetcode.com/problems/word-break/

YET TO UNDERSTAND DHANG SE
https://www.youtube.com/results?sp=mAEB&search_query=word+break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int dp[n+1];
        memset(dp, 0, sizeof dp);
        dp[n] = 1;
        
        unordered_set<string> dict;
        for(string &word: wordDict){
            dict.insert(word);
        }
        
        // dp[i]
        for(int i=n; i>=0; --i){
            string word;
            for(int j=i; j<n; ++j){
                word.push_back(s[j]);
                if(dict.find(word)!=dict.end() && dp[j+1]) dp[i] = 1;
            }
        }
        return dp[0];
    }
};
