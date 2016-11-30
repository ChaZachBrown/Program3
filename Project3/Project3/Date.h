//Zach Brown
//CS 201
//Fall 2015
//Program 3

#include <iostream>
using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;
public:
    
    Date();
    Date(int nMonth, int nDay, int nYear);

    friend istream& operator >>(istream& is, Date& date);//in 
    friend ostream& operator <<(ostream& os, const Date& date);

    

    friend  Date operator +( Date& d, const int N);
   friend const Date operator +(int N, Date& d);
    friend Date operator -(Date& d, const int N );
    friend int operator -(Date& d, Date& d2);

    
     Date operator++ ();
     Date operator++ (int i);
     Date operator-- ();
     Date operator-- (int i);


    const int getMonth();
    const int getDay();
    const int getYear();
    void setMonth(int nMonth);
    void setDay(int nDay);
    void setYear(int nYear);
    void setDate(int nMonth, int nDay, int nYear);
    const int totalDays();//finding total days from date input
    
  friend  bool operator ==(Date& lhs, Date& rhs);
    friend bool operator !=(Date& lhs, Date& rhs);
    friend bool operator >(Date& lhs, Date& rhs);
    friend bool operator >=(Date& lhs, Date& rhs);
    friend bool operator <(Date& lhs, Date& rhs);
     friend bool operator <=(Date& lhs, Date& rhs);


};