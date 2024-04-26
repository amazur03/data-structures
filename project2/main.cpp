#include <iostream>
#include "priority_queue.hpp"

int main() {
    PriorityQueue priorityQueue(50);
    
    priorityQueue.insert(55); 
    priorityQueue.insert(12); 
    priorityQueue.insert(14); 
    priorityQueue.insert(17); 
    priorityQueue.insert(1); 
    priorityQueue.insert(70); 
    priorityQueue.insert(91); 
    priorityQueue.insert(15); 
    priorityQueue.insert(3); 

    std::cout << "Heap created" << std::endl;
    priorityQueue.printQueue();

    std::cout << "Node with maximum priority: " << priorityQueue.extractMax() << "\n";
    std::cout << "After extraction" << std::endl;
    priorityQueue.printQueue();

    std::cout << "Before increasing" << std::endl;
    priorityQueue.printQueue();
    priorityQueue.increaseKey(2, 100);
    std::cout << "After increasing" << std::endl;
    priorityQueue.printQueue();

    std::cout << "Before deletion" << std::endl;
    priorityQueue.printQueue();
    priorityQueue.deleteElem(3);
    std::cout << "After deletion" << std::endl;
    priorityQueue.printQueue();


    return 0;
}