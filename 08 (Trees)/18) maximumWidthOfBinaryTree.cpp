https://leetcode.com/problems/maximum-width-of-binary-tree/

// Tough ques hai thoda isme overflow bhi handle krna hai
// Level order traversal will be used.
The width of one level is defined as the length between the end-nodes 
(the leftmost and rightmost non-null(IMPORTANT) nodes), 

// Isme jo missing nodes hai usko track rakhne k liye we have to use indexes along with level order traversal

https://youtu.be/ZbybYvcVLks (This video, comment section is helpful too I guess)

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        int ans=0;
        queue<pair<TreeNode*, int>> q;                           // {node, index}
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();            
            int mmin = q.front().second;
            int first, last;
            for(int i=0; i<size; ++i){                            // iterate on all the elements of the queue
                long cur_id = q.front().second - mmin;            // to prevent the overflow condition used long, we also subtracted with min to avoid overflow
                TreeNode *node = q.front().first;
                q.pop();
                if(i==0) first = cur_id;
                if(i==size-1) last = cur_id;
                if(node->left) q.push({node->left, cur_id*2+1});  // creating the indexes // this *2 is causing overflow
                if(node->right) q.push({node->right, cur_id*2+2});
            }
            ans=max(ans, last-first+1);
        }
        return ans;
    }
};

Other explanation
https://youtu.be/le-ZZSQRebw

// Better code 

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int res = 1;
        queue <pair<TreeNode *, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            res = max(res, end-start+1);
            for(int i=0; i<size; i++){
                TreeNode *node = q.front().first;
                long idx = q.front().second - start;
                q.pop();
                if(node->left) q.push({node->left, idx*2+1});
                if(node->right) q.push({node->right, idx*2+2});
            }
        }
        return res;
    }
};