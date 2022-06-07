https://leetcode.com/problems/pascals-triangle/

https://youtu.be/6FLvhQjZqvM  (Must watch while revising)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);                  // vector of vector of int of size numRows
        
        for(int i=0; i<numRows; i++){                      // i = rows, j = columns
            res[i].resize(i+1);                            // for every row, number of the row = no of columns, resizing empty vector to size i+1
            res[i][0] = res[i][i] = 1;                     // every row has first & last element as 1
            
            for(int j=1; j<i; j++){
                res[i][j] = res[i-1][j-1] + res[i-1][j];   // [i][j] current row, column, [i-1] previous row, [j] [j-1] whose sum is to be done
            }
        }
        return res;
    }
};


// Element of rth row & cth column is given by the binomial coefficient formula:
// C(r-1, c-1)  (For 1 based indexing)

https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        
        long int nCk = 1;
        
        for(int i=0; i<rowIndex+1; i++){         // coz 0 based indexing given in ques
            res.push_back(nCk);
            nCk = nCk * (rowIndex - i)/ (i+1);
        }
        return res;
    }
};

