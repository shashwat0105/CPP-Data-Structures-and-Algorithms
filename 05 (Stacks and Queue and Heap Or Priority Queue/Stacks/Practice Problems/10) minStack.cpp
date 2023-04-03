https://leetcode.com/problems/min-stack/

// Interview question
// First do with extra space e O(2N) in front of interviewer, then optimise it to O(N) space when he says to do it.

We will two stacks:
Stack : To perform push, pop, top operation
Supporting stack: to find the minimum element. Its work is to store minimum element only. (Extra space)

// For GFG/LC Using 2 Stacks:
class MinStack {
public:
    stack<int> s;
    stack<int> ss;                        // supporting stack
    MinStack() {
        
    }
    
    void push(int val) {
       s.push(val);
       if(ss.empty() || ss.top()>=val){   // = is used because so that while popping equal number of min elements can be popped
           ss.push(val);
       }
       return;
    }
    
    void pop() {
       if(s.size()==0){
           return;
       }
       int ans = s.top();
       s.pop();
       if(ss.top()==ans){
           ss.pop();                     // ie we removed the min element hence waha se bhi hatana padega ie to find the new min element
       }
       return; 
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if(ss.size()==0){
           return -1;                  // it is given that these operations will be called on non empty stack, but in GFG it is said to return -1
       }
       return ss.top();
    }
};

// For LC using 2 stacks(shorter code):
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};

// Other method :
// Using pair and one stack(Better)

class MinStack {
public:
// for every element pushed in the stack, it stores its corresponding minimum value.
    vector<pair<int, int>> s;  // {current, minimum element}
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()) s.push_back({val, val});
        else s.push_back({val, min(s.back().second, val)}); 
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
    }
};


// Space O(N)
// Very good problem:

https://youtu.be/ZvaRHYYI0-4 (Aditya verma)
https://youtu.be/V09NfaGf2ao (Striver)

variable use krna hoga

// Problem: If I am using a variable, and the element popped is the min element. How do I access the old min element?

// Ratne wali method se thoda karenge

// Stack has 5(old min) and we want to insert 3 (ie is the min element), so instead of 3 we insert 2*(min_num_to_be_inserted)-min_element
// ie 2*3-5 ie we insert 1(acting as a flag) in the stack and the variable will store 3.
// After popping we can get back to old min element by: min_ele = 2*curr_min - popped ie 3*3-1 = 5 (old min)

// Modified Push of : push(2*val - mini)
// Rollback(decode): mini = (2*currmini - stack.top()) Watch from 15 min in striver video for proof.

// CODE
class MinStack {
public:
    stack<long> s;
    long long min_ele;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.size()==0){
            s.push(val);
            min_ele=val;
        }  
        else{
            if(val >= min_ele){
                s.push(val);
            }
            else if(val<min_ele){
                s.push((long long)2*val - min_ele);   // Encode using 2X-ME
                min_ele = val;
            }
        }
       return;
    }
    
    void pop() {
       if(s.top() >= min_ele){
           s.pop();
       }
       else if(s.top() < min_ele){          // top element is say 1 and min_ele is currently is 3// koi element min_ele se min nahi ho skta hence 1 is a flag
           min_ele = 2*min_ele - s.top();   // Decode using 2ME-Y
           s.pop(); 
       }
       return; 
    }
    
    int top() {
        if(s.top() >= min_ele){
           return s.top();
        }
        else return min_ele;
       // else if(s.top() < min_ele){  // top element is say 1 and min_ele is currently is 3
       //     return min_ele; 
       // }
    }
    
    int getMin() {
       return min_ele;
    }
};

// explanation that why 2*val-min is used.
How modified value < minimal  always?
say -3 is to be pushed and minimal is -2
-3 < -2
val < minimal
val - minimal < 0
Adding val both the sides
2*val - minimal < val
hence, Modified Value pushed < val 

// Also what if max element from the stack in O(1) is asked
// It will simply be: val+min




