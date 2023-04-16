https://leetcode.com/problems/snakes-and-ladders/


// First we have to create a graph for this snakes and ladders.
// Then we have to run BFS

// If a takes to position b via ladder or a snake, then we have to replace a with b everywhere.
// We have to make this change in all the 6 nodes preceding vertex a.

// Last array of the input is the bottom layer of the board and so on.

// https://youtu.be/zWS2fCJGxmU  (Good vid to understand the workflow)
// 

// Explanation credits on finding the coordinates as well:
//  But because of boustrophedonically ordering, the column number alternats from left to right and from right to left. If you observe carefully
// https://leetcode.com/problems/snakes-and-ladders/discuss/794701/C%2B%2B%3A-bfs-oror-detailed-explanation-oror-faster-than-99.31

3 2 1 0
2
1
0

// We have to decode the coordinate -> See if it is visited or not.
// If it is not visited and see if there is snake/ladder or not. 


class Solution {
public:
    pair<int, int> coordinates(int x, int n){
        int r = n - 1 - (x-1)/n;
        int c = (x-1)%n;
        if(r%2 == n%2){
            return {r, n-c-1};
        }
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int steps = 0;
        queue<int> q;
        q.push(1);
        int n = board.size();
        vector<vector<bool>> vis(n, vector<bool>(n));
        vis[board.size()-1][0] = true;   // marking the bottom left element ie starting node as visited
        while(q.size()!=0){
            int z = q.size();
            for(int i=0; i<z; ++i){ 
                int x = q.front();
                if(x==n*n) return steps;  // after running bfs we reached our destination
                q.pop();
                for(int j = 1; j<=6; ++j){
                    if(j+x > n*n) break;
                    pair<int, int> p = coordinates(x+j, n);  // can store this in array of size 2 as well pos[0], pos[1]
                    if(vis[p.first][p.second]) continue;     // already visited
                    vis[p.first][p.second] = true;
                    if(board[p.first][p.second] != -1){      // either a snake or ladder
                        q.push(board[p.first][p.second]);    // we push the value in queue that is the final value
                    }
                    else{
                        q.push(j+x);   // else it is a normal node, we put it in simply
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};


