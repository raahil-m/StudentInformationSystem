//
//  HeaderFinalProjCourse.h
//  1PR3 Final Project Login
//
//  Created by Raahil Mahetaji on 2018-04-01.
//  Copyright © 2018 Raahil Mahetaji. All rights reserved.
//

#ifndef HeaderFinalProjCourse_h
#define HeaderFinalProjCourse_h

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Course
{
private:
    string courseName;
    double currentGradeAverage;
    double desiredFinalGrade;
    double examWorth;
    double gradeNeeded;
public:
    Course()
    {
        courseName = "";
        currentGradeAverage = 0;
        desiredFinalGrade = 0;
        examWorth = 0;
    }
    Course(string aCourseName, double aCurrentGradeAverage, double aDesiredFinalGrade, double aExamWorth)
    {
        courseName = aCourseName;
        currentGradeAverage = aCurrentGradeAverage;
        desiredFinalGrade = aDesiredFinalGrade;
        examWorth = aExamWorth;
    }
    void setAll(string cN, double cGA, double dFA, double eW, double gN);
    
    string getCourseName();
    double getCurrentGradeAverage();
    double getDesiredFinalGrade();
    double getExamWorth();
    double getGradeNeeded();
};

#endif /* HeaderFinalProjCourse_h */
