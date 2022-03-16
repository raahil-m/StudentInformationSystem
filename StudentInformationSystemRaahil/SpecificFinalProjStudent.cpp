//
//  SpecificFinalProjStudent.cpp
//  1PR3 Final Project Login
//
//  Created by Raahil Mahetaji on 2018-04-01.
//  Copyright © 2018 Raahil Mahetaji. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "HeaderFinalProjStudent.h"

using namespace std;

void Student::setAll(string n, string sN, string b, string a, string p, string pN, int y, string t, string pr)
{
    name = n;
    studentNumber = sN;
    birthday = b;
    address = a;
    postalCode = p;
    phoneNumber = pN;
    year = y;
    term = t;
    program = pr;
}

string Student::getName()
{
    return name;
}

string Student::getStudentNumber()
{
    return studentNumber;
}

string Student::getBirthday()
{
    return birthday;
}

string Student::getAddress()
{
    return address;
}

string Student::getPostalCode()
{
    return postalCode;
}

string Student::getPhoneNumber()
{
    return phoneNumber;
}

int Student::getYear()
{
    return year;
}

string Student::getTerm()
{
    return term;
}

string Student::getProgram()
{
    return program;
}

