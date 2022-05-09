https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

Can a graph be colored with M colors.
Bipartite had M = 2

// We try every color (Recursion is trying every possibility)

// TC = O(N^M)
// SC = O(2N)

bool isSafe(int node, int color[], bool graph[101][101], int n, int col){  // col is the current color I am trying to do that node
    for(int k=0; k<n; k++){                                                // traverse all its adjacent nodes from 0-n in the matrix
        if(k!=node && graph[k][node] == 1 && color[k]==col){               // it is not the current node and it is an adjacent node and the color that I am trying to fill is the same already
            return false;                                                  // which violates the condition hence return a false 
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int n, bool graph[101][101]){
    if(node == n){            // on coloring all the n nodes
        return true;
    }
    
    for(int i=1; i<=m; ++i){                                    // trying every color from 1 to n
        if(isSafe(node, color, graph, n, i)){                   // will tell if its possible to color with that color, ie no adjacent have same color
            color[node] = i;                                    // color with color i
            if(solve(node+1, color, m, n, graph)) return true;  // call the recursive function again
            color[node] = 0;                                    // if the above doesnt returns a true, I backtrack ie take off that color
        }
    }
    return false;    // I tried with all colors and it was not possible to color then I return false overall
}

//Function to determine if graph can be coloured with at most M colours such that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int n) { // m = colors, n = no of nodes
    // your code here
    int color[n] = {0};                                  // a color array with all values 0
    if(solve(0, color, m, n, graph)) return true;
    return false;
}
