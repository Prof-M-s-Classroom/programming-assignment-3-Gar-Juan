//
// Created by Juan Garcia on 5/6/2025.
//
#include <iostream>
#include <climits>
#include "heap.h"

using namespace std;

// Constructor - allocated arrays
MinHeap::MinHeap(int cap) {
    //Private
    capacity = cap; // Capacity of element in heap
    size = 0;   // instantiate number of elements in heap
    heapArray = new int[capacity]; // Heap of vertex indices
    keyArray = new int[capacity]; // Stores Keys
    position = new int[capacity];  // Maps vertex to its position in heap

    // init keys and positions
    for (int i = 0; i < capacity; ++i) {
        keyArray[i] = INT_MAX;
        position[i] = -1;
    }
}

// Deconstructor - clean memory
MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

// Check if heap is empty
bool MinHeap::isEmpty() {
    return size == 0;
}

// Insert new vertex with key
void MinHeap::insert(int vertex, int key) {
    if (size == capacity) return; // Do nothing if heap is full

    // Add a new vertex at the end of the heap
    heapArray[size] = vertex;
    keyArray[vertex] = key;
    position[vertex] = size;
    size++;

    int i = size - 1;

    // up-heap to maintain min-heap
    while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        int parent = (i - 1) / 2;

        // Swap
        int temp = heapArray[i];
        heapArray[i] = heapArray[parent];
        heapArray[parent] = temp;

        // Update positions
        position[heapArray[i]] = i;
        position[heapArray[parent]] = parent;

        //Move up to parent index
        i = parent;
    }
}

// restore min-heap from index
void MinHeap::minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Find the smallest child
    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]])
        smallest = left;
    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]])
        smallest = right;

    // Swap and recurse if needed
    if (smallest != i) {
        int temp = heapArray[i];
        heapArray[i] = heapArray[smallest];
        heapArray[smallest] = temp;

        position[heapArray[i]] = i;
        position[heapArray[smallest]] = smallest;

        minHeapify(smallest);
    }
}

// Remove and return vertex with min key
int MinHeap::extractMin() {
    if (isEmpty()) return -1;

    int root = heapArray[0];
    int lastNode = heapArray[size - 1];

    heapArray[0] = lastNode;
    position[lastNode] = 0;
    position[root] = -1;

    size--;
    minHeapify(0);

    return root;
}

// Update key amd fix heap
void MinHeap::decreaseKey(int vertex, int newKey) {
    int i = position[vertex];
    keyArray[vertex] = newKey;

    // Bubble up if smaller
    while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        int parent = (i - 1) / 2;

        int temp = heapArray[i];
        heapArray[i] = heapArray[parent];
        heapArray[parent] = temp;

        position[heapArray[i]] = i;
        position[heapArray[parent]] = parent;

        i = parent;
    }
}

// Check if vertex is still in heap
bool MinHeap::isInMinHeap(int vertex) {
    return position[vertex] != -1;
}
