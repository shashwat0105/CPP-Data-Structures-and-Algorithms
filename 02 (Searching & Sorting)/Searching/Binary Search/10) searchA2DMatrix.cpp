https://leetcode.com/problems/search-a-2d-matrix/


// Method 1: Brute force:

// Method 2: O(m+n)
Go left and go down:

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

// But this also has extra property apart from column elements increasing (ii) ques
// we can apply binary search 
[[1,3,5,7],[10,11,16,20],[23,30,34,60]]
[1,3,5,7,10,11,16,20,23,30,34,60]
// Single array this is sorted as well.

TO find which column number, row number our mid corresponds to we will do modulo.
log(n*m)

// 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0) return false;
        int m = matrix[0].size();
        int lo = 0, hi = (n*m)-1;
        while(lo<=hi){
            int mid = (lo+hi)>>1;
            if(matrix[mid/m][mid%m] == target) return true;
            else if(matrix[mid/m][mid%m] < target) lo = mid+1;
            else{
                hi = mid-1;
            }
        }
        return false;
    }
};

