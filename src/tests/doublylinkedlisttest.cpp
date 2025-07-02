#include "../../include/DoublyLinkedlist.h"
#include <iostream>

int main(){
    DoublyLinkedList<int> l;
    cout<<"pushing back elements: "<<endl;
    l.pushBack(10);
    l.pushBack(20);
    l.pushBack(30);

    cout<<"current elements (forward)"<<endl;
    l.printForward();

    cout<<"pushing elements in front: "<<endl;
    l.pushFront(5);

    cout<<"current list forward and backward: "<<endl;
    l.printForward();
    l.printBackward();

    cout<<"popping front: "<<endl;
    l.popFront();

    cout<<"list elements forward: "<<endl;
    l.printForward();

    cout<<"popping back: "<<endl;
    l.popBack();

    cout<<"list elements: "<<endl;
    l.printForward();

    cout<<"inserting 15 before 20: "<<endl;
    l.insertBefore(20, 15);

    cout<<"list elements: "<<endl;
    l.printForward();

    cout<<"removing 15: "<<endl;
    l.remove(15);

    cout<<"front: "<<l.front()<<", back: "<<l.back()<<", size: "<<l.size()<<endl;

    cout<<"clearing the list: "<<endl;
    l.clear();

    cout<<"list empty: "<<(l.empty() ? "yes" : "no")<<endl;
    
    return 0;
}