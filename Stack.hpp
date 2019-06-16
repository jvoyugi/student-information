#ifndef STACK_H
#define STACK_H
#include "StudentInfo.hpp"
#include "SinglyLinkedList.hpp"
using namespace std;
//Stack ADT
struct Stack
{
    //inserts a node at the top
    void push(StudentInfo element)
    {
        SinglyLinkedList::node *info = lst.create(element);
        lst.insertFirst(info);
    }
    //removes the node at the top
    //and returns the element stored in it
    StudentInfo pop()
    {
        StudentInfo student;
        return lst.removeFirst(student);
    }
    StudentInfo seek(string admno)
    {
        return lst.find(admno);
    }
};
#endif // STACK_H