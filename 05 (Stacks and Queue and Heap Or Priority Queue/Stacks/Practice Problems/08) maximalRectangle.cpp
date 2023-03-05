https://leetcode.com/problems/maximal-rectangle/

Maximum area of rectangle in a binary matrix

MAH(Previously Done) - 1D
This Ques - 2D


https://youtu.be/St0Jf_VmG_g?t=930 
(See the diagram at this time stamp)

0   1   1   0    1*4  Histogram 1:  0 1 1 0  (Max area 2)
1   1   1   1    2*4  Histogram 2:  1 2 2 1  (Max area 4)
1   1   1   1    3*4  Histogram 3:  2 3 3 2  (Max area 8)
1   1   0   0    4*4  Histogram 4:  3 4 0 0  (Max area 6)

2 D array to Four 1-D arrays

Max area = max(H1, H2, H3, H4)

// CODE
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();            // number of rows
        int m = matrix[0].size();         // number of columns
        vector<int> v;
        int maxAns=0;
        
        // For first row
        for(int j=0; j<m; ++j){
            int x = matrix[0][j] - '0';  // changing char to int
            v.push_back(x);              // first row is as it is copied
        }
        maxAns = MAH(v);
            
        // For rest of the rows
        for(int i=1; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(matrix[i][j]=='0'){         // if the current element is 0 then it becomes ground
                    v[j]=0;
                }
                else{
                    int x = matrix[i][j]-'0';
                    v[j] = v[j] + x;           // else the past height gets added to it.
                }
            }
            maxAns = max(maxAns, MAH(v));
        }
        return maxAns;
    }
    
    // Code snippet of previous ques
    int MAH(vector<int>& heights) {
        int n=heights.size();
        vector<int> indexNSR(n);                                   // it is important to hardcode the size to avoid garbage values while accessing or changing ith element
        vector<int> indexNSL(n);
        stack<int> s;
                
        // NSR                                                     (is NSR k code mein reverse karne ki jaroorat nahi padi maine cout karke dekh lia hai, BUT WHY?)
        for(int i=n-1; i>=0; --i){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            indexNSR[i] = s.empty()? n : s.top();
            // if(s.empty()){
            //     indexNSR[i] = n;
            // }
            // else{
            //     indexNSR[i] = s.top();
            // }
            s.push(i);
        } 

        // for(auto it: indexNSR){
        //     cout<<it<<" ";
        // }
        
        // empty the stack to be used again
        while(!s.empty()) s.pop();
        
        // NSL
        for(int i=0; i<n; ++i){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            indexNSL[i] = s.empty()? -1 : s.top();                 // instead of an array can take this as a variable, and calculate max_area here itself.(See my submitted solutions)
            s.push(i);
        }

        // for(auto it: indexNSL){
        //     cout<<it<<" ";
        // }

        int max_area=0;
        for(int i=0; i<n; i++){
            max_area = max(max_area,(indexNSR[i]-indexNSL[i]-1)*heights[i]) ;
        }
        return max_area;
    }
    
};

// Do analysis of other methods.
// Check the leetcode discuss/YT for other short and DP solutions
https://leetcode.com/problems/maximal-rectangle/discuss/?currentPage=1&orderBy=most_votes&query=
