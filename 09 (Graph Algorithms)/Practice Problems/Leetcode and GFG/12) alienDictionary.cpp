https://leetcode.com/problems/alien-dictionary/  (Premium)

https://practice.geeksforgeeks.org/problems/alien-dictionary/1

Something before something

There are 'k' alphabets from english dictionary being used.
Why the aliens are saying that "baa" apears before "abcd"
Because in their dictionary: b appears before a ie b -> a (directed edge)

First we have to create a graph from this information and return the toposort.
We create the graph by comparing every adjacent strings.

a b c d e
0 1 2 3 4  // I want to store in form of numbers

class Solution{
    public:
    vector<int> topoSort(int N, unordered_map<int, vector<int>> &adj) {
	    queue<int>q;                       
        vector<int> indegree(N, 0);       
        for(int u=0; u<N; u++){         
            for(auto &v : adj[u]){        
                indegree[v]++;            
            }
        }
        // Fill queue with nodes having indegree = 0
        for(int i=0; i<N; i++){
            if(indegree[i]==0){           
                q.push(i);
            }
        }

        vector<int> topo;                
        while(!q.empty()){              
            int u = q.front();           
            q.pop();                     
            topo.push_back(u);           
            for(auto &v : adj[u]){       
                indegree[v]--;           
                if(indegree[v]==0){      
                    q.push(v);
                }
            }
        }
        return topo;
	}
	
    string findOrder(string dict[], int N, int K) {
        //making graph
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<N-1; ++i){
            string s1 = dict[i];
            string s2 = dict[i+1];
            // Now I have to compare both the strings
            int len = min(s1.size(), s2.size());
            for(int ptr=0; ptr<len; ++ptr){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;   // IMPORTANT to break out
                }
            }
        }
        
        vector<int> topoans = topoSort(K, adj);
        
        string ans = "";
        for(auto it: topoans){
            //cout<<it<<" ";
            ans = ans + char(it + 'a');
        }
        return ans;
    }
};

// Further discussion:
When the order is not possible:
1.
abcd abc
When you exhaust the smaller, unequal tab bhi nahi mila, so smaller size string should come first. Hence above case order is not possible.
2.
When there is cyclic dependency.
