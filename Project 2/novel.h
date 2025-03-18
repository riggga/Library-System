#include <iostream>
#include "book.h"
#include <iomanip>
using namespace std;


class Novel : public Book{

    private:
        int publish_year;

    public:

        Novel(){
            setCode(0);
            setTitle("");
            setAvailable(0);
            setRented(0);
            publish_year = 0;
        }
        
        Novel(int c, string t, int year, int avail, int rent){
            setCode(c);
            setTitle(t);
            setAvailable(avail);
            setRented(rent);
            publish_year = year;
        }

        int getPublishYear() const override { return publish_year; }

        void setPublishYear(const int& year) override { publish_year = year; }

        void displayInfo(){
            cout.setf(ios::right);
            cout << getCode() << setw(25) << getTitle() << setw(25) << publish_year << setw(6) << getAvailable() << setw(6) << getRented(); 
        }
};