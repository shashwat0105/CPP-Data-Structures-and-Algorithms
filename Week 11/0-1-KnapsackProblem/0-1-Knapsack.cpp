// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

// Method 1 is :- Only recursion    (T.C. = 2^n)
// Method 2 is :- Recursion plus table (Memoization or TopDown) (T.C. = n*W)
// Method 3 is :- Only table (Tabulation or Bottom Up) (T.C. = n*W)
 

// Method 1 Brute Force Recursion
// https://www.youtube.com/watch?v=kvyShbFVaY8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=3
// Time Complexity 2^n
// We can apply recursion coz choices are there & Output is max profit(hence return type of the knapsack fn will be int)
// 1) Base condtion:- Think of the smallest valid input(smallest & valid)
// 2) Choice Diagram:- W1 -> i) W1 <= W -> Include or Not Include ii) W1 > W -> Not Include(ie item is heavier than bag capacity)
// We will write if else for these "three" include, not include conditions 
// We check for the last array element ie n-1 whether to include it or not first and move to the front

// Whenever recursive function is called it is called with smaller input:- n-> n-1> n-2 otherwise it will never end

int knapsack(int wt[], int val[], int W, int n){
    // 1) Base condition (first thing to write in a recursive function)
    // Smallest valid weight array could be 0(size of array = 0)(ie no items avaialabe to put in bag) & Smallest weight could be 0(ie The capacity of the bag is 0) valid coz weight can't be negative
    // In both the above cases the max profit will be 0.
    if(n == 0 || W == 0){
        return 0;
    }
    // 2) Choice Diagram(second thing to write in a recursive function)
    if(wt[n-1]<=W){
        return max(val[n-1]+ knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1)); // Left part is when n-1 is included, Right part is when not included
    }
    else if(wt[n-1>W]){
        return(knapsack(wt, val, W, n-1));
    }
}


// Method 2 Memoisation with recursion = Topdown approach
// After writing code of method 1, we write 2-4 lines extra and code will be memoised.
// Now we make a global matrix(no need of hassle of passing in a fn) (name it as dp or t) size m*n, How to chose what will be m & n? Matrix of changing variables is made
// In the knapsack function out of wt, val, W, & n -> Only W & n are changing in recursive calls hence
// int t[n+1][W+1] is made coz to store till n we need n+1 size and so for W
// Initialise every element of matrix as -1 using 2 loops or by memset function
// memset(t, -1, sizeof(t))
// Before calling recursive function we will check if in any cell there is any value if yes(-1 not present) then no need to call recursive fn, if no(ie -1 is present) then recursive fn is called

// say given constraints n<=100, W<=1000 we can make a static matrix too by taking slighly bigger value than constraints
//                         K(3,2)
//                  /               \
//             /                        \  
//         /                                 \     
//     K(2,1)                                     K(2,2) 
//    /         \                        /           \  
//  /              \                   /               \
// K(1,0)     K(1,1)             K(1,1)                K(1,2)   
//              {stores       {gets value            /         \
//              value         from t[1][1]         /             \
//             in t[1][1]}        and             K(0,1)       K(0,2)
//             /        \        doesn't call
//           /            \     K(0,0) & K(0,1)} 
//         /                \
//     K(0,0)                  K(0,1)    

// how can one determine overlapping subproblems when solving recursion is: https://qr.ae/pNkmIE

int t[102][1002];
memset(t, -1, sizeof(t));

int knapsack(int wt[], int val[], int W, int n){
    if(n == 0 || W == 0){
        return 0;
    }
    if(t[n][W] != -1){   // ie if the value is already saved then it will be returned from here only
        return t[n][W];
    }
    
    if(wt[n-1]<=W){
        return t[n][W] = max(val[n-1]+ knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1)); 
    }
    else if(wt[n-1>W]){
        return t[n][W] = (knapsack(wt, val, W, n-1));
    }
}

// In case you are getting an error related to memset 
// Call 
//  memset(t, -1, sizeof(t)) ;
// Inside the main() function


// Method 3 Tabulation or BottomUp approach
// In only one place(Scrambled string problem leetcode based on MCM Matrix Chain Multiplication) this method is better where the stack can get filled(stack overflow error) due to recursive calls. Else method 2 is completely safe to use.
// Formation of table:-
// Step 1:- Initialisation (Base condition of above recursive fn changes to initilisation in tabulation)
// Step 2:- Changing recursive calls to iterative.
// n, W -> i, j

int t[n+1][W+1]
for(int i = 0; i < n+1; i++){
    for(int j = 0; j < W+1; j++){
        if(i == 0 || j == 0){
            t[i][j] == 0;   // initilisating the first row and column to 0(base condition)
        }
    }
}

for ( i = 1; i < n+1; i++){
    for ( j = 1; j< W+1; j++){
        if(wt[i-1]<=j){
            return t[i][j] = max(val[i-1]+ t[i-1][j-wt[i-1]], t[i-1][j]);  
        }
        else{
            return t[i][j] = t[i-1][j];
        }
    }
}

return t[n][W];

// if(wt[n-1]<=W){
//     t[n][W] = max(val[n-1]+ t[n-1][W-wt[n-1]], t[n-1][W]);  // basically with the help of smaller sub problems(already solved before) solving the bigger problem
// }
// else{
//     t[n][W] = t[n-1][W];
// }
// the code is above after replacing n with i and W with j







