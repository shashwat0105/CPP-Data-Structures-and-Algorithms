https://leetcode.com/problems/range-sum-query-2d-immutable/

// jada if else na likhna pade isliye m+1, n+1 size ki prefsum matrix li hai
// this is a better practice for 2D prefix or just prefix sum type ques

https://youtu.be/tk0Twx2VQy8  (Watch kar lena ek baar)

Picture representation : jo area do baar use hua usko ek baar add kar dia.
https://assets.leetcode.com/users/hiepit/image_1578762431.png

class NumMatrix {
public:
    vector<vector<int>> sum;  // global declare kia hai toh all elements are 0
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        sum = vector<vector<int>>(m + 1, vector<int>(n + 1)); // sum[i][j] is sum of all elements inside the rectangle [0,0,i,j]
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
        r1++; c1++; r2++; c2++; // Since our `sum` starts by 1 so we need to increase r1, c1, r2, c2 by 1  // saari queries ko ek se badha dia
        return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
