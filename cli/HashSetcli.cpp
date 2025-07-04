#include <iostream>
#include "../include/HashSet.h"
#include <string>
using namespace std;

HashSet<string> hashset;

void runHashSetCLI(){
    int choice;

    while(true){
        cout<<"\n ----- HashSet CLI -----\n";
        cout<<"1. Insert key"<<endl;
        cout<<"2. Check if key exists"<<endl;
        cout<<"3. Erase Key"<<endl;
        cout<<"4. Show Size"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Choose an option: ";
        cin>>choice;
        cin.ignore();

        if(choice == 5){
            break;
        }

        string key;

        switch(choice){
            case 1:
                cout<<"Enter the key: ";
                getline(cin, key);
                hashset.insert(key);
                cout<<"Inserted!"<<endl;
                break;

            case 2:
                cout<<"Enter the key: ";
                getline(cin, key);
                cout<<(hashset.contains(key) ? "Key Exists" : "Key not found!")<<endl;
                break;

            case 3:
                cout<<"Enter the key: ";
                getline(cin, key);
                hashset.erase(key);
                cout<<"key erased!"<<endl;
                break;

            case 4:
                cout<<"Current size: "<<hashset.size()<<endl;
                break;

            default:
                cout<<"Invalid input! try again";
                break;
        }
    }
}

int main(){

    runHashSetCLI();

    return 0;
}
