#include <iostream>
#include "student.h"
#include "util.h"


int main()
{

    while (true)
    {
        //create first student
        Student student1;

        string name = Util::getStringInput("Please enter student 1's name: ");

        student1.setName(name);


        bool stillAddingCourses = true;
        while (stillAddingCourses)
        {
            student1.addCourse();

            //prompt to see if they want to add another course to the list, the function will return
            // true or false and also checks for a valid response.
            stillAddingCourses = student1.addCoursePrompt();
        }

        //print the 1st students courses.
        student1.printCourses();

        //move on to the second student, use the copy constructor to create a deep copy
        Student student2 = student1;

        //we can reuse the old name variable because the student object doesn't depend on it
        name = Util::getStringInput("Please enter Student 2's name: ");
        //Set the name of the second student
        student2.setName(name);


        //Reset and reprint student 1's courseList
        student1.resetCourseList();
        student1.printCourses();

        //print the second students courses.
        student2.printCourses();

        //Make a third student and use the assignment operator to get the values of student2.
        Student student3;
        student3 = student2;

        name = Util::getStringInput("Please enter Student 3's name: ");

        student3.setName(name);
        student3.printCourses();

    }
    return 0;
}
