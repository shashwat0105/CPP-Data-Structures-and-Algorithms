https://leetcode.com/problems/decode-string/

https://youtu.be/yaCRdWMq4A4

class Solution {
public:
    string recDecodeString(string &s, int &i){
        string ans;
        while(i<s.length() && s[i]!=']'){
            if(isdigit(s[i])){                         // whenever we encounter a digit (Inbuilt function)
                int k = 0;
                while(i<s.length() && isdigit(s[i])){
                    k = k*10 + s[i++] - '0';          // say the number to extract is 365
                }
                i++;                                  // skip the '['
                string r = recDecodeString(s, i);
                while(k-- > 0){                       // append it k times
                    ans += r;
                }
                i++;                                  // i is now pointing at ']' so we skip it
            }
            else{                                     // its not a digit
                ans += s[i++];                        // directly append it to the result
            }
        }
        return ans;
    }
    
    string decodeString(string s) {
        int i = 0;
        return recDecodeString(s, i);
    }
};

