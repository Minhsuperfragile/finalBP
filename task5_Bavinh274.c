#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Declare a data type Student_infor including properties: 
studentID(array), fullname(array), birthdate(array), Algebra_grade(float), Calculus_grade(float), BP_grade(float) and GPA(float) */
struct Student_infor
{
    char studentID[10];
    char fullname[30];
    char birthdate[9];
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


int main()
{
    int number;
    printf("Please enter the number of student:\n");
    scanf("%d", &number);

// Declare an array student having data type Student_infor and variable number:
    struct Student_infor student[number];
    for(int i = 0; i<number; i++)
    {
    printf("Enter the information for student_number_%d:\n", i+1);
    printf("Enter the studentID:\n");
    scanf("%s", student[i].studentID);
    printf("Enter the student_fullname:\n");
    scanf(" %[^\n]", student[i].fullname);
    printf("Enter the student_birthdate(Date_Month_Year('_': Space)):\n");
    scanf(" %[^\n]", student[i].birthdate);
    printf("Enter the Algebra_grade:\n");
    scanf("%f", &student[i].Algebra_grade);
    printf("Enter the Calculus_grade:\n");
    scanf("%f", &student[i].Calculus_grade);
    printf("Enter the Basic program grade:\n");
    scanf("%f", &student[i].BP_grade);
    student[i].GPA = (student[i].Algebra_grade + student[i].Calculus_grade + student[i].BP_grade) / 3;
    }

/* Calling the function findhighestGPA in the function main to find the student having highest GPA */
    struct Student_infor HighestGPAstudent = findhighestGPA(student, number);
    printf("The student having the highest GPA is:\n");
    printf("Student ID: %s\n", HighestGPAstudent.studentID);
    printf("Full name: %s\n", HighestGPAstudent.fullname);
    printf("Birthdate: ");
    //Print the value of birthdate(including space character):    
    for(int j=0; j<11; j++)
    {
        printf("%c", HighestGPAstudent.birthdate[j]);
    }
    printf("\nAlgebra grade: %2.2f\n", HighestGPAstudent.Algebra_grade);
    printf("Calculus grade: %2.2f\n", HighestGPAstudent.Calculus_grade);
    printf("Basic Programming grade: %2.2f\n", HighestGPAstudent.BP_grade);
    printf("GPA: %2.2f\n", HighestGPAstudent.GPA);

/*Calling the function findlowestGPA in the function main to find the student having lowest GPA */
    struct Student_infor LowestGPAstudent = findlowestGPA(student, number);
    printf("The student having the lowest GPA is:\n");
    printf("Student ID: %s\n", LowestGPAstudent.studentID);
    printf("Full name: %s\n", LowestGPAstudent.fullname);
    printf("Birthdate: ");
    //Print the value of birthdate(including space character):    
    for(int j=0; j<11; j++)
    {
        printf("%c", LowestGPAstudent.birthdate[j]);
    }
    printf("\nAlgebra grade: %2.2f\n", LowestGPAstudent.Algebra_grade);
    printf("Calculus grade: %2.2f\n", LowestGPAstudent.Calculus_grade);
    printf("Basic Programming grade: %2.2f\n", LowestGPAstudent.BP_grade);
    printf("GPA: %2.2f\n", LowestGPAstudent.GPA);

/*Calling the function findhighestBPgrade in the function main to find the student having highest Basic Programming grade */
    struct Student_infor HighestBPstudent = findhighestBPgrade(student, number);
    printf("The student having the highest Basic Programming grade is:\n");
    printf("Student ID: %s\n", HighestBPstudent.studentID);
    printf("Full name: %s\n", HighestBPstudent.fullname);
    printf("Birthdate(date month year): %s");
    //Print the value of birthdate(including space character):
    for(int j=0; j<11; j++)
    {
        printf("%c", HighestBPstudent.birthdate[j]);
    }
    printf("\nAlgebra grade: %2.2f\n", HighestBPstudent.Algebra_grade);
    printf("Calculus grade: %2.2f\n", HighestBPstudent.Calculus_grade);
    printf("Basic Programming grade: %2.2f\n", HighestBPstudent.BP_grade);
    printf("GPA: %2.2f\n", HighestBPstudent.GPA);
    
    return 0;
}