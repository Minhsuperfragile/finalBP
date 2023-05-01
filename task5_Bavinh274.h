#include <stdio.h>

/* Declare a data type Student_infor including properties: 
studentID(array), fullname(array), birthdate(array), Algebra_grade(float), Calculus_grade(float), BP_grade(float) and GPA(float) */
struct Student_infor
{
    char studentID[10];
    char fullname[30];
    char birthdate[8];
    float Algebra_grade, Calculus_grade, BP_grade;
    float GPA;
};

/* Declare a function findhighestGPA having data type Student_infor */
struct Student_infor findhighestGPA(struct Student_infor *students, int number)
{
    struct Student_infor highestGPA_student = students[0];
    for(int i=1; i<number; i++)
    {
        if(students[i].GPA > highestGPA_student.GPA)
        {
            highestGPA_student= students[i];
        }
    }
    return highestGPA_student;
}

/*Declare a function findlowestGPA having data type Student_infor */
struct Student_infor findlowestGPA(struct Student_infor *students, int number)
{
    struct Student_infor lowestGPA_student = students[0];
    for(int i=1; i<number; i++)
    {
        if(students[i].GPA < lowestGPA_student.GPA)
        {
            lowestGPA_student = students[i];
        }
    }
    return lowestGPA_student;
}

/* Declare a function findhighestBPgrade having data type Student_infor */
struct Student_infor findhighestBPgrade(struct Student_infor *students, int number)
{
    struct Student_infor highestBPgrade_student = students[0];
    for(int i=1; i<number; i++)
    {
        if(students[i].BP_grade > highestBPgrade_student.BP_grade)
        {
            highestBPgrade_student = students[i];
        }
    }
    return highestBPgrade_student;
}
