https://youtu.be/ySp2epYvgTE (Striver)
https://youtu.be/12aMTS0L6WI (Pepcoding)

State = 1 : Pre, S++, left
State = 2 : In,  S++, right
State = 3 : Post, Pop

Iterative in one traversal:
TC = O(3N), SC =(3 or 4N)

vector<int> preInPostTraversal(TreeNode *root){
    stack<pair<TreeNode *, int>> st;
    vector<int> pre, in, post;
    if(root==NULL) return;
    st.push({root, 1});

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        // part of pre, increment 1 to 2, push the left side of the tree
        if(it.second==1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);         // jo nikala usi ko ek increment krke push kr dia.

            if(it.first->left){
                st.push({it.first->left, 1});
            }
        }

        // part of in, increment 2 to 3, push the right side of the tree
        else if(it.second==2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->right){
                st.push({it.first->right, 1});  // coz first time hi visit kia hai abhi
            }
        }
        // when the counter value is 3, just add it to the post ans
        else{
            post.push_back(it.first->val);
        }
    }
}

// Iterative in 3 traversals (Why I wrote this? to remember similar codes for iterative pre, in, post order)
// In three separate loops :
// Using similar coding style of stack + while loop.
class Solution {
public:
    vector<int> traverse(TreeNode* root) {
        vector<int> traversal;  // stores the traversal results

        if (!root) {
            return traversal;  // empty tree, return empty vector
        }

        // Preorder
        stack<TreeNode*> st;  // stores nodes to be visited
        TreeNode* curr = root;

        while (curr || !st.empty()) {
            if (curr) {
                // visit current node and add it to traversal
                traversal.push_back(curr->val);
                st.push(curr);
                curr = curr->left;  // move to left child
            } else {
                // backtrack to last node with unvisited right child
                curr = st.top();
                st.pop();
                curr = curr->right;  // move to right child
            }
        }

        // Reset stack and curr for inorder traversal
        st = stack<TreeNode*>();
        curr = root;

        while (curr || !st.empty()) {
            if (curr) {
                st.push(curr);
                curr = curr->left;  // move to left child
            } else {
                curr = st.top();
                st.pop();
                traversal.push_back(curr->val);  // visit current node and add it to traversal
                curr = curr->right;  // move to right child
            }
        }

        // Now, traversal contains the nodes in the inorder traversal

        // Reset stack, curr, and prev for postorder traversal
        st = stack<TreeNode*>();
        curr = root;
        TreeNode* prev = nullptr;  // stores previously visited node

        while (curr || !st.empty()) {
            if (curr) {
                st.push(curr);
                curr = curr->left;  // move to left child
            } else {
                TreeNode* top = st.top();
                if (top->right && top->right != prev) {
                    curr = top->right;  // move to right child
                } else {
                    traversal.push_back(top->val);  // visit current node and add it to traversal
                    prev = top;
                    st.pop();
                    curr = nullptr;
                }
            }
        }

        // Now, traversal contains the nodes in the postorder traversal

        return traversal;
    }
};

// Ek hi vector k andar teeno push kr diye baari baari se.
// General thinking: ek curr variable jo root se start hote hue left left jaega ar ans m daalega.

Recursive:
void trav(BinaryTreeNode<int> *root, vector<int> &in, vector<int> &pre, vector<int> &post){
    if(!root) return;

    pre.push_back(root->data);
    trav(root->left, in, pre, post);
    in.push_back(root->data);
    trav(root->right, in, pre, post);
    post.push_back(root->data);
}
