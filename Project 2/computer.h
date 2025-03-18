#include <iostream>
#include "book.h"
#include <iomanip>
using namespace std;


class ComputerBook : public Book{

    private:
        string publisher;

    public:

        ComputerBook(){
            setCode(0);
            setTitle("");
            setAvailable(0);
            setRented(0);
            publisher = "";
        }
        ComputerBook(int c, string t,  string pub, int avail, int rent){
            setCode(c);
            setTitle(t);
            setAvailable(avail);
            setRented(rent);
            publisher = pub;
        }

        string getPublisher() const override { return publisher; }

        void setPublisher(const string& pub) override { publisher = pub; }

        void displayInfo(){
            cout.setf(ios::right);
            cout << getCode() << setw(25) << getTitle() << setw(25) << publisher << setw(6) << getAvailable() << setw(6) << getRented(); 
        }
};