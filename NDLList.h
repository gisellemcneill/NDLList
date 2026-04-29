// ------------------------------------------------ NDLList.h -------------------------------------------------------

// Giselle McNeill CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date 4/5/26

// Date of Last Modification 4/8/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the NDLList template class, which implements a singly linked list without a dummy header node
// This list uses only a head pointer, and traversal only moves in one direction (forward)
// from the head to nullptr, which marks the end of the list

// This class supports all standard linked list operations: insert(), remove(), retrieve(), find()
// size(), clear(), isEmpty(), copy constructor, constructor, destructor, and an assignment operator

// This class represents a traditional linked list implementation and will be compared against
// a circular doubly linked list with a dummy header

// -------------------------------------------------------------------------------------------------------------------- /

// --------------------------------------------------------------------------------------------------------------------


#ifndef CSS343PROGRAM1_NDLLIST_H
#define CSS343PROGRAM1_NDLLIST_H
#include <iostream>
using namespace std;

template <class Object>
struct LListNode { // Declaring the node object that will be used
    Object item;
    LListNode* next;
};

template <class Object>
class NDLList {
public:
    NDLList(); //Constructor, set head = nullptr
    NDLList(const NDLList &rhs); //Copy Constructor
    ~NDLList(); //Destructor
    bool isEmpty() const; //Check if the list is empty

    int size() const; //Number of nodes inside the List
    void clear(); //Remove all nodes

    //Insert at data index (0-based)
    //Index == 0, inserts at the head of the list
    void insert(const Object &obj, const int index);
    int find(const Object &obj) const; //Return index or -1 if not found
    void remove(const Object &obj); //Remove first occurence of object
    Object retrieve(const int index) const; //Retrieve the data at index

    const NDLList& operator=(const NDLList &rhs); //Assignment Operator

private:
    //First real node(no dummy header)
    LListNode<Object>* head;


};
#include "NDLList.cpp"
#endif //CSS343PROGRAM1_NDLLIST_H