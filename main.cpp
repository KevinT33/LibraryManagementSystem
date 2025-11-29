/******************************************************************************
Project 2
Kevin Truong
6/6/2025
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "node.h"
#include "functions.h"

int main()
{
    bookNode* library[4] = {nullptr}; // Structure of data that will contain linked lists of different
                                      // types of Book objects
    personNode* person[3] = {nullptr}; // Structure of data that will contain linked lists of different
                                       // types of Person objects

    std::ifstream ifs;
    std::string filename;
    // Gets the filename of the file containing the book data from the user
    while (true) // Repeats until a valid filename is inputted
    {
        std::cout << "Enter filename1: ";
        std::cin >> filename;
        ifs.open(filename); // connect ifstream and the file
        if (ifs.fail())
        {
            std::cout << "File Opening Failed, Try Again" << std::endl;
        }
        else
        {
            break;
        }
    }
    parseBookFile(ifs, library); // Parses the book file
    ifs.close();
    // Gets the filename of the file containing the person data from the user
    while (true) // Repeats until a valid filename is inputted
    {
        std::cout << "Enter filename2: ";
        std::cin >> filename;
        ifs.open(filename); // connect ifstream and the file
        if (ifs.fail())
        {
            std::cout << "File Opening Failed, Try Again" << std::endl;
        }
        else
        {
            break;
        }
    }
    parsePersonFile(ifs, person); // Parses the person file
    ifs.close();
    
    std::cout << std::endl;
    // Will contain the user's menu selection option (integer)
    int menuSelect = 0;
    while (menuSelect != 6)
    {
        // Displays the menu select screen
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "                   MENU                   " << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << " 1. Search a book" << std::endl;
        std::cout << " 2. Show my information" << std::endl;
        std::cout << " 3. Rent a book" << std::endl;
        std::cout << " 4. Return a book" << std::endl;
        std::cout << " 5. Show all books" << std::endl;
        std::cout << " 6. Exit the program" << std::endl;
        std::cout << std::endl;
        std::cout << "Choose one menu [1-6]: ";
        std::cin >> menuSelect; // Has the user input a selection
        std::cout << std::endl;
        
        switch (menuSelect) // Prints a result based on the user's menu selection
                            // (1-6 being the valid options)
        {
            case 1: //  Menu 1 (Has the user search for a book using its title and displays its information)
                searchBook(library);
                break;
            case 2: // Menu 2 (Has the user enter their id number and displays their information)
                showUserInfo(library, person);
                break;
            case 3: // Menu 3 (Has the user borrow a book)
                rentBook(library, person);
                break;
            case 4: // Menu 4 (Has the user return a book)
                returnBook(library, person);
                break;
            case 5: // Menu 5 (Displays all books in category lists along with their information)
                showAllBooks(library);
                break;
            case 6: // Menu 6 (Prepares the program to exit)
                prepareExit(library, person);
                break;
            default: // Reprompts if the user enters an invalid number
                std::cout << "Invalid selection, try again" << std::endl;
                break;
        }
        std::cout << std::endl;
    }
    
    return 0;
}