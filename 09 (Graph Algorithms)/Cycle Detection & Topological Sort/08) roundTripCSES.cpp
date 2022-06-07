// https://cses.fi/problemset/task/1669

// temp = {1,4,3,2,4} , print from last to till u reach a no equal to last to get a cycle

bool dfs(int node, int par){
    vis[node] = true;
    temp.push_back(node);

    for(int v: adj[node]){
        if(vis[v] == false){
            if(dfs(v, node)== true) return true;
        }
        else
            if(par!=v){
                temp.push_back(v);
                return true;
            }
    }

    temp.pop_back();
    return false;
}


