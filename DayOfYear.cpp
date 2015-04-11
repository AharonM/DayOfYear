#include <string>
#include <fstream>
#include "DayOfYear.h"
using namespace std;

//Definition of DayOfYear's Static member variables
string DayOfYear::monthName[NUM_MONTHS]={"January","February","March",
"April","May","June","July","August","September","October","November"
                                                         ,"December"};

int DayOfYear::endMonth[NUM_MONTHS]={31,59,90,120,151,181,212,243,273
                                                        ,304,334,365};


/* DayOfYear member function print:
* Input:
*  outfile - reference to output file
* Process:
*  calls findMonth to find the month and date of the day
* Output:
*  Prints the date and numeric value for the day of the year
*/

void DayOfYear::print(ofstream &outfile)
{
int index=findMonth(day);

if (index==-1)
{
outfile<<"Numeric input: "<<day<<endl;
outfile<<"Error:Invalid Number\n\n";
}
else
{
outfile<<"Numeric input: "<<day<<endl;
outfile<<"Date: "<<monthName[index]<<" "<< day-endMonth[index-1];
outfile<<endl<<endl;
}
}



/* DayOfYear member function printDay:
* Input:
*  outfile - reference to output file
* Process:
*  prints the numeric value of the day of the year
* Output:
*  Prints the date and numeric value for the day of the year
*/

void DayOfYear::printDay(ofstream &outfile)
{
outfile<<"\nNumeric day of the year: "<<day<<endl;
}


/* DayOfYear member function findMonth:
* Input:
*  day - user entered numeric day of the year
* Process:
*  Performs a linear search on the date[] array to get
*  different date numbers to compare with the requested day
* Output:
*  If found, the index of the requested day
*  is returned Otherwise, returns -1
*/

int DayOfYear::findMonth(int day)
{
for (int index = 0; index < NUM_MONTHS; index++)
if (day<=endMonth[index]&&day>1)
return index;
return -1;
}


/* DayOfYear member function getDay:
* Input:
*  none
* Process:
*  retrieves member variable day's value
* Output:
*  returns the member variable day
*/

int DayOfYear::getDay()
{
return day;
}


//************************************************
// Overloaded prefix ++ operator. Causes the     *
// member variable day to be incremented.        *
// Returns the  incremented  object.             *
//************************************************
DayOfYear DayOfYear::operator++()
{
if(day==365)
{
day=1;
}
else
{
++day;
}
return *this;
}

//************************************************
// Overloaded postfix ++ operator. Causes the    *
// member variable day to be incremented.        *
// value of the object before the increment.     *
//************************************************
DayOfYear DayOfYear::operator++(int)
{
DayOfYear temp = *this;
if(day==365)
{
temp=1;
}
else
{
day++;
}
return temp;
}





//************************************************
// Overloaded prefix -- operator. Causes the     *
// member variable day to be decremented.        *
// Returns the  decremented  object.             *
//************************************************

DayOfYear DayOfYear::operator--()
{
if(day==1)
{
day=365;
}
else
{
--day;
}
return *this;
}


//************************************************
// Overloaded postfix -- operator. Causes the    *
// member variable day to be decremented.        *
// value of the object before the decrement.     *
//************************************************
DayOfYear DayOfYear::operator--(int)
{
DayOfYear temp = *this;
if(day==1)
{
temp=365;
}
else
{
day--;
}
return temp;
}
