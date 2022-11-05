https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

When greedy fails, you have to try all possible ways.

value of last variable.
0 - first task was performed btd
1 - second task was performed btd
2 - third task was performed btd
3 - no task was performed before that day(btd) // last day se before koi task nahi hua hoga

dp[N][4] will be required, as these are changing.


// code

int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    // base case
    if(day==0){  // I am standing at the last day, I need to chose best task I can perform except the last task that cannot be performed.
        int maxi = 0;
        for(int task = 0; task<3; task++){ 
            if(task!=last){
                maxi = max(maxi, points[0][task]); 
            }
        }
        return maxi;
    }
    if(dp[day][last]!= -1) return dp[day][last];
    
    int maxi = 0;
    // any other day
    for(int task = 0; task<3; ++task){
        if(task!=last){
            int point = points[day][task] + solve(day-1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return solve(n-1, 3, points, dp);             // last day se before koi task nahi so 3 is passed.
}

// Tabulation

int ninjaTraining(int n, vector<vector<int>> &points){
    // Write your code here.
    vector<vector<int>> dp(n+1, vector<int>(4,-1));
    
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    // for other days
    for(int day=1; day<n; day++){
        for(int last = 0; last<4; last++){
            dp[day][last] = 0;
            for(int task = 0; task<3; ++task){
                if(task!= last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n-1][3];
}

// Space optimisation
// Keep on moving the array of size 4

int ninjaTraining(int n, vector<vector<int>> &points){
    // Write your code here.
    vector<int>prev(4, 0);
    
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    // for other days
    for(int day=1; day<n; day++){
        vector<int> temp(4, 0);
        for(int last = 0; last<4; last++){
            temp[last] = 0;
            for(int task = 0; task<3; ++task){
                if(task!= last){
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
