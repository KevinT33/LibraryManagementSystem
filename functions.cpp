#include <iostream>
#include <iomanip>
#include "node.h"
#include "book.h"
#include "person.h"

// Inserts the book into the linked list in sorted order of code
void insertBookSorted(Book* newBook, bookNode*& bookListHead)
{
    bookNode* newNode = new bookNode{newBook, nullptr}; // Creates a node
    // If the list is empty, makes the new node the head node
    if (!bookListHead)
    {
        bookListHead = newNode;
    }
    // If the code of the new node book is less than the head node, makes it the new head node
    else if (newNode->data->getCode() < bookListHead->data->getCode())
    {
        newNode->link = bookListHead;
        bookListHead = newNode;
    }
    // Otherwise, finds the correct place to insert the node
    else
    {
        bookNode* iterPtr = bookListHead; // Pointer that will traverse the linked list
        // Loops until iterPtr finds the node that newNode should be inserted after
        while (iterPtr->link != nullptr && newNode->data->getCode() > iterPtr->link->data->getCode())
        {
            iterPtr = iterPtr->link;
        }
        // Inserts newNode after the node iterPtr is pointing to
        newNode->link = iterPtr->link;
        iterPtr->link = newNode;
    }
}
// Inserts the person into the linked list in sorted order of id
void insertPersonSorted(Person* newPerson, personNode*& personListHead)
{
    personNode* newNode = new personNode{newPerson, nullptr}; // Creates a node
    // If the list is empty, makes the new node the head node
    if (!personListHead)
    {
        personListHead = newNode;
    }
    // If the id of the new node person is less than the head node, makes it the new head node
    else if (newNode->data->getId() < personListHead->data->getId())
    {
        newNode->link = personListHead;
        personListHead = newNode;
    }
    // Otherwise, finds the correct place to insert the node
    else
    {
        personNode* iterPtr = personListHead; // Pointer that will traverse the linked list
        // Loops until iterPtr finds the node that newNode should be inserted after
        while (iterPtr->link != nullptr && newNode->data->getId() > iterPtr->link->data->getId())
        {
            iterPtr = iterPtr->link;
        }
        // Inserts newNode after the node iterPtr is pointing to
        newNode->link = iterPtr->link;
        iterPtr->link = newNode;
    }
}

// Reads from a file containing book data and stores information in the given static array
void parseBookFile(std::istream& input, bookNode* bookArr[])
{
    while (!input.eof())
    {
        int currentCode = 0;
        std::string currentTitle = "";
        // Gets the current book code and title
        input >> currentCode >> currentTitle;
        try
        {
            // Reads the age/publisher/publish year/author, available count and rented count
            if (currentCode >= 1001 && currentCode <= 2000) // Handles children books
            {
                int currentAge = 0, currentAvailable = 0, currentRented = 0;
                input >> currentAge >> currentAvailable >> currentRented;
                // Creates the object and inserts it in the corresponding linked list
                Book* currentBook = new ChildrenBook(currentCode, currentTitle, currentAvailable, currentRented, currentAge);
                insertBookSorted(currentBook, bookArr[0]);
            }
            else if (currentCode >= 2001 && currentCode <= 3000) // Handles computer books
            {
                int currentAvailable = 0, currentRented = 0;
                std::string currentPublisher = "";
                input >> currentPublisher >> currentAvailable >> currentRented;
                // Creates the object and inserts it in the corresponding linked list
                Book* currentBook = new ComputerBook(currentCode, currentTitle, currentAvailable, currentRented, currentPublisher);
                insertBookSorted(currentBook, bookArr[1]);
            }
            else if (currentCode >= 3001 && currentCode <= 4000) // Handles novels
            {
                int currentPublishYear = 0, currentAvailable = 0, currentRented = 0;
                input >> currentPublishYear >> currentAvailable >> currentRented;
                // Creates the object and inserts it in the corresponding linked list
                Book* currentBook = new Novel(currentCode, currentTitle, currentAvailable, currentRented, currentPublishYear);
                insertBookSorted(currentBook, bookArr[2]);
            }
            else if (currentCode >= 4001 && currentCode <= 5000) // Handles history books
            {
                int currentAvailable = 0, currentRented = 0;
                std::string currentAuthor = "";
                input >> currentAuthor >> currentAvailable >> currentRented;
                // Creates the object and inserts it in the corresponding linked list
                Book* currentBook = new HistoryBook(currentCode, currentTitle, currentAvailable, currentRented, currentAuthor);
                insertBookSorted(currentBook, bookArr[3]);
            }
            else // Throws an error if the code is out of range
            {
                throw currentCode;
            }
        }
        catch (int invalidCode)
        {
            std::string temp = "";
            // Skips the next 3 inputs in order to get to the next book
            for (int i = 0; i < 3; i++)
            {
                input >> temp;
            }
            std::cout << "Book code " << invalidCode << " is not a valid code, and was skipped." << std::endl;
        }
    }
}
// Reads from a file containing person data and stores information in the given static array
void parsePersonFile(std::istream& input, personNode* personArr[])
{
    while (!input.eof())
    {
        int currentId = 0, currentCount = 0;
        std::string currentName = "";
        // Gets the current id, name, and borrow count
        input >> currentId >> currentName >> currentCount;
        try
        {
            // Reads the ids of the books being borrowed
            if (currentId >= 1 && currentId <= 100) // Handles staff
            {
                int currentCodes[STAFF_MAX] = {0};
                // Creates the object
                Person* currentPerson = new Staff(currentId, currentName, 0, currentCodes);
                for (int i = 0; i < currentCount; i++)
                {
                    int code;
                    input >> code;
                    currentPerson->addCode(code);
                }
                // Updates the count after adding
                currentPerson->setCount(currentCount);
                // Inserts the object to the corresponding linked list
                insertPersonSorted(currentPerson, personArr[0]);
            }
            else if (currentId >= 101 && currentId <= 300) // Handles students
            {
                int currentCodes[STUDENT_MAX] = {0};
                // Creates the object
                Person* currentPerson = new Student(currentId, currentName, 0, currentCodes);
                for (int i = 0; i < currentCount; i++)
                {
                    int code;
                    input >> code;
                    currentPerson->addCode(code);
                }
                // Updates the count after adding
                currentPerson->setCount(currentCount);
                // Inserts the object to the corresponding linked list
                insertPersonSorted(currentPerson, personArr[1]);
            }
            else if (currentId >= 301 && currentId <= 1000) // Handles adults
            {
                int currentCodes[ADULT_MAX] = {0};
                // Creates the object
                Person* currentPerson = new Adult(currentId, currentName, 0, currentCodes);
                for (int i = 0; i < currentCount; i++)
                {
                    int code;
                    input >> code;
                    currentPerson->addCode(code);
                }
                // Updates the count after adding
                currentPerson->setCount(currentCount);
                // Inserts the object to the corresponding linked list
                insertPersonSorted(currentPerson, personArr[2]);
            }
            else // Throws an error if the code is out of range
            {
                throw currentId;
            }
        }
        catch (int invalidId)
        {
            int temp = 0;
            // Skips the next inputs in order to get to the next book
            for (int i = 0; i < currentCount; i++)
            {
                input >> temp;
            }
            std::cout << "Person id " << invalidId << " is not a valid id, and was skipped." << std::endl;
        }
    }
}

// Returns the given string with spaces instead of underscores/dashes
std::string formattedString(std::string theString)
{
    for (int i = 0; i < theString.length(); i++)
    {
        if (theString[i] == '_' || theString[i] == '-')
        {
            theString[i] = ' ';
        }
    }
    return theString;
}

// Finds a book in an array given a title
Book* findBookWithTitle(bookNode* bookArr[], std::string theTitle)
{
    // Pointer that will be used to traverse each linked list
    bookNode* iterPtr = nullptr;
    // Searches each linked list in bookArr
    for (int i = 0; i < 4; i++)
    {
        iterPtr = bookArr[i];
        while (iterPtr != nullptr)
        {
            // If the book is found, returns its address
            if (theTitle == iterPtr->data->getTitle())
            {
                return iterPtr->data;
            }
            iterPtr = iterPtr->link;
        }
    }
    throw theTitle; // Throws the book title if the book is not found 
}
// Finds a book in an array given a code
Book* findBookWithCode(bookNode* bookArr[], int theCode)
{
    int linkedListIndex; // Will store the index of the linked list in bookArr to be searched
    if (theCode >= 1001 && theCode <= 2000) { linkedListIndex = 0; } // Will search children's books
    else if (theCode >= 2001 && theCode <= 3000) { linkedListIndex = 1; } // Will search computer books
    else if (theCode >= 3001 && theCode <= 4000) { linkedListIndex = 2; } // Will search novels
    else if (theCode >= 4001 && theCode <= 5000) { linkedListIndex = 3; } // Will search history books
    else { throw theCode; } // Throws the book code if it is out of range
    
    // Pointer that will be used to traverse the linked list
    bookNode* iterPtr = bookArr[linkedListIndex];
    while (iterPtr != nullptr)
    {
        // If the book is found, returns its address
        if (theCode == iterPtr->data->getCode())
        {
            return iterPtr->data;
        }
        iterPtr = iterPtr->link;
    }
    throw theCode; // Throws the book code if the book is not found
}
// Finds a person in an array given an id
Person* findPersonWithId(personNode* personArr[], int theId)
{
    int linkedListIndex; // Will store the index of the linked list in personArr to be searched
    if (theId >= 1 && theId <= 100) { linkedListIndex = 0; } // Will search staff
    else if (theId >= 101 && theId <= 300) { linkedListIndex = 1; } // Will search students
    else if (theId >= 301 && theId <= 1000) { linkedListIndex = 2; } // Will search adults
    else { throw theId; } // Throws the person id if it is out of range
    
    // Pointer that will be used to traverse the linked lists
    personNode* iterPtr = personArr[linkedListIndex];
    while (iterPtr != nullptr)
    {
        // If the person is found, returns their address
        if (theId == iterPtr->data->getId())
        {
            return iterPtr->data;
        }
        iterPtr = iterPtr->link;
    }
    throw theId; // Throws the person id if the person is not found
}

/* Menu Functions */
// Displays information on a book requested by the user
void searchBook(bookNode* bookArr[])
{
    try
    {
        // Gets the book title from the user
        std::string bookTitle;
        std::cout << "Enter book title: ";
        std::cin >> bookTitle;
        // Attempts to find the book
        Book* foundBook = findBookWithTitle(bookArr, bookTitle);
        // Prints the book's information
        std::cout << std::endl;
        std::cout << "Code     : " << foundBook->getCode() << std::endl;
        std::cout << "Title    : " << formattedString(foundBook->getTitle()) << std::endl;
        if (foundBook->getCode() >= 1001 && foundBook->getCode() <= 2000) // Handles children books
        {
            std::cout << "Age      : " << foundBook->getAge() << std::endl;
        }
        else if (foundBook->getCode() >= 2001 && foundBook->getCode() <= 3000) // Handles computer books
        {
            std::cout << "Publisher: " << formattedString(foundBook->getPublisher()) << std::endl;
        }
        else if (foundBook->getCode() >= 3001 && foundBook->getCode() <= 4000) // Handles novels
        {
            std::cout << "Year     : " << foundBook->getPublishYear() << std::endl;
        }
        else if (foundBook->getCode() >= 4001 && foundBook->getCode() <= 5000) // Handles history books
        {
            std::cout << "Author   : " << formattedString(foundBook->getAuthor()) << std::endl;
        }
        std::cout << "Available: " << foundBook->getAvailable() << std::endl;
        std::cout << "Rented   : " << foundBook->getRented() << std::endl;
    }
    catch (std::string nonExistentTitle) // Prints an error message if the book is not found
    {
        std::cout << "The book '" << nonExistentTitle << "' not exist." << std::endl;
    }
}
// Displays information on a user given their id
void showUserInfo(bookNode* bookArr[], personNode* personArr[])
{
    try
    {
        // Gets the id from the user
        int personId;
        std::cout << "Enter your id: ";
        std::cin >> personId;
        // Attempts to find the person
        Person* foundPerson = findPersonWithId(personArr, personId);
        // Prints the person's information
        std::cout << std::endl;
        std::cout << "You are '" << foundPerson->getName() << "'. You borrowed "
            << foundPerson->getCount() << " books." << std::endl;
        // Prints the books the person is borrowing
        for (int i = 0; i < foundPerson->getCount(); i++)
        {
            Book* currentBook = findBookWithCode(bookArr, foundPerson->getCode()[i]);
            std::cout << (i + 1) << ". " << formattedString(currentBook->getTitle()) << " (" << currentBook->getCode() << ")" << std::endl;
        }
    }
    catch (int nonExistentId) // Prints an error message if the person is not found
    {
        std::cout << "Id " << nonExistentId << " not exist" << std::endl;
    }
}
// Allows the user to borrow a book, displaying their information and adjusting the database
void rentBook(bookNode* bookArr[], personNode* personArr[])
{
    try
    {
        // Gets the id from the user
        int personId;
        std::cout << "Enter your id: ";
        std::cin >> personId;
        // Attempts to find the person
        Person* foundPerson = findPersonWithId(personArr, personId);
        // Gets the book title from the user
        std::string bookTitle;
        std::cout << "Enter book title: ";
        std::cin >> bookTitle;
        // Attempts to find the book
        Book* foundBook = findBookWithTitle(bookArr, bookTitle);
        // Checks if the book is available
        if (foundBook->getAvailable() <= 0)
        {
            throw 'u';
        }
        // Attempts to add the book code to the person's borrow list
        int addStatus = foundPerson->addCode(foundBook->getCode());
        if (addStatus == -1) // Occurs when the person has already reached the borrowing limit
        {
            throw 'm';
        }
        else if (addStatus == -2) // Occurs when the person is already borrowing the book
        {
            throw 'd';
        }
        // Updates the book available/rented count and person borrow count 
        // if no errors prevent borrowing
        foundBook->setAvailable(foundBook->getAvailable() - 1);
        foundBook->setRented(foundBook->getRented() + 1);
        foundPerson->setCount(foundPerson->getCount() + 1);
        // Prints the borrow message to the user
        std::cout << std::endl;
        std::cout << "You are '" << foundPerson->getName() << "'. ";
        std::cout << "The book '" << formattedString(foundBook->getTitle()) << "' is available." << std::endl;
        std::string howManyBooks = "";
        if (foundPerson->getCount() == 0) { howManyBooks = "zero books"; }
        else if (foundPerson->getCount() == 1) { howManyBooks = "one book"; }
        else if (foundPerson->getCount() == 2) { howManyBooks = "two books"; }
        else if (foundPerson->getCount() == 3) { howManyBooks = "three books"; }
        else if (foundPerson->getCount() == 4) { howManyBooks = "four books"; }
        std::cout << "Rent succeed. Now you borrowed " << howManyBooks << "." << std::endl;
        // Prints the books the person is borrowing (titles only)
        for (int i = 0; i < foundPerson->getCount(); i++)
        {
            Book* currentBook = findBookWithCode(bookArr, foundPerson->getCode()[i]);
            std::cout << (i + 1) << ". " << formattedString(currentBook->getTitle()) << std::endl;
        }
    }
    catch (char invalidBorrow) // Prints an error message if the person cannot borrow the book
    {
        if (invalidBorrow == 'u')
        {
            std::cout << "Sorry, the book is unavailable." << std::endl;
        }
        else if (invalidBorrow == 'm')
        {
            std::cout << "You are already borrowing the maximum amount of books." << std::endl;
        }
        else if (invalidBorrow == 'd')
        {
            std::cout << "You are already borrowing this book." << std::endl;
        }
    }
    catch (int nonExistentId) // Prints an error message if the person is not found
    {
        std::cout << "Id " << nonExistentId << " not exist" << std::endl;
    }
    catch (std::string nonExistentTitle) // Prints an error message if the book is not found
    {
        std::cout << "The book '" << nonExistentTitle << "' not exist." << std::endl;
    }
}
// Allows the user to return a book, displaying their information and adjusting the database
void returnBook(bookNode* bookArr[], personNode* personArr[])
{
    try
    {
        // Gets the id from the user
        int personId;
        std::cout << "Enter your id: ";
        std::cin >> personId;
        // Attempts to find the person
        Person* foundPerson = findPersonWithId(personArr, personId);
        // Gets the book title from the user
        std::string bookTitle;
        std::cout << "Enter book title to return: ";
        std::cin >> bookTitle;
        // Attempts to find the book
        Book* foundBook = findBookWithTitle(bookArr, bookTitle);
        // Attempts to remove the book code from the person's borrow list
        int removeStatus = foundPerson->removeCode(foundBook->getCode());
        if (removeStatus == -1) // Occurs when the person is not borrowing the book
        {
            throw 'n';
        }
        // Updates the book available/rented count and person borrow count 
        // if no errors prevent returning
        foundBook->setAvailable(foundBook->getAvailable() + 1);
        foundBook->setRented(foundBook->getRented() - 1);
        foundPerson->setCount(foundPerson->getCount() - 1);
        // Prints the return message to the user
        std::cout << std::endl;
        std::cout << "You are '" << foundPerson->getName() << "'. ";
        std::cout << "The book '" << formattedString(foundBook->getTitle()) << "' is returned." << std::endl;
        std::string howManyBooks = "";
        if (foundPerson->getCount() == 0) { howManyBooks = "zero books"; }
        else if (foundPerson->getCount() == 1) { howManyBooks = "one book"; }
        else if (foundPerson->getCount() == 2) { howManyBooks = "two books"; }
        else if (foundPerson->getCount() == 3) { howManyBooks = "three books"; }
        else if (foundPerson->getCount() == 4) { howManyBooks = "four books"; }
        std::cout << "Return succeed. Now you borrowed " << howManyBooks << "." << std::endl;
        // Prints the books the person is borrowing (titles only)
        for (int i = 0; i < foundPerson->getCount(); i++)
        {
            Book* currentBook = findBookWithCode(bookArr, foundPerson->getCode()[i]);
            std::cout << (i + 1) << ". " << formattedString(currentBook->getTitle()) << std::endl;
        }
    }
    catch (char invalidReturn) // Prints an error message if the person cannot return the book
    {
        std::cout << "You are not borrowing this book and therefore cannot return it." << std::endl;
    }
    catch (int nonExistentId) // Prints an error message if the person is not found
    {
        std::cout << "Id " << nonExistentId << " not exist" << std::endl;
    }
    catch (std::string nonExistentTitle) // Prints an error message if the book is not found
    {
        std::cout << "The book '" << nonExistentTitle << "' not exist." << std::endl;
    }
}
// Prints all books and their data
void showAllBooks(bookNode* bookArr[])
{
    // Pointer that will be used to traverse each linked list
    bookNode* iterPtr = nullptr;
    // Prints the children's books
    iterPtr = bookArr[0];
    std::cout << "            < Children Book >            " << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    while (iterPtr != nullptr)
    {
        // Prints children book information
        std::cout << std::setw(5) << iterPtr->data->getCode()
            << std::setw(25) << formattedString(iterPtr->data->getTitle())
            << std::setw(4) << iterPtr->data->getAge()
            << std::setw(4) << iterPtr->data->getAvailable()
            << std::setw(4) << iterPtr->data->getRented() << std::endl;
        iterPtr = iterPtr->link;
    }
    std::cout << std::endl;
    // Prints the computer books
    iterPtr = bookArr[1];
    std::cout << "                 < Computer Book >                 " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    while (iterPtr != nullptr)
    {
        // Prints computer book information
        std::cout << std::setw(5) << iterPtr->data->getCode()
            << std::setw(25) << formattedString(iterPtr->data->getTitle())
            << std::setw(21) << formattedString(iterPtr->data->getPublisher())
            << std::setw(4) << iterPtr->data->getAvailable()
            << std::setw(4) << iterPtr->data->getRented() << std::endl;
        iterPtr = iterPtr->link;
    }
    std::cout << std::endl;
    // Prints the novels
    iterPtr = bookArr[2];
    std::cout << "               < Novel >               " << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    while (iterPtr != nullptr)
    {
        // Prints novel information
        std::cout << std::setw(5) << iterPtr->data->getCode()
            << std::setw(25) << formattedString(iterPtr->data->getTitle())
            << std::setw(7) << iterPtr->data->getPublishYear()
            << std::setw(4) << iterPtr->data->getAvailable()
            << std::setw(4) << iterPtr->data->getRented() << std::endl;
        iterPtr = iterPtr->link;
    }
    std::cout << std::endl;
    // Prints the history books
    iterPtr = bookArr[3];
    std::cout << "                < History Book >                " << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    while (iterPtr != nullptr)
    {
        // Prints history book information
        std::cout << std::setw(5) << iterPtr->data->getCode()
            << std::setw(25) << formattedString(iterPtr->data->getTitle())
            << std::setw(15) << formattedString(iterPtr->data->getAuthor())
            << std::setw(4) << iterPtr->data->getAvailable()
            << std::setw(4) << iterPtr->data->getRented() << std::endl;
        iterPtr = iterPtr->link;
    }
}
// Deallocates heap before exiting the program
void prepareExit(bookNode* bookArr[], personNode* personArr[])
{
    // Iterates through bookArr
    for (int i = 0; i < 4; i++)
    {
        bookNode* currentNode = bookArr[i];
        // Clears out linked list and its books from heap
        while (currentNode != nullptr)
        {
            bookNode* nextNode = currentNode->link;
            delete currentNode->data;
            delete currentNode;
            currentNode = nextNode;
        }
        // Ensures no dangling pointers
        bookArr[i] = nullptr;
    }
    // Iterates through personArr
    for (int i = 0; i < 3; i++)
    {
        personNode* currentNode = personArr[i];
        // Clears out linked list and its people from heap
        while (currentNode != nullptr)
        {
            personNode* nextNode = currentNode->link;
            delete currentNode->data;
            delete currentNode;
            currentNode = nextNode;
        }
        // Ensures no dangling pointers
        personArr[i] = nullptr;
    }
    
    std::cout << "Exiting..." << std::endl;
}

// Prints all people and their data (for testing only)
void showAllPeople(personNode* personArr[])
{
    // Pointer that will be used to traverse each linked list
    personNode* iterPtr = nullptr;
    // Prints the staff
    iterPtr = personArr[0];
    std::cout << "            < Staff >            " << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    while (iterPtr != nullptr)
    {
        // Prints staff information
        std::cout << std::setw(5) << iterPtr->data->getId()
            << std::setw(10) << formattedString(iterPtr->data->getName())
            << std::setw(4) << iterPtr->data->getCount() << "   ";
        for (int i = 0; i < STAFF_MAX; i++)
        {
            std::cout << iterPtr->data->getCode()[i] << "   ";
        }
        std::cout << std::endl;
        iterPtr = iterPtr->link;
    }
    std::cout << std::endl;
    // Prints the students
    iterPtr = personArr[1];
    std::cout << "            < Students >            " << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    while (iterPtr != nullptr)
    {
        // Prints student information
        std::cout << std::setw(5) << iterPtr->data->getId()
            << std::setw(10) << formattedString(iterPtr->data->getName())
            << std::setw(4) << iterPtr->data->getCount() << "   ";
        for (int i = 0; i < STUDENT_MAX; i++)
        {
            std::cout << iterPtr->data->getCode()[i] << "   ";
        }
        std::cout << std::endl;
        iterPtr = iterPtr->link;
    }
    std::cout << std::endl;
    // Prints the adults
    iterPtr = personArr[2];
    std::cout << "            < Adults >            " << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    while (iterPtr != nullptr)
    {
        // Prints adult information
        std::cout << std::setw(5) << iterPtr->data->getId()
            << std::setw(10) << formattedString(iterPtr->data->getName())
            << std::setw(4) << iterPtr->data->getCount() << "   ";
        for (int i = 0; i < ADULT_MAX; i++)
        {
            std::cout << iterPtr->data->getCode()[i] << "   ";
        }
        std::cout << std::endl;
        iterPtr = iterPtr->link;
    }
}