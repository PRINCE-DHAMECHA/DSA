//~ Graphs:-

//! Non-Linear DS

//* A graph consist of finite set of vertices and a set of edges connecting them.

//~ Connected Graph:
//* Atleast one path is there between any two node

//~ Directed Graph:
//* Direction in edge
//& a->b // You cannot go from b to a.

//~ Weighted Graph:
//* Weight assigned to each edges

//~ Cyclic Graph:
//* If graph contains atleast one cycle

//~ DAG (Directed Acyclic graph)
//* Not a cyclic graph

//~ Dense Graph:
//* # Edges is close to maximum possible

//~ Sparse Graph:
//* # Edges is close to minimum possible

//~ Simple Graph:
//* Without loops and without multiple edges

//~ Connected Graph
//* Exist an edge between every pair of vertices

//~ Strongly Connected Graph
//* If there is path in both direction for every pair of node

//~ Adjacent Vertices
//* If there is an edge between the two vertices

//~ Adjacent Edges
//* If there is a common vertex between the two edges

//~ Degree
//* Number of vertices adjacent to the vertex v (for undirected)

//* for directed there's indegree and outdegree

//? Sum indegree+outdegree === EVEN

//~ Path
//* Sequence of distinct vertices such that two consecutive vertices are adjacent

//~ Cycle
//* Closed path is called a cycle
//* Path with only repeating vertices is first and last

//~ Walk
//* Sequence of vertices and edges of graph (No restrictions other than adjacent vertices)