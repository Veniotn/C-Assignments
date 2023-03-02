#include <iostream>
#include "student.h"
#include "util.h"


int main() {
    const int MAX_STUDENTS = 3;
    Student studentList[MAX_STUDENTS];
    int currentStudent = 0;


    cout << "Please enter students name." << endl;

    string name = "Student";

    cin >> name;

    studentList[currentStudent].setName(name);

    bool doneSubmittingCourses = false;
    while (!doneSubmittingCourses)
    {
        studentList[currentStudent].addCourse();

        //prompt to see if they want to add another course to the list, the function will return
        // true or false and also checks for a valid response.
        doneSubmittingCourses = studentList[currentStudent].addCoursePrompt();
    }

    cout << "end" << endl;


    studentList[currentStudent].~Student();

    return 0;
}
