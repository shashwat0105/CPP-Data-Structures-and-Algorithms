// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
// Problem Statement :- Given arr[] ={2, 3, 5, 6, 8, 10}, Sum = 10
// To return count of such subsets possible with Sum = 10, If true as here {10}, {2,3,5}, {2,8} -> return = 3(>0), if false(no such subset) then return 0
// return type of subset sum = boolean (coz true or false)
// return type of count of subset sum = int (if true then count, false then 0)
// t[n+1][Sum+1] Here t[6+1][10+1]
//   0  1     2    3    4    5    6    7    8    9    10   11  -> j(Sum)
// 0 | 1(T)  0(F) 0(F) 0(F) 0(F) 0(F) 0(F) 0(F) 0(F) 0(F) 0(F)   
// 1 | 1(T)
// 2 | 1(T)
// 3 | 1(T)
// 4 | 1(T)
// 5 | 1(T)
// 6 | 1(T)
// 7 | 1(T)
// i(n)
// Similarity from subset sum, the first column was true and only { } null set was solution hence count = 1 
// In choice diagram || is replaced by + (coz not true false), boolean by int (coz not true false)

// code
int countOfSubsetSum(int arr[], int Sum, int n){
    
    // base condition
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < Sum+1; j++){
            if(i==0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j]== 1; // this will overwrite the [0][0] position to finally true
            }
        }
    }
    // Choice Diagram
    if(arr[i-1] <= j){
        t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j]; // Either we include or not include, just replaced || by + 
    }
    else{
        t[i][j] = t[i-1][j];
    }

    return t[n][Sum];  // the right bottom most cell of the table
}
