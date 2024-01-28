// Name: Samuel Jordan (srjorda)
// Class: CPSC-1020-020 (Spring 2023)
// Date: February 4, 2023
// Description: This program provides asks the user a series of questions, and,
//              based on the information provided by the user, can be used to 
//              determine if and for how long they must isolate due to COVID-19.
// Time: 5 hours

#include "calcDays.h"

/*******************************************************************************
                                    calcDays                            
                                                                                
        Takes two objects of class Date and determines the number of
        days between them. This is done by first taking a default date 
        (in this case 01/01/2021) and utilizing a for loop and nested
        conditionals to properly increment the days until it reaches an
        invalid day for the month; in that case, it will increment the
        month and reset the day. If it reaches an invalid month, it will
        increment the year and reset the day and month. This is done
        until the default date is equal to the desired date, and the
        accumulator variable (i) marks the difference in days. After
        doing this for both dates, the difference between differences
        is returned.

*******************************************************************************/

int calcDays(const Date& date2, const Date& date1) {
    
    Date def;
    int i;
    
    for(i = 0; date1.getDay() != def.getDay() ||
               date1.getMonth() != def.getMonth() ||
               date1.getYear() != def.getYear();
               i++) { // adds to def until it equals date1
        switch(def.getMonth()) { 
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(def.getDay() + 1 <= 31) 
                    { def.setDay(def.getDay() + 1); }
                else if(def.getMonth() + 1 <= 12) 
                    { def.setMonth(def.getMonth() + 1); def.setDay(1); }
                else 
                    { def.setYear(def.getYear() + 1); def.setMonth(1); def.setDay(1); }
                break;
            case 2:
                if(def.getDay() + 1 <= 28) 
                    { def.setDay(def.getDay() + 1); }
                else 
                    { def.setMonth(def.getMonth() + 1); def.setDay(1); }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(def.getDay() + 1 <= 30) 
                    { def.setDay(def.getDay() + 1); }
                else 
                    { def.setMonth(def.getMonth() + 1); def.setDay(1); }
                break;
        }
    }     
    int daysDiff1 = i; // number of iterations is days difference
    
    def = {1, 1, 2021}; // default reset
    for(i = 0; date2.getDay() != def.getDay() ||
               date2.getMonth() != def.getMonth() ||
               date2.getYear() != def.getYear(); 
               i++) { // adds to def until it equals date1
        switch(def.getMonth()) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(def.getDay() + 1 <= 31) 
                    { def.setDay(def.getDay() + 1); }
                else if(def.getMonth() + 1 <= 12) 
                    { def.setMonth(def.getMonth() + 1); def.setDay(1); }
                else 
                    { def.setYear(def.getYear() + 1); def.setMonth(1); def.setDay(1); }
                break;
            case 2:
                if(def.getDay() + 1 <= 28) 
                    { def.setDay(def.getDay() + 1); }
                else 
                    { def.setMonth(def.getMonth() + 1); def.setDay(1); }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(def.getDay() + 1 <= 30) 
                    { def.setDay(def.getDay() + 1); }
                else 
                    { def.setMonth(def.getMonth() + 1); def.setDay(1); }
                break;
        }
    } 
    int daysDiff2 = i; // number of iterations is days difference
    
    return (daysDiff1 - daysDiff2); // returns difference
}