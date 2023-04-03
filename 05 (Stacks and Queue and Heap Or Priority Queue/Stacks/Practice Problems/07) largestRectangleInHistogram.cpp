https://leetcode.com/problems/largest-rectangle-in-histogram/

https://youtu.be/J2X70jj_I1o (AV)

A building can be expanded into other buildings only when other building heights >= current building height.

// For left direction expansion we stopped at nearest smaller to left  (NSL)
// for right direction expansion we stopped at nearest smaller to right (NSR)

Index         =  -1(Dummy index Ground) 0   1   2   3   4   5   6   7(Dummy index(n=7) Ground)
Arr           =                         6   2   5   4   5   1   6
Index of NSR  =                         1   5   3   5   5   7   7
Index of NSL  =                        -1  -1   1   1   3  -1   5
Right-Left-1  =                         1   5   1   3   1   7   1                    
(Width of rectangle)
Area          =                         6   10  5   12  5   7   6       
Area possible from current building = widh of rectangle * height of current building

Max area = 12

// CODE (Multiple Pass solution)
// TC = O(4N)
// SC = O(3N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> indexNSR(n);                                   // it is important to hardcode the size to avoid garbage values while accessing or changing ith element
        vector<int> indexNSL(n);
        stack<int> s;
                
        // NSR                                                     
        for(int i=n-1; i>=0; --i){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();  // equal hua toh bhi expand kr jaega isliye pop kr skte hai.
            indexNSR[i] = s.empty()? n : s.top();
            s.push(i);
        } 

        // empty the stack to be used again
        while(!s.empty()) s.pop();
        
        // NSL
        for(int i=0; i<n; ++i){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            indexNSL[i] = s.empty()? -1 : s.top();                 // instead of an array can take this as a variable, and calculate max_area here itself.(See my submitted solutions)
            s.push(i);
        }

        int max_area=0;
        for(int i=0; i<n; i++){
            max_area = max(max_area, (indexNSR[i]-indexNSL[i]-1)*heights[i]) ;
        }
        return max_area;
    }
};


// One pass solution: 
// Another PRO and Concise solution, comments section
https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28905/My-concise-C%2B%2B-solution-AC-90-ms

https://abhinandandubey.github.io/posts/2019/12/15/Largest-Rectangle-In-Histogram.html

// This solution is difficult to explain which can mess up the interview
// 1 pass solution (if interviewer upar wale se waise ho jaega satisfied but agar na ho toh hi batana hai)

https://youtu.be/jC_cWLy7jSI 
// (Striver)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        int n = heights.size();
        
        for(int i=0; i<=n; ++i){ // we go one more step in heights ie ground level
            while(!s.empty() && (i==n || heights[s.top()] >= heights[i])){
                int h = heights[s.top()];
                s.pop();
                int width;
                if(s.empty()) width = i;
                else width = i-s.top()-1;
                maxArea = max(maxArea, width*h);
            }
            s.push(i);
        }
        return maxArea;
    }
};

// Is code ko samajhne k liye examples leke dry run karke hi samajh paoge!! (For later)
