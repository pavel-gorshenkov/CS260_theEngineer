#include "theEngineer.h"
#include "theEngineerList.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <limits>

using namespace std;

theEngineerList::theEngineerList() : headPtr(nullptr), count(0)
{
}

theEngineerList::~theEngineerList()
{
    Node *curr = headPtr;
    while (curr != nullptr)
    {
        Node *toDelete = curr;
        curr = curr->getNext();
        delete toDelete;
    }
}

bool theEngineerList::isEmpty() const
{
    return headPtr == nullptr;
}

theEngineerList::theEngineerList(const theEngineerList &other) : headPtr(nullptr), count(0)
{
    // deep-copy nodes from other preserving order
    if (other.headPtr == nullptr)
        return;
    // copy first node
    headPtr = new Node(other.headPtr->getEngineer());
    Node *destCurr = headPtr;
    Node *srcCurr = other.headPtr->getNext();
    count = 1;
    while (srcCurr != nullptr)
    {
        Node *newNode = new Node(srcCurr->getEngineer());
        destCurr->setNext(newNode);
        destCurr = newNode;
        srcCurr = srcCurr->getNext();
        count++;
    }
}

theEngineerList &theEngineerList::operator=(const theEngineerList &other)
{
    if (this == &other)
        return *this;

    // clear existing list
    Node *curr = headPtr;
    while (curr != nullptr)
    {
        Node *toDelete = curr;
        curr = curr->getNext();
        delete toDelete;
    }
    headPtr = nullptr;
    count = 0;

    if (other.headPtr == nullptr)
        return *this;
    headPtr = new Node(other.headPtr->getEngineer());
    Node *destCurr = headPtr;
    Node *srcCurr = other.headPtr->getNext();
    count = 1;
    while (srcCurr != nullptr)
    {
        Node *newNode = new Node(srcCurr->getEngineer());
        destCurr->setNext(newNode);
        destCurr = newNode;
        srcCurr = srcCurr->getNext();
        count++;
    }

    return *this;
}

bool theEngineerList::loadEngineer(const char *fileName)
{
    const int MAX_VAL = 100;
    engineer newEngineer;
    char lastName[MAX_VAL], firstName[MAX_VAL], engineerTitleString[MAX_VAL];
    titleLevel engineerTitle;
    int assesmentLevel, count = 0;
    ifstream inFile(fileName);

    if (!inFile)
    {
        cout << "could not open " << fileName << endl;
        return false;
    }

    while (inFile.get(lastName, MAX_VAL, ';'))
    {
        inFile.ignore(100, ';');
        inFile.get(firstName, MAX_VAL, ';');

        inFile.ignore(100, ';');

        inFile.get(engineerTitleString, MAX_VAL, ';');

        inFile.ignore(100, ';');
        inFile >> assesmentLevel;

        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        engineerTitle = returnEngineerTitle(engineerTitleString);

        count++;

        newEngineer.setEngineer(lastName, firstName, engineerTitle, assesmentLevel, count);
        insert(newEngineer);

        lastName[0] = '\0';
        firstName[0] = '\0';
        engineerTitleString[0] = '\0';
    }

    inFile.close();

    return true;
}

titleLevel theEngineerList::returnEngineerTitle(const string &title)
{

    if (title == "L1")
        return L1;
    if (title == "L2")
        return L2;
    if (title == "L3")
        return L3;
    if (title == "L4")
        return L4;
    if (title == "L5")
        return L5;
    if (title == "L6")
        return L6;
    if (title == "L7")
        return L7;
    if (title == "L8")
        return L8;

    return L1;
}

bool theEngineerList::insert(const engineer &newEngineer)
{

    Node *newNode = new Node(newEngineer);

    if (isEmpty())
    {
        headPtr = newNode;
        count++;
        return true;
    }

    if (comesBefore(newEngineer, headPtr->getEngineer()))
    {

        newNode->setNext(headPtr);
        headPtr = newNode;
        count++;

        return true;
    }
    Node *prev = headPtr;
    Node *curr = headPtr->getNext();

    while (curr != nullptr && comesBefore(curr->getEngineer(), newEngineer))
    {
        prev = curr;
        curr = curr->getNext();
    }

    newNode->setNext(curr);
    prev->setNext(newNode);
    count++;

    return true;
}

bool theEngineerList::comesBefore(const engineer &a, const engineer &b) const
{
    const char *A = a.getLastName();
    const char *B = b.getLastName();

    if (!A && !B)
        return false;
    if (!A)
        return true;
    if (!B)
        return false;

    int comp = strcmp(A, B);
    if (comp < 0)
        return true;
    if (comp > 0)
        return false;

    const char *Af = a.getFirstName();
    const char *Bf = b.getFirstName();
    if (!Af)
        return true;
    if (!Bf)
        return false;
    if (!Af && !Bf)
        return false;

    return strcmp(A, B) < 0;
}

void theEngineerList::printEngineer()
{
    Node *curr = headPtr;
    int index = 1;
    while (curr != nullptr)
    {

        const engineer &engineer = curr->getEngineer();
        cout << index++ << ") "
             << engineer.getLastName() << " "
             << engineer.getFirstName() << " "
             << engineer::returnEngineerTitle(engineer.getTitle()) << " "
             << engineer.getAssessmentLevel() << endl;

        curr = curr->getNext();
    }
}

bool theEngineerList::promote(const engineer &newEngineer) // Fixed promote engineer title bug
{
    Node *curr = headPtr;
    titleLevel currLevel;

    while (curr != nullptr)
    {
        engineer &engineerTitle = curr->getEngineer();
        titleLevel currLevel = engineerTitle.getTitle();

        if (currLevel < L8) // ** Adjusted condition. currLevel < 8 NOT currLevel <= 8
        {
            titleLevel promoted = static_cast<titleLevel>(currLevel + 1);
            engineerTitle.setTitle(promoted);
        }

        curr = curr->getNext();
    }

    return true;
}

bool theEngineerList::editAssessment(int index, int newAssessment)
{

    cout << "edit assessment function entered" << endl;
    Node *curr = getNodeAt(index);

    if (curr == nullptr)
    {
        return false;
    }
    engineer &anEngineer = curr->getEngineer();

    cout << "You selected " << anEngineer.getLastName() << "'s assessment" << endl;

    anEngineer.setAssessment(newAssessment);
    return true;
}

Node *theEngineerList::getNodeAt(int position) const
{

    if (position >= 1 && position <= count)
    {

        Node *curr = headPtr;
        for (int traverse = 1; traverse < position; traverse++)
        {
            curr = curr->getNext();
        }
        return curr;
    }

    return nullptr;
}

bool theEngineerList::remove()
{

    return removeRecursive(headPtr, nullptr);
}

bool theEngineerList::removeRecursive(Node *&curr, Node *prev) // Recursive node traversal and retrieval
{
    if (curr == nullptr)
    {

        return false;
    }

    engineer &anEngineer = curr->getEngineer();

    if (anEngineer.getAssessmentLevel() == 1)

    {
        Node *toDelete = curr;
        curr = curr->getNext();

        if (prev != nullptr)
        {

            prev->setNext(curr);
        }

        delete toDelete;
        this->count--;

        return removeRecursive(curr, prev) || true;
    }

    else
    {

        Node *next = curr->getNext();
        return removeRecursive(next, curr);
    }
}
