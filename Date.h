// Name: Samuel Jordan (srjorda)
// Class: CPSC-1020-020 (Spring 2023)
// Date: February 4, 2023
// Description: This program provides asks the user a series of questions, and,
//              based on the information provided by the user, can be used to 
//              determine if and for how long they must isolate due to COVID-19.
// Time: 5 hours

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

class Date {
    private:
        // attributes
        int day;
        int month;
        int year;
    
    public:
        // constructors
        Date();
        Date(int d, int m, int y); 
        
        // set member functions
        bool setDay(int d);
        bool setMonth(int m);
        bool setYear(int y);
        
        // get member functions
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        
        // show member function
        string showDate();
};

#endif