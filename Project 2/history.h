#include <iostream>
#include "book.h"
#include <iomanip>
using namespace std;


class HistoryBook : public Book{

    private:
        string author;

    public:

        HistoryBook(){
            setCode(0);
            setTitle("");
            setAvailable(0);
            setRented(0);
            author = "";
        }

        HistoryBook(int c, string t, string auth, int avail, int rent){
            setCode(c);
            setTitle(t);
            setAvailable(avail);
            setRented(rent);
            author = auth;
        }

        string getAuthor() const override { return author; }

        void setAuthor(const string& auth) override { author = auth; }

        void displayInfo(){
            cout.setf(ios::right);
            cout << getCode() << setw(25) << getTitle() << setw(25) << author << setw(6) << getAvailable() << setw(6) << getRented(); 
        }
};

