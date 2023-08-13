https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0
https://practice.geeksforgeeks.org/problems/geek-jump/1 

Striver : https://youtu.be/EgG3jsGoPvQ

// f(n-1): min energy required to reach (n-1) from 0. ie convert it into 0 based indexing

// Memoised code

int rec(int n, vector<int> &heights, vector<int> &dp){
    // base case
    if(n==0) return 0;
    
    if(dp[n]!= -1) return dp[n];
    
    int left = rec(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;                                                    // because right will not always exist ie for n=1, we cannot get two steps back.
    if(n>1) right = rec(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
    
    return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n+1, -1);
    return rec(n-1, heights, dp);
}


// Tabulation code

int frogJump(int n, vector<int> &heights){
    // Write your code here.
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i=1; i<n; ++i){
        int fs = dp[i-1] + abs(heights[i]- heights[i-1]);      // fs = first step
        int ss = INT_MAX;                                      // ss = second step
        if(i>1) ss = dp[i-2] + abs(heights[i]- heights[i-2]);
        dp[i] = min(fs, ss);
    }
    return dp[n-1];
}

// Space optimisation (Is done on tabulation ie bottom up)

Always there can be space optimisation when there is index-1, index-2 kind of thing.

int frogJump(int n, vector<int> &heights){
    // Write your code here.
    int prev = 0;
    int prev2 = 0;
    for(int i=1; i<n; ++i){
        int fs = prev + abs(heights[i]- heights[i-1]);
        int ss = INT_MAX;
        if(i>1) ss = prev2 + abs(heights[i]- heights[i-2]);
        int curi = min(fs, ss);
        prev2 = prev;
        prev = curi;
    }
    return prev;  // prev will be at n-1
}

