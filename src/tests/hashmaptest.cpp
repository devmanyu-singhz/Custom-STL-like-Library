#include "../../include/HashMap.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    HashMap<string, int>map;
    cout<<"inserting elements: "<<endl;
    map.insert("one", 1);
    map.insert("two", 2);
    map.insert("three", 3);

    cout<<"map contains two: "<<(map.contains("two") ? "yes" : "no")<<endl;
    cout<<"value of three: "<<map.at("three")<<endl;

    map.insert("three", 33);
    cout<<"updated value of three: "<<map.at("three")<<endl;
    map.erase("two");
    cout<<"contains two: "<<(map.contains("two") ? "yes" : "no")<<endl;

    cout<<"size: "<<map.size()<<endl;

    return 0;
}