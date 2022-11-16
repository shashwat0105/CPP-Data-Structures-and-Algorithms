https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

DP on rectangle: Striver

In rectangle problems tabulation is more intuitive than recursion.

For every element how many squares are there whose this element is the right bottom guy.

//

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0)); // create a dp table
        for(int i=0; i<n; ++i) dp[i][0] = matrix[i][0];
        for(int j=0; j<m; ++j) dp[0][j] = matrix[0][j];  // copied all

        // dont do the first row and first column again else error. coz they are just that square values only.
        for(int i=1;i<n; ++i){
            for(int j=1; j<m; ++j){
                if(matrix[i][j]==0) dp[i][j]=0; // no change
                else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                }
            }
        }
        int sum = 0;
        for(int i=0;i<n; ++i){
            for(int j=0; j<m; ++j){
                sum+=dp[i][j];
            }
        }
        return sum;
    }
};
