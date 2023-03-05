https://leetcode.com/problems/implement-queue-using-stacks/

https://youtu.be/3Et9MrMc02A 

We will use 2 stacks s1 and s2

// Steps (Making push operation costlier)
push(x){
    1) s1 -> s2 (Whatever is in s1 transfer it to s2)
    2) x-> s1   (Add x to s1)
    3) s2 -> s1 (Whatever is in s2 transfer it back to s1)
}

// TC = O(N)
// SC = O(2N)

// Method 2(Optimised)
// Since there are more number of push operation, and less number of top() or pop() operation lets amortised the time complexity to O(1)
// s1 = input stack
// s2 = output stack

ie push O(1), pop O(N), top O(N)

// Steps(Pseudo code)
// push(x){
//     1) add x to input 
// }

// pop(){
//     if(output not empty){
//         output.pop()
//     }
//     else{
//         input -> output // Transfer all elements from input to output
//     }
//     // or can call the peek or top function
// }

// top(){
//     if(output not empty){
//         return output.top()
//     }
//     else{
//         input -> output
//         output.top()
//     }
// }

CODE
class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        // if(!output.empty()) output.pop();  // output is not empty
        // else{
        //     while(!input.empty()){         // transfering elements till input is not empty
        //         output.push(input.top());
        //         input.pop();
        //     }
        //     output.pop();
        // }
        // instead of this we can call the peak function
        int num = peek();
        output.pop();
        return num;
    }
    
    int peek() {
        if (output.empty())
            while (input.size()){
                output.push(input.top());
                input.pop();
            }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();    // important to check for both(not just output)
    }
};


// Other discuss gems
https://leetcode.com/problems/implement-queue-using-stacks/discuss/64196/0-ms-C%2B%2B-solution-using-one-Stack-w-explanation.

(Interview)
https://leetcode.com/problems/implement-queue-using-stacks/discuss/64284/Do-you-know-when-we-should-use-two-stacks-to-implement-a-queue
https://stackoverflow.com/questions/2050120/why-use-two-stacks-to-make-a-queue/2050402#2050402

