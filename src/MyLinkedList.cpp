#include"MyLinkedList.hpp"
#include<iostream>

using namespace std;

int main()
{
    MyLinkedList<int> l;
    bool a = l.IsEmpty();
    cout<<"l is " << a << "empty"<<endl;


    return 0;
}