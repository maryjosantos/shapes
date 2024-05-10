/*-------------------------------------------
   File: canvaslist.cpp
   Course: CS 251, Fall 2023, UIC
   Author: MaryJo Santos
   Description: implemeted canvaslist functions that were defined in canvaslist.h
  ------------------------------------------- */

#include <iostream>
#include "canvaslist.h"

using namespace std;

// default constructor
CanvasList::CanvasList() {
    listSize = 0;
    listFront = nullptr;
}

// copy constuctor
CanvasList::CanvasList(const CanvasList& cList) {
    listSize = cList.listSize;
    listFront = new ShapeNode;
    *listFront = *(cList.listFront);
}

// copy assignment operator
CanvasList& CanvasList::operator=(const CanvasList& cList) {
    if (this != &cList) {
        delete listFront;
        listFront = new ShapeNode;
        *listFront = *(cList.listFront);
    }

    return *this;
}

// destructor
CanvasList::~CanvasList() {
    clear();
}

// clears entire canvaslist
void CanvasList::clear() {
    for (int i = 0; i < listSize; i++) {
        delete pop_front();
    }

    listSize = 0;
    listFront = nullptr;
}

// inserts shape after given index
void CanvasList::insertAfter(int ind, Shape* s) {
    if (ind < listSize && !(ind < 0)) {
        ShapeNode* addShape = new ShapeNode;
        addShape->value = s;

        ShapeNode* currShape = listFront;
        for (int i = 0; i < ind; i++) {
            currShape = currShape->next;
        }

        addShape->next = currShape->next;
        currShape->next = addShape;

        listSize++;
    }
}

// adds shape to front of canvaslist
void CanvasList::push_front(Shape* s) {
    ShapeNode* addShape = new ShapeNode;

    addShape->value = s;
    addShape->next = listFront;
    listFront = addShape;

    listSize++;
}

// adds shape to back of canvaslsit
void CanvasList::push_back(Shape* s) {
    ShapeNode* addShape = new ShapeNode;
    addShape->value = s;
    addShape->next = NULL;

    if (isempty()) {  // checks if listFront is the one that has to be modified
        listFront = addShape;
    }
    else {
        ShapeNode* currShape = listFront;
        while (currShape->next != NULL) {
            currShape = currShape->next;
        }
    
        currShape->next = addShape;
    }

    listSize++;
}

// removes shape at index from canvaslist
void CanvasList::removeAt(int ind) {
    if (ind < listSize && !(ind < 0)) {   // checks if index is in bounds
        ShapeNode* currShape = listFront;
        ShapeNode* prevShape = NULL;
        for (int i = 0; i < ind; i++) {
            prevShape = currShape;
            currShape = currShape->next;
        }

        if (listSize == 1) {   // determines if list becomes empty
            listFront = NULL;
        }
        else if (ind == 0) {   // checks if listfront has to change
            listFront = currShape->next;
        }
        else {
            prevShape->next = currShape->next;
        }

        listSize--;
        delete(currShape->value);
        delete(currShape);
    }
}

// removes every other shape starting at index 1
void CanvasList::removeEveryOther() {
    ShapeNode* currShape = listFront->next;
    ShapeNode* temp = new ShapeNode;
    ShapeNode* prevShape = listFront;
    int size = listSize;

    for (int i = 1; i < listSize; i += 2) {
        temp = currShape;
        prevShape->next = currShape->next;

        if (currShape->next == NULL) {
            currShape = NULL;
        }
        else {
            currShape = currShape->next->next;
            prevShape = prevShape->next;
        }

        delete(temp->value);
        delete(temp);
        size--;
    }

    listSize = size;
}

// removes shape from front of canvaslist
// returns: pointer to shape that was removed
Shape* CanvasList::pop_front() {
    if (isempty()) {
        return nullptr;
    }

    ShapeNode* currShape = listFront;
    listFront = currShape->next;

    Shape* ptr = currShape->value;
    listSize--;
    delete(currShape);

    return ptr;
}

// removes shape from back of canvaslist
// returns: pointer to shape that was removed
Shape* CanvasList::pop_back() {
    if (isempty()) {
        return nullptr;
    }

    ShapeNode* currShape = listFront;
    ShapeNode* prevShape = NULL;
    while (currShape->next != NULL) {
        prevShape = currShape;
        currShape = currShape->next;
    }

    Shape* ptr = currShape->value;
    if (listSize == 1) {
        listFront = NULL;
    }
    else {
        prevShape->next = NULL;
    }

    listSize--;
    delete(currShape);

    return ptr;
}

// returns: front shape in canvaslist
ShapeNode* CanvasList::front() const {
    return listFront;
}

// returns: boolean value of whether canvaslist is empty or not
bool CanvasList::isempty() const {
    return (listSize == 0);
}

// returns: integer of canvaslist size
int CanvasList::size() const {
    return listSize;
}

// returns: index of first shape found at (x, y)
int CanvasList::find(int x, int y) const {
    ShapeNode* currShape = listFront;

    for (int i = 0; i < listSize; i++) {
        if (currShape->value->getX() == x && currShape->value->getY() == y) {
            return i;
        }

        currShape = currShape->next;
    }

    return -1;
}

// finds shape in canvaslist at index
// returns: pointer to shape found or nullptr if out of range
Shape* CanvasList::shapeAt(int ind) const {
    if (ind < listSize && !(ind < 0)) {
        ShapeNode* currShape = listFront;
        for (int i = 0; i < ind; i++) {
            currShape = currShape->next;
        }

        return currShape->value;
    }

    return nullptr;
}
        
// prints out 'stats' of all the shapes in canvaslist
void CanvasList::draw() const {
    ShapeNode* currShape = listFront;
    for (int i = 0; i < listSize; i++) {
        cout << currShape->value->printShape() << endl;
        currShape = currShape->next;
    }
}

// prints memory address of each node and the shape stored in it
void CanvasList::printAddresses() const {
    // prints out memory address of internal shape
    ShapeNode* currShape = listFront;
    for (int i = 0; i < listSize; i++) {
        cout << "Node Address: " << currShape << "	Shape Address: " << currShape->value << endl;
        currShape = currShape->next;
    }
}
