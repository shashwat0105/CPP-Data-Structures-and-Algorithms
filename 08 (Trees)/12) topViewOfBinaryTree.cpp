https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/

(Not in LC)

// Using the vertical line concept from vertical order traversal.

// On the vertical line whichever is the first node is our ans(top view).

// I will traverse on every node by performing level order traversal
// So, we need queue storing initial root, vertical 0
// Using ordered map(as it stores in sorted order) : (line, node) (To see if we are visiting first time)

// ***** CODE *****

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root){
        //Your code here
        vector<int> ans;
        if(root==NULL) return ans;
        
        map<int, int> mp;                  // line(vertical), node value  // ordered map
        queue<pair<Node*, int>> q;         // node, line(vertical)
        q.push({root, 0}); 
            
        while(!q.empty()){                 // isme andar koi for loop use nahi hota hai
            auto it = q.front();           // get the topmost node
            q.pop(); 
            Node *node = it.first;
            int vertical   = it.second;        // get the vertical line number
            if(!mp[vertical]){                 // if no node corresponding to a vertical line exists.
                mp[vertical]=node->data;       // ie first time we are visiting so we add it to our map
            }
            
            if(node->left){
                q.push({node->left, vertical-1});
            }
            if(node->right){
                q.push({node->right, vertical+1});
            }
        }
        
        for(auto iter: mp){
            ans.push_back(iter.second);     // we will iterate in the map and insert the value
        }
        return ans;
    }
};

// In recursive say pre, in, post order, we may first visit below nodes so we avoid that method. (Levels involved)
// (According to striver)
