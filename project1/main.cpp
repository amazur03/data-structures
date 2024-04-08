#include "dynamic_array.hpp"
#include <iostream>
#include <chrono>

int main() {
    DynamicArray arr(2000, 1000);
    // Start the timer
    auto start = std::chrono::steady_clock::now();
    
    // Perform some operation here
    //arr.insert(0, 0);
    //arr.removeAtIndex(0);
    //arr.searchForElem(0);



    // End the timer
    auto end = std::chrono::steady_clock::now();
    
    // Calculate the duration in nanoseconds
    std::chrono::nanoseconds operationTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    
    // Output the duration in nanoseconds
    std::cout << "Operation time: " << operationTime.count() << " nanoseconds" << std::endl;
    return 0;
}
