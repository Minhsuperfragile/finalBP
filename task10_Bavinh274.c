#include <stdio.h>
#include <string.h>

/* Declare a data type named Student_infor including properties:
  +)array studentID(char)
  +)array fullname(char)
  +)array birthdate(char)
  +)Algebra_grade(float)
  +)Calculus_grade(float)
  +)BP_grade(float)
  +)GPA(float)
*/
struct Student_infor
{
    char studentID[10];
    char fullname[30];
    char birthdate[10];
    float Algebra_grade;
    float Calculus_grade;
    float BP_grade;
    float GPA;
};

// Declare a function named descsorting_byGPA to sort list of students according to GPA descending
void descsorting_byGPA(struct Student_infor *students, int number)
{
    struct Student_infor sort_constant;
    for(int i=0; i<(number-1); i++)
    {
        for(int j=1; j<number; j++)
        {
            if(students[i].GPA < students[j].GPA)
            {
                students[i] = sort_constant;
                sort_constant = students[j];
                students[j] = students[i];
            }
        }
    }
}

//Main function
int main()
{
    int number;
    printf("Enter the number of student: ");
    scanf("%d", &number);
    // Declare an array student having data type Student_infor and variable number:
    struct Student_infor student[number];
    for(int i=0; i<number; i++)
    {
        printf("Enter the information for student numbered %d\n", i+1);
        printf("Enter the Student ID:\n");
        scanf("%s", student[i].studentID);
        printf("Enter the fullname:\n");
        scanf(" %[^\n]", student[i].fullname);
        printf("Enter the birthdate(Date_Month_Year('_': Space)):\n");
        scanf(" %[^\n]", student[i].birthdate);
        printf("Enter the Algebra grade:\n");
        scanf("%f", &student[i].Algebra_grade);
        printf("Enter the Calculus grade:\n");
        scanf("%f", &student[i].Calculus_grade);
        printf("Enter the Basic Programming grade:\n");
        scanf("%f", &student[i].BP_grade);
        student[i].GPA = (student[i].Calculus_grade + student[i].Algebra_grade + student[i].BP_grade) / 3.0;
    }

    //Calling the function descsorting_byGPA to order the list of students:
    descsorting_byGPA(student, number);

    printf("Student ID//Full name//Date of Birth//Algebra//Calculus//Basic Programming//GPA\n");

    //Print the list of students after sorting to the screen:
    for(int i=0; i<number; i++)
    {
        printf("%d) %s  //  %s  //  ",i+1, student[i].studentID, student[i].fullname);
        //Print the value of birthdate(including the space character):
        for(int k=0; k<11; k++)
        {
            printf("%c", student[i].birthdate[k]);
        }
        printf("  //  %2.2f  //  %2.2f  //%2.2f  //  %2.2f\n", student[i].Algebra_grade, student[i].Calculus_grade, student[i].BP_grade, student[i].GPA);        
    }

    return 0;
}