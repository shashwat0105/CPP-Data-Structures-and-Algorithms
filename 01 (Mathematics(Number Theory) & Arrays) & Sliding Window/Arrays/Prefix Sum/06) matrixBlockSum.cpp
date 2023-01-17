https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // 2D prefix matrix similar ques
        int row =  mat.size();
        int col = mat[0].size();

        vector<vector<int>> prefsum(row+1, vector<int> (col+1, 0));  // prefsum[i][j] is sum of all elements from rectangle (0,0,i,j) as left, top, right, bottom corresponding
        for(int i=1; i<=row; ++i){
            for(int j=1; j<=col; ++j){
                prefsum[i][j] = prefsum[i][j-1] + prefsum[i-1][j] + mat[i-1][j-1] - prefsum[i-1][j-1];
            }
        }

        // Now running some range queries type of stuff
        vector<vector<int>> res(row, vector<int>(col));
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                int r1=max(0, i-k);
                int c1=max(0, j-k);
                int r2=min(row-1, i+k);
                int c2=min(col-1, j+k);
                r1++; c1++; r2++; c2++; // Since `prefsum` start with 1 so we need to increase r1, c1, r2, c2 by 1
                res[i][j] = prefsum[r2][c2] - prefsum[r2][c1-1] - prefsum[r1-1][c2] + prefsum[r1-1][c1-1];
            }
        }
        return res;
    }
};





1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/solutions/452478/java-prefix-sum-binary-search-clean-code-o-m-n-log-min-m-n/

https://leetcode.com/hiepit/ -> solutions
