// Coin Change Problem - Minimum Number of coins
// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
// Coin[] = {3, 4, 5}, Sum = 5

// In this we extra initilise the 2nd row as well depending upon whether the sub problem sum is divisible by arr[0]

//         0          1           2           3         4             5   -> j(Sum)
// 0 | INT_MAX-1  INT_MAX-1   INT_MAX-1  INT_MAX-1  INT_MAX-1    INT_MAX-1       // We want sum >= 0 & coin[] ={ } array is empty ie infinite no of coins will be required mathematically
// 1 |     0      INT_MAX-1   INT_MAX-1       1     INT_MAX-1    INT_MAX-1       // For sum = 0 & no of coins > 0, we need min coins = 0
// 2 |     0
// 3 |     0
// i(n)

// infinite = INT_MAX, for safety we take INT_MAX-1 because in code we do + 1 when we take coin -> INT_MAX-1+1 can be stored but INT_MAX+1 cannot be stored in Int as it will become negative

for(int i = 1; j < sum+1; j++){
    if(j% arr[0] ==0){
        t[i][j] = j/arr[0];
    }
    else
        t[i][j] = INT_MAX-1;
}

// for rest i = 2, j = 1 ... unbounded knapsack code & max -> min coz here we want min & instead of adding value we add 1 when we are including the coin ie number of coin is increased by 1
if(coin[]<=j){
    t[i][j] = min(t[i][j-coin[i - 1]] + 1, t[i-1][j])
}
else
    t[i][j] = t[i-1][j];


