#include <iostream>
#include "../../include/Trie.h"
using namespace std;

int main(){
    Trie trie;

    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");
    trie.insert("ape");

    cout<<boolalpha;
    cout<<"search apple: "<<trie.search("apple")<<endl;
    cout<<"count words equal to apple: "<<trie.countWordsEqualTo("apple")<<endl;
    cout<<"starts with ap: "<<trie.startsWith("ap")<<endl;
    cout<<"count words starting with ap: "<<trie.countWordsStartingWith("ap")<<endl;

    trie.remove("apple");
    cout<<"apple present: "<<trie.countWordsEqualTo("apple")<<endl;

    trie.remove("app");
    cout<<"count words equal to app: "<<trie.countWordsEqualTo("app")<<endl;

    return 0;
}