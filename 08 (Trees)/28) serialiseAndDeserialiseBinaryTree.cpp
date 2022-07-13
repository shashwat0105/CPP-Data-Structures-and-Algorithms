https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

https://youtu.be/-YbXySKJsX8 

// Serialise or deconstruct a tree to a string
// Again construct a tree from that string

// Can do any traversal technique

// Is ques ko ar discuss section ar YT videos se padhna hai, basically find other codes

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        
        string s = "";
        queue<TreeNode *> q;                              // level order traversal
        q.push(root);
        while(!q.empty()){
            TreeNode * currNode = q.front();
            q.pop();
            if(currNode==NULL) s.append("#,");
            else s.append(to_string(currNode->val)+',');
            if(currNode!=NULL){          
                q.push(currNode->left);    // chahe yeh jo queue m insert kar rahe hai wo null ho ya na ho daal do, no if condition required because null ko bhi print krna hai ek baar
                q.push(currNode->right);
            }
        }
        return s;
    }
    
    // string stream and getline function are used
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str=="#"){
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s,str, ',');
            if(str=="#"){
                node->right = NULL;
            }
            else{
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};


