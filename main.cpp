// Name: Samuel Jordan (srjorda)
// Class: CPSC-1020-020 (Spring 2023)
// Date: February 4, 2023
// Description: This program provides asks the user a series of questions, and,
//              based on the information provided by the user, can be used to 
//              determine if and for how long they must isolate due to COVID-19.
// Time: 5 hours

#include "calcDays.h"
#include "Date.h"

int main() {
    
    bool invalid = false;   // used constantly for data validation
    string result;          // stores positive/negative and Yes/No
    Date datePositive,      // date user tested positive
         dateExposed,       // date user was exposed to positive case
         dateSecondDose;    // date user received their second vaccination
    int d, m, y;            // Short-term storage for day, month, and year ints
    
/////////////////////////////// Test Result Prompt /////////////////////////////

// this loop is an exaple of the format of following loops

    do { // do while loops utlilized to loop prompt if invalid data is given
        cout << "Test result: ";    // prompt shown to user
        cin >> result;              // information entered by user
        if (result != "positive" && result != "negative") { // input checked
            invalid = true;         // if invalid, then marked invalid
            cout << "Invalid input detected. Please enter valid input." << endl;
        }                           // user informed data entered was invalid
        else invalid = false;       // if not invalid, marked not invalid
    } while(invalid);               // if data was marked invalid, loops again
    
    
//******************************* Positive Branch ******************************

    if(result == "positive") {
        do {
            cout << "Date tested positive: ";
            scanf("%d/%d/%d", &m, &d, &y);
            // if it can't set part of the date, the data is invalid
            if(!datePositive.setMonth(m) || !datePositive.setDay(d) || !datePositive.setYear(y)) {
                cout << "Invalid input detected. Please enter valid input." << endl;
                invalid = true;
            }
            else invalid = false;
        } while(invalid);
        cout << "Length of isolation: 5 days" << endl;
    }
    
//******************************* Negative Branch ******************************

    if(result == "negative") {
        do {
            cout << "Exposed to positive case: ";
            cin >> result;
            if(result != "Yes" && result != "No") {
                invalid = true;
                cout << "Invalid input detected. Please enter valid input." << endl;
            }
            else invalid = false;
        } while(invalid);
       
//========================= Not Exposed to Positive Case =======================
        
        if(result == "No") {
            cout << "Length of isolation: 0 days" << endl;
        }

//=========================== Exposed to Positive Case =========================

        if(result == "Yes") {
            do {
                cout << "Date exposed to positive case: ";
                scanf("%d/%d/%d", &m, &d, &y);
                if(!dateExposed.setMonth(m) || !dateExposed.setDay(d) || !dateExposed.setYear(y)) {
                    cout << "Invalid input detected. Please enter valid input." << endl;
                    invalid = true;
                }
                else invalid = false;
            } while(invalid);
            
            do {
                cout << "Second vaccination does received: ";
                cin >> result;
                if(result != "Yes" && result != "No") {
                    invalid = true;
                    cout << "Invalid input detected. Please enter valid input." << endl;
                }
                else invalid = false;
            } while(invalid);
            
//-------------------------- No Second Vaccination Dose ------------------------

            if(result == "No") {
                cout << "Vaccination status at time of exposure: not fully vaccinated" << endl;
                cout << "Length of isolation: 10 days" << endl;
            }
            
//--------------------------- Second Vaccination Dose --------------------------

            if(result == "Yes") {
                do {
                    cout << "Date second vaccination dose received: ";
                    scanf("%d/%d/%d", &m, &d, &y);
                    if(!dateSecondDose.setMonth(m) || !dateSecondDose.setDay(d) || !dateSecondDose.setYear(y)) {
                        cout << "Invalid input detected. Please enter valid input." << endl;
                        invalid = true;
                    }
                    else invalid = false;
                } while(invalid);
                
                cout << "Days between vaccination and exposure: " << calcDays(dateSecondDose, dateExposed) << endl;
                
                if(calcDays(dateSecondDose, dateExposed) >= 14) {
                    cout << "Vaccination status at time of exposure: fully vaccinated" << endl;
                    cout << "Length of isolation: 5 days" << endl;
                }
                else {
                    cout << "Vaccination status at time of exposure: not fully vaccinated" << endl;
                    cout << "Length of isolation: 10 days" << endl;
                }
            }
        }
    }
    
    return 0;
}