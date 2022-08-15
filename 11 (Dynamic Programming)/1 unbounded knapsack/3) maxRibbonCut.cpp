// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#
// or
// https://codeforces.com/problemset/problem/189/A


// INT_MIN INT_MIN INT_MIN ..... INT_MIN    } we have rod but dont have x,y or z So, which is not possible so to neglect that case we give it INT_MIN so that the value is small enough that even by accumulating previous cutting steps, it will still be neglected at the max function.
// 0
// 0
// 0
// ↓	
// We dont have rod so 0 is the maximum no of cut segments possible.

int maximizeTheCuts(int n, int x, int y, int z){
    //Your code here
    int w[]={x,y,z};
    int t[3+1][n+1];
    
    for(int i=0; i<=n; i++){
        t[0][i]=INT_MIN;                    // topmost row
    }
    for(int i=1; i<=3; i++){                
        t[i][0]=0;                          // leftmost column
    } 
    
    for(int i=1; i<=3; i++){
        for(int j=1; j<=n; j++){
            if(w[i-1]<=j){
                t[i][j]=max(1+ t[i][j- w[i-1]], t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[3][n]<0?0:t[3][n];          // return 0 if cutting is not possible ie a negative value
}


// Memoised Solution

int solve(int n, int x, int y, int z, vector<long long> &dp){
    if(n==0) return 0;
    if(n<0) return INT_MIN;
    if(dp[n]!=-1) return dp[n];
    
    long long a = solve(n-x, x, y, z, dp);           // This n-x can make it negative. in that case we have to return INT_MIN.
    long long b = solve(n-y, x, y, z, dp);
    long long c = solve(n-z, x, y, z, dp);
    
    return dp[n] = 1+max(a, max(b, c));
}
//Function to find the maximum number of cuts.
int maximizeTheCuts(int n, int x, int y, int z){
    //Your code here
    vector<long long> dp(n+1, -1);
    int ans = solve(n, x, y, z, dp);
    if(ans<0) return 0;
    return ans;
}

// Can also think by take not take of cut[] = {x, y, z}
******************

