https://leetcode.com/problems/clone-graph/

Watch MIK video explanation while revising.

// Seems an important ques.
// Watch more vids, discuss on LC
https://leetcode.com/problems/clone-graph/discuss/?currentPage=1&orderBy=most_votes&query=


// We need to traverse all the nodes of original graph. As soon as we reach a node, we will make a copy and recur for rest of the graph.

// Our visited array will be of Node* type not array or bool type.

https://youtu.be/jWf5F_shzho

// Using DFS

class Solution {
public:
    void dfs(Node *node, Node *copy, vector<Node *> &vis){
        vis[copy->val] = copy;
        
        for(auto x: node->neighbors){
            if(vis[x->val]==NULL){    // Not yet visited  1->2 we make a new connection
                Node * newNode = new Node(x->val);
                (copy->neighbors).push_back(newNode);
                dfs(x, newNode, vis);
            }
            else{  // 1 was already visited so now we make a reverse connection 2->1 (Undirected)
                (copy->neighbors).push_back(vis[x->val]);
            }   
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        vector<Node *> vis(1000, NULL);
        Node *copy = new Node(node->val);
        
        dfs(node, copy, vis);  // sending original graph, copy graph and visited array
        return copy;
    }
};

// Using BFS

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*,Node*> umap;
        Node* first = new Node(node->val);
        umap[node] = first;
        
        while(!q.empty())
        {
            Node* u = q.front();
            q.pop();
            vector<Node*> adj;
            for(auto x: u->neighbors)
            {
                if(umap.find(x)==umap.end())
                {
                    umap[x] = new Node(x->val);
                    q.push(x);
                }
                umap[u]->neighbors.push_back(umap[x]);
            }
            
        }
        return umap[node];
    }
};
