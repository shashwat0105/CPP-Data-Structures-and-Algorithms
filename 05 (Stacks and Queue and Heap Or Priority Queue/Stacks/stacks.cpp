Types of Problems in Stack
(Monotonic Stack Problems: 1,2,3,4,5,6,7)
1-Type
1) Nearest Greater to left  (Nearest larger element)
2) Nearest Greater to right (Nearest Smaller element)
3) Nearest smaller to left 
4) Nearest smaller to right

5) Stock Span Problem
6) Maximum Area Histogram

7) Maximum area of Rectangle in Binary Matrix 

8) Rain water trapping
9) Implementing a Min Stack          (With and without Extra Space)
// To be done in the practice folder:
10) Implementing a stack using Heap
11) The celebrity problem
12) Longest valid parenthesis
13) Iterative TOH(Tower Of Hanoi) 
    Implementing TOH using stack is easy, but iteratively is difficult(But was asked in interview)


// IDENTIFICATION OF STACK
// 1) Array
// 2) Two for loops in which inner loop's j is dependent on i, then if brute force is O(n^2) then there is an optimized soln using stack.


// Implementation of Stack using arrays
int arr[5];
top = -1;

push(x){
    arr[++top] = x;
}

pop(){
    top--;
}

top(){
    return arr[top];
}

size(){
    return top+1;
}

isEmpty(){
    return top==-1;
}


// Implement Stack using Queue
