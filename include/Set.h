#ifndef SET_H
#define SET_H

#include "BST.h"
using namespace std;

template <typename T>
class Set{

    private:
    BST<T> tree;

    public:
    Set() = default;

    //copy constructor
    Set(const Set& other) = default;

    //copy assignment
    Set& operator = (const Set& other) = default;

    //move constructor
    Set(Set&& other) noexcept = default;

    //move assignment
    Set& operator = (Set&& other) noexcept = default;

    ~Set() = default;

    //inserting when not present before, handeled by bst
    void insert(const T& val){
        tree.insert(val);
    }

    void remove(const T& val){
        tree.remove(val);
    }

    bool contains(const T& val){
        return tree.contains(val);
    }

    bool empty() const {
        return tree.empty();
    }

    size_t size() const {
        return tree.size();
    }

    void clear(){
        tree.clear();
    }

    void print() const {
        tree.inorder();
    }

};

#endif//SET_H