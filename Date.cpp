// Name: Samuel Jordan (srjorda)
// Class: CPSC-1020-020 (Spring 2023)
// Date: February 4, 2023
// Description: This program provides asks the user a series of questions, and,
//              based on the information provided by the user, can be used to 
//              determine if and for how long they must isolate due to COVID-19.
// Time: 5 hours

#include "Date.h"

// constructors, both default and with data validation
Date::Date() { day = 1; month = 1; year = 2021; }
Date::Date(int d, int m, int y) : day{d}, month{m}, year{y} {
    if(y > 2022 || y < 2021)
        { day = 1; month = 1; year = 2021; }
    else if(m > 12 || m < 0)
        { day = 1; month = 1; year = 2021; }
    else {
        switch(m) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(d > 31 || d < 1) { day = 1; month = 1; year = 2021; }
                else { year = y; month = m; day = d; }
                break;
            case 2:
                if(d > 28 || d < 1) { day = 1; month = 1; year = 2021; }
                else { year = y; month = m; day = d; }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(d > 30 || d < 1) { day = 1; month = 1; year = 2021; }
                else { year = y; month = m; day = d; }
                break;
        }
    }
}
        
// setters, if valid request, set and return true. Otherwise, return false.
bool Date::setDay(int d) { 
    switch(month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(d > 31 || d < 1) { return false; }
                else { day = d; return true; }
                break;
            case 2:
                if(d > 28 || d < 1) { return false; }
                else { day = d; return true; }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(d > 30 || d < 1) { return false; }
                else { day = d; return true; }
                break;
            default:
                return false;
                break;
    }
}
bool Date::setMonth(int m) { 
    if(m > 12 || m < 0) { return false; }
    else { month = m; return true; }
}
bool Date::setYear(int y) { 
    if(y > 2022 || y < 2021) { return false; }
    else { year = y; return true; }
}
        
// getters, return requested value
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
        
// show function, returns a string of the Date in "MM/DD/YYYY" format
string Date::showDate() {
    string dispDate;
    string mm = to_string(month);
    string dd = to_string(day);
    string yyyy = to_string(year);
    
    if(mm.length() < 2) { mm = "0" + mm; }
    if(dd.length() < 2) { dd = "0" + dd; }
    
    dispDate = mm + "/" + dd + "/" + yyyy;
    
    return dispDate;
}