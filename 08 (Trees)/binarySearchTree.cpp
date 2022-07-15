       N
     /   \
    L     R

For a binary search tree(BST) following condition should strictly follow for node values:
=>   Left part of tree <N< Right part of tree
=>   Entire left subtree should itself be a BST

// Primarily duplicates are not allowed.
// But if we want to integrate duplicates
// Then: we can either integrate another node or we can have (node, frequency) stored 

// Height of a BST is kept : log n (base2)

// Search in a BT: O(N) using pre, post, in, level order traversals
// Search in a BST: O(logn)

// Another important property of BST
// Inorder traversal of BST gives the nodes values always in sorted order (WOW)

