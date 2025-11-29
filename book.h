#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:
    // Constructors
    Book(); // Default
    Book(int code, std::string title, int available, int rented); // Parameterized
    // Setters
    void setCode(int code);
    void setTitle(std::string title);
    void setAvailable(int available);
    void setRented(int rented);
    virtual void setAge(int age) = 0; // For ChildrenBook objects
    virtual void setPublisher(std::string publisher) = 0; // For ComputerBook objects
    virtual void setPublishYear(int publish_year) = 0; // For Novel objects
    virtual void setAuthor(std::string author) = 0; // For HistoryBook objects
    // Getters
    int getCode() const;
    std::string getTitle() const;
    int getAvailable() const;
    int getRented() const;
    virtual int getAge() const = 0; // For ChildrenBook objects
    virtual std::string getPublisher() const = 0; // For ComputerBook objects
    virtual int getPublishYear() const = 0; // For Novel objects
    virtual std::string getAuthor() const = 0; // For HistoryBook objects

private:
    int code;
    std::string title;
    int available;
    int rented;
};

class ChildrenBook : public Book
{
public:
    // Constructors
    ChildrenBook(); // Default
    ChildrenBook(int code, std::string title, int available, int rented, int age); // Parameterized
    void setAge(int age); // Setter
    int getAge() const; // Getter
    // Prevents ChildrenBook from becoming an abstract class
    void setPublisher(std::string publisher) {}
    void setPublishYear(int publish_year) {}
    void setAuthor(std::string author) {}
    std::string getPublisher() const { return ""; }
    int getPublishYear() const { return 0; }
    std::string getAuthor() const { return ""; }
private:
    int age;
};

class ComputerBook : public Book
{
public:
    // Constructors
    ComputerBook(); // Default
    ComputerBook(int code, std::string title, int available, int rented, std::string publisher); // Parameterized
    void setPublisher(std::string publisher); // Setter
    std::string getPublisher() const; // Getter
    // Prevents ComputerBook from becoming an abstract class
    void setAge(int age) {}
    void setPublishYear(int publish_year) {}
    void setAuthor(std::string author) {}
    int getAge() const { return 0; }
    int getPublishYear() const { return 0; }
    std::string getAuthor() const { return ""; }
private:
    std::string publisher;
};

class Novel : public Book
{
public:
    // Constructors
    Novel(); // Default
    Novel(int code, std::string title, int available, int rented, int publish_year); // Parameterized
    void setPublishYear(int publish_year); // Setter
    int getPublishYear() const; // Getter
    // Prevents Novel from becoming an abstract class
    void setAge(int age) {}
    void setPublisher(std::string publisher) {}
    void setAuthor(std::string author) {}
    int getAge() const { return 0; }
    std::string getPublisher() const { return ""; }
    std::string getAuthor() const { return ""; }
private:
    int publish_year;
};

class HistoryBook : public Book
{
public:
    // Constructors
    HistoryBook(); // Default
    HistoryBook(int code, std::string title, int available, int rented, std::string author); // Parameterized
    void setAuthor(std::string author); // Setter
    std::string getAuthor() const; // Getter
    // Prevents HistoryBook from becoming an abstract class
    void setAge(int age) {}
    void setPublisher(std::string publisher) {}
    void setPublishYear(int publish_year) {}
    int getAge() const { return 0; }
    std::string getPublisher() const { return ""; }
    int getPublishYear() const { return 0; }
private:
    std::string author;
};

#endif