#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

struct Contact{
        string name;
        string phoneNumber;
};

class PhoneDirectory{
    private:
        vector <Contact> contacts;
        const string filename = "contacts.txt";
        void loadFromFile();
        void saveToFile();
    public:
        PhoneDirectory();
        ~PhoneDirectory();
        void addContact();
        void displayAll();
        void searchContact();
        void removeContact();

};

