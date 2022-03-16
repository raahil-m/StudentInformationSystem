//
//  HeaderFinalProjStudent.h
//  1PR3 Final Project Login
//
//  Created by Raahil Mahetaji on 2018-04-01.
//  Copyright © 2018 Raahil Mahetaji. All rights reserved.
//

#ifndef HeaderFinalProjStudent_h
#define HeaderFinalProjStudent_h

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student
{
protected:
    string name;
    string studentNumber;
    string birthday;
    string address;
    string postalCode;
    string phoneNumber;
    int year;
    string term;
    string program;
    
public:
    Student()
    {
        name = "";
        studentNumber= "";
        birthday= "";
        address= "";
        postalCode= "";
        phoneNumber= "";
        year= 0;
        term= "";
        program= "";
    }
    Student(string aName, string aStudentNumber, string aBirthday, string aAddress, string aPostalCode, string aPhoneNumber, int aYear, string aTerm, string aProgram)
    {
        name = aName;
        studentNumber= aStudentNumber;
        birthday= aBirthday;
        address= aAddress;
        postalCode= aPostalCode;
        phoneNumber= aPhoneNumber;
        year= aYear;
        term= aTerm;
        program= aProgram;
    }
    void setAll(string n, string sN, string b, string a, string p, string pN, int y, string t, string pr);
    string getName();
    string getStudentNumber();
    string getBirthday();
    string getAddress();
    string getPostalCode();
    string getPhoneNumber();
    int getYear();
    string getTerm();
    string getProgram();
};


#endif /* HeaderFinalProjStudent_h */
