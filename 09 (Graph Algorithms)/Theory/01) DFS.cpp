// Depth-first search can be conveniently implemented using recursion.
// Hence used to in applications more in compare to BFS
// Bfs is used in very specific cases only which I will explain in future videos; rest must of the stuff done using dfs can be done using bfs as well; 
// so mostly you will always use dfs only until and unless any special case arrives where only bfs works..

// https://youtu.be/9_ftWKch6vI (Can watch from 18:00 to revise) (LUV)

// 1---2---4       3---5
//     |   |
//     7---6

// above are 2 components of a graph
// Adjacency List for the given graph
   u    v(child)
// 1 -> 2
// 2 -> 1 4 7
// 3 -> 5
// 4 -> 2 6
// 5 -> 3
// 6 -> 4 7
// 7 -> 2 6

// DFS Traversal -> 1 2 4 6 7 3 5 or 1 2 7 6 4 3 5

// In recursive call complete left side is called first then moving to right and so on, which is nothing but going in depth ie DFS

class Solution{
    void dfs(int u, vector<bool> &vis, vector<int> adj[], vector<int> &res){     // takes the argument of current node not total number of nodes.
        res.push_back(node);                 // we push the node
        vis[u] = true;                       // now the node is visited so we mark it as true
        for(int &v: adj[u]){                 // for every node we check its adjacency node if
            if(!vis[v]){                     // if it is not visited then we call the dfs function again
                dfs(v, vis, adj, res);       // using recursion cos recursive calls are dfs
            }
        }
    }
public:
    vector<int>dfsOfGraph(int n, vector<int>adj[]){  // no of nodes = n, edges and nodes stored in adjacency list
        vector<bool>vis(n+1, false);                 // size of the array n+1 and initialised to all 0
        vector<int>res;                              // store our dfs result
        for(int i = 1; i<=n; i++){                   // we go to every node and see (coz there could be multiple components)     
            if(!vis[i]){                             // if the node is not visited ie is not 0
                dfs(i, vis, adj, res);               // we call the dfs recursive function
            }
        }
        return res;
    }
};


// We use two things visted array & adjacency list,,, the compiler here creates a stack which keep track of executing the function

// We use this

void dfs(int v){                          // takes the argument of current node
    vis[v] = 1;                           // as we reach node we mark it as visited '1'
    cout<<v<<"->";                        // printing the node for dfs order  
    for(int &child: adj[v]){              // move in the adjacency list of ,,, using for each loop
        if(vis[child]==0)                 // we check if it is visited or not
            dfs(child);                   // if it is not visited we make recursive call to that child
    }
}
 
// Another general code that can to be used to solve DFS variations
// Very COOL Stuff
// 4 positions where u can write a piece of code depending on the question

const int N = 1e5+10;
vector<int> g[N];
bool vis[N];

// pseudo code
void dfs(int vertex){
    // ** Write codepiece here if you want to **
    // Take action on vetex after entering the vertex.         (1)
    vis[vertex] = true;                                                    // vertex m enter karne k baad we mark that it is visited
    for(int child: g[vertex]){
        // Take action on child before entering the child node (2)
        cout<<"parent "<<vertex<<", child "<<child<<endl;                  // to print the traversal
        if(vis[child]) continue;                                           // child mein ghusne se phle we check ki phle visited tha ki nahi
        dfs(child);
        // Take action on child after exiting the child node   (3)
    }
    // Take action on vertex before exiting the vertex         (4)
}


// Precompution using DFS
https://youtu.be/w2oz11KWNQY  (LUV)

// To find sum of elements in a subtree
// Tree, hence we can avoid using visited, ie simply we can check with parent (DFS in tree)
// To find number of even numbers in a subtree


// Given Q queries, Q <= 10^5
// In each query given V, Print subtree sum of V and Number of even numbers in subtree of V
const int N = 1e5+10
int g[N];
int subtree_sum[N];                                // For every array element we will compute sum of its subtree
int even_ct[N];

void dfs(int vertex, int par=0){
    // Take action on vetex after entering the vertex.         (1)
    subtree_sum[vertex] +=  vertex;                // Adding the vertex value // This can be done before or after the for loop 
    if(vertex%2==0) even_ct[vertex]++;             // If the vertex is even we increase the count                                      
    for(int child: g[vertex]){
        // Take action on child before entering the child node (2)
        if(child==par) continue;                                           
        dfs(child);
        // Take action on child after exiting the child node   (3)
        subtree_sum[vertex] += subtree_sum[child]; // Qki Upar aate hue sum calculate hoga
        even_ct[vertex] += even_ct[child];         // Har vertex mein uske child k paas kitne even honge wahi toh add karenge
    }
    // Take action on vertex before exiting the vertex         (4)
}

int main(){
    int n;
    cin>>n;

    for(int i=0; i<n-1; ++i){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);                        // calling this will precompute both the arrays
    int q;
    while(q--){
        int v;
        cin>>v;
        cout<<subtree_sum[v];     // we dont have to run dfs for every query as we have precomputed for every value
        cout<<even_ct[v];
    }
}
