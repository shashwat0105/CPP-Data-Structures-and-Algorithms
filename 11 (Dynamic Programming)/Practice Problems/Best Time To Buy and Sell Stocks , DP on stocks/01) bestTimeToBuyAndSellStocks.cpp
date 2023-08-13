https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/714232/C%2B%2B-All-buy-sell-stock-problems-solved-in-similar-format-Easy-to-understand


https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Selling at the ith day then when should I but for max profit.

// For every guy if I can keep track of minimum element to the left of it.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // = prices[0] as there is 1 element for sure // this variable is acting as a memo
        int profit = 0;
        int n = prices.size();
        for(int i=0; i<n; i++){                    // if initilise with prices[0] then can start loop with i=1
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, prices[i]-minPrice);
        }
        return profit;
    }
};


