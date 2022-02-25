https://leetcode.com/problems/design-browser-history/

https://youtu.be/SPDhPuMsM9A

// Method 1: 
// Doubly Linked List is used in browser history.

// DLL is implemented using lists in STL. So, no need to write that code.
// In STL we use iterators

class BrowserHistory {
public:
    list<string> history;
    list<string> :: iterator it;   // auto it;
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = history.begin();
    }
    
    void visit(string url) {
        auto del = it;
        del++;
        history.erase(del, history.end());          // google->fb->yt->SC ,, on visiting IG from fb, the history of yt and SC will be gone.
        history.push_back(url);                     // inserting the new url
        it++;
    }
    
    string back(int steps) {
        while(it!=history.begin() && steps--) {    // it reaches the homepage or steps end then loop will break
            it--;
        }
        return *it;                                // dereferencing ie it jis string ko point kar rha wo return karo
    }
    
    string forward(int steps) {
        while(it!=(--history.end()) && steps--) {  // coz history.end is something after the last node so we use pre decrement
            it++;
        }
        return *it;
    }
};



// METHOD 2: Using two STACKs

// IN FUTURE I WILL WRITE THIS METHOD


