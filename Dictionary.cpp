#include <bits/stdc++.h>
#include "HashTable.cpp"

using namespace std;

int hashFunction(string key, int size) {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 37 + ch) % size;
    }
    return hash;
}

class Dictionary {
    HashTable<string, string> dict;

public:
    Dictionary() {};
    Dictionary(int size):  dict(size) {};

    void loadFromFile(string &filename) {
        ifstream file(filename); 
        if (!file.is_open()) { 
            cout << "Error: Unable to open the file!" << endl;
            return;
        }

        string line, eng, vie;
        while (getline(file, line)) { 
            stringstream ss(line); 
            if (ss >> eng) { 
                getline(ss, vie);  
                if (!vie.empty() && vie[0] == ' ') { //xoa khoang trang dau dong
                    vie.erase(0, 1);
                }
                dict.Add(eng, vie, hashFunction); 
            }
        }
        file.close();
        cout << "File loaded successfully." << endl;
    }


    //tim kiem tren bang bam
    void findWord(){
        string word;
        cout << "Enter the english word to look up: ";
        cin.ignore();
        getline(cin, word);

        if(!dict.Contains(word, hashFunction)){
            cout << "This word not found!!" << endl;
            return;
        }
        Node<string, string>* resultNode = dict.Find(word, hashFunction);
        if (resultNode) {
            cout << "The meaning of '" << word << "' is: " << resultNode->getElem() << "\n";
        } else {
            cout << "This word not found!" << endl;
        }
    }

    //sua doi cac tu
    void modifyWord(){
        string word, newMeaning;
        cout << "Enter the English word to modify: ";
        cin.ignore();
        getline(cin, word);
        if(!dict.Contains(word, hashFunction)){
            cout << "This word not found!!" << endl;
            return;
        }
        cout << "Enter the new meaning: ";
        getline(cin, newMeaning);
        if (newMeaning.empty()) {
            cout << "Error: Meaning cannot be empty!" << endl;
            return;
        }
        dict.Remove(word, hashFunction);
        dict.Add(word, newMeaning, hashFunction);
        cout << "Word modified successfully! " << endl;

    }

    //them tu moi
    void insertWord(){
        string word, meaning;
        cout << "Enter the word to insert: ";
        cin.ignore();
        getline(cin, word);
        if(dict.Contains(word, hashFunction)){
            cout << endl <<  "Word already exists" << endl;
        }

        cout << "Enter the meaning of the word: ";
        getline(cin, meaning);
        dict.Add(word, meaning, hashFunction);
        cout << "\nWord added successfully\n";
    }

    //xoa tu
    void removeWord(){
        string word;
        cout << "Enter the word to delete: ";
        cin.ignore();
        getline(cin, word);
        if(!dict.Contains(word, hashFunction)){
            cout << endl << "Word not found" << endl;
            return;
        }
        dict.Remove(word, hashFunction);
        cout << "\nWord deleted successfully\n";
    }

    //luu tu dien vao file
     void saveToFile(string filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Unable to open file for saving." << endl;
            return;
        }

        cout << "Saving dictionary..." << endl;
        SingleList<string, string>* table = dict.getTable();
        for (int i = 0; i < dict.getSize(); i++) {  // Use the actual size of the hash table
            Node<string, string>* current = table[i].getHead();
            while (current != nullptr) {
                file << current->getKey() << " " << current->getElem() << endl;
                current = current->getNext();
            }
        }

        file.close();
        cout << "Dictionary saved to file successfully." << endl;
    }

};



