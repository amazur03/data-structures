#include "priority_queue.hpp"
#include <utility>
#include <iostream>

PriorityQueue::PriorityQueue(int capacity) {
    _capacity = capacity;
    H = new int[capacity];
    _size = 0;
}

PriorityQueue::~PriorityQueue() {
    delete[] H;
}

int PriorityQueue::parent(int i) {
    return (i - 1) / 2;
}

int PriorityQueue::leftChild(int i) {
    return (2 * i) + 1;
}

int PriorityQueue::rightChild(int i) {
    return (2 * i) + 2;
}

void PriorityQueue::heapifyUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void PriorityQueue::heapifyDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l < _size && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r < _size && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        heapifyDown(maxIndex);
    }
}

void PriorityQueue::insert(int p) {
    _size = _size + 1;
    H[_size - 1] = p; // Poprawka: Indeksowanie od zera
    heapifyUp(_size - 1); // Poprawka: Indeksowanie od zera
}

int PriorityQueue::extractMax() {
    int result = H[0];
    H[0] = H[_size - 1]; // Poprawka: Indeksowanie od zera
    _size = _size - 1;
    heapifyDown(0);
    return result;
}

int PriorityQueue::findMax() {
    return H[0];
}

void PriorityQueue::deleteElem(int i) {
    H[i] = findMax() + 1;
    heapifyUp(i);
    extractMax();
}

void PriorityQueue::increaseKey(int i, int newPriority) {
    if (newPriority < H[i]) {
        return;
    }
    H[i] = newPriority;
    heapifyUp(i);
}

void PriorityQueue::decreaseKey(int i, int newPriority) {
    if (newPriority > H[i]) {
        return;
    }
    H[i] = newPriority;
    heapifyDown(i);
}

void PriorityQueue::printQueue() {
    std::cout << "Priority Queue Elements: ";
    for (int i = 0; i < _size; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << std::endl;
}