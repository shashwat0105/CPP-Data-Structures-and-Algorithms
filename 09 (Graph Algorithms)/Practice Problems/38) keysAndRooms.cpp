https://leetcode.com/problems/keys-and-rooms/

// Graph already bana hua tha mai fr bhi bana raha tha :|

class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int node, vector<int> & vis){
        vis[node] = 1;
        for(auto it: rooms[node]){
            if(vis[it]==0){
                dfs(rooms, it, vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n+1, 0);
        dfs(rooms, 0, vis);
        for(int i=0; i<n; ++i){
            cout<<vis[i]<<" ";
            if(vis[i]==0) return false;           // checking if any node is not visited
        }
        return true;
    }
    
};

// OR by counting the number of nodes visited in the graph
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int &numbers, int node, vector<int> &visited){
        visited[node] = 1;
        numbers++;
        for(auto it: rooms[node]){
            if(!visited[it]){
                dfs(rooms, numbers, it, visited);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n+1, 0);
        int numbers=0;
        dfs(rooms, numbers, 0, visited);
        cout<<numbers;

        if(numbers==n) return true;
        return false;
    }
    
};
