// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
// Example arr[] = {2, 3, 7, 8, 10} & Sum = 11 // We want to find if there is any subset whose sum is given Sum (True or False)
// We have choice whether a number will be included or not & here W = Sum 
// Hence on slight variation in knapsack we can achieve code of this.

// Base condition(Initiliasation)
// Table of t[5+1][11+1] is made 
// The first column says Sum required is 0 and Array elements proceed as { }, {2}, {2,3},.. True it is possible to have sum of 0 using such arrays when everytime we take empty set as the required subset { }
// The first row says the array is empty ie { } and sum required is 0, 1, 2, ...,11, which is possible to satisfy only in sum 0, hence rest is false.
//   0  1 2 3 4 5 6 7 8 9 10 11 12  -> j(Sum)
// 0 T  F F F F F F F F F  F  F  F  
// 1 T
// 2 T
// 3 T
// 4 T
// 5 T
// i(n) ie no of elements

// Choice diagram
// Analogy with 0/1 knapsack wt[] -> arr[] -> i, val[] is ignored & W -> Sum -> j, max is changed to || or (coz no sense of max(true, false))

// code
boolean subsetSum(int arr[], int Sum, int n){
    
    bool t[n+1][Sum+1];                                    // bool or int(while counting) depending on value to be stored

    // base condition
    for(int i=0; i<=n; i++){
        t[i][0]=true;                                     // initilising the leftmost column
    }
    for(int j=1; j<=Sum; j++){                              // start from 1: // Initialize top row, except dp[0][0], as false. With  0 elements, no other sum except 0 is possible
        t[0][j]=false;                                    // initilising the topmost row
    } 
    // Choice Diagram     // Fill the subset table in bottom up manner
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= Sum; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j]; // Either we include or not include // true || false // In knapsack in place of weight we were subtracting the weight which was included, here we are subtracting the number which is included from Sum.
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][Sum];                                      // the right bottom most cell of the table
}

// *** Dont use two for loops for base condition sometimes works sometimes dont, above works well

// NOTE: This code works only for positive numbers in the array.
// https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/   (Deals Negative Numbers too) use of hasmap.


