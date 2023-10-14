// A graph that can be colored exactly using 2 colors, such that none adjacent nodes can have same color.

Ques comes like, can we divide the graph into two parts or not.

// Let's color by B = Blue and G = Green
//           G---B
//          /     \
// B---G---B       G---B---G       // even(here 6) no of elements in the cycle
//          \     /                // Yes, bipartite
//           G---B


//        B
//      /   \                      // odd(here 5) no of elements in the cycle
// B---G     G---B---G             // Not bipartite
//     |     |                     // Here, G G came adjacent
//     B-----G


// B---G   B---G                  // Not cyclic
//     |   |                      // Yes, Bipartite
//     B---G

// Hence, If a graph has odd length cycle it is not bipartite, else it is bipartite

// Code Building

//       3---4
//      /    | 
// 1---2     |
//      \    |
//       8---5---6---7

// We take two colors 0 and 1

// There can be many components so I have to call for every component

// If two adjacent nodes have same color means not a bipartite.

bool checkBipartiteBFS(int curr, vector<int>adj[], vector<int> &color, int currColor){ // this func is bfs in component
    queue<int>q;                                  // queue data structure
    q.push(curr);                                 // pushed the starting node
    color[curr] = currColor;                      // color with current color ie 1
    while(!q.empty()){                            // bfs traversal - traversing in the queue till it is not empty
        int u = q.front();
        q.pop();

        for(int &v : adj[u]){                   // traverse for its adjacent node
            if(color[v] == -1){                 // not been colored yet  
                color[v] = 1-color[u];          // coloring with opposite color to the adjacent node, 1-1=0, 1-0=1 // Alternate: color[v] = !color[u]
                q.push(v);                      // once it is colored I push it in my queue data structure
            }
            else if(color[v] == color[u]){      // already been colored and if the adjacent node has same color as I have, hence it is not bipartite
                return false;                    
            }
        }
    }
    return true;                                 // completed the entire bfs traversal, queue became empty, successfully able to color with 2 different colors
}

bool isBipartite(int V, vector<int>adj[]){        // same block of code as checkbipartite of bfs
    vector<int> color(V, -1);                     // color array of size V and initialised by -1
    
    // red = 1, green = 0
    for(int i = 0; i < V; i++){                   // iterating for all the nodes
        if(color[i] == -1){                       // -1 means the node has not been visited yet
            if(!checkBipartiteBFS(i, adj, color, 1)){  // Anywhere it becomes false
                return false;                     // if any of the component is not bipartite the entire graph is not bipartite
            }
        }
    }
    return true;
}

