#include <iostream>
#include "../../include/PriorityQueue.h"
using namespace std;

void testMaxHeap(){
    cout<<"max heap test: "<<endl;
    PriorityQueue<int>maxheap;
    maxheap.push(10);
    maxheap.push(30);
    maxheap.push(20);
    maxheap.push(5);

    while(!maxheap.empty()){
        cout<<maxheap.top()<<" ";
        maxheap.pop();
    }
    cout<<endl;
}

void testMinHeap(){
    cout<<"min heap test: "<<endl;
    PriorityQueue<int, greater<int>>minheap;

    minheap.push(10);
    minheap.push(30);
    minheap.push(20);
    minheap.push(5);

    while(!minheap.empty()){
        cout<<minheap.top()<<" ";
        minheap.pop();
    }

    cout<<endl;
}

int main(){

    testMaxHeap();
    testMinHeap();

    return 0;
}