
// ------------------------------------------------ NDLList.cpp -------------------------------------------------------

// Giselle McNeill CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date 4/5/26

// Date of Last Modification 4/8/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose: Implements a singly linked list using only a head pointer (no dummy header)
//          Standard Linked List operations are included: insert(), remove(), retrieve(), find(), size(), isEmpty()
//          , clear() along with a constructor, destructor, copy constructor, and assignment operator
// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------


#include "NDLList.h"


// ------------------------------------Constructor-----------------------------------------------
// Description:

// Constructor: Constructs an empty singly linked list
// preconditions: None
// postconditions: List is initialized, head pointer initialized to nullptr
//isEmpty will return true, and size will be 0
// --------------------------------------------------------------------------------------------
template <class Object>
NDLList<Object>::NDLList() {
    head = nullptr;
}
//end of constructor


// ------------------------------------ Copy Constructor-----------------------------------------------
// Description:

// Copy Constructor: Creates a deep copy of another NDLList
// preconditions: rhs is a valid NDLList
// postconditions: This list contains the same elements as rhs in the same order
// Two lists now exist: the original (rhs) and the newly created one
// --------------------------------------------------------------------------------------------
template <class Object>
NDLList<Object>::NDLList(const NDLList &rhs) {
    head = nullptr;
    *this = rhs;
}
//end of copy constructor


// ------------------------------------Destructor-----------------------------------------------
// Description:

// Destructor: Deallocates all nodes and deletes the list safely by calling clear()
// preconditions: List is initialized and contains nodes
// postconditions: All nodes are deleted, the list no longer exists/can be used
// head is reset to nullptr
// --------------------------------------------------------------------------------------------
template <class Object>
NDLList<Object>::~NDLList() {
    clear(); //delete items
    head = nullptr; //reset head
}
//end of destructor


// ------------------------------------isEmpty()-----------------------------------------------
// Description:

// isEmpty(): Checks whether the list has any elements
// preconditions: List is initialized
// postconditions: Returns true if head is nullptr, otherwise returns false
// --------------------------------------------------------------------------------------------
template <class Object>
bool NDLList<Object>::isEmpty() const {
    return head == nullptr;
}
//end of isEmpty()


// ------------------------------------size()-----------------------------------------------
// Description:

// size(): traverse the list and count the number of nodes in the list
// preconditions: List is initialized
// postconditions: Returns the number of nodes currently in the list

// --------------------------------------------------------------------------------------------
template <class Object>
int NDLList<Object>::size() const {
    int size = 0;

    LListNode<Object>* current = head;

    while (current != nullptr) {
        size++;
        current = current -> next;
    }
    return size;
}
//end of size()


// ------------------------------------clear()-----------------------------------------------
// Description:

// clear(): delete all nodes in the list
// preconditions: List is initialized and contains nodes
// postconditions: List is empty, all nodes are deleted,
// head is reset to nullptr
// --------------------------------------------------------------------------------------------
template <class Object>
void NDLList<Object>::clear() {

    LListNode<Object>* current = head;
    while (current != nullptr) {
        LListNode<Object>* temp = current;
        current = current -> next;
        delete temp;
    }
    head = nullptr;
}
//end of clear


// ------------------------------------insert()-----------------------------------------------
// Description:

// insert(): Insert new node containing the passed in object at the specified index(0-based)
// preconditions: 0 <= index <= size(), and list is initialized
// postconditions: A new node is inserted at index, nodes following are shifted right
// Size will also increase by 1
// --------------------------------------------------------------------------------------------
template <class Object>
void NDLList<Object>::insert(const Object& obj, const int index) {

    if (index < 0 || index > size()) {
        return;
    }

    //Special case: Insertion is at index 0
    if (index == 0) {
        LListNode<Object>* newNode = new LListNode<Object>();
        newNode -> item = obj;
        newNode -> next = head;
        head = newNode;
        return;
    }

    //Find the node before the insertion position
    LListNode<Object>* previous = head;
    for (int i = 0; i < index - 1; i++) {
        previous = previous -> next;
    }

    //Insert the new node
    LListNode<Object>* newNode = new LListNode<Object>();
    newNode -> item = obj;
    newNode -> next = previous -> next;
    previous -> next = newNode;
}
//end of insert()


//------------------------------------find()-----------------------------------------------
// Description:

// find(): Searches for passed in obj(Object) in the list and returns index
// preconditions: List is initialized, may find obj
// postconditions: Returns index (0-based) of the first occurrence of obj,
// otherwise returns -1 if obj not found, list is unchanged
// --------------------------------------------------------------------------------------------
template <class Object>
int NDLList<Object>::find(const Object& obj)const {

    LListNode<Object>* current = head;
    int index = 0;

    while (current != nullptr) {
        if (current -> item == obj) {
            return index;
        }
        current = current -> next;
        index++;
    }
    return -1;
}
//end of find()


//------------------------------------remove()-----------------------------------------------
// Description:

// remove(): Removes the first occurrence of the node containing obj
// preconditions: List is initialized, may contain obj
// postconditions: Deletes the first occurrence of the node containing obj from the list,
// size decreases by one, list remains intact
// --------------------------------------------------------------------------------------------
template <class Object>
void NDLList<Object>::remove(const Object &obj) {

    //Check if head is empty
    if (head == nullptr) {
        return;
    }

    //Edge Case: remove head safely
    if (head -> item == obj) {
        LListNode<Object>* temp = head;
        head = head -> next;
        delete temp;
        return;
    }

    LListNode<Object>* current = head;

    //Iterate through list to stop at node before removal
    while (current -> next != nullptr) {
        if (current -> next -> item == obj) {
            LListNode<Object>* temp = current -> next;
            current -> next = temp -> next;
            delete temp;
            return;
        }else {
            current = current -> next;
        }
    }
}
//end of remove()


// ------------------------------------retrieve()-----------------------------------------------
// Description:

// retrieve(): Returns the object stored at the passed in index (0-based)
// preconditions: 0 <= index <= size(), list is initialized
// postconditions: Returns the object at specified index, list remains unchanged
// --------------------------------------------------------------------------------------------
template <class Object>
Object NDLList<Object>::retrieve(const int index) const {

    if (index < 0 || index >= size()) {
        return Object();
    }

    LListNode<Object>* current = head;
    int i = 0;

    while (current != nullptr && i < index){
        current = current -> next;
        i++;
    }
    if (current == nullptr) {
        return Object(); //out of bounds
    }
    return current -> item;
}
//end of retrieve()


// ------------------------------------Assignment Operator-----------------------------------------------
// Description:

// Assignment Operator: Assigns contents of list rhs to this list using a deep copy
// preconditions: rhs is a valid CDLList, list is initialized
// postconditions: this list contains a deep copy of rhs; previous data nodes in this list are deleted
// --------------------------------------------------------------------------------------------
template<class Object>
const NDLList<Object>& NDLList<Object>::operator=(const NDLList<Object> &rhs) {

    if (this == &rhs) { //avoid self assignment
        return *this;
    }

    clear();//deallocate old items

    LListNode<Object>* current = rhs.head;
    int index = 0;

    while (current != nullptr) {
        insert(current -> item, index);
        index++;
        current = current -> next;
    }
    return *this;
}
//end of assignment operator


