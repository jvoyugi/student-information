#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <cstdlib>
#include <cstring>
#include "StudentInfo.hpp"
using namespace std;
//Linked-list ADT
class SinglyLinkedList
{
  public:
    int size;
    //Node ADT
    typedef struct Node
    {
        //Element stored
        StudentInfo info;
        //Pointer to next node in the list
        struct Node *next;
    } node;

    class ListIsEmpty
    {
    };
    class ElementNotFound
    {
    };
    SinglyLinkedList()
    {
        size = 0;
    }
    //initialize head and tail
    node *header = NULL;
    node *trailer = NULL;

    StudentInfo last()
    {
        if (isEmpty())
        {
            throw ListIsEmpty();
        }
        return trailer->info;
    }

    //creates a new node and returns it
    node *create(StudentInfo student)
    {
        //Dynamically allocates memory for a node
        node *temp = new node[sizeof(node)];
        temp->info = student;
        temp->next = NULL;
        return temp;
    }
    //returns first element in the list
    StudentInfo first()
    {
        if (isEmpty())
        {
            throw ListIsEmpty();
        }
        return header->info;
    }
    //adds a node at the beginning of the list
    void insertFirst(node *temp)
    {
        temp->next = header;
        header = temp;
        trailer = temp;
        size++;
    }

    //appends a node at the end of the list
    void insertLast(node *temp)
    {

        node *last = header;
        if (!header)
        {
            header = temp;
            trailer = temp;
            return;
        }
        else
        {
            node *last = header;
            while (last->next)
            {
                last = last->next;
            }
            last->next = temp;
        }
        trailer = temp;
        size++;
    }

    //removes the first node and returns the element stored in the node
    StudentInfo removeFirst(StudentInfo &student)
    {
        if (isEmpty())
        {
            throw ListIsEmpty();
        }
        node *temp = NULL;
        student = header->info;
        temp = header;
        header = header->next;
        delete temp;
        size--;
        return student;
    }
    StudentInfo removeLast(StudentInfo &student)
    {
        if (isEmpty())
        {
            throw ListIsEmpty();
        }
        node *temp = NULL;
        student = trailer->info;
        temp = trailer;
        delete temp;
        size--;
        return student;
    }
    StudentInfo find(string admno)
    {
        bool found = false;
        if (isEmpty())
        {
            throw ListIsEmpty();
        }
        node *temp = header;
        while (temp->next)
        {
            if (strcmp(temp->info.getAdmissionNumber().c_str(), admno.c_str()) == 0)
            {
                found = true;
                return temp->info;
            }
            temp = temp->next;
        }
        if (found == false)
        {
            throw ElementNotFound();
        }
    }
    bool isEmpty()
    {
        bool status;
        if (size > 0)
        {
            status = false;
        }
        else
        {
            status = true;
        }
        return status;
    }
    int getSize()
    {
        return size;
    }
};

SinglyLinkedList lst;

#endif //SINGLYLINKEDLIST_H