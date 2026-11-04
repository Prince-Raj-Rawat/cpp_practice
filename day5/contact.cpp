#include "contact.h"

PhoneDirectory::PhoneDirectory(){
}



void PhoneDirectory::addContact(){
    Contact newContact;
    cout << "Enter Name: ";
    cin>> newContact.name;
    cout << "Enter phone number:";
    cin>> newContact.phoneNumber;
    contacts.push_back(newContact);
    cout<<"Contact added successfully.\n";
}



void PhoneDirectory::displayAll(){
    if(contacts.empty()){
        cout<<"Directory is empty.\n";
        return;
    }
    cout<<"\n----- Contact List -----\n";
    for(size_t i = 0; i< contacts.size();++i){
        cout << i + 1 << ". Name: " << contacts[i].name  << " | Phone: " << contacts[i].phoneNumber << "\n";
    }
}


void PhoneDirectory::searchContact(){
    if(contacts.empty()){
        cout<<"Directory is empty.\n";
        return;
    }

    string searchName;
    cout<<"Enter a name to search: ";
    cin>> searchName;

    bool found = false;
    for (const auto& c: contacts){
        if(c.name == searchName){
            cout<<"found : "<<c.name<< "->"<< c.phoneNumber << "\n";
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"Contact not found.\n";
    }
}

void PhoneDirectory::removeContact() {
    if (contacts.empty()) {
        cout << "Directory is empty.\n";
        return;
    }

    string removeName;
    cout << "Enter name to remove: ";
    cin >> removeName;

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == removeName) {
            contacts.erase(it);
            cout << "Contact removed successfully.\n";
            return;
        }
    }

    cout << "Contact not found.\n";
}
