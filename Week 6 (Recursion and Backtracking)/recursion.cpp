To solve recursion problems
Method 1) (Making Input smaller) (Easy)
3 steps
1) Find the base case (a point where a problem cannot be  broken down further ie where we know the ans to the subproblem)
2) Find the relation b/w problem and subproblem
3) Generalise the relation

EG:
Calculate: a^b
1) base case : when b = 0,, every number to the power of 0 is 1
2) Problem: a^b, subproblem: a^(b-1)  (How we calculated/reach at a^(b-1) is known as recursion leap of faith)
   Relation: a^b = a* a^(b-1)
3) f(a, b) = a*f(a, b-1)

// Factorial using recursion; TC = O(N), SC = O(N)
int fact(n){
    // base case
    if(n==0) return 1;
    // recursive case
    int ans = n*fact(n-1);
    return ans;
}

Method 2) Using recursive tree - I/P-O/P Method (When you can think of decisions) (Medium)

Method 3) Using Choice Diagram (Hard)
 
// All recursive problems take extra space due to implicit call stack.


// TO IDENTIFY IF A PROBLEM CAN BE SOLVED BY RECURSION OR NOT
// CHOICES will be given and some DECISION has to be made (Decision space)

// Recursion is everywhere
// Don't do ques solely made for recursion using LOOP

// (very good example to understand power of recursion)
// Print 1 to N using recursion

void print(int n){
    if(n==1){          // or if(n<=0) return;
        cout<<n<<" ";  
        return;
    }
    print(n-1);
    cout<<n<<" ";      // here I first reach the base case then I start printing from base to N (ie printed while moving away from the base case)
}

// Print N to 1 using recursion

void print(int n){
    if(n==1){          // or if(n<=0) return;
        cout<<n<<" ";  
        return;
    }
    cout<<n<<" ";      // I know the value of n so first I print the value of n (ie printed while moving towards the base case also known as backtracking)
    print(n-1);
}

// For this above two ques, you can also use an extra variable i, and increment and decrement accordingly and print it to solve the ques as well.

// To check if an array is sorted using recursion

bool isSorted(int arr[], int n){
    // base case
    if(n==1 || n==0) return true;

    // rec case
    if(arr[0]<arr[1] && isSorted(arr+1, n-1)) return true;
    return false;
}

// Power function
// TC and SC = O(N)
int power(int a, int n){
    if(n==0) return 1;
    return a*power(a,n-1);
}

// TC and SC = O(logn)
// Calculating power faster
a^n = (a^n/2)^2 or a*((a^n/2)^2) depending on n is even or odd respectively.
int fastPower(int a, int n){
    if(n==0) return 1;

    int subProblem = fastPower(a, n/2);
    int subProbSq = subProblem*subProblem;
    if(n&1){                  // if n is odd
        return a*subProbSq;
    }
    return subProbSq;
}


// These above problems had 1 recursive call.
// More than 1 recursive call
// Eg fibonacci number (2)
// N-queens (n calls)

