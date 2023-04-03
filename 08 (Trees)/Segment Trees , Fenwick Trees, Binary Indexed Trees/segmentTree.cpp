https://cp-algorithms.com/data_structures/segment_tree.html

// Since there are updates: 

The leaf nodes are the elements of the array.
As we go up the node store the sum of nodes below it. ie it stores the sum of various segment of that array.

We only need to change logn nodes(height of the tree) to handle the update query!.

https://www.youtube.com/watch?v=-dUiRtJ8ot0 striver

https://www.youtube.com/watch?v=NEG-SoyigGE striver

https://www.youtube.com/playlist?list=PL5DyztRVgtRWt0Kgy7fCN9OSPgr6AI3DO 
codencode

https://www.youtube.com/results?search_query=segment+tree

https://codeforces.com/blog/entry/18051

https://leetcode.com/tag/segment-tree/

https://leetcode.com/tag/segment-tree/discuss/2406209/My-Segment-Tree-Implementation-w-Classes-and-Recursion


// We will use an array to store the node->vals of the tree
// Left child is stored at 2*i+1 positions.
// Right child is stored at 2*i+2 positions.


