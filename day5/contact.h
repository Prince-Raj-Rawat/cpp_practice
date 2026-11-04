#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact{
        string name;
        string phoneNumber;
};

class PhoneDirectory{
    private:
        vector <Contact> contacts;
    public:
        PhoneDirectory();
        void addContact();
        void displayAll();
        void searchContact();
        void removeContact();

};

