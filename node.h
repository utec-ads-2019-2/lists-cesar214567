#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T value):data(value),next(nullptr),prev(nullptr){};
    void killSelf() {
        if (this->next!=nullptr){
            this->next->killSelf();
            delete this;
        }else{
            delete this;
        }
    }
};

#endif