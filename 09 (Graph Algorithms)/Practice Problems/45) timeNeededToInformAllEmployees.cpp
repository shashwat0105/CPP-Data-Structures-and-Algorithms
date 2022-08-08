https://leetcode.com/problems/time-needed-to-inform-all-employees/

https://youtu.be/qjDoGPZPIjc

class Solution {
public:
    void dfs(int managerNode, vector<int>& informTime, unordered_map<int, vector<int>> &umap, int &ans, int &mx){
        mx = max(mx, ans);
        for(auto employee: umap[managerNode]){
            ans += informTime[managerNode];
            dfs(employee, informTime, umap, ans, mx);
            ans -= informTime[managerNode];  // backtrack
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        int mx = 0;
        // creating graph
        unordered_map<int, vector<int>> umap;   
        for(int i=0; i<n; ++i){
            if(manager[i]!= -1){                 // except the head
                umap[manager[i]].push_back(i);   // 2 -> {0,1,3,4,5} 
            }
        }
        
        dfs(headID, informTime, umap, ans, mx);
        return mx;
    }
};


