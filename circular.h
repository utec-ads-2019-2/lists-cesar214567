#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

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
                this->nodes++;
            }else{
                temp->next=this->head;
                (this->head)->prev=temp;
                this->head=temp;
                this->head->prev=this->tail;
                this->tail->next=this->head;
                this->nodes++;
            }
        }

        void push_back(T value) {
            Node<T> *temp=new Node<T>(value);
            if(this->head==nullptr){
                this->head=temp;
                this->tail=temp;
                this->nodes++;
            }else{
                this->tail->next=temp;
                temp->prev=this->tail;
                this->tail=temp;
                this->tail->next=this->head;
                this->head->prev=this->tail;
                this->nodes++;
            }
        }

        void pop_front() {
            if(this->head==nullptr){
                throw out_of_range("out of range");
            }else{
                Node<T> *temp=(this->head)->next;
                Node<T> *temp2=this->head;
                temp->prev=nullptr;
                this->head=temp;
                this->nodes--;
                this->tail->next=this->head;
                this->head->prev=this->tail;
                delete temp2;
            }
        }

        void pop_back() {
            if(this->tail==nullptr){
                throw out_of_range("out of range");
            }else{
                Node<T> *temp=(this->tail->prev);
                Node<T> *temp2=(this->tail);
                temp->next=nullptr;
                this->tail=temp;
                this->nodes--;
                this->tail->next=this->head;
                this->head->prev=this->tail;
                delete temp2;
            }
        }

        T operator[](int index) {
            if (index>this->nodes-index){
                Node<T> *temp=this->head;
                for (int i=0;i<=index-1;i++){
                    temp=temp->next;
                }
                return temp->data;
            }else{
                Node<T> *temp=this->tail;
                for (int i=0;i<this->nodes-(index+1);i++){
                    temp=temp->prev;
                }
                
                return temp->data;
            }
            
        }

        bool empty() {
            return !this->nodes;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            auto temp=this->tail;
            while(temp!=this->head){
                temp->next=nullptr;
                auto temp2=temp->prev;
                delete temp;
                temp=temp2;
            }
            delete this->head;
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
            LinkedList<T> temp;
            Node<T> *node_temporal=this->tail;
            for (int i=0;i<this->nodes;i++){
                temp.push_back(node_temporal->data);
                node_temporal=node_temporal->prev;
            }
            this->clear();
            for (int i=0;i<temp.size();i++){
                this->push_back(temp[i]);
                
            }
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            return {this->head};
        }

	    BidirectionalIterator<T> end() {
            return {this->tail};
        }

        void merge(CircularLinkedList<T> list) {
            for (int i=0;i<list.size();i++){
                this->push_back(list[i]);
            }
        }
};

#endif