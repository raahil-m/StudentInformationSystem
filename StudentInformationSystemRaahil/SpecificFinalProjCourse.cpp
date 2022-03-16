//
//  SpecificFinalProjCourse.cpp
//  1PR3 Final Project Login
//
//  Created by Raahil Mahetaji on 2018-04-01.
//  Copyright © 2018 Raahil Mahetaji. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "HeaderFinalProjCourse.h"

using namespace std;

void Course::setAll(string cN, double cGA, double dFA, double eW, double gN)
{
    courseName = cN;
    currentGradeAverage = cGA;
    desiredFinalGrade = dFA;
    examWorth = eW;
    gradeNeeded = gN;
}

string Course::getCourseName()
{
    return courseName;
}

double Course::getCurrentGradeAverage()
{
    return currentGradeAverage;
}

double Course::getDesiredFinalGrade()
{
    return desiredFinalGrade;
}

double Course::getExamWorth()
{
    return examWorth;
}

double Course::getGradeNeeded()
{
    gradeNeeded = (((100 * desiredFinalGrade) - ((100 - examWorth)*(currentGradeAverage))) / (examWorth));
    return gradeNeeded;
}

