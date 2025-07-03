#ifndef HASH_SET_H
#define HASH_SET_H

#include "HashMap.h"
#include <iostream>
using namespace std;

template <typename Key, typename Hash = hash<Key>>
class HashSet{

    private:
    static constexpr char DUMMY_VALUE = 0;
    HashMap<Key, char, Hash>map;
    
    public:
    HashSet() {}

    void insert(const Key& key){
        map.insert(key, DUMMY_VALUE);
    }

    void erase(const Key& key){
        map.erase(key);
    }

    bool contains(const Key& key) const {
        return map.contains(key);
    }

    size_t size() const {
        return map.size();
    }

    bool empty() const {
        return map.empty();
    }

    void clear() {
        map.clear();
    }

};

template <typename Key, typename Hash>
constexpr char HashSet<Key, Hash>::DUMMY_VALUE;

#endif//HASH_SET_H
