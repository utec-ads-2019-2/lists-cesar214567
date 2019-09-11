#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"
#include <iostream>
using namespace std;


template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
            this->current=other->current;
            return *this;
        }

        bool operator!=(BidirectionalIterator<T> other) {
            if (this->current!=other.current){
                return true;
            }else{
                return false;
            }
        }

        BidirectionalIterator<T> operator++() {
            if (this->current->next!=nullptr){
                //auto temporal=this->current;
                this->current=this->current->next;

                return (*this);
            }else{
                //throw out_of_range("out of range");
            }
            return *this;
        }

        BidirectionalIterator<T> operator--() {
            if (this->current->prev!=nullptr ){
                this->current=this->current->prev;
            }else{
                //throw out_of_range("out of range");
                //return *this;
            }
            return *this;
        }

        T operator*() {
            if (this->current==nullptr){
                //throw out_of_range("pointer is pointing to null");
            }
            return this->current->data;
        }
};

#endif