#include <iostream>
#include "priority_queue.hpp"
#include <vector>
#include <chrono>

int main() {
    std::vector<int> sizes = {1000, 10000, 100000}; // Specify the sizes of the priority queues

    for (int size : sizes) {
        PriorityQueue pq(size);

        std::cout << "-----------------" << size << "-----------------" << std::endl;

        // Measure time for inserting elements
        auto start = std::chrono::steady_clock::now();
        for (int i = 0; i < size; ++i) {
            pq.insert(i, i); // Wstawiamy i jako zarówno dane jak i priorytet
        }
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::nano> insertTime = end - start;
        std::cout << "Dodanie " << size << " elementow zajelo " << insertTime.count() << " nanosekund" << std::endl;

        // Measure time for extracting maximum element
        start = std::chrono::steady_clock::now();
        pq.extractMax();
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::nano> extractMaxTime = end - start;
        std::cout << "Usuniecie elementu o najwyzszym priorytecie zajelo " << extractMaxTime.count() << " nanosekund" << std::endl;

        // Measure time for getting size of the priority queue
        start = std::chrono::steady_clock::now();
        pq.getSize();
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::nano> getSizeTime = end - start;
        std::cout << "Zwrot rozmiaru zajal: " << getSizeTime.count() << " nanosekund" << std::endl;

        // Measure time for modifying priority of an element
        start = std::chrono::steady_clock::now();
        pq.increaseKey(1, 9999999);
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::nano> modifyPriorityTime = end - start;
        std::cout << "Modyfikacja priorytetu zajela: " << modifyPriorityTime.count() << " nanosekund" << std::endl;

        // Measure time for finding maximum element
        start = std::chrono::steady_clock::now();
        pq.findMax();
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::nano> findMaxTime = end - start;
        std::cout << "Podejrzenie elementu o najwyzszym priorytecie zajelo: " << findMaxTime.count() << " nanosekund" << std::endl;

        std::cout << std::endl;

    }

    return 0;
}
