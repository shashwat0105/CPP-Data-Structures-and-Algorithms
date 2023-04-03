https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457

// The greatest integer value which is <= key is the floor.

// Agar equal mil gaya toh best hai.
// Agar smaller mila then that is our candidate, we move towards bigger values(move right).
// Ar badi aa gyi toh chote k liye jana padega(move left).

int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    int floor=-1;
    while(root){
        if(root->val==x){
            floor = x;
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
