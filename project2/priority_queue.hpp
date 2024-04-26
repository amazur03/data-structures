#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP
#include <iostream>

class PriorityQueue {
private:
    int* H; // Array to store the heap
    int _capacity; // Capacity of the heap
    int _size; // Current size of the heap

    int parent(int i); // Function to return the index of the parent node of a given node
    int leftChild(int i); // Function to return the index of the left child of the given node
    int rightChild(int i); // Function to return the index of the right child of the given node
    void heapifyUp(int i); // Function to shift up the node in order to maintain the heap property
    void heapifyDown(int i); // Function to shift down the node in order to maintain the heap property

public:
    PriorityQueue(int capacity); // Constructor
    ~PriorityQueue(); // Destructor

    void insert(int p); // Function to insert a new element in the priority queue
    int extractMax(); // Function to extract the element with maximum priority
    int findMax(); // Function to get value of the current maximum element
    void deleteElem(int i); // Function to remove the element located at given index
    void increaseKey(int i, int newPriority); // Function to increase priority of elem at index i to new priority newPriority
    void decreaseKey(int i, int newPriority); // Function to decrease priority of elem at index i to new priority newPriority

    void printQueue(); // Function to print queue
};

#endif /* PRIORITY_QUEUE_HPP */