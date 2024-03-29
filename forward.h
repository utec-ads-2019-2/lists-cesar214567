#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"


template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            if (this->head==nullptr){
                throw out_of_range("error 404, head not found");
            }
            return (this->head)->data;
        }

        T back() {
            if (this->tail==nullptr){
                throw out_of_range("error 404, tail not found");
            } 
            return (this->tail)->data;
        }

        void push_front(T value) {
            Node<T> *temp=new Node<T>(value);
            if (this->head==nullptr){
                this->head=temp;
                this->tail=temp;
                // Está línea se repite en el else, podría evitarse
                this->nodes++;
            }else{
                temp->next=this->head;
                this->head=temp;
                this->nodes++;
            }
        }

        void push_back(T value) {
            Node<T> *temp=new Node<T>(value);
            if(this->head==nullptr){
                this->head=temp;
                this->tail=temp;
                // Está línea se repite en el else, podría evitarse
                this->nodes++;
            }else{
                this->tail->next=temp;
                this->tail=temp;
                this->nodes++;
            }
            
        }

        void pop_front() {
            // No es necesario en el caso del pop
            if(this->head==nullptr){
                throw out_of_range("out of range");
            }else{
                Node<T> *temp=this->head;
                this->head=this->head->next;
                this->nodes--;
                delete temp;
            }
        }

        void pop_back() {
            // No es necesario en el caso del pop
            if(this->tail==nullptr){
                throw out_of_range("out of range");
            }else{
                Node<T> *temp=(this->head);
                while (temp->next!=this->tail){
                    temp=temp->next;
                }
                Node<T> *temp2=(this->tail);
                this->tail=temp;
                temp->next=nullptr;
                this->nodes--;
                delete temp2;
                
            }
        }

        T operator[](int index) {
            // Si índice es negativo?
            if (index>=this->nodes){
                throw out_of_range("out of range");
            }
            Node<T> *temp=this->head;
            for (int i=0;i<index;i++){
                temp=temp->next;
            }
            return temp->data;
        }

        bool empty() {
            // Podría ser una línea return !this->head;
            if (this->nodes==0){
                return true;
            }else{
                return false;
            }
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->head->killSelf();
            this->head=nullptr;
            this->tail=nullptr; 
            this->nodes=0;
        }

        void sort() {
            int temporal=this->nodes;
            T *elements=new T[this->nodes];
            for (int i=0;i<temporal;i++){
                elements[i]=(*this)[i];
                
            }
            mergesort(elements,0,this->nodes-1);
            this->clear();
            for(int i=0;i<temporal;i++){
                this->push_back(elements[i]);
            }   
        }
    
        void reverse() {
            // No es tan eficiente
            T temp[this->nodes];
            int cantidad=this->nodes;
            for (int i=this->nodes-1;i>=0;i--){
                temp[i]=(*this)[3-i];
            }
            this->clear();
            for (int i=0;i<cantidad;i++){
                this->push_back(temp[i]);
            }
            
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            return {this->head};
        }

	    ForwardIterator<T> end() {
            // Es el siguiente del final
            return {this->tail};
        }

        void merge(ForwardList<T> list) {
            for (int i=0;i<list.nodes;i++){
                this->push_back(list[i]);
            }



        }
};

#endif