#ifndef NODE_CPP
#define NODE_CPP

template <class Keys, class T>
class Node{
    private:
        Keys key;
        T elem;
        Node<Keys, T> *next;
    public:
        Node(): next(0) {}
        ~Node() {
            next = NULL;
        }
        Keys getKey(){
            return key;
        }
        void setKey(Keys k){
            key = k;
        }
        Node<Keys, T> *getNext(){
            return next;
        }
        void setNext(Node<Keys, T> *p){
            next = p;
        }
        T getElem(){
            return elem;
        }
        void setElem(T e){
            elem = e;
        }
};

#endif