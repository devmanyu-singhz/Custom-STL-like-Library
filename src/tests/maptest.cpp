#include "../../include/Map.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    Map<string, int> ages;
    ages.insert("alice", 30);
    ages.insert("bob", 25);
    ages.insert("charlie", 40);

    cout<<"size: "<<ages.size()<<endl;
    cout<<"alice: "<<ages.at("alice")<<endl;
    cout<<"bob: "<<ages.at("bob")<<endl;

    //overwriting existing key
    ages.insert("alice", 35);
    cout<<"after updating alice: "<<endl;
    cout<<"alice: "<<ages.at("alice")<<endl;

    cout<<"contains charlie: "<<(ages.contains("charlie") ? "yes" : "no")<<endl;
    cout<<"contains david: "<<(ages.contains("david") ? "yes" : "no")<<endl;

    ages.erase("bob");
    cout<<"after erasing bob: "<<endl;
    cout<<"contains bob: "<<(ages.contains("bob") ? "yes" : "no")<<endl;

    cout<<"map size before clear: "<<ages.size()<<endl;
    ages.clear();
    cout<<"map size after clear: "<<ages.size()<<endl;

    return 0;
}