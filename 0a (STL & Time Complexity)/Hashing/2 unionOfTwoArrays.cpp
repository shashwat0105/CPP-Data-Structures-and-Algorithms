// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1#

int doUnion(int a[], int n, int b[], int m)  {
        //code here
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        s.insert(a[i]);
    }
    for(int i=0; i<m; i++){
        s.insert(b[i]);
    }
    return s.size();
}


// Good ques 
// https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1#

// int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
//     // Your code goes here
//     unordered_set<int> s;
//     for(int i=0; i<n; i++){
//         s.insert(a[i]);
//     }
//     for(int i=0; i<m; i++){
//         s.insert(b[i]);
//     }
//     return n+m-s.size();
// }

// The above code fails for duplicacy within the arrays
// Test case:
// a[] = 4 4
// b[] = 1 4 2 3 5 4
// Ans: 1

int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
    unordered_set<int> s;
    
    for(int i=0; i<n; i++){
        s.insert(a[i]);
    }
    int count = 0;
    for(int i=0; i<m; i++){
        if(s.find(b[i])!=s.end()){
            count++;
            s.erase(b[i]);            // CRUX OF THE CODE
        }
    }
    return count;
}


