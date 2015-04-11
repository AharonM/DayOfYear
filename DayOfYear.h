#ifndef DAYOFYEAR_H_INCLUDED
#define DAYOFYEAR_H_INCLUDED
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
const int NUM_MONTHS=12;

class DayOfYear
{
private:
static string monthName[NUM_MONTHS];
static int endMonth[NUM_MONTHS];
int day;
public:
//Constructors
    /* DayOfYear default constructor:
    * Input:
    *  none
    * Process:
    *  sets object's data members to default values
    * Output:
    *  object's data members are set
    */

    DayOfYear()
    {
        day=0;
    }


    /* DayOfYear constructor #2:
    * Input:
    * fDay - user entered numeric day of the year
    * Process:
    * sets member variable day to fDay
    * Output:
    * none
    */
    DayOfYear(int fDay)
    {
        day=fDay;
    }


    /* DayOfYear constructor 3:
    * Input:
    * sMonth- a string representing the month
    * sDate- an integer in the range 0 to 31
    * representing the day of the month
    * Process:
    * searches the monthName array for the entered month and
    * when found assigns member variable day its numeric value
    * Output:
    * none
    */

    DayOfYear(string sMonth,int sDate)
    {
        if (sDate<1 || sDate>31)
        {
            cout<<"Error: Day is out of range.\n";
            exit(0);
        }

        int count=0;
        while (sMonth != monthName[count])
            count++;
        if(sMonth==monthName[1] && sDate>28)
        {
            cout<<"Error: Day is out of range.\n";
            exit(0);
        }
        else if(sMonth==monthName[3] && sDate>30)
        {
            cout<<"Error: Day is out of range.\n";
            exit(0);
        }
        else if(sMonth==monthName[5] && sDate>30)
        {
            cout<<"Error: Day is out of range.\n";
            exit(0);
        }
        else if(sMonth==monthName[8] && sDate>30)
        {
            cout<<"Error: Day is out of range.\n";
            exit(0);
        }
        else if(sMonth==monthName[10] && sDate>30)
        {
            cout<<"Error: Day is out of range.\n";
            exit(0);
        }
        else
            day=endMonth[count-1]+sDate;
    }

//Member functions
void print(ofstream &);
void printDay(ofstream &);
int findMonth(int);
int getDay();
//Overloaded operators
DayOfYear operator++();
DayOfYear operator++(int);
DayOfYear operator--();
DayOfYear operator--(int);
};
#endif // DAYOFYEAR_H_INCLUDED
