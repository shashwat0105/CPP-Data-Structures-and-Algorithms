https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Greedy solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                profit += (prices[i] - prices[i-1]);
            }
        }
        return profit;
    }
};

// Dynamic Programming

// Trying all possibilities
// 1) Express everything in terms of index. f(ind, buy)
// I have to keep a variable buy which tells me If I can buy or not.
// 2) Explore possibilities on that day
// 3) Take the max of all profits made
// 4) Base case

If buy = 1 then I can either buy or not buy
If buy = 0 then I can either sell or not sell

