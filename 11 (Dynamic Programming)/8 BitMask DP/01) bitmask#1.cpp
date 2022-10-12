Problem Statement

Let there be N workers and N jobs. Any worker can be assigned to perform any job, 
incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs
by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
N <= 20


// SOLN
2 + 6 + 1 + 4 = 13

// Brute force TC = O(N!)
//
dp(i, mask): min cost to assign (i .... N ) jobs such that using the people represented by the mask.
mask represents the subset of people.
0th bit of the mask is on means 1st person is available to you.
jth bit is on means j+1th person is available to you.

Recurrence:
dp(i, mask) = Cji (cost of assinging jth person to ith job) + dp(i+1, mask|turn off the jth bit)  // do this for all valid j ie jth bit is on
And then select the min.

SC = O(N * 2^N)
TC = O(N^2 * 2^N)

// Code

int cost[21][21];
int dp[21][1<<21]; // ie 2^21 dimension for the mask

int solve(int i, int mask, int &n+1){
    if(i==n) return 0;  // no jobs to be assigned

    if(dp[i][mask] != -1) return dp[i][mask];

    int ans = INT_MAX;
    for(int j = 0; j <n; ++j){
        if(mask & (1<<j)){
            ans = min(ans, cost[j][i] + solve(i+1, (mask ^ (1<<j)), n));  
        }
    }

    return dp[i][mask] = ans;
}

int main(){
    int t=1;
    memset(dp, -1, sizeof(dp));
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cin>>cost[i][j];
            }
        }
        cout<<solve(0, (1<<n)-1, n)<<'\n';  // 2^n - 1 is all the people available.
    }
    return 0;
}

