https://leetcode.com/problems/accounts-merge/

https://youtu.be/FMwpt_aQOGw (Striver)

// Medium-Hard asked in Nutanix perhaps
// Implementation heavy

// Good ques of Union Find
// Every stage something is connecting, merging dynamically implies DSU data structure.

Striver code here: https://leetcode.com/problems/accounts-merge/solutions/3024257/c-easy-approach-using-dsu-striver-approach/

class Solution {
private:
    string find(string s, unordered_map<string, string>& p) {  // find ultimate parent
        if(p[s]==s)
            return s;
        return p[s] = find(p[s], p); // using path compression
        // return p[s] == s ? s : find(p[s], p);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        unordered_map<string, string> owner;
        unordered_map<string, string> parents;
        unordered_map<string, set<string>> unions;
        
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                parents[acts[i][j]] = acts[i][j]; // initially self parent
                owner[acts[i][j]] = acts[i][0];
            }
        }
        
        // Tricky Part
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1], parents);
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j], parents)] = p; // then making the first elements parent as alls parent
        }
        
        // Save the emails with same parent email to same set
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++)
                unions[find(acts[i][j], parents)].insert(acts[i][j]);

        vector<vector<string>> ans;
        for (const auto& p : unions) {
            vector<string> emails(p.second.begin(), p.second.end()); // convert set to vector
            emails.insert(emails.begin(), owner[p.first]); // insert the owner at the start of vector , p.first is the parent email of all p.second(s)
            ans.push_back(emails);
        }
        return ans;
    }
};

// Method 2:
Without DSU
https://leetcode.com/problems/accounts-merge/solutions/1601960/c-python-simple-solution-w-images-and-explanation-building-graph-dfs/

John- J1 J2 
John- J1 J4
John- J3
Mary- M1

I make a graph
Make a edge bw J1 and J2, then ek edge banegi J1 se J4 toh automatically J1, J2 ar J4 connect ho gaye ek sath. J3 ar M1 alag reh gaye.
Ar jab graph ban jae toh bas traverse kr lo simple and intuitive.
