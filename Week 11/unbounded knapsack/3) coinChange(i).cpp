// Coin Change Problem - Maximum Number of ways
// https://www.geeksforgeeks.org/coin-change-dp-7/

// Given a value S, if we want to make change for S cents, and we have infinite supply of each of Coin = { C1, C2, .. , Cm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
// Example:
// for Sum(S) = 4 and Coin = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
// So output should be 4. ie we need to count or find the number of solutions. So "+" will come in our code.
// Coins have choices hence knapsack & can be taken multiple times hence it is unbounded knapsack

// Matching :- wt[] -> coin[] (also we ignore the val[] array) & W -> Sum


int coinChangeI(int coin[], int Sum, int n)
{

    int t[n + 1][Sum + 1];
    // base condition (Taken from count of subset sum problem)
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < Sum+1; j++){
            if(i==0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j]== 1; // this will overwrite the [0][0] position to finally 1
            }
        }
    }
    // Choice Diagram
    // Build table K[][] in bottom up manner
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= Sum; j++)
        {
            // base condition
            if (i == 0 || j == 0)
                t[i][j] = 0;
            // choice diagram
            else if (coin[i - 1] <= j)
                t[i][j] = t[i][j - coin[i - 1]] + t[i - 1][j];  // remove the max, val & insert + in the knapsack code & i-1 -> i when choice is to take the coin unboundedly
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][Sum];
}

