#include <iostream>
#include "student.h"
#include "util.h"


int main() {
//    const int MAX_STUDENTS = 3;
//    Student studentList[MAX_STUDENTS];
//    studentList[currentStudent].setName(name);

    while (true) {


        //create first student
        Student student1;

        cout << "Please enter students name." << endl;

        string name = "Student";

        cin >> name;


        student1.setName(name);

//    studentList[currentStudent].setName(name);

        bool doneSubmittingCourses = false;
        while (!doneSubmittingCourses) {
            student1.addCourse();

            //prompt to see if they want to add another course to the list, the function will return
            // true or false and also checks for a valid response.
            doneSubmittingCourses = student1.addCoursePrompt();
        }

        //print the 1st students courses.
        student1.printCourses();

        //move on to the second student, use the copy constructor to create a deep copy
        Student student2 = student1;

        cout << "enter the name for student 2: ";
        //we can reuse the old name variable because the student object doesn't depend on it
        cin >> name;

        //Set the name of the second student
        student2.setName(name);

        cout << "new student created: " + student2.getName() << endl;


        student1.resetCourseList();
        student1.printCourses();

        //print the second students courses.
        student2.printCourses();

        Student student3;
        student3 = student2;

        cout << "Enter Student 3's name: " << endl;
        cin >> name;

        student3.setName(name);
        student3.printCourses();

    }
    return 0;
}
