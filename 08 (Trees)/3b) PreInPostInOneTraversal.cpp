https://youtu.be/ySp2epYvgTE (Striver)
https://youtu.be/12aMTS0L6WI (Pepcoding)

State = 1 : Pre, S++, left
State = 2 : In,  S++, right
State = 3 : Post, Pop

Iterative:
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
            st.push(it);

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



Recursive:
void trav(BinaryTreeNode<int> *root, vector<int> &in, vector<int> &pre, vector<int> &post){
    if(!root) return;

    pre.push_back(root->data);
    trav(root->left, in, pre, post);
    in.push_back(root->data);
    trav(root->right, in, pre, post);
    post.push_back(root->data);
}

