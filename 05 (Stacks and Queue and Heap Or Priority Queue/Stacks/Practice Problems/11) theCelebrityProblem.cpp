https://www.geeksforgeeks.org/the-celebrity-problem/
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

https://leetcode.com/problems/find-the-celebrity/ (Locked with premium)

M[i][j] = 1 means i knows j, j doesnot knows i
Points to note: There can be only "one" celebrity or no celebrity.

Agar 2 celebrity hai toh 2nd column m sab 1 honge(sab 2 ko jante) ar 2nd row mein sab 0(2 kisi ko ni janta) honge


O(n^2)->sol    

int celebrity(vector<vector<int> >& M, int n) {
    vector<int> v;
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c+=M[i][j];
        }
        if(c==0){
            v.push_back(i);
        }
        c=0;
    }
    if(v.size()==1)
        return v[0];
    return -1;
}

// Stack approach
// https://youtu.be/CiiXBvrX-5A (pepcoding)
// Saare candidates ko stack m daal do
// 0 1 2 3 
// ab upar k do element nikalo ar dekho ki kon kisko janta hai using either M[i][j] or M[j][i]
// Maan lo aya ki 2 janta hai 3 ko toh 2 toh celebrity(yeh kisi ko ni janta hence) nai ho skta, 2 ko stack m nahi dalenge, 3 ko stack m dobara daal denge
// ie do element nikale koi ek hi stack m wapas jaega
// fr top two nikalo ar yeh karo until stack ka size 1 na ho jae.
// Now hamne jo ek element nikalo wo guarantee celeb ni hai but jo bacha wo ek potential celeb hai jaroori nahi ki ho hi,
// Hence we have to check entire row and coloumn again for the that potential celebrity then only we can confirm say that.

int celebrity(vector<vector<int> >& M, int n) {
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){
        int a=s.top();s.pop();
        int b=s.top();s.pop();
        if(M[b][a]==1){
            s.push(a);
        }
        else{
            s.push(b);
        }
    }
    
    int potCeleb = s.top();
    //cout<<potCeleb;
    for(int i=0; i<n; ++i){
        if(i!=potCeleb){
            if(M[i][potCeleb] ==0 || M[potCeleb][i]==1){  // isko koi na jaane ya yeh kisi ko jaan jae
                return -1;
            }
        }
    }
    return potCeleb;
}

//
C++ Without stack(extra space)
TC: O(n)

int celebrity(vector<vector<int> >& M, int n)  {
    // code here 
    int celeb=0;
    for(int i=1;i<n;i++){
        if(M[celeb][i]==1){
            celeb=i;
        }
    }
    int ct=0;
    for(int j=0;j<n;j++){
        if(M[j][celeb]==1){
            ct++;
        }
        if(M[celeb][j]==1){
            ct++;
        }
    }
    if(ct==n-1){
        return celeb;
    }
    return -1;
}

// For later refer GFG Article
Create two indices i and j, where i = 0 and j = n-1
Run a loop until i is less than j.
Check if i knows j, then i can’t be a celebrity. so increment i, i.e. i++
Else j cannot be a celebrity, so decrement j, i.e. j–
Assign i as the celebrity candidate
Now at last check whether the candidate is actually a celebrity by re-running a loop from 0 to n-1  and constantly checking if the candidate knows a person or if there is a candidate who does not know the candidate.
Then we should return -1. else at the end of the loop, we can be sure that the candidate is actually a celebrity.
//Two pointer approach

int celebrity(vector<vector<int> >& m, int n) {
    int i=0,j = n-1;
    int ans =-1;
    
    while(i<j)
    m[i][j]?i++:j--;
    for(int j=0;j<n;j++){
        if(j!=i){
            if(m[i][j]||!m[j][i])
            return -1;
        }
    }
    return i;
}
