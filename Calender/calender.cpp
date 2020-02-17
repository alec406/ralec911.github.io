#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

bool isLeapYear(int year)
{
 return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int getTotalNumberOfDaysInMonth(int year, int month) {
    if(month == 1 || month == 3 || month == 5 || month ==7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    else if(month == 2) {
        if(isLeapYear(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else {
        return 30;
    }
}

int getTotalNumberofDays(int year, int month) {
    int yearCount = 1800;
    int monthCount = 1;
    int totalDays = 0;

    //first find days until current year
    while(yearCount != year) {
        if(isLeapYear(yearCount)) {
            totalDays += 366;
        }
        else {
            totalDays += 365;
        }
        yearCount++;  
    }

    //next find remaining number of days until the correct month
    while(monthCount != month) {
        totalDays += getTotalNumberOfDaysInMonth(year, monthCount);
        monthCount++;
    }

    return totalDays;

}

int getStartDay1800() {
    return 3;
}

int getStartDate(int year, int month) {
    int startDate = (getTotalNumberofDays(year, month) + getStartDay1800()) % 7;
}

void printHeader(int month, int year) {
    if(month == 1) {
        cout << setw(15) << "January " << year << endl;
    }
    else if(month == 2) {
        cout << setw(16) << "February " << year << endl;
    }
    else if(month == 3) {
        cout << setw(15) << "March " << year << endl;
    }
    else if(month == 4) {
        cout << setw(15) << "April " <<year << endl;
    }
    else if(month == 5) {
        cout << setw(13) << "May " << year << endl;
    }
    else if(month == 6) {
        cout << setw(14) << "June " << year << endl;
    }
    else if(month == 7) {
        cout << setw(14) << "July " << year << endl;
    }
    else if(month == 8) {
        cout << setw(15) << "August " << year << endl;
    }
    else if(month == 9) {
        cout << setw(17) << "September " << year << endl;
    }
    else if(month == 10) {
        cout << setw(16) << "October " << year << endl;
    }   
    else if(month == 11) {
        cout << setw(16) << "November " << year << endl;
    } 
    else {
        cout << setw(16) << "December " << year << endl;
    }

    cout << "---------------------------" << endl;

    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
}

void printCalender(int startDate, int month, int year) {
     int daysInMonth = 0;
     int dayOfWeek = 0;
     int dayTracker = 1;

     //first print the header
     printHeader(month, year);

     //next get number of days in the month
     daysInMonth = getTotalNumberOfDaysInMonth(year, month);

     //next print blank days from previous month
    while(dayOfWeek != startDate) {
        cout << "    ";
        dayOfWeek++;
    }

    //next print days of the month
    for(int i = 0; i < daysInMonth; i++) {
        if(dayTracker < 10) {
            cout << " " << dayTracker << "  ";
        }
        else {
            cout << " " << dayTracker << " ";
        }
        dayTracker++;
        if(dayOfWeek == 6) {
            cout << endl;
            dayOfWeek = 0;
        }
        else{
            dayOfWeek++;
        }
    }



}


int main() {
    int year = 0;
    int month = 0;
    int startDate = 0;
    
    //get valid input for year
    do {
        cout << "Enter full year (e.g., 2001): " << endl;
        cin >> year;
        
        if(year < 1800) {
            cout << "Not a valid year" << endl;
            cout << endl;
        }
        else{
            //get valid input for month
            do {
                cout << "Enter month in number between 1 and 12: " << endl;
                cin >> month;

                if(month < 1 || month > 12) {
                    cout << "Not a valid month" << endl;
                    cout << endl;
                }
            }while(month < 1 || month > 12);//loops if month is not valid
            
        }
        
    }while(year < 1800); // loops if year is not valid

    
    startDate = getStartDate(year, month);

    cout << startDate << endl;

    printCalender(startDate, month, year);

    cout << endl;

    return 0;
}