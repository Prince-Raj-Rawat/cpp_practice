#include <iostream>
#include "contact.h"

using namespace std;

int main() {
    PhoneDirectory directory;
    int choice;

    while (true) {
        cout << "\n===== Phone Directory Menu =====\n";
        cout << "1. Add Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Remove Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;

        // Handle invalid non-numeric input (e.g., if user types a letter)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice) {
            case 1:
                directory.addContact();
                break;
            case 2:
                directory.displayAll();
                break;
            case 3:
                directory.searchContact();
                break;
            case 4:
                directory.removeContact();
                break;
            case 5:
                cout << "Exiting Phone Directory. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please select 1-5.\n";
        }
    }

    return 0;
}