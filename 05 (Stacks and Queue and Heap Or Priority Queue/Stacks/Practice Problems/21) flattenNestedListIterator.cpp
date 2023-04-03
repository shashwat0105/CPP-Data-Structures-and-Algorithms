https://leetcode.com/problems/flatten-nested-list-iterator/


// For any particular position the value can be either an integer or a list.
// If the value is integer then no problem we can take it and put it in final ans
// If the value is list we traverse the list which contains integers or list(which will be traversed)
// This makes it a recursive problem. (we dont know how many nested lists are present)

// In comments of the editor 
// getInteger and getList are implemented already

https://youtu.be/FxrTMj1dtxM



CODE

class NestedIterator {
    // globally declared
    vector<int> ans;
    int i=0;          // variable which tells till what point we are currently present
public:
    void helper(vector<NestedInteger> &nestedList){         // to classify whether it is integer or a list
        for(int i=0; i<nestedList.size(); ++i){
            if(nestedList[i].isInteger()){                  // if it is an integer yeh method already built in hai commented code mein LC k
                ans.push_back(nestedList[i].getInteger());
            }
            else{
                helper(nestedList[i].getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {   // constructor
        helper(nestedList);                               // prefer to create a separate helper recursive function
    }
    
    int next() {                                          // read the definition from ques
        // int res=-1;                                    
        // if(i<ans.size()){
        //     ans=ans[i];
        //     i++;
        // }
        
        int res=ans.at(i);
        i++;
        return res;
    }
    
    bool hasNext() {
        return i<ans.size();
    }
};

//
// Iterator cannot be copied yeh pata ni kya hai dekh lena ar bhi solutions (YT pe jada ni hai)
https://leetcode.com/problems/flatten-nested-list-iterator/discuss/?currentPage=1&orderBy=most_votes&query=

https://leetcode.com/problems/flatten-nested-list-iterator/solutions/80169/concise-c-without-storing-all-values-at-initialization/

https://leetcode.com/problems/flatten-nested-list-iterator/solutions/80169/concise-c-without-storing-all-values-at-initialization/
