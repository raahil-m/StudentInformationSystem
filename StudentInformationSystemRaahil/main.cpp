//
//  main.cpp
//  1PR3 Final Project Login
//
//  Created by Raahil Mahetaji on 2018-03-30.
//  Copyright © 2018 Raahil Mahetaji. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "HeaderFinalProjStudent.h"
#include "HeaderFinalProjCourse.h"

using namespace std;

void displayInfo(Student);
void displayGradeInfo(Course);

int main()
{
    string studentNum;
    string password;
    int option;
    int i;
    int result = 0;
    
    cout << "1. Register\n";
    cout << "2. Login\n";
    cin >> option;
    
    if (option == 1)
    {
        ofstream writeFile;
        writeFile.open("RegisterInfo.txt",ios::out | ios::app);
        
        cout << "Enter your student number. Must be 9 digits and only numbers" << endl;
        cin >> studentNum;
    
        if (studentNum.length() != result)
        {
            while (studentNum.length() != result)
            {
                for (i = 0; i < studentNum.length() +1; i++)
                {
                    if (isdigit(studentNum[i]))
                    {
                        result +=1;
                    }
                }
                if (result !=9)
                {
                    cout << "Student number must be 9 digits and only numbers, please re-enter:" << endl;
                    cin >> studentNum;
                    result = 0;
                }
                else
                {
                    cout << "Valid student number." << endl;
                    cout << "Please create a password greater than 6 characters:" << endl;
                    cin >> password;
                    
                }
            }
        }
        if (writeFile.is_open())
        {
            writeFile << studentNum << password <<endl;
        }
        else
        {
            cout << "Error: Unable to open file" << endl;
        }
        writeFile.close();
    }
    string sNum2;
    string pass2;
    string fileAccount;
    string userAccount;
    int correctCount = 0;
    
    if (option == 2)
    {
        
        ifstream readFile;
        readFile.open("RegisterInfo.txt",ios::in);
    
        if (readFile)
        {
            while (correctCount <=0)
            {
                cout << "Enter your student number" << endl;
                cin >> sNum2;
                cout << "Enter your password" << endl;
                cin >> pass2;
                userAccount = sNum2 + pass2;

                while (readFile >> fileAccount)
                {
                    if (fileAccount == userAccount)
                    {
                        correctCount +=1;
                    }
                }
                
                if (correctCount >=1)
                {
                    cout << "Your account exists" << endl;
                    readFile.close();
                }
                else
                {
                    cout << "Your account does not exist. Wrong username or password." << endl;
                    readFile.close();
                    readFile.open("RegisterInfo.txt",ios::in);
                }
            }
        }
        else
        {
            cout << "Error: Cannot open file" << endl;
        }
        string name;
        string studentNumber;
        string birthday;
        string address;
        string postalCode;
        string phoneNumber;
        int year;
        string term;
        string program;
        string courseName;
        double currentGradeAverage;
        double desiredFinalGrade;
        double examWorth;
        double gradeNeeded;
        
        cout << "Welcome to your personal Student Portal!" << endl;
        
        cout << "Please enter your name: ";
        cin >> name;
        cout << "Please enter your Student Number: ";
        cin >> studentNumber;
        cout << "Please enter your birthday (mm/dd/yyyy): ";
        cin >> birthday;
        cout << "Please enter your Address: ";
        cin >> address;
        cout << "Please enter your Postal Code: ";
        cin >> postalCode;
        cout << "Please enter your Phone Number: ";
        cin >> phoneNumber;
        cout << "Please enter what year of study you are currently in (Enter either 1, 2, 3, or 4): ";
        cin >> year;
        cout << "Please enter what term you are currently in: ";
        cin >> term;
        cout << "Please enter what program stream you are in (MUST enter either 'auto', 'bio', or 'process'): ";
        cin >> program;
        cout << program << endl;
        
        string s1 = ("auto");
        string s2 = ("bio");
        string s3 = ("process");
        
        if (program.compare(s1) ==0 || program.compare(s2) ==0 || program.compare(s3) ==0)
        {
            cout << "Valid input." << endl;
        }
        else
        {
            while (program.compare(s1) !=0 || program.compare(s2) !=0 || program.compare(s3) !=0)
            {
                cout << "Please enter what program stream you are in (MUST enter either 'auto', 'bio', or 'process'): ";
                cin >> program;
                cout << program << endl;
                if (program.compare(s1) ==0 || program.compare(s2) ==0 || program.compare(s3) ==0)
                {
                    cout << "Valid input." << endl;
                    break;
                }
            }
        }
        
        Student personalInfo(name, studentNumber, birthday, address, postalCode, phoneNumber, year, term, program);
        displayInfo(personalInfo);
        
        cout << "Please enter Course Name: ";
        cin >> courseName;
        cout << "Please enter your current grade average in this course: ";
        cin >> currentGradeAverage;
        cout << "Please enter the desired final grade for this course: ";
        cin >> desiredFinalGrade;
        cout << "Please enter how much the exam is worth: ";
        cin >> examWorth;
        
        Course grade(courseName, currentGradeAverage, desiredFinalGrade, examWorth);
        displayGradeInfo(grade);
        
        string cLine;
        
        string fileSName;
        fileSName = program + ".txt";
        
        ifstream streamFile;
        streamFile.open(fileSName,ios::in);
        if (streamFile)
        {
            cout << "The courses you are recommended to take for your year of study are: " << endl;
            while (streamFile >> cLine)
            {
                cout << cLine << endl;
            }
        }
        else
        {
            cout << "Error: Cannot open file" << endl;
        }
        streamFile.close();
    }
    return 0;
}

void displayInfo(Student e)
{
    cout << setprecision(2) << fixed << showpoint;
    cout << "Name: " << e.getName() << endl;
    cout << "Student Number: " << e.getStudentNumber() << endl;
    cout << "Birthday: " << e.getBirthday() << endl;
    cout << "Address: " << e.getAddress() << endl;
    cout << "Postal Code: " << e.getPostalCode() << endl;
    cout << "Phone Number: " << e.getPhoneNumber() << endl;
    cout << "Year of Study: " << e.getYear() << endl;
    cout << "Current Term: " << e.getTerm() << endl;
    cout << "Program: " << e.getProgram() << endl;
}

void displayGradeInfo(Course r)
{
    cout << setprecision(2) << fixed << showpoint;
    cout << "Course Name: " << r.getCourseName() << endl;
    cout << "Current Average Grade: " << r.getCurrentGradeAverage() << endl;
    cout << "Desired Final Grade: " << r.getDesiredFinalGrade() << endl;
    cout << "The Exam is Worth: " << r.getExamWorth() << endl;
    
    cout << "The grade you need is: " << r.getGradeNeeded() << endl;
    //_______________________
    
    cout << "If you score a " <<  r.getGradeNeeded() << "% on the final worth " << r.getExamWorth() << "%, you will obtain a final grade of " << r.getDesiredFinalGrade() << "%." << endl;
    
    int input;
    
    cout << "Would you like to see your desired final grade on the 12 point GPA scale or as a letter grade?" << endl;
    cout << "Enter 1 for 12 point GPA, Enter 2 for letter grade." << endl;
    cin >> input;
    
    switch (input)
    {
        case 1:
        {
            if (r.getDesiredFinalGrade() >= 90 && r.getDesiredFinalGrade() <= 100)
            {
                cout << "Your final grade on the 12 point GPA scale is a 12." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 85 && r.getDesiredFinalGrade() <= 89)
            {
                cout << "Your final grade on the 12 point GPA scale is a 11." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 80 && r.getDesiredFinalGrade() <= 84)
            {
                cout << "Your final grade on the 12 point GPA scale is a 10." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 77 && r.getDesiredFinalGrade() <= 79)
            {
                cout << "Your final grade on the 12 point GPA scale is a 9." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 73 && r.getDesiredFinalGrade() <= 76)
            {
                cout << "Your final grade on the 12 point GPA scale is a 8." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 70 && r.getDesiredFinalGrade() <= 72)
            {
                cout << "Your final grade on the 12 point GPA scale is a 7." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 67 && r.getDesiredFinalGrade() <= 69)
            {
                cout << "Your final grade on the 12 point GPA scale is a 6." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 63 && r.getDesiredFinalGrade() <= 66)
            {
                cout << "Your final grade on the 12 point GPA scale is a 5." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 60 && r.getDesiredFinalGrade() <= 62)
            {
                cout << "Your final grade on the 12 point GPA scale is a 4." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 57 && r.getDesiredFinalGrade() <= 59)
            {
                cout << "Your final grade on the 12 point GPA scale is a 3." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 53 && r.getDesiredFinalGrade() <= 56)
            {
                cout << "Your final grade on the 12 point GPA scale is a 2." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 50 && r.getDesiredFinalGrade() <= 52)
            {
                cout << "Your final grade on the 12 point GPA scale is a 1." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 0 && r.getDesiredFinalGrade() <= 49)
            {
                cout << "Your final grade on the 12 point GPA scale is a 0." << endl;
            }
            break;
        }
        case 2:
        {
            if (r.getDesiredFinalGrade() >= 90 && r.getDesiredFinalGrade() <= 100)
            {
                cout << "Your final letter grade is an A+." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 85 && r.getDesiredFinalGrade() <= 89)
            {
                cout << "Your final letter grade is an A." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 80 && r.getDesiredFinalGrade() <= 84)
            {
                cout << "Your final letter grade is an A-." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 77 && r.getDesiredFinalGrade() <= 79)
            {
                cout << "Your final letter grade is a B+." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 73 && r.getDesiredFinalGrade() <= 76)
            {
                cout << "Your final letter grade is a B." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 70 && r.getDesiredFinalGrade() <= 72)
            {
                cout << "Your final letter grade is a B-." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 67 && r.getDesiredFinalGrade() <= 69)
            {
                cout << "Your final letter grade is a C+." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 63 && r.getDesiredFinalGrade() <= 66)
            {
                cout << "Your final letter grade is a C." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 60 && r.getDesiredFinalGrade() <= 62)
            {
                cout << "Your final letter grade is a C-." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 57 && r.getDesiredFinalGrade() <= 59)
            {
                cout << "Your final letter grade is a D+." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 53 && r.getDesiredFinalGrade() <= 56)
            {
                cout << "Your final letter grade is a D." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 50 && r.getDesiredFinalGrade() <= 52)
            {
                cout << "Your final letter grade is a D-." << endl;
            }
            
            if (r.getDesiredFinalGrade() >= 0 && r.getDesiredFinalGrade() <= 49)
            {
                
                cout << "Your final letter grade is an F." << endl;
            }
            break;
        default:
            cout << "Incorrect input, please enter 1 or 2." << endl;
            break;
        }
    }
}



