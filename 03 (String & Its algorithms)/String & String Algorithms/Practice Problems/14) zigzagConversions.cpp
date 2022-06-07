https://leetcode.com/problems/zigzag-conversion/

s = "PAYPALISHIRING", numRows or totalRows = 4

P     I    N
A   L S  I G
Y A   H R
P     I

For first and last row:
No of jumps = (totalRows -1)*2         // jumps = 6 for totalRows = 4  

For other rows like here row 2 and 3
No of jumps = (totalRows -1)*2
     AS WELL AS
No of jumps = (totalRows -1)*2 - 2*(currentRow)

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows <= 1) return s;
        string result = "";
       
        int jumps = (numRows-1)*2;
        
        for(int i = 0; i < numRows; ++i){
            for(int j = i; j < n; j = j + jumps){
               result += s[j];
                
               int secondTypeOfJump = j + jumps - 2*i;
               if(i != 0 && i != numRows-1 && secondTypeOfJump < n)
                   result += s[secondTypeOfJump];
            }
        }
        return result;
    }
    
};
