https://youtu.be/2r5wLmQfD6g

https://practice.geeksforgeeks.org/problems/burning-tree/1/

https://www.geeksforgeeks.org/minimum-time-to-burn-a-tree-starting-from-a-leaf-node/

Start node could be any node including leaf node.

// Node value can be given to you or node address.
// I apply BFS algorithm(radially outwards)
// In order to move upwards, we need to assign parent pointers.(Hashmap) 

// Note: In this ques node value is given instead of mode address, so we need to extra traverse to find that node.
// So, while creating parent pointers, I will also find the address of the target(hence passing it too) (Iska code mein dfs wali recursive calls m dikkat hogi so BFS se better rahega cheeze return karna)

class Solution {
  public:
    int findMaxDistance(unordered_map<Node *, Node *> &parent_track, Node * target){
        queue<Node *> q;
        q.push(target);
        unordered_map<Node *, int> vis;
        vis[target] = 1;
        int time = 0;
        while(!q.empty()){
            int sz = q.size();
            int flag = 0;
            for(int i=0; i<sz; ++i){
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){  // node ka left exist karta hai ar wo phle burn nahi hua hai
                    flag = 1;                        // flag 1 hua mtlb koi na koi new node ko burn kia gaya hai isse pata chalega ki time ko badhana hai ya nahi
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){   // similar for right
                    flag = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                
                if(parent_track[node] && !vis[parent_track[node]]){   // similar for parent
                    flag = 1;
                    vis[parent_track[node]] = 1;
                    q.push(parent_track[node]);
                }
            }
            if(flag == 1) time++;                   // I burned someone who was adjacent to me
        }
        return time;
    }
    
    Node * markParents(Node *root, unordered_map<Node *, Node *> &parent_track, int start){
        queue<Node *> q;
        q.push(root);
        Node * res;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){                     // Logic of for loop: Yeh bina is for k bhi chalega, for lagana better habit hai coz level by level hoga tab travesal, bina uske kaise bhi ho jaega
                auto node = q.front();
                if(node -> data == start) res = node;
                q.pop();
                if(node->left){
                    parent_track[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parent_track[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        return res;
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node *, Node *> parent_track;
        Node * res = markParents(root, parent_track, target);  // does parent mapping as well as return me address of target node.
        int time = findMaxDistance(parent_track, res);
        return time;
    }
};


LEETCODE:
https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

Just see my submission code is exact same.

// I have done without flag as well by returning time-1;