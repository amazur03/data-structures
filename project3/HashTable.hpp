#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <vector>
#include <list>
#include <string>

unsigned int hashFnv1a(const std::string &key);

template<typename K, typename V>
class HashTable {
private:
    std::vector<std::list<std::pair<K, V>>> table;
    unsigned int (*hashFunction)(const K& key);
    int size;

public:
    HashTable(unsigned int (*hashFunc)(const K& key), int tableSize);
    void insert(const K& key, const V& value);
    void remove(const K& key);
};

// Include the template implementation file
#include "HashTable.tpp"

#endif // HASHTABLE_HPP
