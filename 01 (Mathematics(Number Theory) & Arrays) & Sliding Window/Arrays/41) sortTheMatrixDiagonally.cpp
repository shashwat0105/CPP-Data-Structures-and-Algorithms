https://leetcode.com/problems/sort-the-matrix-diagonally/

https://youtu.be/mNWwJQ7_z4Q

For diagonal traversal in 2D matrix we need to remember two things:

1) [i+j]
left bottom to top right traversal   / / / / / / 

2) [i-j]  
left top to right bottom traversal (This ques)   \ \ \ \ \

Steps:
1) In map we will store elements diagonally [i-j]
2) Sort them
3) Store in matrix

every element of a diagonal has same value of (i-j)


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> mp;

        // store diagonal elements
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                mp[i-j].push_back(mat[i][j]);
            }
        }

        // sort them
        for(auto &it: mp){
            sort(it.second.begin(), it.second.end());
        }

        // put them back
        //(Prefered)We traverse from back, else we need access .front and move all the elements to the left
        // Here we can just access using .back and pop

        for(int i=m-1; i>=0; --i){
            for(int j=n-1; j>=0; --j){
                mat[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return mat;
    }
};

