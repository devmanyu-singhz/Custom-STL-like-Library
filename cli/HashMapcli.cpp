#include <iostream>
#include "../include/HashMap.h"
#include <string>
using namespace std;

HashMap<string, string> hashmap;

void runHashMapCLI(){
    int choice;

    while(true){
        cout<<"\n ----- HashMap CLI -----\n";
        cout<<"1. Insert key-value pair"<<endl;
        cout<<"2. Get value by key"<<endl;
        cout<<"3. Check if the key exists"<<endl;
        cout<<"4. Delete Key"<<endl;
        cout<<"5. Print size"<<endl;
        cout<<"6. Clear HashMap"<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore(); //to consume the newline after integer input

        if(choice == 0){
            break;
        }

        string key;
        string value;

        switch(choice){
            case 1:
                cout<<"Enter the key: ";
                getline(cin, key);
                cout<<"Enter the value: ";
                getline(cin, value);
                hashmap.insert(key, value);
                cout<<"Inserted successfully."<<endl;
                break;

            case 2:
                cout<<"Enter the key: ";
                getline(cin, key);
                try{
                    cout<<"Value: "<<hashmap.at(key)<<endl;
                }
                catch(const exception& e){
                    cout<<"Error: "<<e.what()<<endl;
                }
                break;

            case 3:
                cout<<"Enter the key: ";
                getline(cin, key);
                if(hashmap.contains(key)){
                    cout<<"Key is present"<<endl;
                }
                else{
                    cout<<"Key not found!"<<endl;
                }
                break;

            case 4:
                cout<<"Enter the key: ";
                getline(cin, key);
                hashmap.erase(key);
                cout<<"Key deleted!"<<endl;
                break;

            case 5:
                cout<<"Current size: "<<hashmap.size()<<endl;
                break;

            case 6:
                hashmap.clear();
                cout<<"HashMap cleared!"<<endl;
                break;

            default:
                cout<<"Invalid choice! Try again"<<endl;
                break;
        }
    }
}

int main(){

    runHashMapCLI();

    return 0;
}