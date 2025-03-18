#include <iostream>
#include "book.h"
#include <iomanip>
using namespace std;


class ChildrenBook : public Book{

    private:
        int age;

    public:

        ChildrenBook(){
            setCode(0);
            setTitle("");
            setAvailable(0);
            setRented(0);
            age = 0;
        }

        ChildrenBook(int c, string t, int a, int avail, int rent){
            setCode(c);
            setTitle(t);
            setAvailable(avail);
            setRented(rent);
            age = a;
        }

        
        int getAge() const override { return age; }
        void setAge(int a) override { age = a; }

        void displayInfo(){
            cout.setf(ios::right);

            cout << getCode() << setw(25) << getTitle() << setw(25) << age << setw(6) << getAvailable() << setw(6) << getRented(); 
        
        }
};