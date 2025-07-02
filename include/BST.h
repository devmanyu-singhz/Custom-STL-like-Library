#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class BST{

    private:
    struct Node{
        T data;
        Node* left;
        Node* right;

        Node(const T& val) : data(val), left(NULL), right(NULL) {}
    };

    Node* root;
    size_t _size;

    //to insert value
    Node* insert(Node* node, const T& val){
        if(!node){
            _size++;
            return new Node(val);
        }
        if(val < node->data){
            node->left = insert(node->left, val);
        }
        else if(val > node->data){
            node->right = insert(node->right, val);
        }
        return node;
    }

    //to search a value
    bool contains(Node* node, const T& val) const {
        if(!node){
            return false;
        }
        if(val == node->data){
            return true;
        }
        if(val < node->data){
            return contains(node->left, val);
        }
        else{
            return contains(node->right, val);
        }
    }

    //to find minimum node
    Node* findMin(Node* node) const {
        while(node && node->left){
            node = node->left;
        }
        return node;
    }

    //to find maximum node
    Node* findMax(Node* node) const {
        while(node && node->right){
            node = node->right;
        }
        return node;
    }

    //to remove a value
    Node* remove(Node* node, const T& val){
        if(!node){
            return NULL;
        }
        if(val < node->data){
            node->left = remove(node->left, val);
        }
        else if(val > node->data){
            node->right = remove(node->right, val);
        }
        else{
            //node having one or no child
            if(!node->left){
                Node* temp = node->right;
                delete node;
                _size--;
                return temp;
            }
            if(!node->right){
                Node* temp = node->left;
                delete node;
                _size--;
                return temp;
            }
            //node with 2 children
            Node* minnode = findMin(node->right);
            node->data = minnode->data;
            node->right = remove(node->right, minnode->data);
        }
        return node;
    }

    //inorder
    void inorder(Node* node) const {
        if(!node){
            return;
        }
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    //to clear all nodes
    void clear(Node* node){
        if(!node){
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }

    public:
    BST() : root(NULL), _size(0) {}

    ~BST(){
        clear(root);
    }

    void insert(const T& val){
        root = insert(root, val);
    }

    void remove(const T& val){
        root = remove(root, val);
    }

    bool contains(const T& val) const {
        return contains(root, val);
    }

    void inorder() const {
        inorder(root);
        cout<<endl;
    }

    size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    const T& min() const {
        if(!root){
            throw out_of_range("bst is empty!");
        }
        Node* min_node = findMin(root);
        return min_node->data;
    }

    const T& max() const {
        if(!root){
            throw out_of_range("bst is empty!");
        }
        Node* max_node = findMax(root);
        return max_node->data;
    }

    void clear() {
        clear(root);
        root = NULL;
        _size = 0;
    }

};

#endif//BST_H