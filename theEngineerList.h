#ifndef THE_ENGINEER_LIST_H
#define THE_ENGINEER_LIST_H

#include "theEngineer.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <limits>

using namespace std;

class theEngineerList
{

private:
    Node *headPtr;
    int count;
    Node *getNodeAt(int position) const;
    Node *insertNode();

    bool removeRecursive(Node *&curr, Node *prev);

    ifstream inFile;

public:
    theEngineerList();
    theEngineerList(const theEngineerList &);
    theEngineerList &operator=(const theEngineerList &);
    ~theEngineerList();

    bool loadEngineer(const char *fileName);
    titleLevel returnEngineerTitle(const string &title);
    bool isEmpty() const;
    bool insert(const engineer &newEngineer);
    bool comesBefore(const engineer &a, const engineer &b) const;
    bool promote(const engineer &newEngineer);
    bool editAssessment(int index, int newAssessment);
    bool remove();

    void printEngineer();
};

#endif