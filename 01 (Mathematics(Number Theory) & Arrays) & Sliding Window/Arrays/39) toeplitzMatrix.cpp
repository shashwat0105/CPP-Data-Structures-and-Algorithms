https://leetcode.com/problems/toeplitz-matrix/

Google

There are multiple diagonals and all of them must have same elements among them.

We can ignore 0th row and 0th column as no top left neighbour element to compare.

https://youtu.be/q-WIid5qu-I

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(matrix[i][j]!=matrix[i-1][j-1]) return false;
            }
        }
        return true;
    }
};


Ans to follow ups
https://leetcode.com/problems/toeplitz-matrix/solutions/271388/java-solution-for-follow-up-1-2/



