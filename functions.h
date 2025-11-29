#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "node.h"
#include "book.h"
#include "person.h"

// Inserts the book into the linked list in sorted order of code
void insertBookSorted(Book* newBook, bookNode*& bookListHead);
// Inserts the person into the linked list in sorted order of id
void insertPersonSorted(Person* newPerson, personNode*& personListHead);

// Reads from a file containing book data and stores information in the given static array
void parseBookFile(std::istream& input, bookNode* bookArr[]);
// Reads from a file containing person data and stores information in the given static array
void parsePersonFile(std::istream& input, personNode* personArr[]);

// Returns the given string with spaces instead of underscores/dashes
std::string formattedString(std::string theString);

// Finds a book in an array given a title
Book* findBookWithTitle(bookNode* bookArr[], std::string theTitle);
// Finds a book in an array given a code
Book* findBookWithCode(bookNode* bookArr[], int theCode);
// Finds a person in an array given an id
Person* findPersonWithId(personNode* personArr[], int theId);

/* Menu Functions */
// Displays information on a book requested by the user
void searchBook(bookNode* bookArr[]);
// Displays information on a user given their id
void showUserInfo(bookNode* bookArr[], personNode* personArr[]);
// Allows the user to borrow a book, displaying their information and adjusting the database
void rentBook(bookNode* bookArr[], personNode* personArr[]);
// Allows the user to return a book, displaying their information and adjusting the database
void returnBook(bookNode* bookArr[], personNode* personArr[]);
// Prints all books and their data
void showAllBooks(bookNode* bookArr[]);
// Deallocates heap before exiting the program
void prepareExit(bookNode* bookArr[], personNode* personArr[]);

// Prints all people and their data (for testing only)
void showAllPeople(personNode* personArr[]);

#endif
