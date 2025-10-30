#ifndef THE_ENGINEER_H
#define THE_ENGINEER_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

enum titleLevel
{
    L1,
    L2,
    L3,
    L4,
    L5,
    L6,
    L7,
    L8
};

class theEngineerList;

class engineer
{
private:
    char *lastName;
    char *firstName;
    titleLevel engineerTitleLevel;
    int assessmentLevel;
    int engineerCount;

public:
    engineer();
    engineer(const engineer &other);
    engineer(const char *lName, const char *fName, titleLevel title, int assessment, int count);
    ~engineer();
    engineer &operator=(const engineer &entry);

    void setEngineer(const char *lName, const char *fName,
                     titleLevel title, int assessment, int count);

    static const char *returnEngineerTitle(titleLevel t);
    void setTitle(titleLevel title);
    void setAssessment(int assessment);

    const char *getLastName() const;
    const char *getFirstName() const;
    int getAssessmentLevel() const;
    titleLevel getTitle() const;
    int getCount() const;
};

class Node
{
private:
    engineer anEngineer;
    Node *next;

public:
    Node();
    Node(const engineer &anEngineer_In);
    Node(const engineer &anEngineer_In, Node *nextNode);
    void setEngineer(const engineer &anEngineer_In);
    const engineer &getEngineer() const;
    engineer &getEngineer();
    void setNext(Node *nextNode);
    Node *getNext() const;
};

#endif