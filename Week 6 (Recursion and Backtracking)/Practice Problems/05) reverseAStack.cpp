// Without using extra stack we have to do
// Using recursion


// After poping the top element, I have to insert it at the bottom (ie its correct place) (ie another recursive problem)

void insertAtBottom(stack<int> &s, int ele){
    // base condition
    if(s.size()==0){       // will be inserted when there is no element left ie at the bottom
        s.push(ele);
        return;
    }

    int temp = s.size();
    s.pop();
    insertAtBottom(s, ele);  // recursive call for the new s 
    s.push(temp);
    return;
}

void reverse(stack<int> &s){
    // base condition
    if(s.size()==1) return;

    int temp = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, temp);  // inserting the element which we have popped
    return;
}

