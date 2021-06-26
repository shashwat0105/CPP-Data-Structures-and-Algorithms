// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/

// Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
// Example:
//   “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”.
// We have to find min no of partition needed. For ex:- 2 in case of n|iti|k  (nitik),, worst case -> n|i|t|i|k

// Identifying that this ques is based on MCM format?
// We will move 'k' as partition to check if the partitioned parts are palindrome & then we take min

// Four Steps of MCM -
// 1) Find i & j 
// 2) Base condition
// 3) Find k loop
// 4) Calculating ans from temporary ans

// Here there is no problem in i = 0 & j = string length - 1 // But in MCM we need two array elements to calcuate matrix dimensions so i = 0 was invalid

// We have to decide k-> i or i+1 to j or j-1 => Preferred and Valid here -> k moves from i to j-1 & split of recursive fun is i to k & k+1 to j

// s(i)hahs(j)
bool isPalindrome(string s, int i, int j){
    if(i==j){
        return True;
    }
    if(i>j){
        return True;
    }
    while(i<j){
        if(s[i]!=s[j]){
            return False;
        }
        i++;
        j--;
    }
}

int solve(string s, int i, int j){
    if(i>=j){
        return 0; // Either the string is empty or has 1 character only then no need of partition.(already palindrome)
    }
    if(isPalindrome(s, i, j) == True){
        return 0;
    }
    int mn = INT_MAX;
    for(k=i; k<=j-1; k++){  // yaha har ek position pe partition krna hai so k++, somewhere it may be k+2 when needed
        int tempans = solve(s, i, k) + solve(s, k+1, j) + 1; // Here C1 = no of partition in left, C2 is no of partition in right, C3 is "1" partiton b/w left and right 

        //ans = min(ans, temp);
    if(temp<mn){
        mn = temp;
    }
    }
    return mn;
}


// MEMOIZATION (Top Down DP)
// The below code will pass all test cases on GFG but not on InterviewBit(wants more optimised in time and space)
// Variables which are changing are i & j
// 0 < s < 1000 given in ques

int static t[1001][1001];  // using static, no need to pass 't' inside functions (verify this)

int solve(string s, int i, int j){
    if(i>=j){
        return 0; // Either the string is empty or has 1 character only then no need of partition.(already palindrome)
    }
    if(isPalindrome(s, i, j) == True){
        return 0;
    }

    if(t[i][j] != -1){
        return t[i][j];
    }

    int mn = INT_MAX;
    for(k=i; k<=j-1; k++){  // yaha har ek position pe partition krna hai so k++, somewhere it may be k+2 when needed
        int tempans = solve(s, i, k) + solve(s, k+1, j) + 1; // Here C1 = no of partition in left, C2 is no of partition in right, C3 is "1" partiton b/w left and right 

        //ans = min(ans, temp); Verify this!
    if(temp<mn){
        mn = temp;
    }
    }
    return t[i][j] = mn;  // return as well as storing in table
}

int main(){
    memset(t, -1, sizeof(t));
}


// if(isPallindrome(str,i,k))
//         {
//             temp = 1+PP(str,i,k)+PP(str,k+1,j);
//             ans = min(ans,temp);
//         }

// If we do like this it won't give an error (tle) 



// Palindrome Partitioning Memoized Optimisation *********************************
// In above case subprblem i to j is solved or not beforehand is checked
// In optimisation it may be possible that subprblem left(i to k) or right(k+1 to j) may be solved beforehand

int static t[1001][1001];  // using static, no need to pass 't' inside functions (verify this)

int solve(string s, int i, int j){
    if(i>=j){
        return 0; // Either the string is empty or has 1 character only then no need of partition.(already palindrome)
    }
    if(isPalindrome(s, i, j) == True){
        return 0;
    }

    if(t[i][j] != -1){
        return t[i][j];
    }

    int mn = INT_MAX;
    for(k=i; k<=j-1; k++){  
        // Instead of this line write below lines:- int tempans = solve(s, i, k) + solve(s, k+1, j) + 1; 
        if(t[i][k] != -1){
            int left = t[i][k];  // we got the value from before solved 
        }
        else
            left = solve(s, i, k); // we didn;t get the value we call the solve fn to solve it and give to left and store in table as well
            t[i][j] = left;
        
        if(t[k+1][j]!=-1){
            int right = t[k+1][j];
        }
        else
            right = solve(s, k+1, j);
            t[k+1][j] = right;
        
        int tempans = 1 + left + right;
        
        //ans = min(ans, temp);
    if(temp<mn){
        mn = temp;
    }
    }
    return t[i][j] = mn;  // return as well as storing in table
}

int main(){
    memset(t, -1, sizeof(t));
}


// VERIFY THIS BELOW
// he is calling ispalindrome()  before checking t[i][j]!=-1 .
// if  we write ispalindrome() after  checking t[i][j]!=-1 then there is no need of optimisation.
// Basically you could move the isPalindrome check below the t[i][j] != -1 check. Then, it will be the same 


