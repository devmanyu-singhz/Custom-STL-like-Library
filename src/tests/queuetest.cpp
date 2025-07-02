#include <iostream>
#include "../../include/Queue.h"
using namespace std;

void printqueueinfo(Queue<int>& q){
    cout<<"Front: ";
    if(!q.Empty()){
        cout<<q.front();
    }
    else{
        cout<<"N/A";
    }
    cout<<", Size: "<<q.size()<<", Empty: "<<(q.Empty() ? "Yes" : "No")<<endl;
}

int main(){

    Queue<int>q;
    cout<<"enqueing elements: ";
    for(int i = 1; i <= 5; i++){
        q.Enqueue(i*10);
        cout<<i*10<<" ";
    }
    cout<<endl;

    printqueueinfo(q);

    cout<<"removing 2 elements"<<endl;
    q.Dequeue();
    q.Dequeue();

    printqueueinfo(q);

    cout<<"the front element is: "<<q.front()<<endl;
    cout<<"clearing queue: "<<endl;
    q.clear();

    printqueueinfo(q);

    cout<<"testing copy constructor: "<<endl;
    q.Enqueue(100);
    q.Enqueue(200);
    Queue<int>a = q;

    cout<<"original front: "<<q.front()<<endl;
    cout<<"copied front: "<<a.front()<<endl;

    cout<<"modifying original queue: "<<endl;
    q.Dequeue();
    q.Enqueue(300);

    cout<<"original front: "<<q.front()<<", copied front: "<<a.front()<<endl;


    return 0;
}

