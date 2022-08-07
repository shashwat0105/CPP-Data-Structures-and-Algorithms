// DISJOINT SET
https://cp-algorithms.com/data_structures/disjoint_set_union.html 

// Theoretical aspect is important for college and placements
// Problem ques are for competetive programming.

// There are 3 functions
// make() // adds a new node to the network
// find() // gives parent or root of the group
// union() // Join the a, b groups into a single group. Root nodes are joined
https://youtu.be/zEAmQqOpfzM


// We assign single parent to every element in a set
// Say, element a has parent x & element b has parent y -> And x = y then they belong to the same set,

// parent array will store the parent of every node
// rank is used basically according to depth of the trees, It is preferred to attach a small tree below a bigger tree.

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
    if(node = parent[node]){    // ie single node exist
        return node;
    }
//  return findParent(parent[node]);                  //without path compressed  // ie parent ka parent ka parent find krna hai jab tak base condition na hit ho jae ie root node reached
    return parent[node] = findParent(parent[node]);   // with path compressed : IMPROVES TIME as we have updated the parent of all the nodes directly to be the root node.
}

void Union(int u, int v){   // Capital U as union is a reserved word.
    u = findParent(u);      // replacing u with the root of u
    v = findParent(v);      // replacing v with the root of v

    // If rank is not there
    // if(u!=v) parent[v] = u;   // v ko leke u k neeche attach kar dia

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
        Union(u,v);
    }

    // if 2 and 3 belong to the same component or not
    if(findParent(2)!=findParent(3)){
        cout<<"Different component";
    }
    else 
        cout<<"Same component"
    return 0;
}


// Finding number of connected components using DSU
// Counting the number of roots ie find(v) == v count++;


// Other practice problems
// City and floods
// City and campers

 