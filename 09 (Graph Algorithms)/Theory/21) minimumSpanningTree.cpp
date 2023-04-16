// MINIMUM SPANNING TREE (MST)

    2         3
0--------1---------2
|      /  |       /
|6   / 8  |5    / 7
|  /      |   / 
|/        | /  
3         4

Spanning Tree:
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

