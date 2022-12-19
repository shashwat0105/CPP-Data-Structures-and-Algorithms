https://leetcode.com/problems/search-a-2d-matrix-ii/

// Method 1 brute force is linear search O(n*m)

// Method 2: Moving left and down
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // integers in "each" column are sorted
        // pointer starts from top right corner
        // moves leftwards if target<num[cur] and downwards if target>num[cur]
        // if crosses the boundary(out of bound) then that element is not found
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = m-1;
        while(i<n && j>=0){
            if(matrix[i][j]==target) return true; // if index asked return i, j
            if(matrix[i][j]>target) j--;
            else i++;
        }
        return false;
    }
};

