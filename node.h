#ifndef NODE_H
#define NODE_H
#include "book.h"
#include "person.h"

// Node structure that contains Book objects
struct bookNode
{
    Book* data;
    bookNode* link;
};

// Node structure that contains Person objects
struct personNode
{
    Person* data;
    personNode* link;
};

#endif