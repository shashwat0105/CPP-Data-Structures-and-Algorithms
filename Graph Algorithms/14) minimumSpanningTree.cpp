// MINIMUM SPANNING TREE (MST)

    2         3
0--------1---------2
|      /  |       /
|6   / 8  |5    / 7
|  /      |   / 
|/        | /  
3         4

When you can convert a graph to a tree such that it contains exactly N nodes and N-1 edges.
And every node should be reacheable by every other node.
  2   3
O---O---O    (5 nodes and 4 edges), Total Cost(Weight) here: 2+3+6+7=18
|       /
|6     / 7
|     /
O    O


  2   3
O---O---O     (5 nodes and 4 edges), Total Cost(Weight) here: 2+3+8+5 =18
   /| 
 8/ |5 
 O  O

O    O     O  (5 nodes and 4 edges), Total Cost(Weight) here: 6+8+5+7 = 26
|   / |   /
|6 /8 |5 /7 
| /   | /
O     O

and so on... among all these spanning trees possible from the above graph, the one having minimum weight is the MST

// PRIMS ALGORITM | MINIMUM SPANNING TREE

// It picks up a node & takes the minimal edge connected to it.

// We will require 3 arrays
// i) Key array - Every index initilised to inifinity except 0th index which is initialised to 0
// ii) MST array - Every index is initialised to False
// iii) Parent array - Every index is initialised to -1














