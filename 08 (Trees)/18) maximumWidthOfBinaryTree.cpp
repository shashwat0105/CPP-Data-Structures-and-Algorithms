https://leetcode.com/problems/maximum-width-of-binary-tree/

// Level order traversal will be used.
The width of one level is defined as the length between the end-nodes 
(the leftmost and rightmost non-null(IMPORTANT) nodes),
Isme jo missing nodes hai usko track rakhne k liye we have to use indexes along with level order traversal

// Code 1
// Handing overflow using unsigned long

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0; // if the root is NULL, the width is 0
        int res = 1; // initialize the result to 1, as the minimum width is 1
        queue <pair<TreeNode *, unsigned long long>> q; // create a queue of pairs containing a TreeNode pointer and an unsigned long long representing the index of the node
        q.push({root, 0}); // push the root onto the queue with index 0
        while(!q.empty()){
            int size = q.size(); // get the number of nodes in the current level of the tree
            unsigned long long start = q.front().second; // get the index of the first node in the current level
            unsigned long long end = q.back().second; // get the index of the last node in the current level
            res = max(res, (int)(end-start+1)); // update the result with the maximum width of the current level. Cast the result back to int after taking the difference to avoid overflow.
            for(int i=0; i<size; i++){
                TreeNode *node = q.front().first; // get the next node in the current level
                unsigned long long idx = q.front().second; // get the index of the next node in the current level
                q.pop(); // remove the next node from the queue
                if(node->left) q.push({node->left, idx*2+1}); // push the left child onto the queue with index 2*idx+1-start. 
                if(node->right) q.push({node->right, idx*2+2}); // push the right child onto the queue with index 2*idx+2-start. 
            }
        }
        return res; // return the result
    }
};

Code 2
Explanation
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
                long idx = q.front().second - start;             // I have taken this as long, and subtracted start to avoid overflow(just be safe) long se bhi overflow ni ho rha is ques m hence start subtract krne ki need nahi
                q.pop();
                if(node->left) q.push({node->left, idx*2+1});
                if(node->right) q.push({node->right, idx*2+2});
            }
        }
        return res;
    }
};

Same as code 2
Striver: (Ignore below)
https://youtu.be/ZbybYvcVLks (This video, comment section is helpful too I guess)
Striver ne socha tha ki int use krke ar start minus krke overflow bach jaega but esa hua nahi isliye long use krna hi pada.

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
