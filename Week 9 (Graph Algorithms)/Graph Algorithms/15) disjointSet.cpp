// DISJOINT SET

// We assign single parent to every element in a set
// Say, element a has parent x & element b has parent y -> And x = y then they belong to the same set,


// TC = O(4 alpha) which is constant
// findParent()
// union()

int parent[100000];
int rank[100000];

void makeSet(){
    for(int i = 1; i <=n; i++){
        parent[i] = i;            // everyone's parent is itself
        rank[i] = 0;              // and rank of everone is 0
    }
}

// 7 -> 6 -> 4 -> 3 and the ultimate parent was 3, so it will compress and make 7->3 when parent of 7 is asked
int findParent(int node){
    if(node = parent[node]){
        return nod;
    }
    return parent[node] = findParent(parent[node]);   // path compressed
}

void union(int u, int v){
    u = findParent(u);      // finding the parent of u
    v = findParent(v);

    if(rank[u] < rank[v]){
        parent[u] = v;     // took u and attach it to v
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;     // took v and attach it to u
    }
    else{                  // when both are equal
        parent[v] = u;     // can do anything
        rank[u]++;         // since they are equal the level of tree will increase (on attaching similar guys)  
    } 

}

int main(){ 
    makeSet();
    int m;
    cin>>m;

    while(m--){
        int u, v;
        union(u,v);
    }


    // if 2 and 3 belong to the same component or not
    if(findParent(2)!=findParent(3)){
        cout<<"Different component";
    }
    else 
        cout<<"Same component"

    return 0;
}




