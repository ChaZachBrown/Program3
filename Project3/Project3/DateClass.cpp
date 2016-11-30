//Zach Brown
//CS 201
//Fall 2015
//Program 3

#include <iostream>
#include "Date.h"
using namespace std;
Date::Date()
{
    month = 1;
    day = 1;
    year = 2000;
}
bool leapYear(int lyear)//function to check leapyear
{
    if ((lyear % 4 == 0) && (lyear % 100 != 0))
    {
        return true;
    }
    else if ((lyear % 400 == 0) && (lyear != 0))
    {
        return true;
    }
    else
    {
        return false;
    }

}


 istream& operator >>(std::istream& in, Date& Date)//in. make anothertemp variable to check the input of the date and then ue the set functions to check and see if they are legit dates using switch statments.
{
     int tempMonth;
     int tempDay;
     int tempYear;
     char slash;
     
     
     in >> tempMonth >> slash >> tempDay >> slash >> tempYear;    
     Date.setDate(tempMonth, tempDay, tempYear);

   
    return in;
}


 ostream& operator <<(std::ostream& out, const Date& date)//out
{
    out << date.month << "/" << date.day << "/" << date.year;
    return out;
}

 


const int daysInYear(int Imonth, int Iyear)//find the number of days in the current year
 {
     int total=0;
     switch (Imonth-1)
     {
     case 11:
         total += 30;
     case 10:
         total += 31;
     case 9:
         total += 30;
     case 8:
         total += 31;
     case 7:
         total += 31;
     case 6:
         total += 30;
     case 5:
         total += 31;
     case 4:
         total += 30;
     case 3:
         total += 31;
     case 2:
         if (leapYear(Iyear))
             total += 29;
         else
             total += 28;
     case 1:
         total += 31;

        
    
     }
     return total;
  }
const int Date::totalDays()//add up all the days from previous years and then add the amount of days in the current year
 {
     int total = 0;
     for (int i = 0; i < year; i++)
     {
         if (leapYear(i))
             total += 366;
         else
             total += 365;
      }
     total += daysInYear(month, year);
     total += day;
     return total;
     
 }
 Date intcoversion(int IDate)// Takes an integer and converst it to a date
 {
     Date tempDate;
     int tempYear = 0;
     while (IDate >= 365)//years, iterates through and adds how many years there are
     {
         
         if ((leapYear(tempYear)) && (IDate > 366))
         {
             IDate -= 366;
         }
         else if ((!leapYear(tempYear)) && (IDate > 365))
         {
             IDate -= 365;
         }
         else
         {
             tempYear = 1;
             break;
         }
         tempYear += 1;
     }
     tempDate.setYear(tempYear);
     while (true)// goes through each month and subtracts  how many days are in each month and then sets the month and day
     {
     //January
         if (IDate == 0)
         {
             tempDate.setDay(1);
             break;
         }
     if (IDate >= 31)
     {
         tempDate.setMonth(1);
         IDate -= 31;
         if (IDate == 0)
             {
             tempDate.setDay(31);
             break;
             }
     }
     else
     {
         tempDate.setDay(IDate);// IDate=0;
         tempDate.setMonth(1);
         break;
         
     }
     
         //February START HERE 
     
     if (IDate >= 29)
     {
         if (leapYear(tempYear))
         {
             tempDate.setMonth(2);
             IDate -= 29;
             if (IDate == 0)
             {
                 tempDate.setDay(29);
                 break;
             }
         }
     }
    
     if (IDate >= 28)
     {
         if (!leapYear(tempYear))
         {
             tempDate.setMonth(2);
             IDate -= 28;
             if (IDate == 0)
             {
                 tempDate.setDay(28);
                 break;
             }
         }
     }
         else
         {
             
             tempDate.setDay(IDate);// IDate=0;
             tempDate.setMonth(2);
             break;
         }
         //March 
         if (IDate >= 31)
         {
             tempDate.setMonth(3);
             IDate -= 31;
             if (IDate == 0)
             {
                 tempDate.setDay(31);
                 break;
             }
         }
         else
         {
             tempDate.setDay(IDate);// IDate=0;
             tempDate.setMonth(3);
             break;
         }
         //April
         if (IDate >= 30)
         {
             tempDate.setMonth(4);
             IDate -= 30;
             if (IDate == 0)
             {
                 tempDate.setDay(30);
                 break;
             }
         }
         else
         {
             tempDate.setDay(IDate);// IDate=0;
             tempDate.setMonth(4);
             break;
         }
         //May
         if (IDate >= 31)
         {
             tempDate.setMonth(5);
             IDate -= 31;
             if (IDate == 0)
             {
                 tempDate.setDay(31);
                 break;
             }
         }
         else
         {
             tempDate.setDay(IDate);// IDate=0;
             tempDate.setMonth(5);
             break;
         }
         //June
         if (IDate >= 30)
         {
             tempDate.setMonth(6);
             IDate -= 30;
             if (IDate == 0)
             {
                 tempDate.setDay(30);
                 break;
             }
         }
         else
         {
             tempDate.setDay(IDate);// IDate=0;
             tempDate.setMonth(6);
             break;
         }
         //July
         if (IDate >= 31)
         {
             tempDate.setMonth(7);
             IDate -= 31;
             if (IDate == 0)
             {
                 tempDate.setDay(31);
                 break;
             }
         }
         else
         {
             tempDate.setDay(IDate);// IDate=0;
             tempDate.setMonth(7);
             break;
         }
         //August
         if (IDate >= 31)
         {
             tempDate.setMonth(8);
             IDate -= 31;
             if (IDate == 0)
             {
                 tempDate.setDay(31);
                 break;
             }
         }
         else
         {
             tempDate.setDay(IDate);// IDate=0;
             tempDate.setMonth(8);
             break;
         }
         //September
         if (IDate >= 30)
         {
             tempDate.setMonth(9);
             IDate -= 30;
             if (IDate == 0)
             {
                 tempDate.setDay(30);
                 break;
             }
         }
         else
         {
             tempDate.setDay(IDate);// IDate=0;
             tempDate.setMonth(9);
             break;
         }
         //October
         if (IDate >= 31)
         {
             tempDate.setMonth(10);
             IDate -= 31;
             if (IDate == 0)
             {
                 tempDate.setDay(31);
                 break;
             }
         }
         else
         {
             tempDate.setDay(IDate);// IDate=0;
             tempDate.setMonth(10);
             break;
         }
         //November
         if (IDate >= 30)
         {
             tempDate.setMonth(11);
             IDate -= 30;
             if (IDate == 0)
             {
                 tempDate.setDay(30);
                 break;
             }
         }
         else
         {
             tempDate.setDay(IDate);
             tempDate.setMonth(11);
             break;
         }
         //December
         if (IDate >= 31)
         {
             tempDate.setMonth(12);
             IDate -= 31;
             if (IDate == 0)
             {
                 tempDate.setDay(31);
                 break;
             }
         }
         else
         {
             tempDate.setDay(IDate);// IDate=0;
             tempDate.setMonth(12);
             break;
         }
        
     }
     return tempDate;
 }



 // Maths stuffs 

  Date operator +(  Date& d, const int N)//addition
 {
     int iDate;
     Date newDate;
     iDate = d.totalDays() + N;
     newDate = intcoversion(iDate);
     return newDate;

 }
 const Date operator +(const int N, Date& d)//addition
 {
     int tempI = N;
     Date tempD = d;
     return operator + (d, N);
 }

 Date operator -(Date& d, const int N)
 {
     int iDate;
     Date newDate;
     iDate = d.totalDays() - N;
     newDate = intcoversion(iDate);
     return newDate;
 }
 int operator -(Date& d, Date& d2)
 {
     int Date1;
     int Date2;
     int tempint;
     Date1 = d.totalDays();
     Date2 = d2.totalDays();
     if (Date1 < Date2)
     {
         tempint = Date2 - Date1;
     }
     else
     {
         tempint = Date1 - Date2;
     }
     return tempint;

 }


 //comparison opperators ************************************************************************************************
 bool operator ==(Date& lhs, Date& rhs)
 {
     return ((lhs.totalDays()) == (rhs.totalDays()));
     
 }
 bool operator !=(Date& lhs, Date& rhs)
 {
     return (lhs.totalDays() != rhs.totalDays());
 }
 bool operator >(Date& lhs, Date& rhs)
 {
     return (lhs.totalDays() > rhs.totalDays());
 }
 bool operator >=(Date& lhs, Date& rhs)
 {
     return (lhs.totalDays() >= rhs.totalDays());
 }
 bool operator <(Date& lhs, Date& rhs)
 {
     return (lhs.totalDays() < rhs.totalDays());
 }
 bool operator <=(Date& lhs, Date& rhs)
 {
     return (lhs.totalDays() <= rhs.totalDays());
 }


 Date Date::operator++()
 {
     int daysInMonth[12];
     daysInMonth[0] = 31;
     daysInMonth[1] = 28;
     daysInMonth[2] = 31;
     daysInMonth[3] = 30;
     daysInMonth[4] = 31;
     daysInMonth[5] = 30;
     daysInMonth[6] = 31;
     daysInMonth[7] = 31;
     daysInMonth[8] = 30;
     daysInMonth[9] = 31;
     daysInMonth[10] = 30;
     daysInMonth[11] = 31;
     int tempMonth = month;
     int tempDay = day;
     int tempYear = year;

     if (leapYear(tempYear))
     {
         daysInMonth[1] = 29;
     }

     if (tempDay + 1 > daysInMonth[tempMonth - 1])
     {
         if (tempMonth == 12)
         {
             tempYear++;
             tempDay++;
             tempMonth++;
         }
         else
         {
             tempDay = 1;
             tempMonth++;
         }
     }
     else
     {
         tempDay++;
     }
     return Date(tempMonth, tempDay, tempYear);
 } 
Date Date::operator++ (int i)
 {

    int daysInMonth[12];
    daysInMonth[0] = 31;
    daysInMonth[1] = 28;
    daysInMonth[2] = 31;
    daysInMonth[3] = 30;
    daysInMonth[4] = 31;
    daysInMonth[5] = 30;
    daysInMonth[6] = 31;
    daysInMonth[7] = 31;
    daysInMonth[8] = 30;
    daysInMonth[9] = 31;
    daysInMonth[10] = 30;
    daysInMonth[11] = 31;
    int tempMonth = month;
    int tempDay = day;
    int tempYear = year;

    if (leapYear(tempYear))
    {
        daysInMonth[1] = 29;
    }

    if (tempDay + 1 > daysInMonth[tempMonth])
    {
        if (tempMonth == 12)
        {
            tempYear++;
            tempDay = 1;
            tempMonth = 1;
        }
        else
        {
            tempDay = 1;
            tempMonth++;
        }
    }
    else
    {
        tempDay++;
    }
    return Date(tempMonth, tempDay, tempYear);
 }

Date Date::operator--()
{

    int daysInMonth[12];
    daysInMonth[0] = 31;
    daysInMonth[1] = 28;
    daysInMonth[2] = 31;
    daysInMonth[3] = 30;
    daysInMonth[4] = 31;
    daysInMonth[5] = 30;
    daysInMonth[6] = 31;
    daysInMonth[7] = 31;
    daysInMonth[8] = 30;
    daysInMonth[9] = 31;
    daysInMonth[10] = 30;
    daysInMonth[11] = 31;
    int tempMonth = month;
    int tempDay = day;
    int tempYear = year;

    if (leapYear(tempYear))
    {
        daysInMonth[1] = 29;
    }

    if (tempDay - 1 <= 0)
    {
        if (tempMonth == 1)
        {
            tempYear--;
            tempDay = daysInMonth[12];
            tempMonth = 12;
        }
        else
        {
            tempDay = daysInMonth[tempMonth - 1];
            tempMonth = tempMonth - 1;

            
        }
    }
    else
    {
        tempDay--;
    }
    return Date(tempMonth, tempDay, tempYear);
}

Date Date::operator--(int i)
{

    int daysInMonth[12];
    daysInMonth[0] = 31;
    daysInMonth[1] = 28;
    daysInMonth[2] = 31;
    daysInMonth[3] = 30;
    daysInMonth[4] = 31;
    daysInMonth[5] = 30;
    daysInMonth[6] = 31;
    daysInMonth[7] = 31;
    daysInMonth[8] = 30;
    daysInMonth[9] = 31;
    daysInMonth[10] = 30;
    daysInMonth[11] = 31;
    int tempMonth = month;
    int tempDay = day;
    int tempYear = year;

    if (leapYear(tempYear))
    {
        daysInMonth[1] = 29;
    }

    if (tempDay - 1 <= 0)
    {
        if (tempMonth == 1)
        {
            tempYear--;
            tempDay = daysInMonth[12];
            tempMonth = 12;
        }
        else
        {
            tempDay = daysInMonth[tempMonth - 1];
            tempMonth = tempMonth - 1;


        }
    }
    else
    {
        tempDay--;
    }
    return Date(tempMonth, tempDay, tempYear);
}



//getters ***************************************************************************************************************
const int Date::getMonth()
 {
    return month;
 }
const int Date:: getDay()
{
    return day;
}
const int Date::getYear()
{
    return year;
}

//Setters ****************************************************************************************************************
void Date::setMonth(int nMonth)
{
    month = nMonth;
}
void Date::setDay(int nDay)
{
    day = nDay;
}
void Date::setYear(int nYear)
{
    year = nYear;
}
//constructor########################################################
void Date::setDate(int nMonth, int nDay,int nYear)
{
    year = nYear;

    if (nMonth < 13 && nMonth >0)
    {
        month = nMonth;

        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (nDay > 0 && nDay <= 31)
            {
                day = nDay;

            }
            else
            {
                cout << "Not a vaid day" << endl;
            }
            break;
        case 2:
            if (nDay > 0 && nDay <= 28)


            {
                day = nDay;

            }
            else if ((nDay == 29) && (leapYear(year)))
            {
                day = nDay;
            }

            else
                cout << "Not a vaid day" << endl;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (nDay > 0 && nDay <= 30)
            {
                day = nDay;
            }
            else
                cout << "Not a vaid day" << endl;
            break;


        }
    }
    else
    {
        cout << "A valid month was not entered." << endl;
        
    }
}

Date::Date(int nMonth, int nDay, int nYear)
{
    year = nYear;
    if (nMonth < 13 && nMonth >0)
    {
        month = nMonth;

        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (nDay > 0 && nDay <= 31)
            {
                day = nDay;

            }
            else
            {
                cout << "Not a vaid day" << endl;
            }
            break;
        case 2:
            if (nDay > 0 && nDay <= 28)


            {
                day = nDay;

            }
            else if ((nDay == 29) && (leapYear(year)))
            {
                day = nDay;
            }

            else
                cout << "Not a vaid day" << endl;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (nDay > 0 && nDay <= 30)
            {
                day = nDay;
            }
            else
                cout << "Not a vaid day" << endl;
            break;


        }
    }
    else
        cout << "A valid month was not entered." << endl;

}


