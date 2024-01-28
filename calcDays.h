// Name: Samuel Jordan (srjorda)
// Class: CPSC-1020-020 (Spring 2023)
// Date: February 4, 2023
// Description: This program provides asks the user a series of questions, and,
//              based on the information provided by the user, can be used to 
//              determine if and for how long they must isolate due to COVID-19.
// Time: 5 hours

#ifndef CALCDAYS_H
#define CALCDAYS_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "Date.h"
using namespace std;

int calcDays(const Date& date2, const Date& date1);

#endif