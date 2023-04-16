https://leetcode.com/problems/word-ladder-ii/

https://youtu.be/DREutrv2XD0  (Striver)
HARDDDD

We have to print all the possible sequences here. DAMNNN

Straight forward BFS wont work here.

Entirely level has to be completed THEN ONLY you will erase it from set.
Coz in a particular level a word can appear multiple times for different answers.
For ex:
bat pat pot poz coz
bat bot pot poz coz
"pot" appeared in both ans at level 3.
Beyond this level you wont take "pot" coz it will increase the length of the path.

Code 1: TLE on Leetcode : 32/36 passed, works on GFG
This is perfect solution for an interview:

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q;  
        q.push({beginWord});
        
        unordered_set<string> st(wordList.begin(), wordList.end()); // add all the words to set DS
        
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        
        int level = 0;
        vector<vector<string>> ans;

        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();

            // erase all the words that have been used in previous level to transform
            if(vec.size()>level){
                level++;
                for(auto it: usedOnLevel) st.erase(it);
            }

            string word = vec.back();
            // forming ans 
            if(word==endWord){
                if(ans.size()==0){  // I am filling ans for the first time
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){  // after that
                    ans.push_back(vec);
                }
            }

            for(int i=0; i<word.size(); ++i){  // I have to traverse for every character
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ++ch){
                    word[i] = ch;
                    if(st.count(word )){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word); // mark as visited on level
                        vec.pop_back();  // for the same level I have to find another word, I will pop this
                    }
                }
                word[i] = original; // we have to undo the change, as the word would have become **z**
            }
        }
        return ans;
    }
};

Code 2: Accepted on LC
The test case are made strict.
CP oriented solution: (NOT FOR INTERVIEW)

Step 1:-
Count the minimum steps required to reach beginword from each string present in the word list using simple BFS.
Step 2:-
Then for returning the path, start backtracking from the endword and keep moving to words having minimum steps 1 less than the current word.

https://youtu.be/AD4SFl7tu7I (Striver)
https://takeuforward.org/graph/word-ladder-ii-optimised-approach-g-31/  (Article for code)
Instead of converting from beginword, if we try from end word, there can be lesser amout of paths.
