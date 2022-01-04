https://leetcode.com/problems/student-attendance-record-i/

class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<n; ++i){
            if(s[i]=='A'){
                count++;
                if(count>1){
                    return false;
                }
            }
            else if(s[i]=='L' && s[i+1]=='L' && s[i+2]=='L'){
                return false;
            }
        }
        return true;
    }
};

// 1 line python
return s.count('A') <= 1 and s.count('LLL') == 0
