// NGL

arr[] = {1, 3, 2, 4}

We will see the left array on each element
Ans[] = {-1, -1, 3, -1}

// Brute force

for(int i=0; i<n; ++i){
    for(int j=i-1; j>=0; --j){}
}

j is dependent on i (j=i-1) ie itna brute force likh k I got ki stack use hoga

// Changes from past ques
// 1) Traverse left to right
// 2) No need to reverse

vector<int> ans;
stack<int> s;

for(int i=0; i<n; ++i){
    while(!s.empty() && arr[i] > s.top()){
        s.pop();
    }
    if(s.empty()){
        ans.push_back(-1);
    }
    else{
        ans.push_back(s.top());
    }
    s.push(arr[i]);
}


https://www.geeksforgeeks.org/closest-greater-or-same-value-on-left-side-for-every-element-in-array/

Other solution
An efficient solution is to use Self-Balancing BST (Implemented as set in C++ and TreeSet in Java). 
In a Self Balancing BST, we can do both insert and closest greater operations in O(Log n) time.
