https://leetcode.com/problems/longest-string-chain/description/

// Similar to LIS
// The "main stuff" will change as below
// In among two strings I have to compare if they are differentiating by 1.

class Solution {
public:
    static bool comp(string &s1, string &s2){   // need to use static else error
        return s1.size() < s2.size();
    }

    bool check(string &s1, string &s2){ // s1>s2
        if(s1.size() != s2.size()+1) return false;
        int firstptr = 0;
        int secondptr = 0;
        while(firstptr<s1.size()){
            if(s1[firstptr] == s2[secondptr] && secondptr<s2.size()){
                firstptr++;
                secondptr++;
            }
            else{
                firstptr++;
            }
        }
        if(firstptr==s1.size() && secondptr==s2.size()) return true;
        return false;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp); // sort according to length
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        
        for(int i=0; i<n; ++i){
            for(int prev = 0; prev<i; ++prev){
                if(check(words[i], words[prev]) && 1 + dp[prev]>dp[i]){  // change here
                    dp[i] = 1 + dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};

// TC = O(n^2*l + nlogn)


