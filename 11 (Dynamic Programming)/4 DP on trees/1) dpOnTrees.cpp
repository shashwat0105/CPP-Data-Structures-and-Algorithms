// https://www.geeksforgeeks.org/dynamic-programming-trees-set-1/

// We define functions for nodes of the trees, which we calculate recursively based on children of a nodes. 
// One of the states in our DP usually is a node i, denoting that we are solving for the subtree of node i.

// We want to store the value which we calculate after doing some calculations on a node

// GENERAL SYNTAX
// Bird View
// int functionname( INPUT )
// {
//     BASE CONDITION

//     HYPOTHESIS //(Dont question this, ki isse ans aya kaise, it will give me some left sub tree ans, some right subtree ans)

//     INDUCTION //(Using ans of left and right part to get ans for parent node)
//     temp, ans, res ( 3 things in induction )
// }


int solve(Node*root, int& result){ // & coz we pass by reference otherwise in every recursive call its value will get changed
    // Base condition (80% ques will have below base condition, others will have some more)
    if(root == nullptr){ // or root == NULL , same thing
        return 0;
    }

    // Hypothesis
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    // Induction
    // May or may not pass through root node
    // temp ans:- jab node ans banna nahi chahta ie senior ko pass karega toh better ans milega
    // ans :- jab node ans banna chahta hai
    int temp = calculate temp ans  (yaha kch likhna hai); // ie current node se aage bhi pass krna hai
    int ans = max(temp, relation yaha kch likhna hai); // Ek particular node ko decide krna hai ki yahi wo node hai jisse diameter pass ho ya aage dusri node m transfer krna hai 
    res = max(ans, res);

    return temp; // qki yahi aage transfer hoga

}

int main(){
    int res = INT_MIN;
    solve(root, res);
    
    return res;
}


// He returned temp because ans is alredy updated and we require temp for further process i.e. l+r+1 means the diameter 
// but for further process we don't require ans rather we require either the left subtree height or the right subtree height 
// whichever is maximum plus 1 that's why temp is returned


// int solve(Node* root, int* ans)
// {
//     if(root == NULL)
//          return 0;
//     int l = solve(root->left, ans);
//     int r = solve(root-> right, ans);
//     *ans = max(*ans, l+r+1);
//     return 1+max(l,r);
// } 

