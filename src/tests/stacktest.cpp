#include "../../include/Stack.h"
#include <iostream>
using namespace std;

void printstack(Stack<int>&s){
    cout<<"Top: "<<(s.Empty() ? -1 : s.top())<<", Size: "<<s.size() <<", Empty: "<<(s.Empty() ? "Yes" : "No");
    cout<<endl;
}

int main(){

    Stack<int>s;
    cout<<"pushing elements: ";
    for(int i=1; i<=5; i++){
        s.Push(i*10);
        cout<<i*10<<" ";
    }

    cout<<endl;

    printstack(s);

    cout<<"popping 2 elements: "<<endl;
    s.Pop();
    s.Pop();

    printstack(s);

    cout<<"top element is: "<<s.top()<<endl;
    cout<<"clearing stack"<<endl;
    s.clear();

    printstack(s);

    cout<<"testing copy constructor: "<<endl;
    s.Push(100);
    s.Push(200);
    Stack<int>a = s;
    cout<<"top of s: "<<s.top()<<endl;
    cout<<"top of a: "<<a.top()<<endl;

    cout<<"modifying original stack: "<<endl;
    s.Pop();
    s.Push(300);

    cout<<"original top: "<<s.top()<<", copied top: "<<a.top()<<endl;

    return 0;
}