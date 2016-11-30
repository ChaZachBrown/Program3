//Zach Brown
//CS 201
//Fall 2015
//Program 3

#include <iostream>
#include "Date.h"
#include <fstream>
#include <string>
using namespace std;
Date intcoversion(int IDate);

int main()
{
//###############################user requested files#####################################
    string fileName;
    cout << "What is the name of the input file?";
    getline(cin, fileName);
    ifstream fin;
    fin.open(fileName.c_str());
    while (!fin.is_open())//eeror checking for making sure the file is opened
    {
        cout << "The file could not open. Please enter the correct file: ";
        getline(cin, fileName);
        ifstream fin;
        fin.open(fileName.c_str());
        if (fin.is_open())//if file is opened, this will brek out of the error checking
        {
            break;
        }

    }
    string outname;
    cout << "What is the name of the output file?";
    getline(cin, outname);
    ofstream fout(outname);


 //#######################reading the input file##############################
    while (!fin.eof())
    {
        int firstC;
        fin >> firstC;

        if (firstC == 1)
        {
            Date tempDate;
            string tempOperator;
            int tempInt;
            Date newDate;
            fin >> tempDate;
            fin >> tempOperator;
            fin >> tempInt;
           
            
            if (tempOperator == "+")
            {
                fout << tempDate + tempInt<< endl;
            }

            if (tempOperator == "-")
            {
                fout << tempDate - tempInt << endl;

            }
       }
        if (firstC == 2)
        {
            Date tempDate;
            string tempOperator;
            int tempInt;
            Date newDate;
            fin >> tempInt;
            fin >> tempOperator;
            fin >> tempDate;
            
            if (tempOperator == "+")
            {
                fout << tempInt + tempDate << endl;
            }

        }
        if (firstC == 3)
        {
            Date tempDate;
            string tempOperator;
            Date tempDate2;
            Date newDate;
            fin >> tempDate;
            fin >> tempOperator;
            fin >> tempDate2;
            fout << tempDate - tempDate2 << endl;
        }
        if (firstC == 4)
        {
            Date tempDate;
            string tempOperator;
            Date tempDate2;
            fin >> tempDate;
            fin >> tempOperator;
            fin >> tempDate2;
            if (tempOperator == "==")
            {
                bool i;
                i = tempDate == tempDate2;
                if (i == true)
                    fout << "True" << endl;
                else
                    fout << "False" << endl;
            }
            if (tempOperator == ">")
            {
                bool i;
                i = tempDate > tempDate2;
                if (i == true)
                    fout << "True" << endl;
                else
                    fout << "False" << endl;
            }
            if (tempOperator == ">=")
            {
                bool i;
                i = tempDate >= tempDate2;
                if (i == true)
                    fout << "True" << endl;
                else
                    fout << "False" << endl;
            }
            if (tempOperator == "<")
            {
                bool i;
                i = tempDate < tempDate2;
                if (i == true)
                    fout << "True" << endl;
                else
                    fout << "False" << endl;
            }
            if (tempOperator == "<=")
            {
                bool i;
                i = tempDate <= tempDate2;
                if (i == true)
                    fout << "True" << endl;
                else
                    fout << "False" << endl;
            }
            if (tempOperator == "!=")
            {
                bool i;
                i = tempDate != tempDate2;
                if (i == true)
                    fout << "True" << endl;
                else
                    fout << "False" << endl;
            }
        }
    }



    
    Date newdate;
    Date thedate =  Date(1, 2, 3);
    cout << thedate.getDay()<< endl;
    cout << thedate.getMonth() << endl;
    cout << thedate.getYear() << endl;
    thedate.setDay(8);
    thedate.setMonth(2);
    thedate.setYear(222);
    cout << thedate << endl;


    int inte =365;//4745
    int Int = 28;
    newdate = intcoversion(inte);
    cout << newdate.totalDays()<< endl;
    Date date2;
    int inte2 = 365;
    date2 = intcoversion(inte2);
    //************ testing comparison operators
    if (newdate >= date2)
    {
        cout << ("true") << endl;
    }
    else
    {
        cout << ("false") << endl;
    }
    if (newdate != date2)
    {
        cout << ("true") << endl;
    }
    else
    {
        cout << ("false") << endl;
    }
    if (newdate <= date2)
    {
        cout << ("true") << endl;
    }
    else
    {
        cout << ("false") << endl;
    }
    if (newdate < date2)
    {
        cout << ("true") << endl;
    }
    else
    {
        cout << ("false") << endl;
    }
    if (newdate > date2)
    {
        cout << ("true") << endl;
    }
    else
    {
        cout << ("false") << endl;
    }

    if (newdate  == date2)
    {
        cout << ("true")<< endl;
    }
    else
    {
        cout << ("false")<< endl;
    }
   cout << date2 - newdate << endl;
   cout << thedate + 56 << endl;


    cout << newdate<< endl;
    cout << newdate++ << endl;
    cout << newdate--<< endl;
  
 
    system("pause");
    


    return 0;

}
