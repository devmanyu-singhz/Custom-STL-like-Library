#ifndef QUEUE_H
#define QUEUE_H

#include "Vector.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class Queue{

    private:
    Vector<T> container;
    size_t start;

    void compact_if_needed() {
        //compact if too much front space unused (optional optimization)
        if(start > container.size()/2){
            Vector<T>new_container;
            for(size_t i = start; i < container.size(); i++){
                new_container.pushBack(container[i]);
            }
            container = new_container;
            start = 0;
        }
    }

    public:
    //constructor
    Queue() : start(0) {}

    //copy constructor, assignment and destructor
    Queue(const Queue& other) = default;
    Queue& operator = (const Queue& other) = default;

    ~Queue() = default;

    void Enqueue(const T& val){
        container.pushBack(val);
    }

    void Dequeue(){
        if(Empty()){
            throw out_of_range("Queue::dequeue(): empty queue!");
        }
        start++;
        compact_if_needed();
    }

    T& front(){
        if(Empty()){
            throw out_of_range("Queue::front(): empty queue!");
        }
        return container[start];
    }

    const T& front() const {
        if(Empty()){
            throw out_of_range("Queue::front(): empty queue!");
        }
        return container[start];
    }

    bool Empty() const {
        return start >= container.size();
    }

    size_t size() const {
        return Empty() ? 0 : container.size() - start;
    }

    void clear(){
        container.clear();
        start = 0;
    }

};

#endif //QUEUE_H