#include <iostream>
#include "../../include/HashSet.h"
using namespace std;

int main(){
    HashSet<int> set;

    set.insert(10);
    set.insert(15);
    set.insert(5);

    cout<<"contains 15: "<<(set.contains(15) ? "yes" : "no")<<endl;
    cout<<"contains 20: "<<(set.contains(20) ? "yes" : "no")<<endl;

    cout<<"size before erase: "<<set.size()<<endl;
    set.erase(10);
    cout<<"size after erase: "<<set.size()<<endl;

    set.clear();

    cout<<"hash set empty: "<<(set.empty() ? "yes" : "no")<<endl;

    return 0;
}