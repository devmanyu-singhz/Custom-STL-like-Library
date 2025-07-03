#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <stdexcept>
using namespace std;

template<typename Key, typename Value, typename Hash = hash<Key>>
class HashMap{

    private:
    static const size_t DEFAULT_CAPACITY = 16;
    static constexpr float LOAD_FACTOR = 0.75f;

    vector<list<pair<Key, Value>>> table;
    size_t numelements;
    Hash hasher;

    void rehash(){
        size_t newcapacity = table.size()*2;
        vector<list<pair<Key, Value>>> newtable(newcapacity);

        for(const auto& bucket : table){
            for(const auto& kv : bucket){
                const Key& key = kv.first;
                const Value& val = kv.second;
                size_t newindex = hasher(key) % newcapacity;
                newtable[newindex].emplace_back(key, val);
            }
        }

        table = move(newtable);
    }

    public:
    HashMap() : table(DEFAULT_CAPACITY), numelements(0) {}

    void insert(const Key& key, const Value& value){
        if((float)numelements / table.size() > LOAD_FACTOR){
            rehash();
        }

        size_t index = hasher(key) % table.size();
        for(auto& kv : table[index]){
            if(kv.first == key){
                kv.second = value;
                return;
            }
        }

        table[index].emplace_back(key, value);
        numelements++;
    }

    bool contains(const Key& key) const {
        size_t index = hasher(key) % table.size();
        for(const auto& kv : table[index]){
            if(kv.first == key){
                return true;
            }
        }
        return false;
    }

    Value& at(const Key& key){
        size_t index = hasher(key) % table.size();
        for(auto& kv : table[index]){
            if(kv.first == key){
                return kv.second;
            }
        }
        throw out_of_range("key not found in hash map!");
    }

    const Value& at(const Key& key) const {
        size_t index = hasher(key) % table.size();
        for(const auto& kv : table[index]){
            if(kv.first == key){
                return kv.second;
            }
        }
        throw out_of_range("key not found in hash map!");
    }

    void erase(const Key& key){
        size_t index = hasher(key) % table.size();
        auto& bucket = table[index];

        for(auto it = bucket.begin(); it != bucket.end(); it++){
            if(it->first == key){
                bucket.erase(it);
                numelements--;
                return;
            }
        }
    }

    size_t size() const {
        return numelements;
    }

    bool empty() const {
        return numelements == 0;
    }

    void clear() {
        table.clear();
        table.resize(DEFAULT_CAPACITY);
        numelements = 0;
    }

};

#endif//HASH_MAP_H