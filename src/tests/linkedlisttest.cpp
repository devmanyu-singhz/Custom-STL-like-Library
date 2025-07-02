#include <iostream>
#include "../../include/Linkedlist.h"
using namespace std;

void printListStatus(const LinkedList<int>& list){
    cout<<"List size: "<<list.size()<<", Empty: "<<(list.empty() ? "yes" : "no")<<endl;
    cout<<"list contents: "<<endl;
    list.print();
    cout<<endl;
}

int main(){
    LinkedList<int> l;
    cout<<"pushing elements in the list: "<<endl;
    l.pushBack(10);
    l.pushBack(20);
    l.pushBack(30);
    l.pushBack(40);
    
    printListStatus(l);

    cout<<"pushing elements in the list from the front: "<<endl;
    l.pushFront(50);
    l.pushFront(60);
    l.pushFront(70);

    printListStatus(l);

    cout<<"front: "<<l.front()<<", back: "<<l.back()<<endl;

    cout<<"popping elements from the front and back: "<<endl;
    l.popFront();
    l.popBack();

    printListStatus(l);

    cout<<"contains 20: "<<(l.contains(20) ? "yes" : "no")<<endl;
    cout<<"contains 100: "<<(l.contains(100) ? "yes" : "no")<<endl;

    cout<<"removing 20: "<<endl;
    l.remove(20);

    printListStatus(l);

    cout<<"testing copying constructor:"<<endl;
    LinkedList<int>a = l;
    printListStatus(a);

    cout<<"modifying original list: "<<endl;
    l.pushBack(200);
    printListStatus(l);

    cout<<"copied lst should be unchanged: "<<endl;
    printListStatus(a);

    cout<<"clearing original list: "<<endl;
    l.clear();
    printListStatus(l);

    return 0;
}
