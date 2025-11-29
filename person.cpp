#include <iostream>
#include <string>
#include "person.h"

/* Person functions */
// Constructors
Person::Person() : id(0), name(""), count(0) {} // Default
Person::Person(int id, std::string name, int count) :
    id(id), name(name), count(count) {} // Parameterized
// Setters
void Person::setId(int id) { this->id = id; }
void Person::setName(std::string name) { this->name = name; }
void Person::setCount(int count) { this->count = count; }
// Getters
int Person::getId() const { return id; }
std::string Person::getName() const { return name; }
int Person::getCount() const { return count; }

/* Staff functions */
// Constructors
Staff::Staff() : Person() // Default
{
    for (int i = 0; i < STAFF_MAX; i++)
    {
        code[i] = 0;
    }
}
Staff::Staff(int id, std::string name, int count, int code[]) : // Parameterized
    Person(id, name, count)
{
    for (int i = 0; i < STAFF_MAX; i++)
    {
        this->code[i] = code[i];
    }
}
void Staff::setCode(int code[]) // Setter
{
    for (int i = 0; i < STAFF_MAX; i++)
    {
        this->code[i] = code[i];
    }
}
const int* Staff::getCode() const // Getter
{
    return code;
}
int Staff::addCode(int bookCode) // Adds the book code to the borrowed array in order of code, if possible
                                 // (returns index if added, -1 if at max capacity, -2 if already borrowing)
{
    // Checks if the borrowing limit has been reached
    if (getCount() >= STAFF_MAX)
    {
        return -1; // Returns -1 if the borrowing limit has already been reached
    }
    // Initially checks if there are any duplicates
    for (int i = 0; i < STAFF_MAX; i++)
    {
        // Checks if the book is already being borrowed
        if (bookCode == code[i])
        {
            return -2; // Returns -2 if the person is already borrowing the book
        }
    }
    // Searches for an index to insert the book code
    for (int i = 0; i < STAFF_MAX; i++)
    {
        // Adds the code to an empty slot
        if (code[i] == 0)
        {
            code[i] = bookCode;
            return i; // Returns the index of where the code is added
        }
        // Adds the code by shifting the greater codes to the right
        else if (bookCode < code[i])
        {
            for (int j = STAFF_MAX - 1; j > i; j--)
            {
                code[j] = code[j - 1];
            }
            code[i] = bookCode;
            return i; // Returns the index of where the code is added
        }
    }
    return -1; // For safety in case an empty slot is not found
}
int Staff::removeCode(int bookCode) // Removes the book code from the borrowed array, if possible
                                    // (returns index if removed, -1 if not borrowing)
{   // Searches for the book code to be removed
    for (int i = 0; i < STAFF_MAX; i++)
    {
        // Checks if the code is found
        if (bookCode == code[i])
        {
            // Shifts the preceding index values to the left to replace it if necessary
            for (int j = i; j < STAFF_MAX - 1; j++)
            {
                code[j] = code[j + 1];
            }
            code[STAFF_MAX - 1] = 0; // Zeroes out the last index
            return i; // Returns the index of where the code was removed
        }
    }
    return -1; // Returns -1 if the code is not found (not currently borrowing the book)
}

/* Student functions */
// Constructors
Student::Student() : Person() // Default
{
    for (int i = 0; i < STUDENT_MAX; i++)
    {
        code[i] = 0;
    }
}
Student::Student(int id, std::string name, int count, int code[]) : // Parameterized
    Person(id, name, count)
{
    for (int i = 0; i < STUDENT_MAX; i++)
    {
        this->code[i] = code[i];
    }
}
void Student::setCode(int code[]) // Setter
{
    for (int i = 0; i < STUDENT_MAX; i++)
    {
        this->code[i] = code[i];
    }
}
const int* Student::getCode() const // Getter
{
    return code;
}
int Student::addCode(int bookCode) // Adds the book code to the borrowed array in order of code, if possible
                                   // (returns index if added, -1 if at max capacity, -2 if already borrowing)
{
    // Checks if the borrowing limit has been reached
    if (getCount() >= STUDENT_MAX)
    {
        return -1; // Returns -1 if the borrowing limit has already been reached
    }
    // Initially checks if there are any duplicates
    for (int i = 0; i < STUDENT_MAX; i++)
    {
        // Checks if the book is already being borrowed
        if (bookCode == code[i])
        {
            return -2; // Returns -2 if the person is already borrowing the book
        }
    }
    // Searches for an index to insert the book code
    for (int i = 0; i < STUDENT_MAX; i++)
    {
        // Adds the code to an empty slot
        if (code[i] == 0)
        {
            code[i] = bookCode;
            return i; // Returns the index of where the code is added
        }
        // Adds the code by shifting the greater codes to the right
        else if (bookCode < code[i])
        {
            for (int j = STUDENT_MAX - 1; j > i; j--)
            {
                code[j] = code[j - 1];
            }
            code[i] = bookCode;
            return i; // Returns the index of where the code is added
        }
    }
    return -1; // For safety in case an empty slot is not found
}
int Student::removeCode(int bookCode) // Removes the book code from the borrowed array, if possible
                                      // (returns index if removed, -1 if not borrowing)
{   // Searches for the book code to be removed
    for (int i = 0; i < STUDENT_MAX; i++)
    {
        // Checks if the code is found
        if (bookCode == code[i])
        {
            // Shifts the preceding index values to the left to replace it if necessary
            for (int j = i; j < STUDENT_MAX - 1; j++)
            {
                code[j] = code[j + 1];
            }
            code[STUDENT_MAX - 1] = 0; // Zeroes out the last index
            return i; // Returns the index of where the code was removed
        }
    }
    return -1; // Returns -1 if the code is not found (not currently borrowing the book)
}

/* Adult functions */
// Constructors
Adult::Adult() : Person() // Default
{
    for (int i = 0; i < ADULT_MAX; i++)
    {
        code[i] = 0;
    }
}
Adult::Adult(int id, std::string name, int count, int code[]) : // Parameterized
    Person(id, name, count)
{
    for (int i = 0; i < ADULT_MAX; i++)
    {
        this->code[i] = code[i];
    }
}
void Adult::setCode(int code[]) // Setter
{
    for (int i = 0; i < ADULT_MAX; i++)
    {
        this->code[i] = code[i];
    }
}
const int* Adult::getCode() const // Getter
{
    return code;
}
int Adult::addCode(int bookCode) // Adds the book code to the borrowed array in order of code, if possible
                                 // (returns index if added, -1 if at max capacity, -2 if already borrowing)
{
    // Checks if the borrowing limit has been reached
    if (getCount() >= ADULT_MAX)
    {
        return -1; // Returns -1 if the borrowing limit has already been reached
    }
    // Initially checks if there are any duplicates
    for (int i = 0; i < ADULT_MAX; i++)
    {
        // Checks if the book is already being borrowed
        if (bookCode == code[i])
        {
            return -2; // Returns -2 if the person is already borrowing the book
        }
    }
    // Searches for an index to insert the book code
    for (int i = 0; i < ADULT_MAX; i++)
    {
        // Adds the code to an empty slot
        if (code[i] == 0)
        {
            code[i] = bookCode;
            return i; // Returns the index of where the code is added
        }
        // Adds the code by shifting the greater codes to the right
        else if (bookCode < code[i])
        {
            for (int j = ADULT_MAX - 1; j > i; j--)
            {
                code[j] = code[j - 1];
            }
            code[i] = bookCode;
            return i; // Returns the index of where the code is added
        }
    }
    return -1; // For safety in case an empty slot is not found
}
int Adult::removeCode(int bookCode) // Removes the book code from the borrowed array, if possible
                                    // (returns index if removed, -1 if not borrowing)
{   // Searches for the book code to be removed
    for (int i = 0; i < ADULT_MAX; i++)
    {
        // Checks if the code is found
        if (bookCode == code[i])
        {
            // Shifts the preceding index values to the left to replace it if necessary
            for (int j = i; j < ADULT_MAX - 1; j++)
            {
                code[j] = code[j + 1];
            }
            code[ADULT_MAX - 1] = 0; // Zeroes out the last index
            return i; // Returns the index of where the code was removed
        }
    }
    return -1; // Returns -1 if the code is not found (not currently borrowing the book)
}