#ifndef HASHTABLE_TPP
#define HASHTABLE_TPP

#include "HashTable.hpp"

template <typename K, typename V>
HashTable<K, V>::HashTable(unsigned int (*hashFunc)(const K& key), int tableSize)
    : hashFunction(hashFunc), size(tableSize) {
    table.resize(size);
}

template <typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value) {
    unsigned int hashValue = hashFunction(key) % size;
    table[hashValue].emplace_back(key, value);
}

template <typename K, typename V>
void HashTable<K, V>::remove(const K& key) {
    unsigned int hashValue = hashFunction(key) % size;
    auto& cell = table[hashValue];
    auto it = cell.begin();
    while (it != cell.end()) {
        if (it->first == key) {
            it = cell.erase(it);
            return;
        } else {
            ++it;
        }
    }
}

#endif // HASHTABLE_TPP
