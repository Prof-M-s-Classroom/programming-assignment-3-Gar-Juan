//
// Created by Juan Garcia on 5/6/2025.
//
#include<iostream>
#include <climits>
#include <vector>
#include "graph.h"
#include "heap.h"

using namespace std;

// Constructor - This creates empty adj matrix
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjMatrix = new int*[numVertices];

    // Creates the adjacency matrix
    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j) {
            adjMatrix[i][j] = 0; // Initialize all weights to 0
        }
    }
}

// Deconstructor - cleans up memory
Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] adjMatrix[i]; // Free up each row
    }
    delete[] adjMatrix; // Free up the pointer
}

// Add undirected edge with weight
void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

// build and print MST using Prim's
void Graph::primMST() {
    int* parent = new int[numVertices]; // MST parent
    int* key = new int[numVertices]; // key for picking min weight edge

    MinHeap minHeap(numVertices); // Call MinHeap

    // initialize keys and heap
    for (int v = 0; v < numVertices; ++v) {
        key[v] = INT_MAX;
        parent[v] = -1;
        minHeap.insert(v, key[v]);
    }
    key[0] = 0; // Start from vertex 0 as mentioned in class
    minHeap.decreaseKey(0, 0); // update heap with a new key value

    // Loop to include all vertices in MST
    while (!minHeap.isEmpty()) {
        int u = minHeap.extractMin(); // minimum key vertex
        // This will update adjacent vertices
        for (int v = 0; v < numVertices; ++v) {
            if (adjMatrix[u][v] && minHeap.isInMinHeap(v) && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
                minHeap.decreaseKey(v, key[v]);
            }
        }
    }

    // Print the MST edges and total weight
    int totalWeight = 0;
    cout << "Edge | \tWeight\n";
    for (int i = 1; i < numVertices; ++i) {
        cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << endl;
        totalWeight += adjMatrix[i][parent[i]];
    }

    cout << "The total weight of MST: " << totalWeight << endl;

    delete[] parent;
    delete[] key;
}
