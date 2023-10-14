https://leetcode.com/problems/flood-fill/

// Go in all four directions and reject all the invalid edges
// A particular node in a dfs call here will be represented using two variable i and j

// Better in an interview you make a copy of the input(as tampering with input is not preferred).

class Solution {
public:
    void dfs(int i, int j, int iniColor, int newColor, vector<vector<int>>& image, vector<pair<int, int>> &directions){
        int n = image.size();
        int m = image[0].size();

        // Rejecting all the invalid edges beforehand
        if(i<0 || j<0 || i>=n || j>=m || image[i][j]!=iniColor) return; // out of bound edge // I will call dfs only when do edges ka color same hoga tabhi toh fr uska color change kar paunga, this also acts as visiting array as I won't go back to the already colored node.

        image[i][j] = newColor;

        for(auto &dir: directions){
            int newI = i+dir.first;
            int newJ = j+dir.second;
            dfs(newI, newJ, iniColor, newColor, image, directions);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        vector<pair<int, int>> directions = {{1,0}, {0,-1}, {-1,0}, {0,1}};
        if(iniColor!=newColor) dfs(sr, sc, iniColor, newColor, image, directions);
        return image;
    }
};
