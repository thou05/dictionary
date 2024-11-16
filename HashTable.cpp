#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP
#include "SList.cpp"

template<class Keys, class T>
class HashTable{
    private:
        int m;
        SingleList<Keys, T> *table;
    public:
        HashTable() : m(0), table(nullptr) {}
        HashTable(int n) : m(n), table(new SingleList<Keys, T>[m]) {}
        ~HashTable(){
            delete[] table;
        }
        
        int getSize() {
            return m;
        }

        SingleList<Keys, T> *getTable(){
            return table;
        }

        Node<Keys, T>* Add(Keys key, T e, int (*hash)(Keys, int)) {
            int h = hash(key, m);
            Node<Keys, T>* p = table[h].getNode(key);
            if (p == NULL) {
                return table[h].pushback(key, e);
            }
            return NULL;
        }

        void Remove(Keys key, int (*hash)(Keys, int)) {
            int h = hash(key, m);
            Node<Keys, T>* p = table[h].getNode(key);
            if (p != NULL) {
                table[h].remove(p);
            }
        }

        Node<Keys, T> *Find(Keys key, int (*hash)(Keys, int)){
            int h = hash(key, m);
            return table[h].getNode(key);
        }

        bool Contains(Keys key, int (*hash)(Keys, int)){
            int h = hash(key, m);
            return table[h].getNode(key) != NULL;
        }

        int Count(){
            int t = 0;
            for(int i = 0; i < m; i++){
                t = t + table[i].size();
            }
            return t;
        }
};


#endif
