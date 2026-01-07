#ifndef MYLINKEDLIST_HPP
#define MYLINKEDLIST_HPP

#include<iostream>

using namespace std;

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
    MyLinkedList(){
        auto node = new Node<T>(0);
        head = node;
    }

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

    void push_front(const T& val){
        Node<T>* new_node  = new Node<T>(val);
        new_node->next = head->next;
        head->next = new_node;
        size++;
    }

    void push_back(const  T& val){
        Node<T>* cur_node = head;
        while(cur_node->next != nullptr) cur_node = cur_node->next;
        Node<T>* new_node = new Node<T>(val);
        cur_node->next = new_node;
    }

    void pop_front(){
        if(head->next){
            Node<int>* del_node = head->next;
            head->next = head->next->next;
            delete del_node;
        }
    }

    void pop_back(){
        Node<T>* p = head, q = p->next;
        if(head->next)
        {
            while(q->next!=nullptr)
            {
                p = q;
                q = q->next;
            }
            p->next = nullptr;
            delete q;
        }
    }

    bool find(const T& val){
        Node<T>* node = head->next;
        while(node)
        {
            if(node->data==val) return true;
            node = node->next;
        }
    }

    void print(){
        Node<T>* cur_node = head->next;
        if(cur_node == nullptr) cout<<"NULL";
        else
        {
            while(cur_node->next)
            {
                print<<cur_node->data<<" -> ";
                cur_node = cur_node->next;
            }
            cout<<"NULL";
        }
    }
    


};


#endif