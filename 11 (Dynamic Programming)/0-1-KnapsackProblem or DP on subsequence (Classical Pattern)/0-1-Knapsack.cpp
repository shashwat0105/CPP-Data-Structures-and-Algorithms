// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

// Method 1 is :- Only recursion    (T.C. = 2^n)
// Method 2 is :- Recursion plus table (Memoization or TopDown) (T.C. = n*W)
// Method 3 is :- Only table (Tabulation or Bottom Up) (T.C. = n*W)
 

// Method 1 Brute Force Recursion
// https://www.youtube.com/watch?v=kvyShbFVaY8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=3  (Aditya Verma)
// Time Complexity 2^n
// We can apply recursion coz choices are there & Output is max profit(2 conditions to identify recursion)(hence return type of the knapsack fn will be int)
// 1) Base condtion:- Think of the smallest valid input(smallest & valid)
// 2) Choice Diagram:- W1 -> i) W1 <= W -> Include or Not Include ii) W1 > W -> Not Include(ie item is heavier than bag capacity)
// We will write if else for these "three" include, not include conditions 
// We check for the last array element ie n-1 whether to include it or not first and then move towards the front

// Knapsack problems has only 1 array, just that it has 2 properties. 
// Whenever recursive function is called it is called with smaller input:- n-> n-1> n-2 otherwise it will never end
#include <bits/stdc++.h>
using namespace std;

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
    else if(wt[n-1]>W]){
        return(knapsack(wt, val, W, n-1));
    }
}
     
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(wt, val, W, n);     // n here is size not index.

    return 0;
}

// Method 2 Memoisation with recursion = Topdown approach
// After writing code of method 1, we write 2-4 lines extra and code will be memoised.
// Now we make a global matrix(no need of hassle of passing in a fn) (name it as dp or t) size m*n, How to chose what will be m & n? Matrix of changing variables is made
// In the knapsack function out of wt, val, W, & n -> Only W & n are changing in recursive calls hence
// int t[n+1][W+1] is made coz to store till n we need n+1 size and so for W
// Initialise every element of matrix as -1 using 2 loops or by memset function
// memset(t, -1, sizeof(t))
// Before calling recursive function we will check if in any cell there is any value if yes(-1 not present) then no need to call recursive fn, if no(ie -1 is present) then recursive fn is called

// fun1 -> fun2 -> fun3 -> fun4... , this is NOT DP (as function will not get repeated coz everytime it will get smaller only).
// Below is DP, coz one function calls 2 functions.
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

#include <bits/stdc++.h>
using namespace std;

int t[102][1002];
// memset(t, -1, sizeof(t));  // memset should be inside a function hence we put it inside the main function

int knapsack(int wt[], int val[], int W, int n){
    // base condition
    if(n == 0 || W == 0){
        return 0;
    }
    if(t[n][W] != -1){   // ie if the value is already saved then it will be returned from here only
        return t[n][W];
    }
    
    // choice diagram
    if(wt[n-1]<=W){
        return t[n][W] = max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1)); 
    }
    else if(wt[n-1>W]){
        return t[n][W] = (knapsack(wt, val, W, n-1));
    }
    return -1;                                                                                       // Refer to bottom GFG passed code, so see a slight change. ie upar return na karna chaho toh last mein return t[n][W] bhi kar skte
}
     
int main()
{
    memset(t, -1, sizeof(t));
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(wt, val, W, n);

    return 0;
}


// Method 3 Tabulation or BottomUp approach
// In only one place(Scrambled string problem leetcode based on MCM Matrix Chain Multiplication) this method is better where the stack can get filled(stack overflow error) due to recursive calls. Else method 2 is completely safe to use.
// Formation of table:-
// Step 1:- Initialisation (Base condition of above recursive fn changes to initilisation in tabulation)
// Step 2:- Changing recursive calls to iterative.
// n, W -> i, j

#include <bits/stdc++.h>
using namespace std;
 
int knapSack(int wt[], int val[], int W, int n)
{

    int t[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for(int i = 0; i <= n; i++)                // Note the loop is running from 0 to n(included)
    {
        for(int j = 0; j <= W; j++)
        {
            // base condition
            if (i == 0 || j == 0)
                t[i][j] = 0;
            // choice diagram
            else if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] +
                                t[i - 1][j - wt[i - 1]],
                                t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][W]; 
}
 
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
     
    cout << knapSack(wt, val, W, n);
     
    return 0;
}

// the code above is after replacing n with i and W with j.
// if(wt[n-1]<=W){
//     t[n][W] = max(val[n-1]+ t[n-1][W-wt[n-1]], t[n-1][W]);  // basically with the help of smaller sub problems(already solved before) solving the bigger problem
// }
// else{
//     t[n][W] = t[n-1][W];
// }

// You can notice that for nth row we only require n-1 th row, ie we can optimise the space.

// Identification of knapsack problem?
// Above ques can also be said as single item array which has 2 properties weight & value.
// Some items having choice & W which we have to optimise


// Some points:-
// For ex You want to find fibonnaci of 5
// Memoisation or top down : Will find by fib 4, fib 3, then fib 2, then fib 1, then fib 0 ( "Only finds those values which are required" )
// Tabulation or bottom approach will find :- fib 0 then fib 1 then fib 2 then fib 3 then fib 4 then fib 5 (Fills complete table by finding each and every value)
// 


********************************
// Most Space Optimised O-1 Knapsack solution (WOW):
 int knapSack(int W, int wt[], int val[], int n) {  
    vector<int> dp(W+1,0);
    for(int i=0;i<n;i++){                   // left to right
        for(int j=W;j>=wt[i];j--){          // right to left
            dp[j]=max(dp[j], dp[j-wt[i]]+val[i]);
        }
    }
    return dp[W];
}

**************** STRIVER explanation ****************

1) Express in terms of f(ind, W)
2) Explore all paths pick and not pick
3) max of all possible ways.

// Memoised passes GFG

int solve(int ind, int W, int wt[], int val[], vector<vector<int>> &dp){
    // starting at n-1 so write base case at index = 0. Thief has single element and has W weight left to take.
    if(ind==0){                     // Base case different tareeke se likha hai, coz isme ind=0 means 1 element is there, above 0 means no element is there.
        if(wt[0]<=W) return val[0];
        return 0;                   // in other cases when he cannot steal.
    }
    
    if(dp[ind][W]!= -1) return dp[ind][W];
    
    int notTake = 0 + solve(ind-1, W, wt, val, dp);
    int take = INT_MIN;
    if(wt[ind]<=W){
        take = val[ind] + solve(ind-1, W-wt[ind], wt, val, dp);
    }
    return dp[ind][W] = max(take, notTake);
}

int knapSack(int W, int wt[], int val[], int n) { 
    // Your code here
    vector<vector<int>> dp(n, vector<int> (W+1, -1));
    return solve(n-1, W, wt, val, dp);
}

// Tabulated

int knapSack(int maxW, int wt[], int val[], int n) { 
    // Your code here
    vector<vector<int>> dp(n, vector<int> (maxW+1, 0));
    
    for(int w = wt[0]; w<=maxW; ++w){  // base case for every w which is less than W
        dp[0][w] = val[0];
    }
    
    for(int ind=1; ind<n; ++ind){     // ind=0 already covered in base case
        for(int w=0; w<=maxW; ++w){
            int notTake = 0 + dp[ind-1][w];
            int take = INT_MIN;
            if(wt[ind]<=w){
                take = val[ind] + dp[ind-1][w-wt[ind]];
            }
            dp[ind][w] = max(take, notTake);
        }
    }
    return dp[n-1][maxW];
}

// Space optimised

// 2 rows

int knapSack(int maxW, int wt[], int val[], int n) { 
    // Your code here
    vector<int> prev(maxW+1, 0), cur(maxW+1, 0);
    
    for(int w= wt[0]; w<=maxW; ++w){  // base case for every w which is less than w
        prev[w] = val[0];
    }
    
    for(int ind=1; ind<n; ++ind){
        for(int w=0; w<=maxW; ++w){
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if(wt[ind]<=w){
                take = val[ind] + prev[w-wt[ind]];
            }
            cur[w] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[maxW];
}

// Single row

// Even if we reverse the weight loop voz it just depends on previous row. The ans remains the same
for(int ind=1; ind<n; ++ind){
    for(int w=maxW; w>=0; --w){
        ... // same ans

w-wt[ind] : no need of right elements. ie depends on left elements so cant fill left to right.

// code

int knapSack(int maxW, int wt[], int val[], int n) { 
    // Your code here
    vector<int> prev(maxW+1, 0);
    
    for(int w= wt[0]; w<=maxW; ++w){  // base case for every w which is less than w
        prev[w] = val[0];
    }
    
    for(int ind=1; ind<n; ++ind){
        for(int w=maxW; w>=0; --w){
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if(wt[ind]<=w){
                take = val[ind] + prev[w-wt[ind]];
            }
            prev[w] = max(take, notTake);
        }
    }
    return prev[maxW];
}
