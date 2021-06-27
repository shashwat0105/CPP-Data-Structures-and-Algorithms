// https://www.geeksforgeeks.org/diameter-of-a-binary-tree-in-on-a-new-method/

// Diameter = No. of nodes along the longest path between two leafs
// It may or may not pass through root node 
//  there may be more than one path in the tree of the same diameter

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    

Return 4, which is the no of nodes along diameter path [4,2,1,3] or [5,2,1,3].

//
// temp = max(l, r) + 1; // when it dont want to be the ans(turn would be made on some senior node), +1 is the the node itself, cant include both heights, hence max is taken
// ans(relation) = l + r + 1; // when it wants to be the ans ie the turn would be made on this node , both left height + right height + 1

int solve(Node * root, int& res){  
    // BASE CONDITION
    if(root == nullptr){
        return 0;
    }

    // HYPOTHESIS SAME FOR EVERY QUES
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    // INDUCTION STEPS CHANGES ACC TO QUES (here temp and relation)
    int temp = max(l, r) + 1; 
    int ans = max(temp, 1+l+r);
    res = max(res, ans);

    return temp; 
}

int main(){
    int res = INT_MIN;
    solve(root, res);
    
    return res;
}


// Some points which can be look into
//  Use res as global....then we don't need to pass it by reference. 
//  Here, int ans = max(temp, 1+l+r) is not required , ans = 1+l+r will work. But to remember as a general syntax do it that way!
//  here actually l and r are returning the heights of the left and right subtrees, not the diameters. 
//  Coz the diameter of the whole tree is basically the maximum value of (l + r + 1)  for every node, this is what being done here. 
// the variable temp will store diameter (check this) 

// l and r are heights. At every node, in temp, we are storing the max height, which can be from either left or right. 
// Then in variable named ans , we are storing the diameter possible taking current node as root. 
// Then we are comparing the diameter with res and updating it ,in case the current answer is greater than res 
