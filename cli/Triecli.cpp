#include <iostream>
#include <string>
#include "../include/Trie.h"
using namespace std;

Trie trie;

void runTrieCLI(){
    int choice;

    while(true){
        cout<<"\n----- Trie CLI -----\n";
        cout<<"1. Insert word"<<endl;
        cout<<"2. Check if word exists"<<endl;
        cout<<"3. Remove word"<<endl;
        cout<<"4. Check prefix"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Choose an option: ";
        cin>>choice;
        cin.ignore();

        if(choice == 5){
            break;
        }

        string word;

        switch(choice){
            case 1:
                cout<<"Enter the word: ";
                getline(cin, word);
                trie.insert(word);
                cout<<"Inserted!"<<endl;
                break;

            case 2:
                cout<<"Enter the word: ";
                getline(cin, word);
                cout<<(trie.search(word) ? "Word Exists" : "Word not found!")<<endl;
                break;

            case 3:
                cout<<"Enter the word: ";
                getline(cin, word);
                trie.remove(word);
                cout<<"Removed"<<endl;
                break;

            case 4:
                cout<<"Enter the prefix: ";
                getline(cin, word);
                cout<<(trie.startsWith(word) ? "Prefix exists" : "Prefix not found!")<<endl;
                break;

            default:
                cout<<"Invalid input! try again"<<endl;
                break;
        }
    }
}

int main(){

    runTrieCLI();

    return 0;
}