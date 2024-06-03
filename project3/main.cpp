#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include "HashTable.hpp"

using namespace std;
using namespace std::chrono;

int main() {
    int tab[] = {1000, 10000, 100000};
    int repetitions = 100;
    string keyBase = "data structures";

    for (int data : tab) {
        vector<long long> insertTimesFnv1a(repetitions);
        vector<long long> removeTimesFnv1a(repetitions);

        cout << "-----------------------" << data << "-----------------------" << endl;

        // Testing Fnv-1a
        for (int r = 0; r < repetitions; ++r) {
            HashTable<string, int> hashTableFnv1a(hashFnv1a, data);

            // Adding elements
            auto start = high_resolution_clock::now();
            for (int i = 0; i < data; i++) {
                hashTableFnv1a.insert(keyBase + to_string(i), i);
            }
            auto stop = high_resolution_clock::now();
            insertTimesFnv1a[r] = duration_cast<nanoseconds>(stop - start).count();

            // Removing element
            start = high_resolution_clock::now();
            hashTableFnv1a.remove(keyBase + "0");
            stop = high_resolution_clock::now();
            removeTimesFnv1a[r] = duration_cast<nanoseconds>(stop - start).count();
        }

        // Calculating average times
        long long avgInsertTimeFnv1a = accumulate(insertTimesFnv1a.begin(), insertTimesFnv1a.end(), 0LL) / repetitions;
        long long avgRemoveTimeFnv1a = accumulate(removeTimesFnv1a.begin(), removeTimesFnv1a.end(), 0LL) / repetitions;

        // Displaying results
        cout << "Fnv-1a: Average time to add " << data << " elements: " << avgInsertTimeFnv1a << " nanoseconds." << endl;
        cout << "Fnv-1a: Average time to remove an element: " << avgRemoveTimeFnv1a << " nanoseconds." << endl;
    }

    return 0;
}
