https://leetcode.com/problems/pascals-triangle/

https://youtu.be/6FLvhQjZqvM  (Must watch while revising)

Pascal triangle to be visualised as:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);             // initialize n rows
        for(int i = 0; i < n; i++) {            // i = rows, j = columns
            ans[i] = vector<int>(i+1,1);        // ith row(0-indexed) has i+1 elements ar sabko 1 kar dia // every row has first & last element as 1
            for(int j = 1; j < i; j++)          // 1st and last elements will be 1, rest will be sum of two elements from above row
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];  // // [i][j] current row, column, [i-1] previous row, [j] [j-1] whose sum is to be done           
        }
        return ans;
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
            nCk = nCk * (rowIndex - i)/ (i+1);   // An optimised way of finding nCr
        }
        return res;
    }
};

