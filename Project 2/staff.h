#include <iostream>
#include "person.h"
#include <iomanip>
using namespace std;


class Staff : public Person{

    private:
        int code[NUM_STAFF_BORROW] = {0};
        
    public:
        Staff() {
            setId(0);
            setName("");
            setCount(0);
        }
        Staff(int i, string n, int c) {
            setId(i);
            setName(n);
            setCount(c);
        }

        int getCode(int index) const override { return code[index]; }
        void setCode(int c, int index) override { code[index] = c; }

        void displayInfo()override{
            cout.setf(ios::right);
            cout << getId() << setw(6) << getName() << setw(6) << getCount();
            for(int i = 0; i < NUM_STAFF_BORROW; i++){
                if(code[i] != 0) {
                    cout << setw(6)  <<code[i];
                }
            }
        }

        bool isFull()override{
            if(code[NUM_STAFF_BORROW-1] != 0){
                return true;
            }
            return false;
        }

        int getNextAvailableIndex() override{
            for(int i = 0; i < NUM_STAFF_BORROW; i++){
                if(code[i] == 0) {
                    return i;
                }
            }
            return -1;
        }

        bool borrowedBook(int c) override{
            for(int i = 0; i < NUM_STAFF_BORROW; i++){
                if(this->code[i] == c) {
                    return true;
                }
            }
            return false;
        }

        void removeBook(int c)override{
            int idxToRemove;
            for(int i = 0; i < NUM_STAFF_BORROW; i++){
                if(this->code[i] == c) {
                    idxToRemove = i;
                }
            }
            this->code[idxToRemove] = 0;
            for (int i = idxToRemove; i < NUM_STAFF_BORROW - 1; i++) {
                code[i] = code[i + 1];
                code[i + 1] = 0;
            }

        }

        void sort_code() override {
            int i, j, min_idx;
            
            for (i = 0; i < NUM_STAFF_BORROW - 1; i++){
                if (code[i] == 0) continue;
                min_idx = i;
                for (j = i + 1; j < NUM_STAFF_BORROW; j++){
                    if (code[j] == 0) continue;
                    if (code[j] < code[min_idx])
                    min_idx = j;
                }
                

                if (min_idx != i)
                    swap(code[min_idx], code[i]);

            }  
        }
};