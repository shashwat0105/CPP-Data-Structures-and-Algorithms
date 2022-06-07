https://ianparberry.com/TowersOfHanoi/index64.html

https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1/

https://youtu.be/l45md3RYX7c

Hypothesis // jo bolenge kar k dega

s = source
d = destination
h = helper

solve(n, s->d, h)  

smaller problem:
solve(n-1, s->h, d)  // will move n-1 plates from source to helper and the destination will act as new helper.

// Induction:
Jo remaining 1 plate hai use destination mein rakh denge

// Base condition
only 1 plate is there 

Normal TOH code
void solve(int N, int s, int d, int h, int &c) {
    if(N==1){
        cout<<"move disk "<<N<<" from rod "<<s<<" to rod "<<d<<endl;
        return;
    }
    solve(N-1, s, h, d);                                          // moving n-1 disks from source to helper
    cout<<"move disk "<<N<<" from rod "<<s<<" to rod "<<d<<endl;  // moving 1 left disk from source to destination
    solve(N-1, h, d, s);                                          // n-1 disks were on helper, moving them to destination with the help of source
}



// For GFG need to print 2^N -1 as well ie number of steps
class Solution{
    public:
    // avoid space at the starting of the string in "move disk....."
    void solve(int N, int s, int d, int h, int &c) {
        c++;
        //Your code here
        if(N==1){
            cout<<"move disk "<<N<<" from rod "<<s<<" to rod "<<d<<endl;
            return;
        }
        solve(N-1, s, h, d, c);  // moving n-1 disks from source to helper
        cout<<"move disk "<<N<<" from rod "<<s<<" to rod "<<d<<endl;  // moving 1 left disk from source to destination
        solve(N-1, h, d, s, c);  // n-1 disks were on helper, moving them to destination with the help of source
    }
    long long toh(int N, int from, int to, int aux) {
        int c=0;
        solve(N, from, to, aux, c);
        return c;
    }
};


