#include <iostream>
#include "../../include/Set.h"
using namespace std;

int main(){

    Set<int>s;
    cout<<"inserting values: "<<endl;
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(15);
    s.insert(5);

    cout<<"set elements: "<<endl;
    s.print();

    cout<<"contains 10: "<<(s.contains(10) ? "yes" : "no")<<endl;
    cout<<"contains 7: "<<(s.contains(7) ? "yes" : "no")<<endl;

    cout<<"removing 10: "<<endl;
    s.remove(10);

    cout<<"set elements: "<<endl;
    s.print();

    cout<<"size: "<<s.size()<<endl;
    cout<<"clearing set: "<<endl;
    s.clear();

    cout<<"set empty: "<<(s.empty() ? "yes" : "no");

    return 0;
}