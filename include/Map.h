#ifndef MAP_H
#define MAP_H

#include "BST.h"
#include <utility>
#include <stdexcept>
using namespace std;

template <typename Key, typename Value>
class Map{

    private:
    struct Pair{
        Key key;
        Value value;

        Pair(const Key& k, const Value& v) : key(k), value(v) {}

        //for bst ordering
        bool operator < (const Pair& other) const {
            return key < other.key;
        }

        bool operator > (const Pair& other) const {
            return key > other.key;
        }

        bool operator == (const Pair& other) const {
            return key == other.key;
        }
    };

    BST<Pair> bst;

    public:
    Map() = default;

    void insert(const Key& key, const Value& value){
        this->erase(key);
        bst.insert(Pair(key, value));
    }

    void erase(const Key& key){
        bst.remove(Pair(key, Value()));
    }

    bool contains(const Key& key) const {
        return bst.contains(Pair(key, Value()));
    }

    Value& at(const Key& key){
        const auto* node = bst.find(Pair(key, Value()));
        if(!node){
            throw out_of_range("key not found!");
        }
        return const_cast<Value&>(node->value);
    }

    const Value& at(const Key& key) const {
        const auto* node = bst.find(Pair(key, Value()));
        if(!node){
            throw out_of_range("key not found!");
        }
        return node->value;
    }

    void clear(){
        bst.clear();
    }

    size_t size() const {
        return bst.size();
    }

    bool empty() const {
        return bst.empty();
    }

    void print() const {
        bst.inorder();
    }

};

#endif//MAP_H