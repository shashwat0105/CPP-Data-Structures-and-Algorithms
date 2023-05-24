https://leetcode.com/problems/sudoku-solver/

https://takeuforward.org/data-structure/sudoku-solver/
https://youtu.be/FWAIf_EVUKE   (Striver)

// We only need to return one valid sudoku(only one exists) not all possible(more complexity).

class Solution {
public:
    bool isValid(vector < vector < char >> & board, int row, int col, char c) {
      for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;                                           // to check in entire column

        if (board[row][i] == c) return false;                                           // to check in entire row

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;     // to check in the submatrix
      }
      return true;
    }
    
    bool solve(vector < vector < char >> & board) {
      for (int i = 0; i < board.size(); i++) {          // we try to find which cell/position is empty
        for (int j = 0; j < board[0].size(); j++) {
          if (board[i][j] == '.') {                     // found empty
            for (char c = '1'; c <= '9'; c++) {         // we try all from 1-9
              if (isValid(board, i, j, c)) {
                board[i][j] = c;

                if (solve(board))             // koi character rakha ja skta hai toh iska mtlb yeh nahi ki wo aage chal ek valid sudoku produce kar hi dega. Isliye poora dekhna padega ki true hai ya nahi,
                  return true;                // made recursion call to find the next empty position to be filled with next possible element
                else
                  board[i][j] = '.'; // undoing what was filled as finally a valid sudoku was not found
              }
            }

            return false; // valid sudoku not found
          }
        }
      }
      return true; // we coudn't find an empty position, hence we return a true ie our ans 
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


// To check in submatrix:
board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3]

3 * (row / 3), 3 * (col / 3)
This points at top left element in a submatrix.
+i/3 and i%3 will help in moving in the submatrix at 9 places as i increments.

// Not a recursion ques, but a sudoku ques on LC
https://leetcode.com/problems/valid-sudoku/
