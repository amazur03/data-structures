#include "dynamic_array.hpp"
#include <iostream>

// Default constructor
DynamicArray::DynamicArray() {
    _capacity = 4;                      // Initial capacity set to 4
    _size = 0;                          // Initially, the array is empty
    array = new int[_capacity];         // Allocate memory for the array
}

// Constructor with initial capacity
DynamicArray::DynamicArray(int capacity, int size) {
    _capacity = capacity;               // Set capacity to the provided value
    _size = size;                          // Initially, the array is empty
    array = new int[_capacity];         // Allocate memory for the array
    for(int i = 0; i <= size; i++){
        array[i] = i;
    }
}

// Destructor to release dynamically allocated memory
DynamicArray::~DynamicArray() {
    delete[] array;                     // Release the memory allocated for the array
}

// Function to get the current size of the array
int DynamicArray::getSize() const {
    return _size;
}

// Function to get the current capacity of the array
int DynamicArray::getCapacity() const {
    return _capacity;
}

// Function to check if the array is empty
bool DynamicArray::isEmpty() const {
    return _size == 0;
}

// Function to get the element at a specific index
int DynamicArray::searchAtIndex(int index) const {
    if (index < 0 || index >= _size) {
        std::cerr << "Index out of bounds\n";   // Error message for out of bounds index
        return -1;
    }
    return array[index];                        // Return the element at the given index
}

// Function to search for an element and return its index
int DynamicArray::searchForElem(int elem) const {
    for (int i = 0; i < _size; i++) {
        if (array[i] == elem) {
            return i;                           // Return the index if element found
        }
    }
    return -1;                                  // Return -1 if element not found
}

// Function to print the elements of the array
void DynamicArray::printArray() const {
    std::cout << "Elements of the array: ";
    for (int i = 0; i < _size; i++) {
        std::cout << array[i];                  // Print each element
        if (i < _size - 1) {
            std::cout << " ";                   // Add space between elements
        }
    }
    std::cout << std::endl;                     // Newline after printing
}

// Function to insert an element at a specific index
void DynamicArray::insert(int elem, int index) {
    if (index < 0 || index > _size) {
        std::cerr << "Invalid index for insertion\n";  // Error message for invalid index
        return;
    }
    if (_size == _capacity) {
        growArray();                        // If array is full, increase capacity
    }
    for (int i = _size; i > index; --i) {
        array[i] = array[i - 1];           // Shift elements to make space for new element
    }
    array[index] = elem;                   // Insert the new element
    ++_size;                               // Increase size
}

// Function to remove an element at a specific index
void DynamicArray::removeAtIndex(int index) {
    if (index < 0 || index >= _size) {
        std::cerr << "Invalid index for removal\n";    // Error message for invalid index
        return;
    }
    for (int i = index; i < _size - 1; ++i) {
        array[i] = array[i + 1];           // Shift elements to remove the element at index
    }
    --_size;                               // Decrease size
}

// Private function to increase the capacity of the array
void DynamicArray::growArray() {
    _capacity *= 2;                        // Double the capacity
    int* temp = new int[_capacity];        // Allocate memory for a new array with increased capacity
    for (int i = 0; i < _size; i++) {
        temp[i] = array[i];                // Copy elements from the old array to the new one
    }
    delete[] array;                        // Delete the old array
    array = temp;                          // Point array to the new array with increased capacity
}
