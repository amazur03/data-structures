#include "dynamic_array.hpp"
#include <iostream>

int main() {
    DynamicArray arr(2);
    arr.insert(1, 0);
    arr.insert(2, 1);
    arr.insert(3, 2);
    arr.insert(4, 3);
    arr.insert(5, 4);
    arr.printArray(); // Output: Elements of the array: 1 2 3 4 5

    arr.removeAtIndex(2);
    arr.printArray(); // Output: Elements of the array: 1 2 4 5

    return 0;
}
