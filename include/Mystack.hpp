#ifndef MYSTACK_HPP
#define MYSTACK_HPP

#include"MyLinkedList.hpp"
#include<stdexcept>

template<typename T>
class MyStack{
private:
    MyLinkedList<T> container;

public:

    MyStack() = default;

    ~MyStack() = default;

    MyStack(const MyStack& other) : container(other.container) {}

    MyStack& operator=(const MyStack& other)
    {
        if(this != other){
            container = other.container;
        }
        return *this;
    }

    void push(const T& val)
    {
        container.push_front(val);
    }

    void pop()
    {
        if(empty()){
            return;
        }
        container.pop_front();
    }

    T& top()
    {
        return container.front();
    }

    const T& top() const{

        return container.front();
    }

    bool empty() const{
        return this->container.IsEmpty();
    }

    int size()const{
        return container.GetSize();
    }




};



#endif