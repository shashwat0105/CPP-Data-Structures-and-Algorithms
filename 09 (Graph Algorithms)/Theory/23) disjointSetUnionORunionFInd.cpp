// DISJOINT SET
https://cp-algorithms.com/data_structures/disjoint_set_union.html 
https://youtu.be/zEAmQqOpfzM (LUV)
https://youtu.be/aBxjDBC4M1U (Striver)

// Theoretical aspect is important for college and placements
// Problem ques are for competetive programming.

// Example: It is asked to tell whether two nodes belong to same component.
// Method 1: Using DFS: TC = O(V+E)
// Method 2: Using DSU: TC = O(1) // Faster queries in constant time.
// Usually used in dynamic graphs. ie graphs changing at every instant.k,


// There are 3 functions
// make()  // adds a new node to the network
// find()  // gives ultimate parent or root of the group
// union() // Join the a, b groups into a single group. Root nodes are joined


// Just the DSU template gets repeated everywhere.

FIND:
// We assign single parent to every element in a set
// Also say, element a has parent x & element b has parent y -> And x = y then they belong to the same set,

// parent array will store the parent of every node
// If smaller gets attached to bigger no change in rank coz it still is the bigger one.
// If two equal gets attached then only we increase the rank.

UNION:
1. Find ultimate parent of u and v
2. Find ranks of u and v
3. Connect smaller ranks to larger ranks.
// In union, we just basically modify the parents.
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

// 7 -> 6 -> 4 -> 3 and the ultimate parent was 3, so it will compress and make 7->3 when parent of 7 is asked: This is known as path compression. ie no need of computing ultimate parent again and again.
int findUParent(int node){
    if(node = parent[node]){    // ie single node exist
        return node;
    }   
//  return findParent(parent[node]);                   //without path compressed  // ie parent ka parent ka parent find krna hai jab tak base condition na hit ho jae ie root node reached
    return parent[node] = findUParent(parent[node]);   // with path compressed : IMPROVES TIME as we have updated the parent of all the nodes directly to be the root node.
}

void Union(int u, int v){   // Capital U as union is a reserved word.
    int ultiPU = findUParent(u);      // finding ultimate parent or root of u
    int ultiPV = findUParent(v);      // finding ultimate parent or root of v

    // If rank is not there
    // if(ultiPU!=ultiPV) parent[ultiPV] = ultiPU;  // v ko leke u k neeche attach kar dia  ; If u==v then there is cycle formed due to joining of this edge.

    if(ultiPU == ultiPU) return;     // they already belong to same component.
    if(rank[ultiPU] < rank[ultiPV]){
        parent[ultiPU] = ultiPV;     // took u and attach it to v
    }
    else if(rank[ultiPU] > rank[ultiPV]){
        parent[ultiPV] = ultiPU;     // took v and attach it to u
    }
    else{                            // when both are equal
        parent[ultiPV] = ultiPU;     // can do anything
        rank[ultiPU]++;              // since they are equal the level of tree will increase (on attaching similar guys)  
    } 
}

int main(){ 
    makeSet();
    int m;
    cin>>m;

    while(m--){
        int u, v;
        cin>>u>>v;  // taking input of nodes which are connected by an edge
        Union(u,v);
    }

    // if 2 and 3 belong to the same component or not
    if(findUParent(2)!=findUParent(3)){
        cout<<"Different component";
    }
    else 
        cout<<"Same component"
    return 0;
}


Application of DSU:
// Finding number of connected components using DSU
// Counting the number of roots ie find(v) == v count++;
// DSU is also used for cycle detection.
// If in making a union of two nodes and their parent is same hence there is a cycle!!.


// Other practice problems
// City and floods
// City and campers

// CODE SNIPPET TEMPLATE OF STRIVER (DSU by rank and size)
https://ide.geeksforgeeks.org/392f3f85-cb79-4631-9da2-3dd78e775873

Advantage of union by size over rank is that, by size you can also get size of the connected component ie no of nodes in that component as well.
