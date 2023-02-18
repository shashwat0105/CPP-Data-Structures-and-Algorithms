https://leetcode.com/problems/where-will-the-ball-fall/description/

// We have to see 1 hone pe kaha pe atak jaega, -1 hone pe kaha pe atak jaega

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> res;
        for(int ball=0; ball<n; ++ball){
            int row=0;
            int col=ball;  // every ball falls from row=0 and col = ball number

            bool atka = false;
            while(row<m && col<n){
                if(grid[row][col]==1){
                    if(col==n-1 || grid[row][col+1]== -1){ // agar abhi ka 1 hai toh wo agar last column m hai ya uska right ele -1 hai toh wo atak jaega
                        atka = true;
                        break;
                    }
                    col++;   // 1 se girne pe wo right side jaega
                }
                else{  // -1
                    if(col==0 || grid[row][col-1]==1){  // agar abhi -1 hai toh wo agar first column m hai ya uska left ele +1 hai toh wo atak jaega
                        atka = true;
                        break;
                    }
                    col--;   // -1 se girne pe wo left side jaega
                }
                row++;       // row toh badhega hi
            }
            if(atka == true) res.push_back(-1);
            else res.push_back(col);  // jis column m finally gir k pahucha
        }
        return res;
    }
};
