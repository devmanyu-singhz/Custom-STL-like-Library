#ifndef STACK_H
#define STACK_H

#include "Vector.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class Stack{

    private:
    Vector<T> container;

    public:
    //constructors
    Stack() = default;
    Stack(const Stack& other) = default;
    Stack& operator = (const Stack& other) = default;

    //destructor
    ~Stack() = default;

    //core operations
    void Push(const T& val){
        container.pushBack(val);
    }

    void Pop(){
        if(Empty()){
            throw out_of_range("Stack::pop: empty stack!");
        }
        container.popBack();
    }

    T& top(){
        if(Empty()){
            throw out_of_range("Stack::pop: empty stack!");
        }
        return container[container.size() - 1];
    }

    const T& top() const {
        if(Empty()){
            throw out_of_range("Stack::pop: empty stack!");
        }
        return container[container.size() - 1];
    }

    bool Empty(){
        return  container.isEmpty();
    }

    size_t size() const {
        return container.size();
    }

    void clear(){
        container.clear();
    }

};


#endif //STACK_H