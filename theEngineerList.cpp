#include "theEngineer.h"
#include "theEngineerList.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <limits>

using namespace std;



theEngineerList::theEngineerList() : headPtr(nullptr), count(0) {

}

theEngineerList::~theEngineerList() {
    Node* curr = headPtr;
    while (curr != nullptr) {
        Node* toDelete = curr;
        curr = curr->getNext();
        delete toDelete;
    }
}

bool theEngineerList::isEmpty() const {
    return headPtr == nullptr;
}

theEngineerList::theEngineerList(const theEngineerList& other) : headPtr(nullptr), count(0) {
    // deep-copy nodes from other preserving order
    if (other.headPtr == nullptr) return;
    // copy first node
    headPtr = new Node(other.headPtr->getEngineer());
    Node* destCurr = headPtr;
    Node* srcCurr = other.headPtr->getNext();
    count = 1;
    while (srcCurr != nullptr) {
        Node* newNode = new Node(srcCurr->getEngineer());
        destCurr->setNext(newNode);
        destCurr = newNode;
        srcCurr = srcCurr->getNext();
        count++;
    }
}


theEngineerList& theEngineerList::operator=(const theEngineerList& other) {
    if (this == &other) return *this;

    // clear existing list
    Node* curr = headPtr;
    while (curr != nullptr) {
        Node* toDelete = curr;
        curr = curr->getNext();
        delete toDelete;
    }
    headPtr = nullptr;
    count = 0;

    // copy from other (reuse copy ctor logic)
    if (other.headPtr == nullptr) return *this;
    headPtr = new Node(other.headPtr->getEngineer());
    Node* destCurr = headPtr;
    Node* srcCurr = other.headPtr->getNext();
    count = 1;
    while (srcCurr != nullptr) {
        Node* newNode = new Node(srcCurr->getEngineer());
        destCurr->setNext(newNode);
        destCurr = newNode;
        srcCurr = srcCurr->getNext();
        count++;
    }

    return *this;
}

bool theEngineerList::insert(const engineer& newEngineer) {

        Node* newNode = new Node(newEngineer);
        
        if (isEmpty()) {
            headPtr = newNode;
            count++;
            cout << "Engineer is first in the list";
            return true;
        }

        if (comesBefore(newEngineer, headPtr->getEngineer())) {

                 newNode->setNext(headPtr);
                headPtr = newNode;
                count++;

                return true;
        }
        Node* prev = headPtr;
        Node* curr = headPtr->getNext();

        while (curr != nullptr && comesBefore(curr->getEngineer(), newEngineer)) {
                prev = curr;
                curr = curr->getNext();
        }

        newNode->setNext(curr);
        prev->setNext(newNode);
        count++;

        cout << "Engineer was inserted alphabetically";
        return true;
    }



 bool theEngineerList::comesBefore(const engineer& a, const engineer& b) const {
        const char* A = a.getLastName();
        const char* B = b.getLastName();

        if (!A && !B ) return false;
        if (!A) return true;
        if (!B) return false;

        int comp = strcmp(A, B);
        if (comp<0) return true;
        if (comp>0) return false;

        const char* Af = a.getFirstName();
        const char* Bf = b.getFirstName();
        if (!A) return true;
        if (!B) return false;
        if (!A && !B) return false;

        return strcmp (A, B) < 0;
    }      



 void theEngineerList::printMission() {
    cout << " printMission is called and function is entered" << endl;
    Node* curr = headPtr;
    int index = 1;
    while (curr != nullptr) {
        
        const engineer& engineer = curr->getEngineer();
    cout << index++ << ") " 
     << engineer.getLastName()  << " " 
     << engineer.getFirstName() << " "
     << engineer::returnEngineerTitle(engineer.getTitle()) << " "
     << engineer.getAssesmentLevel() << endl;

         curr = curr->getNext();

    }
}


