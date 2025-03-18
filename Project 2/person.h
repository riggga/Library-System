#include <iostream>
using namespace std;

#define NUM_STUDENT_BORROW 2
#define NUM_STAFF_BORROW 3
#define NUM_ADULT_BORROW 4
#ifndef PERSON_H
#define PERSON_H

class Person{

    private:
        int id;
        string name;
        int count;

    public:

        // Getters

        /**
         * @brief Get the person's ID.
         * @return The ID of the person.
         */
        int getId() const { return id; }

        /**
         * @brief Get the person's name.
         * @return The name of the person.
         */
        string getName() const { return name; }

        /**
         * @brief Get the number of books borrowed.
         * @return Number of books currently borrowed.
         */
        int getCount() const { return count; }

        // Setters

        /**
         * @brief Set the person's ID.
         * @param i The ID to set.
         */
        void setId(int i) { id = i; }

        /**
         * @brief Set the person's name.
         * @param n The name to set.
         */
        void setName(const string& n) { name = n; }

        /**
         * @brief Set the number of books borrowed.
         * @param c The number of books.
         */
        void setCount(int c) { count = c; }

        // Virtual Methods

        /**
         * @brief Pure virtual method to display person details.
         */
        virtual void displayInfo() = 0;

        /**
         * @brief Get the code of a borrowed book at a specific index.
         * @param index The index of the book.
         * @return The code of the book.
         */
        virtual int getCode(int index) const  = 0;

        /**
         * @brief Set the code for a borrowed book at a specific index.
         * @param c The code of the book.
         * @param index The index to set.
         */
        virtual void setCode(int c, int index) = 0;

        /**
         * @brief Check if the person has reached their borrowing limit.
         * @return True if the limit is reached, false otherwise.
         */
        virtual bool isFull() = 0;

        /**
         * @brief Get the next available index for borrowing a book.
         * @return The index where the next book can be added.
         */
        virtual int getNextAvailableIndex() = 0;

        /**
         * @brief Check if the person has borrowed a specific book.
         * @param c The code of the book to check.
         * @return True if the book is borrowed, false otherwise.
         */
        virtual bool borrowedBook(int c) = 0;

        /**
         * @brief Remove a book from the borrowed list by its code.
         * @param c The code of the book to remove.
         */
        virtual void removeBook(int c) = 0;

        /**
         * @brief Sort the codes of borrowed books.
         */
        virtual void sort_code() = 0;
};

#endif