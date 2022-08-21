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

// Space optimized rod cutting.
