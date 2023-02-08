https://leetcode.com/problems/spiral-matrix/


// In this approach, we will be using four loops to print all four sides of the matrix.

// 1st loop: This will print the elements from left to right.

// 2nd loop: This will print the elements from top to bottom.

// 3rd loop: This will print the elements from right to left.

// 4th loop: This will print the elements from bottom to top.

top        right


left       bottom


// TC - O(m*n)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        
        while(left<=right && top<=bottom){
            // get every element in top row
            for(int i=left; i<=right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            
            // get every element in rightmost column
            for(int i=top; i<=bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            
            // to keep a check if this condition breaks in between (also to handle cases of 1 row, 1 column of the matrix)
            if(top>bottom or left>right){
                break;
            }
            
            // get every element in bottomost row
            for(int i=right; i>=left; i--){
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            
            // get every element in leftmost column
            for(int i=bottom; i>=top; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};

// Below link has a code which uses if else if "direction" conditions to get into a particular block, which is also a good way to tackle edge cases
https://leetcode.com/problems/spiral-matrix/discuss/978853/C%2B%2B-or-0ms-faster-than-100-or-Easy-solution-with-proper-explanation

