Leetcode:
https://leetcode.com/problems/online-stock-span/

CRUX:
O/P = Index of current - Index of Next greater element to Left (NGEL)  // If there is greater element to left
    = Index of current + 1 // otherwise

Instead of stack<int> s  -> stack<pair<int, int> s;
In stack we will store price along with its span, so that agla koi aye toh wo previous wale ka span use kar paega.

// Better Code and Complexity
// Refer this below for dry run and image
https://leetcode.com/problems/online-stock-span/discuss/636856/Single-stack-explanation-with-Diagram

class StockSpanner {
public:
    stack<pair<int, int>> s;   // stack of pair<Price, Span>
    StockSpanner() {} 
    
    int next(int price) {
        int span = 1;
        while(!s.empty() && s.top().first<=price){
            span+=s.top().second;                   // stack ka element chhote hai toh span increase hoga
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};

// Using a vector
class StockSpanner {
private: 
    vector<int> prices;
    stack<int>s;
    int i=0;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        prices.push_back(price);
        while (!s.empty() && prices[s.top()]<=prices[i]){
            s.pop();     
        }
        int val;
        if (s.empty()) val = i+1;
        else val = i - s.top();
        s.push(i);
        i++;
        return val;
    }
};

GFG:
https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/

https://youtu.be/p9T-fE1g1pU

100 80 60 70 60 75 85

Stock Span
// (starting from today and going backward) for which the stock price was less than or equal to today's price.

// Identification
We have to find
Consecutive smaller or equal to before it. = This is same as nearest greater to left.

After that we subtract the indices to get the number of consecutive smaller.
ie Index of NGL - Index of current

// Before we stored NGL now we will store NGL ka index in the vector
Indexes                    :   0   1  2  3  4  5  6    
                              100 80 60 70 60 75 85
Vector storing index of NGL:   -1  0  1  1  3  1  0

Output ans                 : (0--1) (1-0) (2-1) (3-1) (4-3) (5-1) (6-0)


CODE:
class Solution
{
    public:
    //Function to calculate the span of stock's price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans;
       stack<pair<int, int>> s;
       for(int i= 0; i<n; ++i){
           while(!s.empty() && s.top().first<=price[i]){   // yeh = ki wajah se error aa jata hai isko dhyan se handle karo ki = hone pe bhi pop kar sakte hai kya  
               s.pop();
           }
           if(s.empty()){
               ans.push_back(-1);
           }
           else{
               ans.push_back(s.top().second);
           }
           s.push({price[i], i});
       }
       for(int i=0; i<ans.size(); i++){
           ans[i] = i-ans[i];
       }
       return ans;
    }
    
};

// OR

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here    
       vector<int> ans;
       stack<pair<int, int>> s;
       for(int i= 0; i<n; ++i){
           while(!s.empty() && s.top().first<=price[i]){
               s.pop();
           }
           if(s.empty()){
               ans.push_back(i+1);
           }
           else{
               ans.push_back(i-s.top().second);
           }
           s.push({price[i], i});
       }
       return ans;
    }
};


// Avoiding pair
// We can modify the stack to store just NGL indexes and while comparing we can use something like this  a[s.top()]<=a[i]  we can ignore the use of pair<> in such a case.

class Solution
{
    public:
    //Function to calculate the span of stocks price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans;
       stack<int> s;
       for(int i= 0; i<n; ++i){
           while(!s.empty() && price[s.top()]<=price[i]){
               s.pop();
           }
           if(s.empty()){
               ans.push_back(i+1);
           }
           else{
               ans.push_back(i-s.top());
           }
           s.push(i);
       }
       return ans;
    }
};


