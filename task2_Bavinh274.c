#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Student_infor
{
    char StudentID[10];
    char fullname[30];
    char birthdate[8];
    float Algebra_grade;
    float Calculus_grade;
    float BP_grade;
    float overall_grade;
}; 

int main()
{
    int n;
    printf("Enter the number of students:\n");
    scanf("%d", &n);
    
    struct Student_infor student[n];
    
    for(int i=0; i<n; i++)
    {
    printf("Enter the information for student_number_%d:\n", i+1);
    printf("Enter the studentID:\n");
    scanf("%s", student[i].StudentID);
    printf("Enter the student_fullname:\n");
    scanf(" %[^\n]", student[i].fullname);
    printf("Enter the student_birthdate:\n");
    scanf(" %[^\n]", student[i].birthdate);
    printf("Enter the Algebra_grade:\n");
    scanf("%f", &student[i].Algebra_grade);
    printf("Enter the Calculus_grade:\n");
    scanf("%f", &student[i].Calculus_grade);
    printf("Enter the Basic program grade:\n");
    scanf("%f", &student[i].BP_grade);
    student[i].overall_grade = (student[i].Algebra_grade + student[i].Calculus_grade + student[i].BP_grade) / 3;
    }
    // for(int j = 0; j < 11; j++)
    // {
    //     printf("%c", student[0].birthdate[j]);
    // }
    return 0;
}
