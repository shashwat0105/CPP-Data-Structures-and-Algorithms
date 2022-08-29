https://leetcode.com/problems/n-queens/

https://youtu.be/i05Ju7AftcM

Can see the recursive tree from here.
We go in column and then in every row of that column to check for a valid position

For isValid
It is sufficient to check 3 moves of the queen to be placed now out of 8
Left
Diagonally upper left
Diagonally lower left

// Method 1

class Solution {
public:
    bool isValid(int row, int col, vector<string> board, int n){
        // check upper diagonal left in the entire currently filled board. 
        int duprow = row;
        int dupcol = col;
        while(row>=0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;                                      // both row and column decrease while moving in upper diagnol direction
            col--;
        }
        
        // check left 
        col = dupcol;
        row = duprow;
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        // check lower diagonal left
        row = duprow;
        col = dupcol;
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);             // I am inserting a 2D board here. 
            return;
        }
        
        for(int row=0; row<n; row++){         // For first column it will go in every row and find ways.
            if(isValid(row, col, board, n)){
                board[row][col] = 'Q';        // if it is valid to place a queen we put Q
                solve(col+1, board, ans, n);  // call the recursion
                board[row][col] = '.';        // backtracking step    //  For first column before going into next row, we have to revert back the changes.
            }
        }
    }   
        
public:    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<string> board(n);     // vector of string board which will go in ans  // board here is 1D.
        string s(n, '.');
        for(int i=0; i<n; ++i){
            board[i] = s;            // filling board with . (I am inserting a string in a vector of string ie board becomes 2D)
        }
        
        solve(0, board, ans, n);
        return ans;
    }
};

// Another way of writing isValid function.
int queen[20];  // queen[i] -> where my queen is in row i
bool isValid(int row, int col){
    for(int i=0; i<row; ++i){
        int prow = i;
        int pcol = queen[i];   

        if(pcol = col || abs(col-pcol)==abs(row-prow)) return 0;
    }
    return 1;
}




// Method 2 (To understand again more):
// Better Time complexity!!
// Every call inside isValid was taking O(N) time

// Hence, we optimise it using hashing // ie if there was already there a queen or not
// We hash the left check using a vector of size n
// We hash the left lowerDiagonal using a vector of size 2n -1
// We hash the left upperDiagonal using a vector of size 2n-1
// Index value at a particular cell is given by (n-1) + (row-col)

class Solution {
    
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(leftRow[row]==0 && lowerDiagonal[row + col]==0 && upperDiagonal[n-1 + col - row]==0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col - row] = 1;
                
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);   // recursive call
                
                board[row][col] = '.';                     // backtrack
                leftRow[row] = 0;                          // backtrack
                lowerDiagonal[row+col] = 0;                // backtrack
                upperDiagonal[n-1 + col - row] = 0;        // backtrack
            }
        }
    }   
        
public:    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<string> board(n);     // vector of string board which will go in ans
        string s(n, '.');
        for(int i=0; i<n; ++i){
            board[i] = s;            // filling board with . (I am inserting a string in a vector of string ie it becomes 2D)
        }
        
        vector<int> leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};





