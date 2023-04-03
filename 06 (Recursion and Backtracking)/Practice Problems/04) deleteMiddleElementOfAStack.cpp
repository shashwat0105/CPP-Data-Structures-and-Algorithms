https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/

// Decision cannot be think of, hence we will use Base Hypothesis Induction method ie making input small

// We first remove all items one by one(moving towards the base case), then we recur. 
// After recursive calls, we push all items back(moving away from the base case) except the middle item.  
// You can imagine the call stack as it was beautifully explained in CP udemy course (Prateek narang)

class Solution
{
    public:
    // main recursion function
    void solve(stack<int> &s, int k){  // kth element from the top has to be deleted
        if(k==1){
            s.pop();
            return;
        }
        int temp = s.top();            // these popped items will get stored in the call stacks while moving towards the base case.
        s.pop();
        solve(s, k-1);
        // induction step
        s.push(temp);
        return;
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack){
        // code here.. 
        if(s.size()==0) return;
        int k = int(sizeOfStack/2)+1;
        solve(s, k);
        return;
    }
};


OR
void deleteMid(stack<int>&s, int sizeOfStack){
    // code here.. 
    if(ceil(sizeOfStack/2.0)==s.size())   // will execute when size of stack is reduced to half. (Here we use base case for reducing stack size)
    {
        s.pop();
        return;  
    }
    int topElement=s.top();
    s.pop();
    deleteMid(s,sizeOfStack);            // s is getting reduced.
    s.push(topElement);
}

OR 
// Using an extra stack, taking out n/2 elements from original and putting in another stack.
// Then putting back elements.
int i=0;
stack<int>t;  // new stack t
while(i<(sizeOfStack)/2){
    t.push(s.top());
    s.pop();
    i++;
}
s.pop();
while(!t.empty()){
    s.push(t.top());
    t.pop();
}


// In java
https://www.geeksforgeeks.org/stack-class-in-java/
Direct way:
s.removeElementAt((sizeOfStack-1)/2);

// For future study:
// Asked in Amazon
https://github.com/nkatre/Operations-on-Stack/blob/master/findMiddle%20and%20deleteMiddle%20in%20constant%20time%20in%20Stack
