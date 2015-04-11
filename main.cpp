/*
Name: Assignment#6: Day of the Year
Author: Aharon Mishiev
Date: 11/05/2013
Description:Part 1 of This program prompts the user for a numeric
day of the year and converts it to a month and day format, in part 2
the program does the reverse action and prompts the user for a
month and day and displays its numeric equivalent and modifies it
using overloaded increment and decrement operators.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "DayOfYear.h"
using namespace std;

int main()
{
    DayOfYear part1,part2,part2i,part2d;
    string sMonth;
    int sDate;
    int fDay;
    // open output file
    ofstream outfile ("output.txt");
    outfile<<"Part 1 of the assignment:\n\n";
    int x=0;
    do
    {
        //Prompt for the day of the year
        cout<<"Enter the numeric day of the year you wish to convert: ";
        cin>>fDay;
        part1=DayOfYear(fDay);
        part1.print(outfile);
        x++;
    }
    while (x<5);

    x=0;
    outfile<<"\nPart 2 of the assignment:\n";
    do
    {
        cout<<"\nEnter the month and day you wish to convert: ";
        cin>>sMonth>>sDate;
        part2=DayOfYear(sMonth,sDate);
        outfile<<"\n\nEntered Month and Day: "<<sMonth<<" "<<sDate<<endl;
        part2.printDay(outfile);


        part2i=part2;
        part2d=part2;
//Postfix and Prefix Operators demonstrartions
        part2= ++part2i;
        outfile<<"\nPrefix++:\n";
        outfile<<"part2: "<<part2.getDay()<<endl;
        outfile<<"part2i: "<<part2i.getDay()<<endl;
        part2=part2i++;
        outfile<<"\nPostfix++:\n";
        outfile<<"part2: "<<part2.getDay()<<endl;
        outfile<<"part2i: "<<part2i.getDay()<<endl;

        part2=--part2d;
        outfile<<"\nPrefix--:\n";
        outfile<<"part2: "<<part2.getDay()<<endl;
        outfile<<"part2d: "<<part2d.getDay()<<endl;
        part2=part2d--;
        outfile<<"\nPostfix--:\n";
        outfile<<"part2: "<<part2.getDay()<<endl;
        outfile<<"part2d: "<<part2d.getDay()<<endl;
        x++;
    }
    while (x<5);
    return 0;
}
