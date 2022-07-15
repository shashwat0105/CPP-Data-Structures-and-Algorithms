https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457

// The greatest integer value which is <= key is the floor.

int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    int floor=-1;
    while(root){
        if(root->val==x){
            floor=x;
            return floor;
        }
        else if(root->val > x){
            root = root->left;
        }
        else if(root->val < x){
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}

