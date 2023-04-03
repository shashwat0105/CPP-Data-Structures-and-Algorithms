https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
// Using next permutation ques concept
    int nextGreaterElement(int m) {
        string s1 = to_string(m); // given 12 -> "12"
        int n = s1.size();
        int breakpt = -1;
        // finding breakpt
        for(int i=n-2; i>=0; --i){
            if(s1[i]<s1[i+1]){
                breakpt = i;
                break;
            }
        }
        if(breakpt<0) return -1;
        else{
            for(int i=n-1; i>breakpt; --i){
                if(s1[i]>s1[breakpt]){
                    swap(s1[i], s1[breakpt]);
                    reverse(s1.begin()+breakpt +1, s1.end());
                    break;
                }
            }
        }
        long long ele = stoll(s1);   // iska dhyan rakhna hoga
        if(ele>INT_MAX) return -1;  // out of bound na chala jae
        return ele;
    }
};

