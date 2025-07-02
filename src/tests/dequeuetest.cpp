#include "../../include/Dequeue.h"
#include <iostream>
using namespace std;

int main(){

    Dequeue<int>dq;
    cout<<"pushing back elements: "<<endl;
    dq.pushBack(10);
    dq.pushBack(20);

    cout<<"printing elements forward: "<<endl;
    dq.printForward();

    cout<<"pushing elements in front: "<<endl;
    dq.pushFront(5);

    cout<<"printing elements backward: "<<endl;
    dq.printBackward();

    cout<<"front: "<<dq.front()<<", back: "<<dq.back()<<endl;

    cout<<"popping elements from front and back: "<<endl;
    dq.popBack();
    dq.popFront();

    cout<<"printing the elements: "<<endl;
    dq.printForward();

    cout<<"size: "<<dq.size()<<endl;

    dq.clear();

    cout<<"dequeue is empty: "<<(dq.empty() ? "yes" : "no");

    return 0;
}