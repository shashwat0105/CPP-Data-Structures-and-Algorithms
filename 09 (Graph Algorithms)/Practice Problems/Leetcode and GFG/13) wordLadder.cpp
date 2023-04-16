https://leetcode.com/problems/word-ladder/

https://youtu.be/tRPda0rcf8E (striver)

HARD

I can pick a character and change it to anything from a-z

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;  // (string, level)
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end()); // add all the words to set DS
        st.erase(beginWord);   // if the start word exist we delete it

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            
            for(int i=0; i<word.size(); ++i){  // I have to traverse for every character
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ++ch){
                    word[i] = ch;
                    // it exist in set
                    if(st.find(word)!=st.end()){
                        st.erase(word);           // if a word comes in my path, usko repeat agar karoge toh path bada hi ho jaega hence we erase it.
                        q.push({word, steps+1});
                    }
                }
                word[i] = original; // we have to undo the change, as the word would have become **z**
            }
        }
        return 0;
    }
};

TC = N * wordLength * 26

// Follow up:
Time complexity will remain same but can you further improve on time?
Yes, by kind of bi-directional BFS. (Kind of parallel processing)
ie We may also start from the endWord simultaneously. Once we meet the same word, we are done.
Code here:
https://leetcode.com/problems/word-ladder/solutions/40707/c-bfs/
Also in above code instead of a pair in queue, you can use a count variable by introducing a for loop of q.size() that used to keep track of levels. Code in in above.

