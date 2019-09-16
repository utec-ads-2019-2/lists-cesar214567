#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class ForwardIterator : public Iterator<T> {
    public:
        ForwardIterator() : Iterator<T>() {};
        ForwardIterator(Node<T> *node) : Iterator<T>(node) {};

        ForwardIterator<T> operator=(ForwardIterator<T> other) {
            this->current=other->current;
            return *this;
        }

        bool operator!=(ForwardIterator<T> other) {
            // Podría ser una línea
            if (this->current==other.current){
                return false;
            }else{
                return true;
            }
        }

        ForwardIterator<T> operator++() {
            // temporal? Este es el ++it, no el it++
            auto temporal=this->current;
            this->current=this->current->next;
            return temporal;
            
        }

        T operator*() {
            // Caso vacío?
            return this->current->data;
        }
};

#endif