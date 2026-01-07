#ifndef MYLINKEDLIST_HPP
#define MYLINKEDLIST_HPP

#include<iostream>

template<typename T>
struct Node{
    T data;
    Node* next;
    Node(T val):data(val),next(nullptr){} 
};

template<typename T>
class MyLinkedList{
private:
    Node<T>* head;
    int size;

public:
    MyLinkedList(): head(nullptr), size(0){}

    ~MyLinkedList(){
        auto current_node = head;
        while(current_node != nullptr)
        {
            Node<T>* next_node = current_node->next;
            delete current_node;
            current_node = next_node;

        }
        
    }

    bool IsEmpty(){
        return size==0;
    }

    int GetSize(){
        return this->size;
    }

};


#endif