// https://youtu.be/G0N7j-x3YT4

int timer = 1;                      // integer timer count start from 1
bool dfs(int node){
    vis[node] = 1;
    In[node] = timer++;            // visiting a node and saving it's in time

    for(int child: adj[node]){
        if(vis[child] == 0){
            dfs(child);
        }
    }
    Out[node] = timer++;           // after processing all the childrens, we will save it's out time
}

// This concept helps us to ans: whether one node lies in the subtree of another or not
// In time of root < In time of child
// Out time of root > Out time of child

// So, If a node x lies in the subtree of y then: i) In time of x > In time of y ii) Out time of x < Out time of y

// This concept also helps us in finding bridges and articulation point.


