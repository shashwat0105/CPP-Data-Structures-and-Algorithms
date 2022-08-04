https://leetcode.com/problems/employee-importance/

Asked in GOOGLE

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        for(auto x: employees) m[x->id] = x;
        int sum = 0;
        dfs(m, id, sum);
        return sum;
    }
    void dfs(unordered_map<int, Employee*> &m, int id, int &sum){
        sum += m[id]->importance;
        for(auto child: m[id]->subordinates) dfs(m, child, sum);
    }
};
