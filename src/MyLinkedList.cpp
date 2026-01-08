#include"MyLinkedList.hpp"
#include<iostream>

using namespace std;

int main()
{
    MyLinkedList<int> l;
    bool a = l.IsEmpty();
    cout<<"l is " << a << "empty"<<endl;

    for(int i=0;i<10;i++)
    {
        l.push_back(i);
    }
    l.print();

    l.reverse();
    cout<<"list had been reversed!"<<endl;
    l.print();


    return 0;
}