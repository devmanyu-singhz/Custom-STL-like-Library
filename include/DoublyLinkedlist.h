#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DoublyLinkedList{

    private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& val) : data(val), next(NULL), prev(NULL) {}
    };

    Node* head;
    Node* tail;
    size_t _size;

    void clear_all(){
        while(!empty()){
            popFront();
        }
    }

    void copy_from(const DoublyLinkedList& other){
        Node* curr = other.head;
        while(curr){
            pushBack(curr->data);
            curr = curr->next;
        }
    }

    public:
    DoublyLinkedList() : head(NULL), tail(NULL), _size(0) {}

    ~DoublyLinkedList(){
        clear_all();
    }

    DoublyLinkedList(const DoublyLinkedList& other) : head(NULL), tail(NULL), _size(0){
        copy_from(other);
    }

    DoublyLinkedList& operator = (const DoublyLinkedList& other){
        if(this != &other){
            clear_all();
            copy_from(other);
        }
        return *this;
    }

    void pushFront(const T& val){
        Node* newnode = new Node(val);
        newnode->next = head;
        if(head){
            head->prev = newnode;
        }
        head = newnode;
        if(_size == 0){
            tail = head;
        }
        _size++;
    }

    void pushBack(const T& val){
        Node* newnode = new Node(val);
        newnode->prev = tail;
        if(tail){
            tail->next = newnode;
        }
        tail = newnode;
        if(_size == 0){
            head = tail;
        }
        _size++;
    }

    void popFront(){
        if(empty()){
            throw out_of_range("list is empty!");
        }
        Node* temp = head;
        head = head->next;
        if(head){
            head->prev = NULL;
        }
        else{
            tail = NULL;
        }
        delete temp;
        _size--;
    }

    void popBack(){
        if(empty()){
            throw out_of_range("list is empty!");
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail){
            tail->next = NULL;
        }
        else{
            head = NULL;
        }
        delete temp;
        _size--;
    }

    T& front() {
        if(empty()){
            throw out_of_range("list is empty!");
        }
        return head->data;
    }

    const T& front() const {
        if(empty()){
            throw out_of_range("list is empty!");
        }
        return head->data;
    }

    T& back() {
        if(empty()){
            throw out_of_range("list is empty!");
        }
        return tail->data;
    }

    const T& back() const {
        if(empty()){
            throw out_of_range("list is empty!");
        }
        return tail->data;
    }

    size_t size(){
        return _size;
    }

    bool empty(){
        return _size == 0;
    }

    void clear(){
        clear_all();
    }

    void printForward() const {
        Node* curr = head;
        while(curr){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }

    void printBackward() const {
        Node* curr = tail;
        while(curr){
            cout<<curr->data<<" ";
            curr = curr->prev;
        }
        cout<<endl;
    }

    void remove(const T& val){
        Node* curr = head;
        while(curr){
            if(curr->data == val){
                if(curr->prev){
                    curr->prev->next = curr->next;
                }
                else{
                    head = curr->next;
                }

                if(curr->next){
                    curr->next->prev = curr->prev;
                }
                else{
                    tail = curr->prev;
                }

                delete curr;
                _size--;
                return;
            }
            curr = curr->next;
        }
    }

    void insertBefore(const T& target, const T& val){
        Node* curr = head;
        while(curr){
            if(curr->data == target){
                Node* newnode = new Node(val);
                newnode->next = curr;
                newnode->prev = curr->prev;

                if(curr->prev){
                    curr->prev->next = newnode;
                }
                else{
                    head = newnode;
                }
                curr->prev = newnode;
                _size++;
                return;
            }
            curr = curr->next;
        }
        throw invalid_argument("target value not found!");
    }

};

#endif//DOUBLY_LINKED_LIST_H