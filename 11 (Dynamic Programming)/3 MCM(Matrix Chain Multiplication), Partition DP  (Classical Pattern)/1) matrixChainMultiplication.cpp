// HARD Difficulty level topic.
// NUTANIX always asks ques based on variation of MCM, read interview experiences, base pay 22 LPA
// We will learn memoisation/top down of MCM (bottom up doesn't has benefits)

// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// Matrix Chain Multiplication
// Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
// The problem is not actually to  perform the multiplications, but merely to decide in which order to perform the multiplications.

// Identification +  Format
// A string or array is given, we select i(usually near left end index) & j(usually near right end index)
// Then we break it in a 'k', two subproblems i to k & k+1 to j, we solve them get temporary answers.
// We modify the value of k(har ek 'k' par break krna hai), get different subproblems and different temporary answers.
// Now, we apply a function (say max or min according to ques) on different temporary answers to get our final answer.


// Base condition
// (i) Think of smallest valid input
// (ii) Think of 1st invalid input (here this helps more in MCM)

// i == j (One element in the array, makes sense)
// i > j (invalid input)

// FORMAT SKELETON
int solve(int arr[], int i, int j){

    // Base condition
    if(i>j){   // may be different according to question
        return 0;
    }
    
    for(int k = i; k < j; k++){  // acc to ques, k can start from i, i+1 & end at j or j-1 & k++ or k+2
        // Calculate temporary answer
        temp ans = solve(arr, i, k) +  // here + or - or anything depending on ques
                   solve(arr, k+1, j)
        
        ans = func(temp ans)
    }

    return ans;
}



// SAMPLE PROBLEM STATEMENT
// arr[] = {}  // will contain dimension of matrices A1, A2, A3, ...
// Some matrices:- A1, A2, A3, ... are given of different sizes say (2*5), (20*20), (30*10) ...
// We need to multiply A1*A2*A3... and minimise the cost of multiplication

// Cost of multiplication of 2 matrices:- A (2*3) & B (3*6) -> is 2*3*6 = 36  

// Combinations of multiplication we can do:-
// (A1*(A2*A3))*A4 -C1 cost
// ((A1*A2)*(A3*A4)) - C2 cost
// A1*(A2*(A3*A4)) - C3 cost and so on...
// We have to find minimum cost among them.

// For example
// A(10*30), B(30*5), C(5*60)
// A(BC) => 30*5*60 + 10*30*60 = 27000 cost (temp ans)
// (AB)C => 10*30*5 + 10*5*60 = 4500   cost (temp ans)
// Then we will chose minimum among the temp answers.


// PROBLEM STATEMENT
// arr[] = {40, 20, 30, 10, 30}
// If size of arr is n -> no of matrices = n-1
// Deriving size of matrices from given array -> Ai => arr[i-1]*arr[i]
// A1 => 40*20
// A2 => 20*30
// A3 => 30*10
// A4 => 10*30

// Now we need to decide value of i & j
// if value of i = 0 then arr[0-1] is invalid, hence we take i = 1, & no issue in j = n-1

// Two schemes of writing for loops(chose any)
// (i) k = i to k = j-1 -> i to k & k+1 to j   (Preferred)
// (ii) k = i to k = j  -> i to k-1 & k to j
 
int solve(int arr[], int i, int j){
    // Step 1: Find i & j values  (i = 1 & j = n-1)
    // Step 2: Find right base condition
    // Base condition
    // Previously it was i>j, but even i == j is invalid. Coz it will mean the array contains only 1 element which is also not valid. Because arr[i-1]*arr[i], we want atleast 2 elements in the array to define size of a matrix. 
    if(i>=j){
        return 0;
    }
    int mn = INT_MAX;
    // Step 3: Move k -> i to j
    // Here k will move from i to j-1 (to get valid matrix in our multiplication) see SS or chala k dekho
    for(int k = i; k<=j-1; k++){
        int tempans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];  // Say for (A*B)*(C*D), cost of A*B + cost of C*D + cost of (result matrix)*(result matrix) {dimension found by taking example see SS}

        // Step 4: Calculate ans from temp ans
        if(tempans < mn){
            mn = tempans;
        }
    }
    return mn;
}


int main(){
    solve(arr, 1, n-1)
}


// MEMOIZATION OR TOP DOWN METHOD
// Changing variables are i & j

// size of matrix n, say constraints given n<1000

// (Works in GFG)

int solve(int arr[], int i, int j, vector<vector<int>> & dp){
    if(i>=j) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    
    int minVal = INT_MAX;
    for(int k=i; k<j; ++k){
        int tempAns = solve(arr, i, k, dp) + solve(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
        minVal = min(tempAns, minVal);
    }
    return dp[i][j] = minVal;                    // minVal is assigned to dp[i][j] and either of them is returned.
}

int matrixMultiplication(int N, int arr[]){
    // code here
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
    return solve(arr, 1, N-1, dp);
}



**************************** STRIVER ***********************************

start point i       k - partitions                   end point j

// Two matrices:
m*n and n*o
// Then number of multiplications are m*n*o

https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Given matrix dimensions
Array is given:
[10 20 30 40 50]
     A  B  C  D

ith matrix dimension is given by A[i-1] * A[i]

Rules of partition DP:
1) Start with entire block/array (i, j) ~ (start pt, end pt)
2) Try all partition. Run a loop to try all partitions
3) Return the best possible two partition.

f(1, 4): return min multiplications to multiply matrix 1 to matrix 4
f(1, n-1) is what u need to find.

Base case when there is only one matrix ie i==j

Our parition variable can move either
k = i to j-1  (preferred)      or       i+1 to j
f(i, k), f(k+1, j)             or     f(i, k-1), f(k, j)

Suppose I make a partition at k


Steps required to multiply (AB)*(CD)
= 10*30*50  ie [i-1]*[k]*[j]

Then steps = A[i-1]*A[k]*A[j] // steps required to multiply those two partitions
                + f(i, k)     // steps required to multiply all elements inside this partition
                    + f(k+1, j) // steps required to multiply all elements inside this partition

Take min of all these steps

// Memoised

int solve(int i, int j, int arr[], vector<vector<int>> &dp){
    // base case
    if(i==j) return 0;
    
    if(dp[i][j]!= -1) return dp[i][j];
    
    int mini = 1e9;
    for(int k=i; k<j; ++k){
        int steps = arr[i-1]*arr[k]*arr[j] + solve(i, k, arr, dp) + solve(k+1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(int n, int arr[]){
    // code here
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(1, n-1, arr, dp);    
}

// TC = O(N^3)
// SC = O(N^2 + N)

// Tabulation

1) Copy paste base case
2) Write down the changing parameters
// Understanding part i--->    <----j top down
//                    <------i j----> bottom up something like that
// Just opposite and take care of edge case.
// In top down i was moving from 1 to n-1 hence here it will move opposite n-1 to 1
// In top down j was moving from n-1 to 1 hence here it will opposite and j will always be right of i so, i+1 to n-1
3) Copy the recurence

int matrixMultiplication(int n, int arr[]){
    // code here
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    // base case
    for(int i=0; i<n; ++i){
        dp[i][i] = 0;
    }
    
    for(int i=n-1; i>=1; --i){
        for(int j=i+1; j<n; ++j){
            int mini = 1e9;
            for(int k=i; k<j; ++k){
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
        
    return dp[1][n-1];
}


