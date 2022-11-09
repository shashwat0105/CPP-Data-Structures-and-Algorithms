https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

YET TO UNDERSTAND

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k>=prices.size()/2){ // at most u will make n/2 transactions, if k>=n/2 then u can make max no of transactions
            int profit = 0;
            for(int i=1; i<prices.size(); ++i){
                if(prices[i]>prices[i-1]) profit += prices[i]-prices[i-1];
            }
            return profit;            
        } 
        vector<int> buy(k+1, INT_MAX);
        vector<int> sell(k+1, 0);
        
        for(int price: prices){
            for(int i=1; i<=k; ++i){
                buy[i] = min(buy[i], price - sell[i-1]);
                sell[i] = max(sell[i], price-buy[i]);
            }
        }
        return sell[k];
    }
};

//
we can at most make n/2 transactions in the worst case of stock alternating between going up and down everyday . As an example : 1 4 2 6 3 8 . We will buy and sell on alternate days .

If there is any stretch where the stock is increasing continuously or decreasing continuously , then we will only need lesser number of transactions as we can skip a day in between to sell or buy .
Ex. 1 2 3 6 4 2 8 . Here , we don't need to sell on the 2nd day and we can wait that day out . Similarly , we don't need to buy on day 5 . So these 'wait' days only further reduce the number of max transactions from k/2


buy[i] = min(buy[i], price-sell[i - 1]);
why we are subtracting last transaction sell ?
Think of it like that . Sell[i-1] is the profit we have so far after selling i-1 stocks . 
After buying the i th stock , we are now calculating the loss we have at the end of this buying . At every step , we are minimizing the loss so far on the 'buy' step and consequently maximizing the profit so far on the 'sell' step

