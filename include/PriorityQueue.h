#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "Vector.h"
#include <functional>
#include <stdexcept>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T, typename compare = less<T>>
class PriorityQueue{

    private:
    Vector<T> heap;
    compare comp;

    void heapifyUp(size_t index){
        while(index > 0){
            size_t parent = (index - 1)/2;
            if(comp(heap[parent], heap[index])){
                std::swap(heap[parent], heap[index]);
                index = parent;
            }
            else{
                break;
            }
        }
    }

    void heapifyDown(size_t index){
        size_t n = heap.size();
        while(true){
            size_t left = 2*index + 1;
            size_t right = 2*index + 2;
            size_t largest = index;

            if(left < n && comp(heap[largest], heap[left])){
                largest = left;
            }
            if(right < n && comp(heap[largest], heap[right])){
                largest = right;
            }
            if(largest != index){
                std::swap(heap[index], heap[largest]);
                index = largest;
            }
            else{
                break;
            }
        }
    }

    public:
    PriorityQueue() = default;
    explicit PriorityQueue(const compare& cmp) : comp(cmp) {}

    void push(const T& val){
        heap.pushBack(val);
        heapifyUp(heap.size()-1);
    }

    void pop(){
        if(empty()){
            throw out_of_range("priority queue is empty!");
        }
        heap[0] = heap[heap.size()-1];
        heap.popBack();

        if(!empty()){
            heapifyDown(0);
        }
    }

    const T& top() const {
        if(empty()){
            throw out_of_range("priority queue is empty!");
        }
        return heap[0];
    }

    const T& peek() const {
        return top();
    }

    bool empty() const {
        return heap.isEmpty();
    }

    size_t size() const {
        return heap.size();
    }

    void clear(){
        heap.clear();
    }

    void swap(PriorityQueue& other){
        std::swap(heap, other.heap);
        std::swap(comp, other.comp);
    }

    void buildHeap(){
        for(int i = static_cast<int>(heap.size() / 2) - 1; i >= 0; i--){
            heapifyDown(i);
        }
    }

};

#endif//PRIORITY_QUEUE_H