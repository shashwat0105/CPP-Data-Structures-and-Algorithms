https://www.interviewbit.com/problems/nearest-smaller-element/

// Nearest smaller element or Nearest smaller to left

// Nearest Smaller Element
// Left to right traverse karenge ar dekhenge ki stack m abhi koi bada element toh nahi hai, sabko pop kar do

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans;
    stack<int> s;

    for(int i=0; i<A.size(); ++i){
        while(!s.empty() && s.top()>=A[i]){          // this comparison condition changes
            s.pop();        
        }
        if(s.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(s.top());
        }
        s.push(A[i]);
    }
    return ans;
} 

Nearest Smaller to Right

// We will traverse from right
// reverse at end coz using push_back
// equality condition changes

vector<int> Solution::nextSmaller(vector<int> &A) {
    vector<int> ans;
    stack<int> s;

    for(int i=A.size()-1; i>=0; --i){
        while(!s.empty() && s.top()>=A[i]){          // this comparison condition changes from NGR (Yeh = sign k liye consecutive equal elements in inputs deke dekh lena)
            s.pop();
        }
        if(s.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(s.top());
        }
        s.push(A[i]);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

