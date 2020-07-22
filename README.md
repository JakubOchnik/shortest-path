# Shortest path finder (Bellman-Ford algorithm implementation)
A C program which returns a total weight of a shortest path between two vertices of a directed graph.
## Synopsis
Bellman-Ford algorithm is one of two main shortest path algorithms. The more popular one is Dijkstra's. It's faster, but it doesn't work with negative path weights. The objective was to consider negative weights and check if the graph contains a negative cycle or disconnection between vertices.
## How does it work?
After graph and problem description, the Bellman-Ford algorithm starts. The program analyzes every edge and in *V-1* loop iterations it eventually finds a minimum total weight of every path starting at vertice A. Result (smallest total weight of a path from vertice A to B) is a value in result (d[b]) array at index B.
## Example input and output
### Input:
<img src="http://www.ochnik.me/static/example-graph.png" align="center" height="50%" width="50%">
<br/>*A graph used in example input*<br/><br/>
```
4 5
0 1 1
1 3 1
3 2 1
0 2 2
3 0 -3
2
0 3
0 2
```
### Output:
```
2
-inf
```