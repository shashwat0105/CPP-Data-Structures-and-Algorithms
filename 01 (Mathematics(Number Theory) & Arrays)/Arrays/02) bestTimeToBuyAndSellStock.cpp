https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

https://youtu.be/XIWykOHE1SE

// Brute Force O(n^2) gives TLE:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int profit = 0;
        for(int i=0; i<prices.size(); i++){
            for(int j=i+1; j<prices.size(); j++){
                int profit = prices[j] - prices[i];
                if(profit > maxProfit){
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }
};

// Optimised Approach: Time: O(n), Space: O(1)
int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX;                          //  min price till now
    int profit = 0;
    for(int i=0; i<prices.size(); i++){
        min_price = min(prices[i], min_price);
        profit = max(profit, prices[i] - min_price);
    }
    return profit;
}   


