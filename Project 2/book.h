#include <iostream>
using namespace std;
#ifndef BOOK_H
#define BOOK_H

/**
 * @class Book
 * @brief Represents a general book with its attributes and virtual methods
 */
class Book{

    private:
        int code; // Unique code for the book.
        string title; // Title of the book.
        int available; /// Number of copies available for borrowing
        int rented; /// Number of copies currently rented.
    
    public:


        // Getters

        /**
         * @brief Get the book's code.
         * @return The code of the book.
         */
        int getCode() const { return code; }

        /**
         * @brief Get the book's title.
         * @return The title of the book.
         */
        string getTitle() const { return title; }

        /**
         * @brief Get the number of available copies.
         * @return Number of copies available.
         */
        int getAvailable() const { return available; }

        /**
         * @brief Get the number of rented copies.
         * @return Number of copies currently rented.
         */
        int getRented() const { return rented; }


        // Setters

        /**
         * @brief Set the book's code.
         * @param c The code to set.
         */
        void setCode(int c) { code = c; }

        /**
         * @brief Set the book's title.
         * @param t The title to set.
         */
        void setTitle(const string& t) { title = t; }

        /**
         * @brief Set the number of available copies.
         * @param avail Number of copies available.
         */
        void setAvailable(int avail) { available = avail; }

        /**
         * @brief Set the number of rented copies.
         * @param rent Number of copies rented.
         */
        void setRented(int rent) { rented = rent; }

        // Virtual Methods

        /**
         * @brief Pure virtual method to display book details. To be implemented by derived classes.
         */
        virtual void displayInfo() = 0;
        
        /**
         * @brief Get the age for children's books.
         * @return The age.
         */                                                                                                                                                                                                                                                                                                                                                                            
        virtual int getAge() const { return 0; }

        /**
         * @brief Set the age for children's books.
         * @param a The age to set.
         */
        virtual void setAge(int a) {return;}

        /**
         * @brief Get the publisher of the book.
         * @return The publisher name.
         */
        virtual string getPublisher()const { return ""; }

        /**
         * @brief Set the publisher for computer books.
         * @param pub The publisher name to set.
         */
        virtual void setPublisher(const string& pub) {return;}

        /**
         * @brief Get the author of the book.
         * @return The author's name. 
         */
        virtual string getAuthor() const { return ""; }
        /**
         * @brief Set the author for history books.
         * @param auth The author's name to set.
         */
        virtual void setAuthor(const string& auth) {return;}

        /**
         * @brief Get the publication year of the book.
         * @return The publication year.
         */
        virtual int getPublishYear() const { return 0; }
        /**
         * @brief Set the publication year for novels.
         * @param year The publication year to set.
         */
        virtual void setPublishYear(const int& year){return;}
};

#endif