https://leetcode.com/problems/beautiful-arrangement/

https://youtu.be/xf8qAkqDr8Y  (Algo made easy)

TC = O(K), SC = O(N)  // k = number of arrangements we are getting.

class Solution {
public:
    void calculate(int n, int pos, vector<bool> &visited, int &count){
        if(pos>n){
           count++;
           return;
        } 
        
        // i is the number I am filling at a particular position. ie I am trying every number from 1 to N to fill in those positions.
        for(int i=1; i<=n; ++i){                             // first step is to think about range of your loop, har level m kitne choices rahenge
            if(!visited[i] && (pos%i==0 || i%pos==0)){
                visited[i] = true;
                calculate(n, pos+1, visited, count);
                visited[i] = false;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<bool> visited(n+1, false); // 1-based indexing
        int count = 0;
        calculate(n, 1, visited, count);
        return count;
    }
};


https://leetcode.com/problems/beautiful-arrangement/discuss/1000788/C%2B%2B-Backtracking-DFS-%2B-Bitwise-Solutions-Compared-and-Explained-100-Time-~95-Space

// Swap method(faster but same complexity)
class Solution {
public:
    int solve(int n, vector<int>&a){
        if(n <= 0) return 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i]%n == 0 || n%a[i] == 0){
                swap(a[i], a[n-1]);
                ans += solve(n-1, a);
                swap(a[i], a[n-1]);
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<int>a;
        for(int i = 0; i < n; i++){
            a.push_back(i+1);
        }
        return solve(n, a);
    }
};
