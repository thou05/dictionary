#ifndef SINGLELIST_CPP
#define SINGLELIST_CPP

#include <bits/stdc++.h>
#include "Node.cpp"
using namespace std;

template<class Keys, class T>
class SingleList{
    private:
        Node<Keys, T> *header;
        Node<Keys, T> *trailer;
        long sz;
    public:
        SingleList() : header(NULL), trailer(NULL), sz(0) {}
        ~SingleList() {
            while (header != nullptr) {
                Node<Keys, T>* temp = header;
                header = header->getNext();
                delete temp;
            }
        }
        
        long size(){
            return sz;
        }
        int isEmpty(){
            return sz == 0;
        }

        Node<Keys, T>* getHead(){
            return header;
        }

        Node<Keys, T>* getNode(Keys k) {
            Node<Keys, T>* p = header;
            while (p != NULL && p->getKey() != k) {
                p = p->getNext();
            }
            return p;
        }

        Node<Keys, T>* pushback(Keys k, T e) {
            Node<Keys, T>* q = new Node<Keys, T>;
            q->setKey(k);
            q->setElem(e);
            if (header == NULL) {
                header = q;
                trailer = q;
            } else {
                trailer->setNext(q);
                trailer = q;
            }
            sz++;
            return q;
        }
        
        void replace(Node<Keys, T> *p, Keys k, T e){
            p->setKey(k);
            p->setElem(e);
        }
        void remove(Node<Keys, T> *p){
            Node<Keys, T> *p1;
            if(p == header){
                if(size() == 1){
                    header = NULL;
                    trailer = NULL;
                }else{
                    header = header->getNext();
                }
                sz--;
            }else{
                p1 = header;
                while(p1->getNext() != p){
                    p1 = p1->getNext();
                }
                if(p1 != NULL){
                    if(p != trailer){
                        p1->setNext(p->getNext());
                    }else{
                        trailer = p1;
                        p1->setNext(NULL);
                    }
                    sz--;
                }
            }
            delete p;
        }
        
};

#endif