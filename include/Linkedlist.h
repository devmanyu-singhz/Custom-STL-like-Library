#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class LinkedList {

    private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t _size;

    void copy_from(const LinkedList& other) {
        Node* curr = other.head;
        while (curr) {
            pushBack(curr->data);
            curr = curr->next;
        }
    }

    public:
    LinkedList() : head(nullptr), tail(nullptr), _size(0) {}

    // Copy constructor
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), _size(0) {
        copy_from(other);
    }

    // Assignment operator
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            copy_from(other);
        }
        return *this;
    }

    // Destructor
    ~LinkedList() {
        clear();
    }

    void pushFront(const T& value) {
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
        if (_size == 0) tail = head;
        _size++;
    }

    void pushBack(const T& value) {
        Node* new_node = new Node(value);
        if (_size == 0) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        _size++;
    }

    void popFront() {
        if (empty()){
            throw out_of_range("List is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        _size--;
        if (_size == 0) tail = nullptr;
    }
    void popBack() {
        if (empty()){
            throw out_of_range("List is empty");
        }
        if (_size == 1) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail)
                current = current->next;
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        _size--;
    }

    T& front() {
        if (empty()){
            throw out_of_range("List is empty");
        }
        return head->data;
    }

    T& back() {
        if (empty()){
            throw out_of_range("List is empty");
        }
        return tail->data;
    }

    bool contains(const T& value) const {
        Node* curr = head;
        while (curr) {
            if (curr->data == value){
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void remove(const T& value) {
        if (empty()){
            return;
        }

        if (head->data == value) {
            popFront();
            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr) {
            if (curr->data == value) {
                prev->next = curr->next;
                if (curr == tail) tail = prev;
                delete curr;
                --_size;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void clear() {
        while (!empty()) {
            popFront();
        }
    }

    bool empty() const {
        return _size == 0;
    }

    size_t size() const {
        return _size;
    }

    void print() const {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout <<endl;
    }
};

#endif//LINKEDLIST_H