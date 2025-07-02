#include "../../include/Vector.h"
#include <iostream>
using namespace std;

int main(){
    Vector<int> v;
    v.pushBack(10);
    v.pushBack(20);
    v.pushBack(30);

    for(size_t i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    v.popBack();

    cout<<"after popping:"<<endl;

    for(size_t i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    Vector<int> a;
    a.pushBack(1);
    a.pushBack(2);
    a.pushBack(3);

    Vector<int> b = a;
    Vector<int> c;
    c = a;

    for(size_t i = 0; i < a.size(); i++){
        cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}