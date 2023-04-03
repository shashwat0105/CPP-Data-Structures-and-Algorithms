https://ianparberry.com/TowersOfHanoi/index64.html
https://en.wikipedia.org/wiki/Tower_of_Hanoi

https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1/

https://youtu.be/l45md3RYX7c

With 3 disks, the puzzle can be solved in 7 moves
The minimal number of moves required to solve a Tower of Hanoi puzzle is 2^n − 1, where n is the number of disks. 

Hypothesis // jo bolenge kar k dega

From source to destination using helper rod.
Rules:
1. move 1 disk at a time
2. never place a smaller disk under a larger disk
3. u can only move a disk at the top.

Assume the notation:
A=source
B=helper
C=desitination

What we want: A to C using B
What we did: Steps Involved:
Move n-1 disks: A to B using C as Helper(Recursive call)
Move nth disk : A to C (Print statement)
Move n-1 disks: B to C using A as Helper(Recursive call)  // Finally yaha saari disks A se C pahuch gyi.

//
s = source
d = destination
h = helper
solve(n, s->d, h)    // n is the number of disk.

smaller problem:
solve(n-1, s->h, d)  // will move n-1 plates from source to helper and the destination will act as new helper.

// Induction:
Jo remaining 1 plate hai use destination mein rakh denge

// Base condition: when only 1 plate is there 

Normal TOH code
void solve(int N, int s, int d, int h) {
    if(N==1){
        cout<<"move disk "<<N<<" from rod "<<s<<" to rod "<<d<<endl;
        return;
    }
    solve(N-1, s, h, d);                                          // moving n-1 disks from source to helper
    cout<<"move disk "<<N<<" from rod "<<s<<" to rod "<<d<<endl;  // moving 1 left disk from source to destination
    solve(N-1, h, d, s);                                          // n-1 disks were on helper, moving them to destination with the help of source(as helper)
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
        solve(N-1, h, d, s, c);  // n-1 disks were on helper, moving them to destination with the help of source(as helper)
    }
    long long toh(int N, int from, int to, int aux) {
        int c=0;
        solve(N, from, to, aux, c);
        return c;
    }
};


