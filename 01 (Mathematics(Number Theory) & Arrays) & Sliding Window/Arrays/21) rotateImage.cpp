https://leetcode.com/problems/rotate-image

// TC = O(n^2)

class Solution {
public:
    // Every row is becoming a column.
    // Ans: Transpose the matrix & then reverse every row.
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // code for transpose of a matrix
        for(int i = 0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

90: Transpose + Reverse Rows
180: Reverse Rows + Reverse columns
270 : Transpose + Reverse Columns

Reverse row : reverse(matrix[i].begin(), matrix[i].end());
Reverse column: reverse(matrix.begin(), matrix.end());


