https://leetcode.com/problems/minimum-cost-for-tickets/

// recursive

// Yeh bhi dhang ka nahi hai.
// Fails for:
// [1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29]
// [3,14,50]
class Solution {
public:
    int solve(int n, vector<int>& days, vector<int>& costs, int index){
        // base case
        if(index >= n) return 0;  // jada ki ticket le li toh aage nikal jaega
        
        // 1 day pass
        int op1 = costs[0] + solve(n, days, costs, index+1);
        
        int i;       // yeh pehle declare krna hi padega
        // 7 day pass
        // finding index in the days array, that after incrementing by 7 where will it maximum reach.
        // say [1, 2, 5, 7, 20, 35] // 7 day pass will last till 7.
        
        for(i=index; i<n && days[i] < days[index]+7; ++i);   // this loop does nothing but changes i. 
        
        int op2 = costs[1] + solve(n, days, costs, i);
        
        // 30 day pass
        for(int i=index; i<n && days[i] < days[index]+30; ++i);
        
        int op3 = costs[2] + solve(n, days, costs, i);
        
        return min({op1, op2, op3});
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solve(n, days, costs, 0);   // start index 0 is passed
    }
};

********************
Simple sawal hai upar ka chutiyapa karne ki kya jaroorat hai?
Thanks to: https://leetcode.com/problems/minimum-cost-for-tickets/discuss/886443/Evolution-%3A-Recursion-greater-Memo-on-Recursion-greater-DP-greater-6-line-DP.-Detailed-explanation


class Solution {
public:
    int calculate(vector<int>& costs, int i, vector<bool> map, vector<int> &memo){
        if(i>365) return 0;
        if(memo[i]!= -1) return memo[i];
        if(!map[i]) return memo[i] = calculate(costs, i+1, map, memo);
        
        return memo[i] = min({
            costs[0] + calculate(costs, i+1, map, memo),
            costs[1] + calculate(costs, i+7, map, memo),
            costs[2] + calculate(costs, i+30, map, memo)
        });
    } 
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> map(366, false);
        vector<int> memo(366, -1);
        for(auto x: days){
            map[x] = true;
        }
        int dollars = calculate(costs, 0, map, memo);
        return dollars;
    }
};

He figures out, because he already has the reapeated calculations jotted, he can just begin from the end and whatever price he ends up paying for today, will be the min cost for year!

class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = 367;
        vector<bool> map(n, false);
        vector<int> dp(n, 0);
        for(auto x: days){
            map[x] = true;
        }
        for(int i=n-1; i>=0; --i){
            dp[i] = dp[min(n-1, i+1)];
            if(map[i]){
                dp[i] = min({costs[0]+dp[min(n-1, i+1)], costs[1]+dp[min(n-1, i+7)], costs[2]+dp[min(n-1, i+30)]});
            }
        }
        
        return dp[0];
    }
};
