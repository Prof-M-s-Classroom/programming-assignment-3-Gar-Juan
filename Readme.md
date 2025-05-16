[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Your Name Here : Juan Garcia 

## Description
This program implements an undirected, weighted graph using an adjacency list. 
It creates a graph with a fixed number of vertices and adds weighted edges between vertex 
pairs which are provided in the main.cpp file. The structure of the code consists of a 
main function that is required to remain unchanged. Its purpose is 
to initialize the graph with 5 vertices and adding multiple weighted edges between the nodes.
The graph.cpp file models the graph using an adjacency matrix and manages the connections 
between vertices with weighted edges. The heap.cpp file contains a custom Min Heap structure 
that stores pairs of (vertex, key). It provides key functions such as: insert(vertex, key): 
Adds a new node into the Min Heap which is required for the Prim’s algorithm. extractMin(): 
Removes and returns the node with the smallest key. decreaseKey(vertex, newKey): 
Updates the key (cost) of a given vertex to a smaller value and reorders the heap maintaining the 
Min Heap property. isEmpty(): Checks whether the Min Heap is empty. These components work 
together to support the implementation of Prim’s algorithm for finding a Minimum Spanning Tree.


## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis

| Operation            | Time Complexity |
|----------------------|---------|
| Insert in MinHeap    | O(logV) |
| Extract Min          | O(logV) |
| Decrease Key         | O(logV) |
| Prim’s MST Overall   | O(ElogV)|

_Explain why your MST implementation has the above runtime._
Prim’s algorithm goes through each vertex once and checks all its connected edges,
which can be up to E total. By using a Min Heap, it can insert, extract,
and decrease key in O(log V) time. This makes the overall runtime O(E log V), 
which works well for sparse graphs.

## Test Case Description

Input:  
// main.cpp
Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);

    g.primMST();

OutPut:
Edge |  Weight
0 - 1   2
1 - 2   3
0 - 3   6
1 - 4   5
The total weight of MST: 16





