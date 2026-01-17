#ifndef MYLINKEDLIST_HPP
#define MYLINKEDLIST_HPP

#include<iostream>
#include<stdexcept>

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
        size = 0;
    }

    MyLinkedList(const MyLinkedList& other)
    {
        head = new Node<T>(0);
        size =0;

        if (other.head->next == nullptr) return;

        auto src_node = other.head->next;
        auto dest_node = head;

        while(src_node)
        {
            auto new_node = new Node<T>(src_node->data);
            dest_node->next = new_node;

            dest_node = new_node;
            src_node = src_node->next;

            size++;
        }
    }

    MyLinkedList& operator=(const MyLinkedList& other)
    {
        if(this != &other)   //judge whether "other" is equal itself object，自赋值问题，所以比较两个指针是否指向同一个位置

        {
            auto current_node = head->next;//delete itself
            while(current_node != nullptr)
            {
                auto next_node = current_node->next;
                delete current_node;
                current_node =next_node;
            }
            head->next = nullptr;
            

            auto p = other.head->next, q = this->head;
            while(p)
            {
                auto new_node = new Node<T>(p->data);
                q->next = new_node;
                q = new_node;
                p = p->next;
            }
            size = other.size;
        }

        return *this;

    }

    ~MyLinkedList(){
        auto current_node = head;
        while(current_node != nullptr)
        {
            delete current_node;
            Node<T>* next_node = current_node->next;
            current_node = next_node;
        }
        
    }

    const bool IsEmpty()const {
        return size==0;
    }

    const int GetSize()const{
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
        size++;
    }

    void pop_front(){
        if(head->next){
            Node<T>* del_node = head->next;
            head->next = head->next->next;
            delete del_node;
            size--;
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
            size--;
        }
        
    }

    bool find(const T& val)const{
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
        if(index<0||index>size) 
        {
            cout << "insert false!---index is not in correct size!" <<endl;
            return;
        }
        Node<T> *p = head, *new_node = new Node<T>(val);
        for(int i=0;i<index;i++)
        {
            p = p->next;
        }
        new_node -> next = p -> next;
        p ->next = new_node;
        size++;

    }

    // remove the index node

    void remove_at(const int& index)
    {
        if(index<0||index>size) 
        {
            cout << "remove_at false!---index is not in correct size!" <<endl;
            return;
        }
        auto p = head;
        for(int i=0;i<index;i++)
        {
            p = p ->next;
        }
        auto q= p->next;
        p->next = q->next;
        delete q;
        size--;
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
            if(fast) {fast = fast->next;
            slow = slow->next;}
            else break;
        }

        return slow->data;

    }

    T& front(){
        if(IsEmpty()){
            throw std::runtime_error("List is empty");
        }
        return head->next->data;
    }

    const T& front()const{
        if(IsEmpty()){
            throw std::runtime_error("List is empty");
        }
        return head->next->data;
    }


};


#endif