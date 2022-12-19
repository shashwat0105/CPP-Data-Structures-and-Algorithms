https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/solutions/1304132/priority-queue-step-by-step-explanation/

//Approach: 
//We're basically adding all the activites that start on a same given day.
//Out of these we now attend the one which ends at the earliest possible.
//We increment the day and hence remove all the activites which coudn't be attended.


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        // priority queue contains deadlines of all the events that have already started but not ended.
        priority_queue<int, vector<int>, greater<int>> pq;  // minheap

        // sort by event start date
        sort(events.begin(), events.end());

        int min_day = events[0][0];
        int max_day = events[0][1];
        for(int i=1; i<n; i++) max_day = max(max_day, events[i][1]);

        int index = 0, ans = 0;
        for(int i=min_day; i<=max_day; ++i){
            // remove all elements which are already over // end day is less than the current day
            while(!pq.empty() && pq.top()<i) pq.pop();

            // insert deadline of 'all' events that start at day i (today)
            while(index<n && events[index][0]==i){
                pq.push(events[index][1]);
                index++;
            }
            
            // if there are events that we can attend today we attend the event with smallest endtime
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};