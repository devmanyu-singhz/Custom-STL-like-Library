#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

template <typename T>
class Vector {
    private:
    T* data;
    size_t _size;
    size_t _capacity;

    void resize(size_t new_cap){
        T* new_data = new T[new_cap];
        for(size_t i = 0; i < _size; i++){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        _capacity = new_cap;
    }

    public:
    //default constructor
    Vector() : data(NULL), _size(0), _capacity(0) {}

    //default destructor
    ~Vector(){
        delete[] data;
    }

    //copy constructor
    Vector(const Vector& other) : _size(other._size), _capacity(other._capacity) {
        data = new T[_capacity];
        for(size_t i = 0; i < _size; i++){
            data[i] = other.data[i];
        }
    }

    //copy assignment operator
    Vector& operator = (const Vector& other) {
        if(this != &other){
            delete[] data;
            _size = other._size;
            _capacity = other._capacity;
            data = new T[_capacity];
            
            for(size_t i = 0; i < _size; i++){
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    //move constructor
    Vector(Vector&& other) noexcept
        :data(other.data), _size(other._size), _capacity(other._capacity) {
            other.data = NULL;
            other._size = 0;
            other._capacity = 0;
        }

    //move assignment operator
    Vector& operator = (Vector&& other) noexcept {
        if(this != &other) {
            delete[] data;
            data = other.data;
            _size = other._size;
            _capacity = other._capacity;

            other.data = NULL;
            other._size = 0;
            other._capacity = 0;
        }
        return *this;
    }

    //push back function
    void pushBack(const T& val){
        if(_size == _capacity){
            resize(_capacity == 0 ? 1 : 2*_capacity);
        }
        data[_size++] = val;
    }

    //pop back function
    void popBack(){
        if(_size == 0){
            throw out_of_range("Vector is empty!");
        }
        _size--;
    }

    //element access - unsafe v
    T& operator[](size_t index){
        if(index >= _size){
            throw out_of_range("Index out of range!");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if(index >= _size){
            throw out_of_range("Index out of range!");
        }
        return data[index];
    }

    //element access - safe v
    T& at(size_t index){
        if(index >= _size){
            throw out_of_range("Index out of range!");
        }
        return data[index];
    }

    const T& at(size_t index) const {
        if(index >= _size){
            throw out_of_range("Index out of range!");
        }
        return data[index];
    }

    //function to return the current size
    size_t size() const {
        return _size;
    }

    //function to return the current capacity
    size_t capacity() const {
        return _capacity;
    }

    //function to check if the vector is empty
    bool isEmpty() const {
        if(_size == 0){
            return true;
        }
        return false;
    }

    //function to clear the vector
    void clear() {
        delete[] data;
        data = NULL;
        _size = 0;
        _capacity = 0;
    }

};

#endif //VECTOR_H

