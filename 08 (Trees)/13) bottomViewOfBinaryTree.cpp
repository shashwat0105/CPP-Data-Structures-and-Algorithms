https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1/

https://youtu.be/0FtVY6I4pB8

// For overlapping we take the node which is to the right.

// We can do vertical order traversal and the last node will make the bottom view.

// Map : (line, node)

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root==NULL) return ans;
        map<int, int> mp;
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node *node = it.first;
            int line = it.second;
            mp[line]= node->data;                      // isme wo check karne ki jaroorat nahi qki agar koi naya ata hai toh wahi le lia jata hai
            
            if(node->left){
                q.push({node->left, line-1});
            }
            if(node->right){
                q.push({node->right, line+1});
            }
        }
        
        for(auto it: mp){
            ans.push_back(it.second);     // second mein hi node data stored hai
        }
        
        return ans;
    }
};

// 
Will recursive traversal work? (inorder, pre, post etc)
generally dont do, as it is more complex (height wgyra bhi leni padegi according to striver)




