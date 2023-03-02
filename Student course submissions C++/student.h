//
// Created by nick on 2/28/2023.
//

#ifndef INC_2_2_STUDENT_H
#define INC_2_2_STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student{
    public:
        //default constructor
        Student()
        {
            name = "";
            numCourses = 0;
            courseListSize = 1;
            courseList = new string[courseListSize];
        }

        //Copy Constructor
        Student(const Student& studentToCopy)
        {
            name = studentToCopy.name;
            numCourses = studentToCopy.numCourses;
            courseListSize = studentToCopy.courseListSize;
            courseList = studentToCopy.courseList;
        }

        //Destructor
        ~Student()
        {
            //We only need to manually destroy the dynamic array because, other member variables are automatically destroyed.
            delete [] courseList;
        }

        //Assignment Operator
        Student& operator=(const Student& otherStudent)
        {
            //delete clear dynamic memory
            delete[] courseList;

            //Copy the courseList to the current object.
            for (int listIndex = 0; listIndex < courseList->size(); listIndex++)
            {
                courseList[listIndex] = otherStudent.courseList[listIndex];
            }

            //return a pointer to the object.
            return *this;
        }


        //Methods
        void addCourse();
        bool addCoursePrompt();
        void resizeCourseList();


        //getters and setters
        const string &getName() const {
            return name;
        }

        void setName(const string &name) {
            Student::name = name;
        }

        int getNumCourses() const {
            return numCourses;
        }

        void setNumCourses(int numCourses) {
            Student::numCourses = numCourses;
        }

        string *getCourseList() const {
            return courseList;
        }

        void setCourseList(string *courseList) {
            Student::courseList = courseList;
        }

        int getCourseListSize() const {
            return courseListSize;
        }

        void setCourseListSize(int courseListSize) {
            Student::courseListSize = courseListSize;
        }

        int getStudentId() const {
            return studentID;
        }

        void setStudentId(int studentId) {
            studentID = studentId;
        }

    private:
        string name;
        int numCourses;
        string *courseList;
        int courseListSize;
        int studentID;
    };
// Student

#endif //INC_2_2_STUDENT_H
