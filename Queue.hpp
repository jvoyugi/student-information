#ifndef QUEUE_H
#define QUEUE_H
#include "SinglyLinkedList.hpp"
#include "StudentInfo.hpp"
#include <iostream>
using namespace std;
//Queue ADT
struct Queue
{
  //SinglyLinkedList lst;

  //inserts a node at the rear
  void enqueue(StudentInfo element)
  {
    SinglyLinkedList::node *info = lst.create(element);
    lst.insertLast(info);
  }

  //removes the node at the top
  //and returns the element stored in it
  StudentInfo dequeue()
  {
    StudentInfo student;
    return lst.removeFirst(student);
  }

  StudentInfo seek(string admno)
  {
    return lst.find(admno);
  }
};
#endif //QUEUE_H