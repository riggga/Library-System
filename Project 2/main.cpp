/**
 * Project #2
 * Yewei Wang
 * 10669043
 * Submission Date: 12/11/2024
*/

#include <iostream>
#include <fstream>
#include "book.h"
#include "adult.h"
#include "children.h"
#include "computer.h"
#include "history.h"
#include "novel.h"
#include "person.h"
#include "staff.h"
#include "student.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * @struct BookNode
 * @brief Represents a node in a linked list of books.
 */
struct BookNode{

    Book* book;
    BookNode* link;
};

/**
 * @struct PersonNode
 * @brief Represents a node in a linked list of persons.
 */
struct PersonNode{

    Person* person;
    PersonNode* link;
};

const int NUM_BOOK_TYPE = 4;
const int NUM_PERSON_TYPE = 3;
const int MAX_BOOK_TITLE_LENGTH = 10000;

/**
 * @brief Prints all books grouped by type.
 * @param lib Array of BookNode pointers representing different book types.
 */
void printAllBooks(BookNode* lib[4]);

/**
 * @brief Reads books from an input file and populates the library.
 * @param reader Input file stream containing book data.
 * @param library Array of BookNode pointers to store books by type.
 */
void book_reader(ifstream& reader, BookNode* library[NUM_BOOK_TYPE]);

/**
 * @brief Reads persons from an input file and populates the person list.
 * @param reader Input file stream containing person data.
 * @param person Array of PersonNode pointers to store persons by type.
 */
void person_reader(ifstream& reader, PersonNode* person[NUM_PERSON_TYPE]);

/**
 * @brief Gets the type of a book based on its code.
 * @param code The code of the book.
 * @return A string representing the book type (e.g., "children", "novel").
 */
string getBookType(int code);


/**
 * @brief Gets the type of a person based on their ID.
 * @param id The ID of the person.
 * @return A string representing the person type (e.g., "staff", "student").
 */
string getPersonType(int id);

/**
 * @brief Inserts a new Book into the linked list.
 * @param head Pointer to the head of the BookNode linked list.
 * @param b Pointer to the Book object to insert.
 */
void insert(BookNode*& head, Book* b);

/**
 * @brief Inserts a new Person into the linked list.
 * @param head Pointer to the head of the PersonNode linked list.
 * @param p Pointer to the Person object to insert.
 */
void insert(PersonNode*& head, Person* p);

/**
 * @brief Prints the list of all persons in a linked list.
 * @param head Pointer to the head of the PersonNode linked list.
 */
void printList(PersonNode* head);

/**
 * @brief Prints the list of all books in a linked list.
 * @param head Pointer to the head of the BookNode linked list.
 */
void printList(BookNode* head);

/**
 * @brief Searches for a book in the library by title.
 * @param lib Array of BookNode pointers representing different book types.
 * @param title The title of the book to search for.
 * @return A pointer to the BookNode containing the book, or nullptr if not found.
 */
BookNode* findBook(BookNode* lib[NUM_BOOK_TYPE], string title);

/**
 * @brief Searches for a book in the library by code.
 * @param lib Array of BookNode pointers representing different book types.
 * @param code The code of the book to search for.
 * @return A pointer to the BookNode containing the book, or nullptr if not found.
 */
BookNode* findBook(BookNode* lib[NUM_BOOK_TYPE], int code);

/**
 * @brief Searches for a person in the library by ID.
 * @param person Array of PersonNode pointers representing different person types.
 * @param id The ID of the person to search for.
 * @return A pointer to the PersonNode containing the person, or nullptr if not found.
 */
PersonNode* findPerson(PersonNode* person[NUM_PERSON_TYPE], int id);

/**
 * @brief Replaces underscores in a string with spaces.
 * @param str The character array containing the string.
 */
void replaceUnderscoresWithSpaces(char str[MAX_BOOK_TITLE_LENGTH]);

/**
 * @brief Handles the menu for searching a book by title.
 * @param library Array of BookNode pointers representing different book types.
 */
void menu_one(BookNode* library[NUM_BOOK_TYPE]);

/**
 * @brief Handles the menu for showing person information.
 * @param library Array of BookNode pointers representing different book types.
 * @param person Array of PersonNode pointers representing different person types.
 */
void menu_two(BookNode* library[NUM_BOOK_TYPE], PersonNode* person[NUM_PERSON_TYPE]);

/**
 * @brief Handles the menu for renting a book.
 * @param library Array of BookNode pointers representing different book types.
 * @param person Array of PersonNode pointers representing different person types.
 */
void menu_three(BookNode* library[NUM_BOOK_TYPE], PersonNode* person[NUM_PERSON_TYPE]);

/**
 * @brief Handles the menu for returning a rented book.
 * @param library Array of BookNode pointers representing different book types.
 * @param person Array of PersonNode pointers representing different person types.
 */
void menu_four(BookNode* library[NUM_BOOK_TYPE], PersonNode* person[NUM_PERSON_TYPE]);

/**
 * @brief Deletes all nodes in a linked list of BookNode.
 * @param head Pointer to the head of the BookNode linked list.
 */
void deleteList(BookNode* head);

/**
 * @brief Deletes all nodes in a linked list of PersonNode.
 * @param head Pointer to the head of the PersonNode linked list.
 */
void deleteList(PersonNode* head);


int main(){

    // Arrays for storing book and person data
    BookNode* library[NUM_BOOK_TYPE] = {nullptr};
    PersonNode* person[NUM_PERSON_TYPE] = {nullptr};

    // Input file names
    string file1, file2;

    // File streams
    ifstream bookReader, personReader;

    int choice;
    bool run = true;

    // Get filenames for book and person data
    cout << "Enter filename 1: ";
    cin >> file1;
    cout << "Enter filename 2: ";
    cin >> file2;

    // Open input files
    bookReader.open(file1);
    personReader.open(file2);

    // Populate book and person data from files
    book_reader(bookReader, library);
    person_reader(personReader, person);

    // Close input files
    bookReader.close();
    personReader.close();
    
    // Main menu loop
    do {
        cout << "----------------------------------------" << endl;
        cout << setw(22) << "MENU" << endl;
        cout << "----------------------------------------" << endl;

        cout << setw(3) << "1. Search a book\n" << setw(3) << "2. Show my information\n" << setw(3) << "3. Rent a Book\n" << setw(3) << "4. Return a book\n" << setw(3) << "5. Show all books\n" << setw(3) << "6. Exit the program\n" << endl;

        cout << setw(3) << "Choose one menu [1-6]: ";
        cin >> choice;

        switch(choice) {
            case 1:
                menu_one(library);  // Search for a book
                break;

            case 2:
                menu_two(library, person); // Show person info
                break;

            case 3:
                menu_three(library, person); // Rent a book
                break;

            case 4: 
                menu_four(library, person); // Return a book
                break;

            case 5: 
                printAllBooks(library); // Display all books
                break;

            case 6:
                for(int i = 0; i < NUM_BOOK_TYPE; i++){
                    deleteList(library[i]);
                }
                for(int i = 0; i < NUM_PERSON_TYPE; i++){
                    deleteList(person[i]);
                }

                run = false;
                break;

            default:
                cout << "Error";
                break;
        }

    } while(run);
    
    
    return 0;
}



void menu_one(BookNode* library[NUM_BOOK_TYPE]){

    string book_title;

    cin.clear();    
    cin.ignore(INT_MAX, '\n'); 

    cout << "Enter book title: ";
    
    getline(cin, book_title);

    

    try{
        
        // Search for the book
        BookNode* node = findBook(library, book_title);

        if(!node) {
            throw book_title;
        }

        Book* book = node->book;

        string bookType = getBookType(book->getCode());
        
        // Display book details based on type

        cout << "\nCode: " << book->getCode() << endl;

        char cTitle[10000];
        strcpy(cTitle, book->getTitle().c_str());
        replaceUnderscoresWithSpaces(cTitle);

        cout << "Title: " << cTitle << endl;
        

        if(bookType == "children") {                   
            cout << "Age: " << book->getAge() << endl;
        } else if(bookType == "computer") {    
            cout << "Publisher: " << book->getPublisher() << endl;      
        } else if(bookType == "novel") {
            cout << "Publish Year: " << book->getPublishYear() << endl;
        } else if(bookType == "history") {
            cout << "Author: " << book->getAuthor() << endl;             
        }

        cout << "Available: " << book->getAvailable() << endl;
        cout << "Rented: " << book->getRented() << endl;



    } catch(const string& title) {
        cout << "\nThe book ' " << title << " ' does not exist." << endl;
    }
}

void menu_two(BookNode* library[NUM_BOOK_TYPE], PersonNode* person[NUM_PERSON_TYPE]){

    int id;
    
    // Get person ID from the user
    cout << "Enter your id: ";
    cin >> id;
    
    try{
        // Find the person by ID
        PersonNode* node = findPerson(person, id);
        
        if(!node){
            throw id;
        }
        // Display person's borrowed books
        cout << "\nYou are '" << node->person->getName() << "'. You borrowed " << node->person->getCount() << " books." << endl;
        for(int i = 0; i < node->person->getCount(); i++){
            int code = node->person->getCode(i);
            BookNode* bNode = findBook(library, code);
            
            char cTitle[10000];
            strcpy(cTitle, bNode->book->getTitle().c_str());
            replaceUnderscoresWithSpaces(cTitle);

            cout << i+1 << ". " << cTitle << " (" << code << ")" << endl;
            
        } 

    } catch(int i){
        // Handle exception when person is not found
        cout << "\nID " << i << " not found." << endl;
    }
}

void menu_three(BookNode* library[NUM_BOOK_TYPE], PersonNode* person[NUM_PERSON_TYPE]){

    int id;
    string book_title;

    // Get person ID and book title
    cout << "Enter your id: ";
    cin >> id;

    cin.clear();    
    cin.ignore(INT_MAX, '\n'); 

    cout << "Enter book title: ";
    getline(cin, book_title);
    

    try{

        // Find the person and the book
        PersonNode* pNode = findPerson(person, id);
        BookNode* bNode = findBook(library, book_title);


        // Check if the book is available and the person can borrow more books
        if(bNode->book->getAvailable() == 0){
            throw "book";
        } else if(pNode->person->isFull()){
            throw "person";
        } else{
            int idx = pNode->person->getNextAvailableIndex();
            int code = bNode->book->getCode();
            

            pNode->person->setCode(code, idx);
            pNode->person->setCount(pNode->person->getCount() + 1);

            bNode->book->setAvailable(bNode->book->getAvailable() - 1);
            bNode->book->setRented(bNode->book->getRented() + 1);

            // Display success message
            cout << "\nYou are '" << pNode->person->getName() << "'. The book " << book_title << " is available." << endl;
            cout << "Rent Succeed. Now you borrowed " << pNode->person->getCount() << " books." << endl;

            for(int i = 0; i < pNode->person->getCount(); i++){
                int code = pNode->person->getCode(i);
                BookNode* bNode = findBook(library, code);

                char cTitle[10000];
                strcpy(cTitle, bNode->book->getTitle().c_str());
                replaceUnderscoresWithSpaces(cTitle);

                cout << i+1 << ". " << cTitle << endl;
                
            } 

        }

    } catch(const char* type){
        if(string(type) == "book") {
            cout << "\nThe book " << book_title << " is not available." << endl;
        } else{
            cout << "\nYou have already borrowed books to max." << endl;
        }
    }
}

void menu_four(BookNode* library[NUM_BOOK_TYPE], PersonNode* person[NUM_PERSON_TYPE]){

    int id;
    string book_title;

    // Get person ID and book title
    cout << "Enter your id: ";
    cin >> id;

    cin.clear();    
    cin.ignore(INT_MAX, '\n'); 

    cout << "Enter book title: ";
    getline(cin, book_title);

    try{

        // Find the person and the book
        PersonNode* pNode = findPerson(person, id);
        BookNode* bNode = findBook(library, book_title);
        int code = bNode->book->getCode();

        // Check if the person borrowed the book
        if(!pNode->person->borrowedBook(code)){
            throw book_title;
        }

        // Return the book
        pNode->person->removeBook(code);
        pNode->person->setCount(pNode->person->getCount() - 1);

        bNode->book->setAvailable(bNode->book->getAvailable() + 1);
        bNode->book->setRented(bNode->book->getRented() - 1);

        cout << "\nYou are '" << pNode->person->getName() << ". The book " << book_title << " is returned." << endl;
        cout << "Return succeed. Now you borrowed " << pNode->person->getCount() << " book." << endl;

        // List all remaining borrowed books
        for(int i = 0; i < pNode->person->getCount(); i++){
            code = pNode->person->getCode(i);
            bNode = findBook(library, code);

            char cTitle[10000];
            strcpy(cTitle, bNode->book->getTitle().c_str());
            replaceUnderscoresWithSpaces(cTitle);

            cout << i+1 << ". " << cTitle << endl;
            
        } 


    } catch (const string& title){
        cout << "\nYou did not borrow " << title << "." << endl;
    }
}

BookNode* findBook(BookNode* lib[NUM_BOOK_TYPE], string title){

    for(int i = 0; i < NUM_BOOK_TYPE; i++){
        BookNode* current_head = lib[i];

        while(current_head){
            if(current_head->book->getTitle() == title){
                return current_head;
            }
            current_head = current_head->link;
        }

    }

    return nullptr;



}

BookNode* findBook(BookNode* lib[NUM_BOOK_TYPE], int code){

    for(int i = 0; i < NUM_BOOK_TYPE; i++){
        BookNode* current_head = lib[i];

        while(current_head){
            if(current_head->book->getCode() == code){
                return current_head;
            }
            current_head = current_head->link;
        }

    }

    return nullptr;



}

PersonNode* findPerson(PersonNode* person[NUM_PERSON_TYPE], int id){

    for(int i = 0; i < NUM_PERSON_TYPE; i++){
        PersonNode* current_head = person[i];

        while(current_head){
            if(current_head->person->getId() == id){
                return current_head;
            }
            current_head = current_head->link;
        }

    }

    return nullptr;



}
void printAllBooks(BookNode* lib[4]) {
    for(int i = 0; i < 4; i++){
        switch(i) {
            case 0:
                cout << setw(42) << " <<< Children Book >>>" << endl;
                cout << "------------------------------------------------------------------" << endl;
                break;
            case 1:
                cout << setw(42) << " <<< Computer Book >>>" << endl;
                cout << "------------------------------------------------------------------" << endl;
                break;
            case 2:
                cout << setw(38) << " <<< Novel >>>" << endl;
                cout << "------------------------------------------------------------------" << endl;
                break;
            case 3:
                cout << setw(42) << " <<< History Book >>>" << endl;
                cout << "------------------------------------------------------------------" << endl;
                break;
            default:
                cout << "Error" << endl;
                break;
        }

        printList(lib[i]);
        cout << endl;
    }
}
void book_reader(ifstream& reader, BookNode* library[NUM_BOOK_TYPE]){
    int code, age, publish_year, avail, rented;
    string title, publisher, author;
 

    while(reader >> code){
        string bookType = getBookType(code);


        // Insert into each linked list by type
        if(bookType == "children") {
            reader >> title >> age >> avail >> rented;
            
            Book* currBook = new ChildrenBook(code, title, age, avail, rented);
            insert(library[0], currBook);
        } else if(bookType == "computer") {
            reader >> title >> publisher >> avail >> rented;
        
            Book* currBook = new ComputerBook(code, title, publisher, avail, rented);
            insert(library[1], currBook);
        } else if(bookType == "novel") {
            reader >> title >> publish_year >> avail >> rented;
            
            Book* currBook = new Novel(code, title, publish_year, avail, rented);
            insert(library[2], currBook);

        } else if(bookType == "history") {
            reader >> title >> author >> avail >> rented;

            
            Book* currBook = new HistoryBook(code, title, author, avail, rented);
            insert(library[3], currBook);
        }

    }
    
}

void person_reader(ifstream& reader, PersonNode* person[NUM_PERSON_TYPE]){
    int id, count, code;
    string name, line;
    

    while(getline(reader, line)){

        stringstream ss(line);

        ss >> id >> name >> count;
        string personType = getPersonType(id);

        Person* currPerson = nullptr;

        // Insert into each linked list by type
        if(personType == "staff") {
            
            currPerson = new Staff(id, name, count);
            int idx = 0;

            while(ss >> code){
                currPerson->setCode(code, idx);
                idx++;
            }

            currPerson->sort_code();
            insert(person[0], currPerson);

        } else if(personType == "student") {
            
            currPerson = new Student(id, name, count);
            int idx = 0;
            
            while(ss >> code){
                currPerson->setCode(code, idx);
                idx++;
            }
            currPerson->sort_code();
            insert(person[1], currPerson);

        } else if(personType == "adult") {
            
            currPerson = new Adult(id, name, count);
            int idx = 0;
            
            while(ss >> code){
                currPerson->setCode(code, idx);
                idx++;
            }
            currPerson->sort_code();
            insert(person[2], currPerson);
        }

    }
    
}

string getBookType(int code){
    if(code >= 1001 && code <= 2000){
        return "children";
    } else if(code >= 2001 && code <= 3000){
        return "computer";
    } else if(code >= 3001 && code <= 4000){
        return "novel";
    } else if(code >= 4001 && code <= 5000){
        return "history";
    }

    return "";
}

string getPersonType(int id){
    if(id >= 1 && id <= 100){
        return "staff";
    } else if(id >= 101 && id <= 300){
        return "student";
    } else if(id >= 301 && id <= 1000){
        return "adult";
    } else{
        return "";
    }
}

void insert(BookNode*& head, Book* b) {
    BookNode* newNode = new BookNode;
    newNode->book = b;
    newNode->link = nullptr;
    
    if (!head) {
        head = newNode;
    } else {
        BookNode* current = head, *prev = nullptr, *next = nullptr;

        for(; current && newNode->book->getCode() > current->book->getCode(); current = current->link){
            prev = current;
            next = current->link;
            
        }


        if(!prev){
            newNode->link = head;
            head = newNode;
        } else if(!current){
            prev->link = newNode;
        } else{
            prev->link = newNode;
            newNode->link = next;
        }
    }

    
}



void insert(PersonNode*& head, Person* p) {
    PersonNode* newNode = new PersonNode;
    newNode->person = p;
    newNode->link = nullptr;

    if (!head) {
        head = newNode;
    } else {
        PersonNode* current = head, *prev = nullptr, *next = nullptr;
        
        for(; current && newNode->person->getId() > current->person->getId(); current = current->link){
            prev = current;
            next = current->link;
        }


        if(!prev){
            newNode->link = head;
            head = newNode;
        } else if(!current){
            prev->link = newNode;
        } else{
            prev->link = newNode;
            newNode->link = next;
        }
    }
}

void printList(PersonNode* head){

    if(!head){
        cout << "nothing";
    }

    for(PersonNode* curr = head; curr; curr = curr->link){
        curr->person->displayInfo();
        cout << endl;
        
    }

}

void printList(BookNode* head){

    if(!head){
        cout << "nothing";
    }
    
    for(BookNode* curr = head; curr; curr = curr->link){
        curr->book->displayInfo();
        cout << endl;
    }

}

void replaceUnderscoresWithSpaces(char str[MAX_BOOK_TITLE_LENGTH]) {
    for (int i = 0; i < MAX_BOOK_TITLE_LENGTH; i++){
        if (str[i]== '_') {
            str[i] = ' ';
        }
    }
}

void deleteList(BookNode* head){
    BookNode* ptr = nullptr;

    while (head) {
        ptr = head;
        head = head->link;
        delete ptr->book;
        delete ptr;
    }
}
void deleteList(PersonNode* head){
    PersonNode* ptr = nullptr;

    while (head) {
        ptr = head;
        head = head->link;

        delete ptr->person;
        delete ptr;
    }
}