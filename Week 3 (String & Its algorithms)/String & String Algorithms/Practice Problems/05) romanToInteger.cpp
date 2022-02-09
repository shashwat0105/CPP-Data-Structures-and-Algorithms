https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        int n = s.size();
        
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'V') res+= 5;
            if(s[i] == 'L') res+= 50;
            if(s[i] == 'D') res+= 500;
            if(s[i] == 'M') res+= 1000;
            
            if(s[i] == 'I'){
                if(s[i+1]=='V' || s[i+1]=='X') res-=1;
                else res+=1;
            }
            if(s[i] == 'X'){
                if(s[i+1]=='L' || s[i+1]=='C') res-=10;
                else res+=10;
            }
            if(s[i] == 'C'){
                if(s[i+1]=='D' || s[i+1]=='M') res-=100;
                else res+=100;
            }
        }
        return res;
    }
};