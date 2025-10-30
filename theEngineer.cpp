#include "theEngineer.h"

engineer::engineer() // default constructor
    : lastName(nullptr), firstName(nullptr),
      engineerTitleLevel(L1), assessmentLevel(0), engineerCount(0)
{
}

// copy constructor (deep copy)
engineer::engineer(const engineer &other)
    : lastName(nullptr), firstName(nullptr), engineerTitleLevel(other.engineerTitleLevel),
      assessmentLevel(other.assessmentLevel), engineerCount(other.engineerCount)
{

    if (other.lastName)
    {
        lastName = new char[strlen(other.lastName) + 1];
        strcpy(lastName, other.lastName);
    }
    if (other.firstName)
    {
        firstName = new char[strlen(other.firstName) + 1];
        strcpy(firstName, other.firstName);
    }
}

engineer::~engineer()
{ // destructor
    delete[] lastName;
    delete[] firstName;
}

engineer::engineer(const char *lName, const char *fName, // parameterized constructor
                   titleLevel title, int assessment, int count)
    : engineerTitleLevel(title), assessmentLevel(assessment),
      engineerCount(count)
{

    lastName = new char[strlen(lName) + 1];
    strcpy(lastName, lName);
    firstName = new char[strlen(fName) + 1];
    strcpy(firstName, fName);
}
// copy constructor (deep copy)
engineer &engineer::operator=(const engineer &anEngineer)
{
    if (this == &anEngineer)
        return *this; // self-assignment guard

    // free current resources
    delete[] lastName;
    delete[] firstName;

    // deep-copy lastName
    if (anEngineer.lastName)
    {
        lastName = new char[strlen(anEngineer.lastName) + 1];
        strcpy(lastName, anEngineer.lastName);
    }
    else
    {
        lastName = nullptr;
    }

    // deep-copy firstName
    if (anEngineer.firstName)
    {
        firstName = new char[strlen(anEngineer.firstName) + 1];
        strcpy(firstName, anEngineer.firstName);
    }
    else
    {
        firstName = nullptr;
    }

    // copy simple fields
    engineerTitleLevel = anEngineer.engineerTitleLevel;
    assessmentLevel = anEngineer.assessmentLevel;
    engineerCount = anEngineer.engineerCount;

    return *this;
}

void engineer::setEngineer(const char *lName, const char *fName, // Setter
                           titleLevel title, int assessment, int count)
{

    delete[] lastName;
    delete[] firstName;
    lastName = new char[strlen(lName) + 1];
    strcpy(lastName, lName);
    firstName = new char[strlen(fName) + 1];
    strcpy(firstName, fName);

    engineerTitleLevel = title;
    assessmentLevel = assessment;
    engineerCount = count;
}

void engineer::setTitle(titleLevel title)
{
    engineerTitleLevel = title;
}
void engineer::setAssessment(int assessment)
{
    assessmentLevel = assessment;
}

// convert enum title integer value to alphanumeric character representation
const char *engineer::returnEngineerTitle(titleLevel t)
{
    switch (t)
    {
    case L1:
        return "L1";
    case L2:
        return "L2";
    case L3:
        return "L3";
    case L4:
        return "L4";
    case L5:
        return "L5";
    case L6:
        return "L6";
    case L7:
        return "L7";
    case L8:
        return "L8";
    default:
        return "Unknown";
    }
}

const char *engineer::getLastName() const { return lastName; }
const char *engineer::getFirstName() const { return firstName; }
int engineer::getAssessmentLevel() const { return assessmentLevel; }
titleLevel engineer::getTitle() const { return engineerTitleLevel; }
int engineer::getCount() const { return engineerCount; }

Node::Node() : anEngineer(), next(nullptr) {}
Node::Node(const engineer &anEngineer_In) : anEngineer(anEngineer_In), next(nullptr) {}
Node::Node(const engineer &anEngineer_In, Node *nextNode) : anEngineer(anEngineer_In), next(nextNode) {}
void Node::setEngineer(const engineer &anEngineer_In)
{
    anEngineer = anEngineer_In;
}
const engineer &Node::getEngineer() const
{
    return anEngineer;
}
engineer &Node::getEngineer()
{

    return anEngineer;
}

void Node::setNext(Node *nextNode)
{
    next = nextNode;
}
Node *Node::getNext() const
{
    return next;
}
