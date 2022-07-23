// See CP handbook for a general tree
// n nodes and n-1 edges.

// Esa graph jisme cycle na ho use bolte hai tree

// Binary tree is a special case for a tree

https://dynalist.io/d/8JunO-H3ZxPg9wDul58ouDMS (Master Tree DS almost Saare topics cover ho jaenge)

// DFS in tree 
// Like we do in graphs, instead of visited, we took parent
void dfs(int vertex, int parent=0){
    for(auto child : g[vertex]){
        if(child==parent) continue;
        dfs(child, vertex);
    }
}
