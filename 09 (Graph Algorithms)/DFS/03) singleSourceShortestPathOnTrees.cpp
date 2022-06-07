// Single source shortest path (SSSP)
// To find shortest distance from source node to other node.

//       1
//     /   
//    2   
//  /   \
// 3     4
//     /   \
//    5     6

// dfs(1, 0) -> dfs(2, distance of node 1 +1) = dfs(2, 0+1) -> dfs(3, 1+1) -> dfs(4, 1+1) -> dfs(5, 2+1) -> dfs(6, 2+1)
// This works for trees not graph(we use dijasktra's algorithm in graph)

