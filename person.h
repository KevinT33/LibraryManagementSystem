#ifndef PERSON_H
#define PERSON_H

#include <string>

const int STAFF_MAX = 3;
const int STUDENT_MAX = 2;
const int ADULT_MAX = 4;

class Person
{
public:
    // Constructors
    Person(); // Default
    Person(int id, std::string name, int count); // Parameterized
    // Setters
    void setId(int id);
    void setName(std::string name);
    void setCount(int count);
    virtual void setCode(int code[]) = 0; // For Staff, Student, and Adult objects
    // Getters
    int getId() const;
    std::string getName() const;
    int getCount() const;
    virtual const int* getCode() const = 0; // For Staff, Student, and Adult objects
    // Other virtual functions
    virtual int addCode(int code) = 0; // For Staff, Student, and Adult objects
    virtual int removeCode(int code) = 0; // For Staff, Student, and Adult objects
private:
    int id;
    std::string name;
    int count;
};

class Staff : public Person
{
public:
    // Constructors
    Staff(); // Default
    Staff(int id, std::string name, int count, int code[]); // Parameterized
    void setCode(int code[]); // Setter
    const int* getCode() const; // Getter
    int addCode(int code); // Adds the book code to the borrowed array in order of code, if possible
                           // (returns index if added, -1 if at max capacity, -2 if already borrowing)
    int removeCode(int code); // Removes the book code from the borrowed array, if possible
                              // (returns index if removed, -1 if not borrowing)
private:
    int code[STAFF_MAX];
};

class Student : public Person
{
public:
    // Constructors
    Student(); // Default
    Student(int id, std::string name, int count, int code[]); // Parameterized
    void setCode(int code[]); // Setter
    const int* getCode() const; // Getter
    int addCode(int code); // Adds the book code to the borrowed array in order of code, if possible
                           // (returns index if added, -1 if at max capacity, -2 if already borrowing)
    int removeCode(int code); // Removes the book code from the student's borrowed array, if possible
private:
    int code[STUDENT_MAX];
};

class Adult : public Person
{
public:
    // Constructors
    Adult(); // Default
    Adult(int id, std::string name, int count, int code[]); // Parameterized
    void setCode(int code[]); // Setter
    const int* getCode() const; // Getter
    int addCode(int code); // Adds the book code to the borrowed array in order of code, if possible
                           // (returns index if added, -1 if at max capacity, -2 if already borrowing)
    int removeCode(int code); // Removes the book code from the adult's borrowed array, if possible
private:
    int code[ADULT_MAX];
};

#endif