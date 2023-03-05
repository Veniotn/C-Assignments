//
// Created by nick on 2/28/2023.
//

#include "student.h"
#include "util.h"



void Student::addCourse()
{
    //If a course has been added already resize the array.
    if (numCourses >= 1)
    {
        Student::resizeCourseList();
    }

    cout << "Enter the name of the course for " + this->name + ": ";

    //numCourses always points to the last index of the courseList
    cin >> courseList[numCourses];
    numCourses++;
}

void Student::printCourses()
{
    cout << "\nPrinting courses for " << name <<  ":" << endl;

    for (int currentCourseIndex = 0; currentCourseIndex < courseListSize; currentCourseIndex++) {
        cout << "Course " << "#" << (currentCourseIndex+1) << ": " << courseList[currentCourseIndex] << endl;
    }

    cout << "Total courses: " << numCourses << endl;
}



void Student::resizeCourseList()
{

    //increase the max size of the list.
    courseListSize++;

    //Create a new list with the greater size
    string *tempCourseList = new string[courseListSize];

    //Copy the current list of courses into the temporary list.
    for (int listIndex = 0; listIndex < numCourses; listIndex++)
    {
        tempCourseList[listIndex] = courseList[listIndex];
    }
    //clear the old lists elements.
    delete[] courseList;

    //rename the new array.
    courseList = tempCourseList;

    cout << "used resize function" << endl;
}

void Student::resetCourseList()
{
    numCourses = 0;
    courseListSize = 0;
    delete[] courseList;
};


bool Student::addCoursePrompt()
{
    string answer = "";
    //prompt if they want to add more courses, keep in a loop in case of bad input.
    while (true)
    {

        cout << "Would you like to add another course? [yes] or [no]";
        cin >> answer;

        if (Util::toLower(answer) == "yes")
        {
            return true;
            //Continue the loop if they type yes
        }
        else if (Util::toLower(answer) == "no")
        {
            return false;
        }
        else
        {
            cout << "invalid response." << endl;
        }

    }
}








