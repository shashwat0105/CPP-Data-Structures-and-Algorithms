https://leetcode.com/problems/find-the-town-judge/

// It should give 0 votes, and should get N-1 votes
// [[1, 3]] ; since 2 is missing we are short of a vote hence we have to return -1;

// Method 1:
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // 1st value: How many he trusts
        // 2nd value: How many trusts him
        vector<pair<int, int>> arr(n+1, {0, 0});
        for(int i=0; i<trust.size(); ++i){
            arr[trust[i][0]].first +=1;
            arr[trust[i][1]].second +=1;
        }
        
        // Now finding who is trusted by N-1 others
        for(int i=1; i<=n; ++i){
            if(arr[i].first==0 && arr[i].second==n-1) return i;
        }
        return -1;
    }
};

// Thinking in different terms
// Degree of a node = indegree - outdegree
// Here we want : indegree - outdegree = n-1

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Method 2: Using degree logic
        vector<int> data(n+1, 0);
        for(auto x: trust){
            data[x[0]]--;
            data[x[1]]++;
        }
        for(int i=1; i<=n; ++i){
            int x = data[i];
            if(x==n-1) return i;
        }
        return -1;
    }
};
