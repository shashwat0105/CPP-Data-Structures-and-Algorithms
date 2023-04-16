// All pairs shortest path algo.

// Very different from Dijakstra or bellmanford

// In dijkstra: There is a single source from where we find shortest path to all other nodes.
// What if we want shortest distance of 7 from 2 as well as 3 ie there are multiple sources.
// Ie "finding shortest distance from every node to every other node is asked."
// Hence it is a multisource shortest path algo, also can detect negative cycles.

// I will say ki via 0 I want to reach, then via 1 then via 2 and so on.

https://youtu.be/5MEZXOyaRmk (LUV)

https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html#practice-problems
https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
https://www.geeksforgeeks.org/detecting-negative-cycle-using-floyd-warshall/?ref=rp

Dynamic programming ie storing of values is used.

// We allow 1, 2, 3, ... k nodes or levels at a time in finding the distance.

Question:
https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?
Said to do it in place.

How to check negative cycle. 
Distance of a node from that node only is 0. But if it becomes < 0 means there is a negative cycle.

CODE:
void shortest_distance(vector<vector<int>>&matrix){
	int n = matrix.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == -1) {
				matrix[i][j] = 1e9;
			}
			if (i == j) matrix[i][j] = 0;
		}
	}

	for (int k = 0; k < n; k++) {     // k is the via node through which we will go
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = min(matrix[i][j],
								   matrix[i][k] + matrix[k][j]);
			}
		}
	}

	// // if to detect the negative cycle was also asked
	// for(int i=0; i<n; ++i){
	//     if(matrix[i][i]<0) cout<<"Negative cycle"
	// }

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 1e9) {
				matrix[i][j] = -1;
			}
		}
	}
}

// Sample Input
6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2

// Sample Output
0 1 3 3 2 4 
I 0 2 2 1 3 
I I 0 I 2 4 
I I I 0 3 1 
I I I I 0 2 
I I I I I 0 

TC = O(N^3)
If there was given graph doesnt have -ve cycle, you can apply dijasktra on every node. TC = V * ElogV, less than floyd warshal
Tell extra stuff to interviewer why dijasktra wont work. How can u detect -ve cycle.
// Refer https://codeforces.com/problemset/problem/295/B (Greg and Graph) from practice section
