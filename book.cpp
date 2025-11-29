#include <iostream>
#include <string>
#include "book.h"

/* Book functions */
// Constructors
Book::Book() : code(0), title(""), available(0), rented(0) {} // Default
Book::Book(int code, std::string title, int available, int rented) :
    code(code), title(title), available(available), rented(rented) {} // Parameterized
// Setters
void Book::setCode(int code) { this->code = code; }
void Book::setTitle(std::string title) { this->title = title; }
void Book::setAvailable(int available) { this->available = available; }
void Book::setRented(int rented) { this->rented = rented; }
// Getters
int Book::getCode() const { return code; }
std::string Book::getTitle() const { return title; }
int Book::getAvailable() const { return available; }
int Book::getRented() const { return rented; }

/* ChildrenBook functions */
// Constructors
ChildrenBook::ChildrenBook() : Book(), age(0) {} // Default
ChildrenBook::ChildrenBook(int code, std::string title, int available, int rented, int age) :
    Book(code, title, available, rented), age(age) {} // Parameterized

void ChildrenBook::setAge(int age) { this->age = age; } // Setter
int ChildrenBook::getAge() const { return age; } // Getter

/* ComputerBook functions */
// Constructors
ComputerBook::ComputerBook() : Book(), publisher("") {} // Default
ComputerBook::ComputerBook(int code, std::string title, int available, int rented, std::string publisher) :
    Book(code, title, available, rented), publisher(publisher) {} // Parameterized
void ComputerBook::setPublisher(std::string publisher) { this->publisher = publisher; } // Setter
std::string ComputerBook::getPublisher() const { return publisher; } // Getter

/* Novel functions */
// Constructors
Novel::Novel() : Book(), publish_year(0) {} // Default
Novel::Novel(int code, std::string title, int available, int rented, int publish_year) :
    Book(code, title, available, rented), publish_year(publish_year) {} // Parameterized
void Novel::setPublishYear(int publish_year) { this->publish_year = publish_year; } // Setter
int Novel::getPublishYear() const { return publish_year; } // Getter

/* HistoryBook functions */
// Constructors
HistoryBook::HistoryBook() : Book(), author("") {} // Default
HistoryBook::HistoryBook(int code, std::string title, int available, int rented, std::string author) :
    Book(code, title, available, rented), author(author) {} // Parameterized
void HistoryBook::setAuthor(std::string author) { this->author = author; } // Setter
std::string HistoryBook::getAuthor() const { return author; } // Getter