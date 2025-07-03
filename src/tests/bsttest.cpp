#include <iostream>
#include "../../include/BST.h"
using namespace std;

int main(){

    BST<int> tree;

    cout<<"inserting values: "<<endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(40);
    tree.insert(20);
    tree.insert(60);
    tree.insert(80);

    cout<<"inorder traversal: "<<endl;
    tree.inorder();

    cout<<"tree contains 40: "<<(tree.contains(40) ? "yes" : "no")<<endl;
    cout<<"tree contains 100: "<<(tree.contains(100) ? "yes" : "no")<<endl;

    cout<<"minimum value: "<<tree.min()<<endl;
    cout<<"maximum value: "<<tree.max()<<endl;

    cout<<"removing 70: "<<endl;
    tree.remove(70);
    cout<<"inorder after removal: "<<endl;
    tree.inorder();

    cout<<"tree size: "<<tree.size()<<endl;
    cout<<"clearing tree: "<<endl;
    tree.clear();

    cout<<"tree clear: "<<(tree.empty() ? "yes" : "no")<<endl;

    BST<int>bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(15);

    const int* found = bst.find(15);
    if(found){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }

    return 0;
}