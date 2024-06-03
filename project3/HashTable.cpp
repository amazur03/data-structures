#include "HashTable.hpp"

unsigned int hashFnv1a(const std::string &key) {
    const unsigned int fnvPrime = 0x01000193; // 16777619
    unsigned int hash = 0x811C9DC5; // 2166136261
    for (char c : key) {
        hash ^= static_cast<unsigned int>(c);
        hash *= fnvPrime;
    }
    return hash;
}
