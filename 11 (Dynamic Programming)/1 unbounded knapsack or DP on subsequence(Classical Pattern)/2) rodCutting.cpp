// DP on subsequence

// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
// Input:- Length of Rod (N)  Say N = 4  
//         Price Array [] = {3,6,8,8}, Length of pieces array may/maynot be given = {1,2,3,4} (Common Sense if there is no boundation on length in which we can split)
// Size of the rod & size of the array is same in most of the cases here t[4+1][4+1]
// To cut the rods in various parts such that to gain max profit
// Similar to unbounded knapsack becoz 4 = 2+2 or 1+1+2  i.e. repitition is allowed.
// wt -> length[], val -> price[] -> W -> N

int cutRod(int price[], int n) {
    //code here
    vector<int> length;             // forming the length array.
    for(int i=0; i<n; ++i){
        length.push_back(i+1);
    }
    
    int t[n+1][n+1];
    
    for(int i=0; i<=n; ++i){
        t[i][0] = 0;
    }
    for(int j=0; j<=n; ++j){
        t[0][j] = 0;
    }
    
    for(int i=1; i<=n; ++i){
        for(int j =1; j<=n; ++j){
            if(length[i-1]<=j){
                t[i][j] = max(price[i-1]+t[i][j-length[i-1]], t[i-1][j]);
            }
            else t[i][j] = t[i-1][j];
        }
    }
    return t[n][n];
}

// Striver

// Memoised

int solve(int ind, int price[], int target, vector<vector<int>> &dp){
    if(ind==0){  // ie rod length = 1
        return target*price[0];    // every target will be div by rod of size 1
    }
    
    if(dp[ind][target]!= -1) return dp[ind][target];
    
    int notTake = 0 + solve(ind-1, price, target, dp);
    int take = -1e9;
    int rodLength = ind+1;
    if(rodLength<=target){
        take = price[ind] + solve(ind, price, target-rodLength, dp);
    }
    return dp[ind][target] = max(take, notTake);
}

int cutRod(int price[], int n) {   // n is the size of the array as well as the target to be made
    
    //code here
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return solve(n-1, price, n, dp);
}


// Tabulated

int cutRod(int price[], int n) {   // n is the size of the array as well as the target to be made
    //code here
    vector<vector<int>> dp(n, vector<int> (n+1, 0));
    // base case
    for(int N = 0; N<=n; ++N){
        dp[0][N] = N*price[0];
    }
    
    for(int ind=1; ind<n; ++ind){
        for(int N=0; N<=n; ++N){
            int notTake = 0 + dp[ind-1][N];   // memo mein jo target tha yaha N ka naam de dia hai bas
            int take = -1e9;
            int rodLength = ind+1;
            if(rodLength<=N){
                take = price[ind] + dp[ind][N-rodLength];
            }
            dp[ind][N] = max(take, notTake);
        }
    }
    return dp[n-1][n];
}

// Space optimised

int cutRod(int price[], int n) {   // n is the size of the array as well as the target to be made
        
    //code here
    vector<int> prev(n+1, 0), cur(n+1, 0);
    // base case
    for(int N = 0; N<=n; ++N){
        prev[N] = N*price[0];
    }
    
    for(int ind=1; ind<n; ++ind){
        for(int N=0; N<=n; ++N){
            int notTake = 0 + prev[N];   // memo mein jo target tha yaha N ka naam de dia hai bas
            int take = -1e9;
            int rodLength = ind+1;
            if(rodLength<=N){
                take = price[ind] + cur[N-rodLength];
            }
            cur[N] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[n];
}

// 1 D
// Same as unbounded
// Just replace cur by prev ie rewrite in the same array simply

int cutRod(int price[], int n) {   // n is the size of the array as well as the target to be made
    //code here
    vector<int> prev(n+1, 0);
    // base case
    for(int N = 0; N<=n; ++N){
        prev[N] = N*price[0];
    }
    
    for(int ind=1; ind<n; ++ind){
        for(int N=0; N<=n; ++N){
            int notTake = 0 + prev[N];   // memo mein jo target tha yaha N ka naam de dia hai bas
            int take = -1e9;
            int rodLength = ind+1;
            if(rodLength<=N){
                take = price[ind] + prev[N-rodLength];
            }
            prev[N] = max(take, notTake);
        }
    }
    return prev[n];
}

