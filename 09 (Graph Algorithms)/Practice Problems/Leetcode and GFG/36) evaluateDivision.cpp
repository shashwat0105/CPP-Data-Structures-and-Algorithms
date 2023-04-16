https://leetcode.com/problems/evaluate-division/ 


class Solution {
public:
    void dfs(string s, string d, map<string, vector<pair<string, double>>> &m, set<string> visited, double &ans, double temp){
        if(visited.find(s)!=visited.end()) return;
        else{
            visited.insert(s);
            if(s==d){            // we reached our destination
                ans = temp;
                return;
            }
            else{
                for(auto a: m[s]){
                    dfs(a.first, d, m, visited, ans, temp * a.second);
                }
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        // creating the graph 
        map<string, vector<pair<string, double>>> m;
        for(int i=0; i<e.size(); ++i){
            m[e[i][0]].push_back({e[i][1], v[i]});   // push back k bina nahi likh paoge I guess: https://stackoverflow.com/questions/10487865/insert-vector-for-value-in-map-in-c
            m[e[i][1]].push_back({e[i][0], 1/v[i]}); // if a/b is given then b/a can also be calculated
        }
        
        // we need to find a path from given source to destination, if it exists then only division is possible which is = product of path weights.
        // These source and destination are given in queries array
        vector<double>res;
        for(int i=0; i<q.size(); ++i){
            string s = q[i][0];
            string d = q[i][1];
            
            set<string> visited;
            double ans = -1.0;
            if(m.find(s)!=m.end()){                  // we have to call dfs only if the source exists in the map
                dfs(s, d, m, visited, ans , 1.0);
            }
            res.push_back(ans);
        }
        return res;
    }
};

