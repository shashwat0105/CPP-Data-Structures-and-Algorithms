https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

There will be many ans so return any.

class Solution {
private:
    unordered_map<int,int> m;
public:
    TreeNode* util(vector<int>& pre,vector<int>& post,int preStart,int preEnd,int postStart,int postEnd){
        if(preStart > preEnd)
            return NULL;
        TreeNode* root = new TreeNode(pre[preStart]);
        if(preStart == preEnd)
            return root;
        
        int idx = m[pre[preStart + 1]];
        int offset = idx - postStart;
        root->left = util(pre,post,preStart+1,preStart+1+offset,postStart,idx);
        root->right = util(pre,post,preStart+1+offset+1,preEnd,idx+1,postEnd);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        for(int i = 0;i < n;i++)
            m[post[i]] = i;
        return util(pre,post,0,n-1,0,n-1);
    }
};
