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

