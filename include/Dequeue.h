#ifndef DEQUEUE_H
#define DEQUEUE_H

#include "DoublyLinkedlist.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Dequeue{

    private:
    DoublyLinkedList<T> list;

    public:
    Dequeue() = default;
    ~Dequeue() = default;

    void pushFront(const T& val){
        list.pushFront(val);
    }

    void pushBack(const T& val){
        list.pushBack(val);
    }

    void popFront(){
        if(empty()){
            throw out_of_range("Dequeue is empty!");
        }
        list.popFront();
    }

    void popBack(){
        if(empty()){
            throw out_of_range("Dequeue is empty!");
        }
        list.popBack();
    }

    T& front(){
        if(empty()){
            throw out_of_range("Dequeue is empty!");
        }
        return list.front();
    }

    const T& front() const {
        if(empty()){
            throw out_of_range("Dequeue is empty!");
        }
        return list.front();
    }

    T& back(){
        if(empty()){
            throw out_of_range("Dequeue is empty!");
        }
        return list.back();
    }

    const T& back() const {
        if(empty()){
            throw out_of_range("Dequeue is empty!");
        }
        return list.back();
    }

    size_t size() const {
        return list.size();
    }

    bool empty() const {
        return list.empty();
    }

    void clear(){
        list.clear();
    }

    void printForward() const {
        list.printForward();
    }

    void printBackward() const {
        list.printBackward();
    }

};

#endif//DEQUEUE_H