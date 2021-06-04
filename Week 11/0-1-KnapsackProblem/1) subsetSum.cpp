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

for(int i = 0; i < n+1; i++){
    for(int j = 0; j < Sum+1; j++){
        if(i==0){
            t[i][j] = False;
        }
        if(j==0){
            t[i][j]== True; // this will overwrite the [0][0] position to finally true
        }
    }
}

// Choice Diagram
// Analogy with 0/1 knapsack wt[] -> arr[] -> i, val[] is ignored & W -> Sum -> j, max is changed to || or (coz no sense of max(true, false))
if(arr[i-1] <= j){
    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j]; // true || false // in place of weight we are subtracting the weight which was included here we are subtracting the number from Sum which is included.
}
else{
    t[i][j] = t[i-1][j];
}

return t[n][Sum];  // the right bottom most cell of the table

