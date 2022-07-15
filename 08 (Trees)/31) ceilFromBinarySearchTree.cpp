https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464

https://www.geeksforgeeks.org/floor-and-ceil-from-a-bst/

// Ceil of an integer is the closest integer greater than or equal to a given number.

int findCeil(BinaryTreeNode<int> *root, int x){
    // Write your code here.
    int ceil= -1;
    while(root){
        if(root->data == x){
            ceil = root->data;
            return ceil;
        }
        if(root->data > x){
            ceil = root->data;
            root = root->left;
        } 
        else if(root->data < x){         // yaha ya toh else likho ya else if sirf if nahi
            root = root->right;
        }
    }
    return ceil;
}

// Recursive soln:

int func(BinaryTreeNode<int> *curr, int key, int &ceil)
{
    if(!curr)              return ceil;
    if(curr->data == key)  return ceil = key;
    
    if(curr->data > key) {
        ceil = curr->data;
        return func(curr->left, key, ceil);
    }
    return func(curr->right, key, ceil);
}
int findCeil(BinaryTreeNode<int> *root, int key){
    int ceil = -1;
    ceil = func(root,key,ceil);
    return ceil;
}
