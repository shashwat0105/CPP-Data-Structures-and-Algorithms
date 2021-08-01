// Articulation point is a node on whose removal, the graph is broken down into two or more components.

// Formulae which we will use:
// low[it] <= tin[node]  && parent!= -1
// if(child>1 && parent!= -1)  // for starting node to be articulation point

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation)
{

    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    for (auto it = adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[i])
        {
            dfs(it, node, vis, tin, low, timer, adj, isArticulation)
            {
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                {
                    isArticulation[node] = 1;
                }
            }
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }

    if (parent == -1 && child > 1)
    {
        isArticulation[node] = 1;
    }
}

int main()
{
    int n, m; // taking graph as input
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u] = push_back(v);
        adj[v] = push_back(u);
    }

    vector<int> tin(n, -1);           // assigned time of insertion as -1
    vector<int> low(n, -1);           // lowest time of insertion as -1
    vector<int> vis(n, 0);            // visited array as 0
    vector<int> isArticulation(n, 0); // it could be printed multiple times so we carry a hash

    int timer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (isArticulation[i] == 1)
            cout << i << endl;
    }

    rteturn 0;
}
