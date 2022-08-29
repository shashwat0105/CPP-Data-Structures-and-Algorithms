https://youtu.be/QGJXQAaDs3I  (Kartik Arora)

Find the number of lists that exist and satisfy the following:
    1.  list contains exactly 'N' elements
    2.  all elements of the list are between 'low' and 'high'
    3.  sum of all elements is even

Return answer modulo 10^9+7

Constraints
1 <= n <= 10^6                 //(Tells to get a O(N) solution)
1 <= low <= high <= 10^6

Sample
(n=3,low=1,high=2) -> 4
(n=2,low=1,high=10) -> 50


// Explanation:
[x _ _ _ _ ... _]
I want x till last to be even. (1, even)
If x is odd, then remaining array sum should be odd. (2, odd)
If x is even, then remaining array sum should be even. (2, even)

// DP State
dp(i, 0): ways to fill position from i to N, such that sum is even. (0 means even)
dp(i, 1): ways to fill position from i to N, such that sum is odd.  (1 means odd)

Total nums = High - Low + 1
Number of odds = x
Number of even = y = Total nums - x

Recurrence Relation:
dp(i, 0) = x * dp(i+1, 1) + y * dp(i+1, 0);   
          There are x ways to fill the first position.

// Extra: If given the sum to be odd
dp(i, 1) = x*dp(i+1, 0) + y*dp(i+1, 1); 

// Base case:
dp(N, 0) = y  // ie number of even numbers

// Pseudo code:

int dp[1000001][2];

int pseudo(int i, bool odd, int low, int high, int n){
    if(i==n){
        {if(!odd) return 1};
        else return 0;
    }

    if(dp[i][odd]!= -1) return dp[i][odd];
    int numOdds = (high - low + 1) /2;

    if(low%2==1 && high%2==1) numOdds++;

    int numEvens = (high-low+1) - numOdds;

    return dp[i][odd] = (numOdds*pseudo(i+1, ((odd)?0:1), low, high, n)
                            + numEven*pseudo(i+1, ((odd)?1:0), low, high, n))%mod;
}


