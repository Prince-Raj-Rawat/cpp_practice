#include "contact.h"

PhoneDirectory::PhoneDirectory(){
    loadFromFile();
}

PhoneDirectory::~PhoneDirectory(){
    saveToFile();
}

void PhoneDirectory::loadFromFile(){
    ifstream inFile(filename);

    if(!inFile.is_open()){
        return;
    }

    contacts.clear();
    string line;
    while(getline(inFile,line)){
        size_t delimiterPos = line.find(',');
        if(delimiterPos != string::npos){
            Contact c;
            c.name = line.substr(0,delimiterPos);
            c.phoneNumber = line.substr(delimiterPos +1);
            contacts.push_back(c);

        }
    }

    inFile.close();

}

void PhoneDirectory::saveToFile(){
    ofstream outFile(filename);
    if(!outFile.is_open()){
        cout<<"Error: could not save contact to file.\n";
        return;
    }

    for(const auto& c : contacts){
        outFile << c.name << "," << c.phoneNumber << "\n";
    }
    outFile.close();

}

void PhoneDirectory::addContact(){
    Contact newContact;
    cout << "Enter Name: ";
    cin>> newContact.name;
    cout << "Enter phone number:";
    cin>> newContact.phoneNumber;
    contacts.push_back(newContact);
    saveToFile();
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
            saveToFile();
            cout << "Contact removed successfully.\n";
            return;
        }
    }

    cout << "Contact not found.\n";
}
