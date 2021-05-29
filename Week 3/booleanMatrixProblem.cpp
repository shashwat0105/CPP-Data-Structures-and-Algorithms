// Google the topic for ques/problem statement  https://www.geeksforgeeks.org/a-boolean-matrix-question/

// https://youtu.be/TBTNZXzwpP8   Watch this video to revise
// Method 1
// We will do this in a temp matrix, coz doing it in original matrix will create confusion between old 1 and new 1's
// Time complexity = No. of 1's(say = x) * (Time taken to change to all 1s in that row or column) = O(x * (m+n)), In worst case x = m*n
// Space complexity = O(m*n) extra space
//    OR
// Using two temp arrays
void booleanMatrix(vector<vector<int> > &matrix)
    {
        int row = matrix.size(); // gives number of rows
        int col = matrix[0].size(); // gives number of column
        
        // making two temp arrays, initially we give every element value false to every array element using fill STL function
        // https://www.geeksforgeeks.org/fill-in-cpp-stl/
        bool arr_row[row]; fill(arr_row, arr_row+row, false);
        bool arr_column[col]; fill(arr_column, arr_column+col, false);
        
        // storing the 1 from matrix in temp array
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(matrix[i][j]==1)
                {
                    arr_row[i]=1;
                    arr_column[j]=1;
                }
            }
        }
        
        // now putting the 1 stored in temp arrays in the original matrix as req.
        for(int i=0; i<row; i++)
        {
            if(arr_row[i])
            {
                for(int j=0; j<col; j++)
                {
                    matrix[i][j]=1;
                }
            }
        }
        for(int j=0; j<col; j++)
        {
            if(arr_column[j])
            {
                for(int i=0; i<row; i++)
                {
                    matrix[i][j]=1;
                }
            }
        }
        
    }



// Method 2
// Instead of temp matrix, in the original matrix instead of converting 0 to 1 mark them as -1 to keep a track, hence later convert all -1 to 1
// Space = O(1)
// Time is same = O(x *(m+n))

// OR
// Use 2 row_flag, col_flag variables & the 1st row and column act as the above temp arrays

