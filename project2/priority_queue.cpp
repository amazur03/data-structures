#include "priority_queue.hpp"
#include <utility>
#include <iostream>

PriorityQueue::PriorityQueue(int capacity) {
    _capacity = capacity;
    H = new std::pair<int, int>[capacity];
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
    while (i > 0 && H[parent(i)].first < H[i].first) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void PriorityQueue::heapifyDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l < _size && H[l].first > H[maxIndex].first) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r < _size && H[r].first > H[maxIndex].first) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        heapifyDown(maxIndex);
    }
}

void PriorityQueue::insert(int priority, int data) {
    _size = _size + 1;
    H[_size - 1] = std::make_pair(priority, data); // Poprawka: Indeksowanie od zera
    heapifyUp(_size - 1); // Poprawka: Indeksowanie od zera
}

std::pair<int, int> PriorityQueue::extractMax() {
    std::pair<int, int> result = H[0];
    H[0] = H[_size - 1]; // Poprawka: Indeksowanie od zera
    _size = _size - 1;
    heapifyDown(0);
    return result;
}

int PriorityQueue::findMax() {
    return H[0].second;
}

void PriorityQueue::increaseKey(int data, int newPriority) {
    for (int i = 0; i < _size; ++i) {
        if (H[i].second == data) {
            if (newPriority < H[i].first) {
                return;
            }
            H[i].first = newPriority;
            heapifyUp(i);
            return;
        }
    }
}

void PriorityQueue::decreaseKey(int data, int newPriority) {
    for (int i = 0; i < _size; ++i) {
        if (H[i].second == data) {
            if (newPriority > H[i].first) {
                return;
            }
            H[i].first = newPriority;
            heapifyDown(i);
            return;
        }
    }
}


int PriorityQueue::getSize(){
    return _size;
}

void PriorityQueue::printQueue() {
    std::cout << "Priority Queue Elements: ";
    for (int i = 0; i < _size; ++i) {
        std::cout << "(" << H[i].first << ", " << H[i].second << ") ";
    }
    std::cout << std::endl;
}
