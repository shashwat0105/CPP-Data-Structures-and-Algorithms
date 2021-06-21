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
// i>j (invalid input)

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



// PROBLEM STATEMENT





