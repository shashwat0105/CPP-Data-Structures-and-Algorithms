https://youtube.com/playlist?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk
(Striver Playlist)

Array, LinkedList are linear DS
Trees are heirarchical DS

1) Full Binary Tree
2) Complete Binary Tree
3) Perfect Binary Tree
4) Balanced Binary Tree
5) Degenerate Binary Tree


// Similar to linked list, root node is given then u can traverse:

// Binary tree representation in C++
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node (int val){
        data = val;
        left = right = val;
    }
}

main(){
    struct Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

}

     1
    / \
   2   3
   \
    5

// TRAVERSAL IN TREE

          1
        /   \
      2      3
     /  \   /  \
    4   5   6  7

1) Inorder traversal: (Root beech mein)
Left -> Root -> Right (Go to the subtrees and apply the same order)
Order: 4 2 5 1 6 3 7

2) Pre Order Traversal (Root sbse phle)
Root -> Left -> Right
Order: 1 2 4 5 3 6 7

3) Post Order Traversal (Root sbse baad)
Left -> Right -> Root
Order: 4 5 2 6 7 3 1
