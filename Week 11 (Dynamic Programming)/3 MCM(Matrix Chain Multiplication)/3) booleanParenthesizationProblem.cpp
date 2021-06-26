// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/

Evaluate Expression To True-Boolean Parenthesization Recursion
Given a boolean expression with following symbols.
Symbols
    'T' --- true 
    'F' --- false 
And following operators filled between symbols
Operators
    &   ---boolean AND
    |   --- boolean OR
    ^   --- boolean XOR 
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
Example:
Input: symbol[]    = {T, F, T}
       operator[]  = {^, &}
Output: 2
The given expression is "T ^ F & T", it evaluates true
in two ways "((T ^ F) & T)" and "(T ^ (F & T))"


// Based on MCM because here also we are putting parenthesis at various places.
// 'k' will be breaked on a operator not on T, F coz -> (T^F&)T(^F) doesn't make sense, but (T)|(F&T^F) makes sense.
// Hence k -> k+2 (instead of k++)
// i, j will have T/F, k will have operator

// Step 1 :- Find i & j :- i = 0; i < length - 1

// XOR operation:- True when one side is true and other is false.
// No. of ways := (no of ways in which left is true) * (no of ways in which right is false) + (no of ways in which left is false) * (no of ways in which right is true)
// ie in subproblems we have to find both true and false, not just true
// Hence, function(s, i, j) is not sufficient we have to pass one more argument T (true) or False
// Hence, fun(s, i, j, T) -> fun(s, i, k, T) & fun(s, k+1, j, F) type of function will be made.

// i to j is string breaked on k -> splits in 2 parts -> i to k-1 & k+1 to j

// lT = left true
// lF = left false
// rT = right true
// rF = right false

#include<bits/stdc++.h>
using namespace std;

int solve(string s, int i, int j, int isTrue){
    int k, ans=0;
    // Base condition
    if(i>j){  
        return false;
    }
    if(i==j){  // one element in string containing either T or F
        if(isTrue == true){ // or isTrue == 1, jab apne ko true nikalna tha toh apan ne dekha single letter mein true hai ky toh true return kara dia else false return, 
            return s[i]=='T';
        }
        else                // jab apne ko false nikalna tha toh apan ne dekha single letter mein false hai ky toh true return kara dia else false return.
            return s[i] == 'F';
    }

    // for loop
    for(int k = i+1; k<=j-1; k+=2){
        int lT = solve(s, i, k-1, 1);  // or solve(s, i, k-1, true), & 0 instead of F, the subproblem's right index will be one less than k, coz k points to an operator
        int lF = solve(s, i, k-1, 0);
        int rT = solve(s, k+1, j, 0);
        int rF = solve(s, k+1, j, 1);

        // calculating final ans (simple boolean algebra)
        if(s[k] == '&'){
            if(isTrue == true){
                ans = ans + lT*rT;  // ie when there is & operator, T&T evaluates to T
            }
            else
                ans = ans + lF*rT + lT*rF + lF*rF; // These cases evaluates to false when used in & opeartor
        }

        else if(s[k] == '|'){
            if(isTrue == true){
                ans = ans + lT*rT + lF*rT + lT*rF;  
            }
            else
                ans = ans + lF*rF;
        }

        else if(s[k] == '^'){
            if(isTrue == true){
                ans = ans + lF*rT + lT*rF;  // XOR is true when one is true  
            }
            else
                ans = ans + lF*rF lT*rT ; // XOR is false when both are same
        }
    }
    return ans;
}

int main()

{

    string s;

    cout<<"Enter the string:"<<endl;
    cin>>s;
    cout<<"the string is:"<<s<<endl;

    int i=0, j=s.size()-1;
    int isTrue;

    cout<<"If we want true result put 1 else put 0:";
    cin>>isTrue;

    cout<<"The number of ways you get the ans in TRUE:"<< solve(s,i,j,isTrue);

}

// Cpp implicitly converts true as 1 & false as 0. However, incase of java it would fail.

// MEMOIZATION METHOD OPTIMISATION
// Dimension of table(matrix) depends on (=) number of variables that are changing in function call.
// Here i, j & isTrue are changing. Hence matrix dimensions:- i*j*isTrue (3D matrix)
// Constraints:- 0<s< 1000 -> max value of i & j could be length of string. & isTrue takes value as 0 & 1
// int t[1001][1001][2];

// Visualization of a 3D array can be typical so we can also use a map
// Coz our aim is to store the value of recursive calls somewhere, not necessarily in tables
// Map (We will do global declaration of this unordered map, not in main nor in solve function but near header files otherwise u need to pass map inside solve(i, j, map)...
// i + " " + j + " " + isTrue  -> Unique key -> Say 50_90_F whose value comes out to be 9 that will be stored.
// Key column | Value column
//            |
//            |
//            |
//            |


#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;

int solve(string s, int i, int j, int isTrue){
    int k, ans=0;
    // Base condition
    if(i>j){  
        return false;
    }
    if(i==j){  
        if(isTrue == true){  
            return s[i]=='T';
        }
        else                
            return s[i] == 'F';
    }

    // code changes
    string temp = to_string(i); // stl function, string contains 'i' now
    temp.push_back(' ');        // i_
    temp.append(to_string(j));  // i_j
    temp.push_back(' ');        // i_j_
    temp.append(to_string(isTrue)); // i_j_true or i_j_false
    // key is now prepared and stored in temp
    if(mp.find(temp)!=mp.end())  // find is searching in rows and has not reached end row ie upar kahi phle mil gyi hai value so wahi return kar do
        return mp[temp];
    // ab agar upar value nahi mila(1st time evaluation) toh neeche evaluate karo and jo value aye use map mein store kar do
    // for loop
    for(int k = i+1; k<=j-1; k+=2){
        int lT = solve(s, i, k-1, 1);  
        int lF = solve(s, i, k-1, 0);
        int rT = solve(s, k+1, j, 0);
        int rF = solve(s, k+1, j, 1);

        // calculating final ans (simple boolean algebra)
        if(s[k] == '&'){
            if(isTrue == true){
                ans = ans + lT*rT;  
            }
            else
                ans = ans + lF*rT + lT*rF + lF*rF; 
        }

        else if(s[k] == '|'){
            if(isTrue == true){
                ans = ans + lT*rT + lF*rT + lT*rF;  
            }
            else
                ans = ans + lF*rF;
        }

        else if(s[k] == '^'){
            if(isTrue == true){
                ans = ans + lF*rT + lT*rF;  // XOR is true when one is true  
            }
            else
                ans = ans + lF*rF lT*rT ; // XOR is false when both are same
        }
    }
    return mp[temp] = ans;
}

int main(){
    mp.clear();  // instead of initilising table to -1, here we clear the map ie no value be there in the map

    solve();
}


// Practice this
// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/


