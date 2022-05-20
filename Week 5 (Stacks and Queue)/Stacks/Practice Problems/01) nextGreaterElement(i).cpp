https://www.geeksforgeeks.org/next-greater-element/

Next greater element or nearest greater to right

// We have to check in the right array part of the current element and find the nearest and largest element

// Brute force
for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){}
}

// two for loops and inner j is dependent on i hence the TC can be improved using stack


1 3 0 0 1 2 4
  -----------

I have to check from the left in 3 0 0 1 2 4 so I want 3 to be accessed first ie should be on top of stack. 
ie it should be inserted last or 4 to be inserted first then 2 then 1 ...

stack empty return -1
stack.top() > arr[i] -> stack.top()
stack.top() <= arr[i] -> stack.pop()  -----> stack empty nahi ho jata 
                                     or ---> till stack.top() > arr[i] 

/*if stack gots empty means there
is no element on right which is greater
than the current element.
if not empty then the next greater
element is on top of stack*/


We traverse the array from back hence this stores ans in reverse order so we reverse the ans to get final ans.

class Solution{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans;
        stack<long long> s;
        
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top()<=arr[i]){  // DONT write while(s.top()<=arr[i]&& !s.empty()){} as it will give segementation error as first condition is checked first and if stack is empty then u cant access the top element
                s.pop();
            }
            if(s.size()==0){                       // checking ki kis condition se while terminate hua
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
            s.push(arr[i]);                       // [1 3 2 4]  In this example when we permanently pop 2, we also push 3 ie a better ans in the stack at the top. So, there is no issue
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


LEETCODE Ques

https://leetcode.com/problems/next-greater-element-i/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dummyans;
        stack<int> s;
        
        for(int i=nums2.size()-1; i>=0; i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.size()==0){          // checking ki kis condition se while terminate hua
                dummyans.push_back(-1);
            }
            else{
                dummyans.push_back(s.top());
            }
            s.push(nums2[i]);
        }
        reverse(dummyans.begin(), dummyans.end());
        
        vector<int> ans;
        
        for(int i=0; i<nums1.size(); ++i){
            for(int j=0; j<nums2.size(); ++j){
                if(nums1[i]==nums2[j]){
                    ans.push_back(dummyans[j]);
                }
            }
        }
        return ans;
        
    }
};

// Optimised using map instead of dummyans

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;  // instead of dummyans we will use map to store
        stack<int> s;
        
        int n = nums2.size();
        for(int i=n-1; i>=0; --i){
            while(!s.empty() && nums2[i]>s.top()){  // abhi jo element chal raha hai wo bada hai top se
                s.pop();
            }
            if(s.empty()){
                m[nums2[i]] = -1;
            }
            else{
                m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        for(auto i: nums1){
            ans.push_back(m[i]);
        }
        return ans;
    }
};


// Also we are finding NGE for all elements in nums2, if size of nums1 <<< size of nums2 then we can say that selectively computation is better.

// PEECHE SE HI TRAVERSAL KARNA YAAD RAKHO(BEST YAHI HAI)


---------- OPTIONAL -----------
// We can also traverse from start(Ispe thoda analysis krna hai) (In this ques order doesnt matter as we are storing in map, but kya NGE ques start traversal se solve ho skta hai)
https://leetcode.com/problems/next-greater-element-i/discuss/671261/C%2B%2B-or-Map-%2B-Stack-or-Commented

NGE Ques start traversal
https://youtu.be/T-E3hWEPWWU

vector<long long> nextLargerElement(vector<long long> arr, int n){
       // Your code here
       stack<int>st;
       vector<long long> res(n , -1);
       
       for(int i=0;i<n;i++){
           
           if(st.empty()) {
               st.push(i);
               continue;
           }
           while(!st.empty() && arr[st.top()] < arr[i]){
               res[st.top()] = arr[i];
               st.pop();
           }
           st.push(i);
       }
       return res;
   }
};