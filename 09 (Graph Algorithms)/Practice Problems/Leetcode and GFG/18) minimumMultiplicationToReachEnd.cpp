https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

https://youtu.be/_BvEJ3VIDWw (Striver)

Kind of ki jo keh raha kar do problem
 
We used to go in adjacent nodes, here we multiply to get adjacent nodes.

CODE:
int minimumMultiplications(vector<int>& arr, int start, int end) {
    queue<pair<int, int>> q;
    q.push({start, 0});

    vector<int> dist(100000, 1e9);
    dist[start] = 0;
    int mod = 100000;

    while (!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(node==end) return steps;       // early return
        for (auto &it : arr){
            int num = (it * node) % mod;
 
                dist[num] = steps + 1;

                // if (num == end)
                //     return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }
    return -1;
}
