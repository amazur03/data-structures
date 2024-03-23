#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

class DynamicArray {
private:
    int _capacity;          // Capacity of the dynamic array
    int _size;              // Current size of the dynamic array
    int* array;             // Pointer to the dynamic array
    void growArray();       // Private function to increase the capacity of the array

public:
    DynamicArray();                             // Default constructor
    DynamicArray(int capacity);                 // Constructor with initial capacity
    ~DynamicArray();                            // Destructor to release dynamically allocated memory

    int getSize() const;                        // Function to get the current size of the array
    int getCapacity() const;                    // Function to get the current capacity of the array
    bool isEmpty() const;                       // Function to check if the array is empty
    int searchAtIndex(int index) const;         // Function to get the element at a specific index
    int searchForElem(int elem) const;          // Function to search for an element and return its index
    void printArray() const;                    // Function to print the elements of the array
    void insert(int elem, int index);           // Function to insert an element at a specific index
    void removeAtIndex(int index);              // Function to remove an element at a specific index
};

#endif // DYNAMIC_ARRAY_HPP
