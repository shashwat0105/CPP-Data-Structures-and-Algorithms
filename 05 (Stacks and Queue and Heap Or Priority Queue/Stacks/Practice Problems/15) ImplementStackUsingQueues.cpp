https://leetcode.com/problems/implement-stack-using-queues/

Using queues so queue STL will be used
https://www.cplusplus.com/reference/queue/queue/

Stack: LIFO
Queues: FIFO

// Using 2 Queues
We require 2 queues Q1 and Q2 to implement stack (Nothing but we will reverse the order using the other queue so that the order becomes that of a stack)

Steps:
push(x){
    1) Add x to Q2
    2) Q1 -> Q2 (Element by element transfer from Q1 to Q2 ie top will go first(FIFO))
    3) Swap Q1 and Q2
}

pop(){
    1) Remove the top of Q1
}

TC = O(N)
SC = O(N)

// CODE

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int num = q1.front();
        q1.pop();
        return num;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();    // will return whatever it evaluates to
    }
};


// Using single queue

// TC = O(N), SC = O(N)
// Push in queue
// Iterate to one less than the size of the queue and push the front element again and pop the element
// ie reverse the elements

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; ++i){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

// First use first approach then use second approach optimisation in an interview.

https://www.geeksforgeeks.org/implement-stack-using-queue/
