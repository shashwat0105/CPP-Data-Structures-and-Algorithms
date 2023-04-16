Follow up of number of Island Problem:

Number of Distinct Islands (LC premium)  https://leetcode.com/problems/number-of-distinct-islands/
Description:
https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Number%20of%20Distinct%20Islands

GFG
https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

Store the shape in set data structure and return its size.
How to store the shape?
Method 1:

string dfs(vector<vector<int>>& grid, int i, int j, string pattern) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        return "O";

    grid[i][j] = 0;
    pattern += dfs(grid, i+1, j, "D"); //D : Down
    pattern += dfs(grid, i-1, j, "U"); //U : Up
    pattern += dfs(grid, i, j-1, "L"); //L : Left
    pattern += dfs(grid, i, j+1, "R"); //R : Right

    return pattern;
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    set<string> st;
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            if(grid[i][j] == 1) {
                string island_pattern = dfs(grid, i, j, " ");
                //cout<<island_pattern<<" ";
                st.insert(island_pattern);
            }
        }
    }

    return st.size();
}

Method 2:
Striver approach
By storing the relative coordinates by subtracting from base coordinates
Code:
https://takeuforward.org/data-structure/number-of-distinct-islands/
