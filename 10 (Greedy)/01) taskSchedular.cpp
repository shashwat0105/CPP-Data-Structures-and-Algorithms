https://leetcode.com/problems/task-scheduler/

If we have more number of different tasks than n, then we can alternate between those tasks.
Get rid of max frequency tasks.

// Method 1 using priority queue, by repeatedly transfering elements from heap to a temp array.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>counts;
        for(char t: tasks){
            counts[t]++;
        }
        priority_queue<int> pq; // only need to store the task frequency no need for storing the alphabet as well
        for(auto c: counts){
            pq.push(c.second);
        }
        int result = 0;
        while(!pq.empty()){
            int time = 0;
            vector<int> temp;
            for(int i=0; i<n+1; ++i){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1); // 1 occurence has been used
                    pq.pop();
                    time++;
                }
            }
            for(auto t: temp){
                if(t) pq.push(t);
            }
            result += pq.empty() ? time : n+1;
        }
        return result;
    }
};


// Method 2 using greedy type intuition.

https://leetcode.com/problems/task-scheduler/solutions/760569/c-greedy-o-n-time-o-1-space-with-explanation-in-5-lines/

["A","A","A","A","A","B","B","C"], n = 1
maxcnt = 5
there is only A that occures 5 times so e = 1. that ie at the end keval ispe hi dhyan dena padega idle daalne k liye

Visualisation with example.
https://leetcode.com/problems/task-scheduler/solutions/471238/Simple-C-solution-(wo-priority-queue)-3-lines-of-code-O(N)-O(N):-Detailed-explanation-w-samples/

// (maxcnt-1) number of cycles are there
// (n+1) is the size of one cycle
// Esa samajh skte hai

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int maxcnt=0, e=0; // maxcnt = maximum of occurence of each element, e = number of characters which occurs maxcnt times. A A A B B B C then e = 2
        for(auto t: tasks){
            mp[t]++;
            maxcnt = max(maxcnt, mp[t]);
        }
        for(auto m: mp){
            if(m.second==maxcnt) e++;
        }
        int lower_bound_ans = (maxcnt-1)*(n+1) + e;
        int upper_bound_ans = tasks.size(); // "upper bound" of the answer? That is, what if we don't have any idle time units, what is the answer then.
    
        return max(upper_bound_ans, lower_bound_ans);
    }
};
