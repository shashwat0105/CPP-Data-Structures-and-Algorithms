https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-heap/

To check for two properties:
1) It is a CBT
2) Max heap

class Solution {
    int countNodes(Node *tree){
        if(!tree)return 0;
        
        return 1 + countNodes(tree->left)+countNodes(tree->right);
    }
    
    bool isCBT(Node *tree,int index,int &count){
        if(!tree)return 1;
        
        if(index >= count)return 0;                      // any index in a cbt cannot be greater than count
        
        else{
            bool left = isCBT(tree->left,2*index+1,count);
            bool right = isCBT(tree->right,2*index+2,count);
            return left && right;
        }
    }
    
    bool isMaxHeap(Node *tree){
        if(tree->left==NULL && tree->right==NULL)return true;     // leaf node
        
        if(!tree->right)return tree->data>=tree->left->data;
        
        else{
            bool left=isMaxHeap(tree->left);
            bool right = isMaxHeap(tree->right);
            bool cur = (tree->data >= tree->left->data) && (tree->data >= tree->right->data);
            return left && right && cur;
        }
    }
    
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int count= countNodes(tree);
        return isCBT(tree,index,count) && isMaxHeap(tree);
    }
};
