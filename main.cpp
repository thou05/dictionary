#include <bits/stdc++.h>
#include "Dictionary.cpp"

using namespace std;


int main() {
    Dictionary dict(101); 
    string filename = "dictionary.txt"; 
    dict.loadFromFile(filename);

    int choice;
    do {
        cout << "\n============MENU================\n";
        cout << "|  " << "1. Find a word" << setw(15) << "|" << endl;
        cout << "|  " << "2. Modify a word" << setw(13) << "|" << endl;
        cout << "|  " << "3. Add a word" << setw(16) << "|" << endl;
        cout << "|  " << "4. Remove a word" << setw(13) << "|" << endl;
        cout << "|  " << "5. Save dictionary to file" << setw(3) << "|" << endl;
        cout << "|  " << "0. Exit" << setw(22) << "|" << endl;
        cout << "===============================\n";
        cout << "Enter your choice: ";
        
        cin >> choice;

        //tranh vong lap vo han
        if (choice == 0) {
            cout << "Exiting program...\n";
            break; 
        }

        switch (choice) {
            case 1: {
                dict.findWord();
                break;
            }
            case 2: {
                dict.modifyWord();
                break;
            }
            case 3: {
                dict.insertWord();
                break;
            }
            case 4: {
                dict.removeWord();
                break;
            }
            case 5: {
                dict.saveToFile(filename);
                break;
            }
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 0);

    return 0;
}