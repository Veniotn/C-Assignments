//
// Created by nick on 2/28/2023.
//

#include "student.h"
#include "util.h"



void Student::addCourse()
{
    //If the course list is bigger than it was when constructed, expand it.
    if (numCourses >= 1){
        Student::resizeCourseList();
    }

    cout << "Enter the name of the course for " + this->name + ": ";

    //numCourses always points to the last index of the courseList
    cin >> courseList[numCourses];
    cout << "\nSuccessfully added " + courseList[numCourses] + " to " + this->name + "'s profile.\n";
    cout << numCourses;
    numCourses++;
}


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
            return false;
            //Continue the loop if they type yes
        }
        else if (Util::toLower(answer) == "no")
        {
            return true;
        }
        else
        {
            cout << "invalid response." << endl;
        }

    }
}

void Student::resizeCourseList() {

    cout << "using resize function" << endl;

    //increase the max size of the list.
    courseListSize++;

    //Create a new list with the greater size
    string *tempCourseList = new string[courseListSize];

    //Copy the current list of courses into the temporary list, we use numcourses because the course list size
    // would cause an out of bound exception.
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






