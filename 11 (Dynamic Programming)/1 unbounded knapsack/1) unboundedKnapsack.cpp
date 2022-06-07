// https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/
// Multiple occurences of same item is allowed

// For example:- The item is icecream:- 
// 1) I dont like icecream -> So, I WON'T take it regardless of the number of times you offer me. (Processed)
// 2) I like icecream -> I can take it any number of times you offer me. (Unprocessed)

// 0/1 -> Item -> 1) Taken -> Processed -> n-1 -> i-1
//                2) Not Taken -> Processed -> n-1 -> i-1
// unbounded -> Item -> 1) Taken -> Unprocessed -> n -> i  (Here is the code variation only) ie agar lena hai toh hm usko apni array se nahi hataenge
//                      2) Not Taken -> Processed -> n-1 -> i-1    ie agar nahi lena hai toh hata denge array se


#include <bits/stdc++.h>
using namespace std;

int unboundedKnapSack(int wt[], int val[], int W, int n)
{

    int t[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            // base condition
            if (i == 0 || j == 0)
                t[i][j] = 0;
            // choice diagram
            else if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] +
                                t[i][j - wt[i - 1]],  // the only change i-1 -> i
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
     
    cout << unboundedKnapSack(wt, val, W, n);
     
    return 0;
}

// THIS UNBOUNDED KNAPSACK CAN BE DONE IN O(n) SPACE AS WELL (GFG CODE)
