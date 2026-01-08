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
            Node<T>* del_node = head->next;
            head->next = head->next->next;
            delete del_node;
        }
    }

    void pop_back(){
        Node<T>* p = head, *q = p->next;
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
        return false;
    }

    void print(){
        Node<T>* cur_node = head->next;
        if(cur_node == nullptr) cout<<"NULL"<<endl;
        else
        {
            while(cur_node)
            {
                cout<<cur_node->data<<" -> ";
                cur_node = cur_node->next;
            }
            cout<<"NULL"<<endl;;
        }
    }

    void insert(const int& index, const  T& val)
    {
        Node<T> *p = head, *new_node = new Node<T>(val);
        for(int i=0;i<index;i++)
        {
            p = p->next;
        }
        new_node -> next = p -> next;
        p ->next = new_node;

    }

    // remove the index node

    void remove_at(const int& index)
    {
        auto p = head;
        for(int i=0;i<index;i++)
        {
            p = p ->next;
        }
        auto q= p->next;
        p->next = q->next;
        delete q;
    }

    // reverse the list

    void reverse()
    {
        if(head->next==nullptr||head->next->next==nullptr) return;
        Node<T> *pre=nullptr,*cur=head->next,*next=nullptr;
        while(cur!=nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = pre;
    }

    //fid the middle element of list
    T get_middle()
    {
        auto fast=head,slow=head;
       if(head->next == nullptr) 
       {
            cout<<"there is none element.";
            return T();
       }

       if(head->next->next==nullptr) 
        return head->next->data;
       
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
            if(fast) fast = fast->next;
            else break;
        }

        return slow->data;

    }



};


#endif