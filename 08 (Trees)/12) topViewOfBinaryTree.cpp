https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/

(Not in LC)

// Using the line concept from vertical order traversal.

// On the line whichever is the first node is our ans(top view).

// Performing level order traversal
// SO, we need queue storing initial root, vertical 0
// Using map(as it stores in sorted order) : (line, node) (To see if we are visiting first time)

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
        
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
            
        while(!q.empty()){
            auto it = q.front();           // get the topmost node
            q.pop();
            Node *node = it.first;
            int line = it.second;          // get the vertical line number
            if(mp.find(line)==mp.end()){   // if that line doesnt exist in the map
                mp[line]=node->data;       // ie first time we are visiting so we add it to our map
            }
            
            if(node->left){
                q.push({node->left, line-1});
            }
            if(node->right){
                q.push({node->right, line+1});
            }
        }
        
        for(auto it: mp){
            ans.push_back(it.second);     // we will iterate in the map and insert the value
        }
        return ans;
    }
};



// In recursive say pre, in, post order, we may first visit below nodes so we avoid that method (According to striver)

// For future analysis(JAVA se C++ samajh lena basically how he improved the time):

 I cut down the time complexity of inserting elements in treemap(O(logN)) to O(1) by using a Hash Map. I just stored the min value of the line in the tree and then kept on incrementing from that and kept on storing the elements.

JAVA Code: 

class Pair{
    int state;
    Node root;
    
    Pair(int state, Node root){
        this.state = state;
        this.root = root;
    }
}

class Solution
{
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    static int traverseLevelOrder(Node root, Map<Integer, Integer> map){
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(0,root));
        
        int min = Integer.MAX_VALUE;
        
        while(!queue.isEmpty()){
            Pair pair = queue.poll();
            Node currNode = pair.root;
            int state = pair.state;
            min = Math.min(min, state);
            
            if(!map.containsKey(state))
                map.put(state, currNode.data);
            if(currNode.left != null)
                queue.offer(new Pair(state-1, currNode.left));
            if(currNode.right != null)
                queue.offer(new Pair(state+1, currNode.right));
        }
        return min;
    }
    
    static ArrayList<Integer> topView(Node root)
    {
        
        //This question can't be done using normal dfs beacuse there is a concept
        //of levels being used in this question
        Map<Integer, Integer> map = new HashMap<>();
        int min = traverseLevelOrder(root, map);
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i = min; map.containsKey(i); i++)
            ans.add(map.get(i));
        return ans;
    }
}

