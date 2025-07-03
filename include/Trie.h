#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class TrieNode{

    public:
    bool isEnd;
    int wordCount;
    int prefixCount;
    unordered_map<char, TrieNode*>children;

    TrieNode() : isEnd(false), wordCount(0), prefixCount(0) {}
    ~TrieNode() {
        for(auto& p : children){
            delete p.second;
        }
    }
};

class Trie{

    private:
    TrieNode* root;

    bool removeHelper(TrieNode* node, const string& word, int depth){
        if(!node){
            return false;
        }
        if(depth == word.size()){
            if(node->wordCount > 0){
                node->wordCount--;
                node->prefixCount--;
                if(node->wordCount == 0){
                    node->isEnd = false;
                }
                return true;
            }
            return false;
        }
        char c = word[depth];
        if(node->children.count(c) && removeHelper(node->children[c], word, depth+1)){
            node->prefixCount--;
            //cleanup unused nodes
            if(node->children[c]->prefixCount == 0){
                delete node->children[c];
                node->children.erase(c);
            }
            return true;
        }
        return false;
    }

    public:
    Trie() : root(new TrieNode()) {}
    ~Trie() {
        delete root;
    }

    void insert(const string& word){
        TrieNode* node = root;
        for(char c : word) {
            if(!node->children.count(c)){
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->prefixCount++;
        }
        node->isEnd = true;
        node->wordCount++;
    }

    bool search(const string& word) const {
        TrieNode* node = root;
        for(char c : word){
            if(!node->children.count(c)){
                return false;
            }
            node = node->children.at(c);
        }
        return node->isEnd;
    }

    bool startsWith(const string& prefix) const {
        TrieNode* node = root;
        for(char c : prefix){
            if(!node->children.count(c)){
                return false;
            }
            node = node->children.at(c);
        }
        return true;
    }

    int countWordsEqualTo(const string& word) const {
        TrieNode* node = root;
        for(char c : word){
            if(!node->children.count(c)){
                return 0;
            }
            node = node->children.at(c);
        }
        return node->wordCount;
    }

    int countWordsStartingWith(const string& prefix) const {
        TrieNode* node = root;
        for(char c : prefix) {
            if(!node->children.count(c)){
                return 0;
            }
            node = node->children.at(c);
        }
        return node->prefixCount;
    }

    void remove(const string& word){
        removeHelper(root, word, 0);
    }

};

#endif//TRIE_H