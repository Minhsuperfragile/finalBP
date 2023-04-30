#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write function for each task, only use main func to do actions
// Func1: Enter every information
// Func 2: Print information as table using loop
// Func 3: Print information as text file

// Func 4,5,6: find the students with highest GPA, lowest GPA, highest BP grade
// Func 7: Print out the student last name
// Func 8: Print out GPA in descending order

// struct to store information 
typedef struct studentInfo
{
    char fullName[20], ID[11], birthDate[11];
    float algebra, calculus, basicProgamming, GPA;
} student;

// function to calculate GPA 
float caculateGPA(float *algebra, float *calculus, float *basicProgramming)
{
    float GPA = ((*algebra + *calculus + *basicProgramming) / 3);
    return GPA;
}

// function to get the last name 
char getLastName(char *fullName)
{
    char strOfFullName[50];
    strcpy(strOfFullName, fullName);
    char *token, *last;
    last = token = strtok(strOfFullName, " ");

    while (token != NULL)
    {
        last = token;
        token = strtok(NULL, " ");
    }
    printf("The last name of %s is: %s\n", fullName, last);
}

// function to print out the highest GPA
void highestGPA(student a[], int number)
{
    float res1 = 0;
    int position1;
    for (int i = 0; i < number; i++)
    {
        if (a[i].GPA > res1)
        {
            res1 = a[i].GPA;
            position1 = i;
        }
    }
    printf("The student with the highest GPA is: %s with GPA is %.2f\n", a[position1].fullName, res1);
}

// function to print out the lowest GPA
void lowestGPA(student a[], int number)
{
    int position2;
    float min_GPA = a[0].GPA;
    for (int i = 0; i < number; i++)
    {
        if (a[i].GPA < min_GPA)
        {
            min_GPA = a[i].GPA;
            position2 = i;
        }
    }
    printf("The student with the lowest GPA is: %s with GPA is %.2f\n", a[position2].fullName, min_GPA);
}

//function to print out the highest Basic Programming score 
void highestBP(student a[], int number)
{
    float res3 = 0;
    int position3;
    for (int i = 0; i < number; i++)
    {
        if (a[i].basicProgamming > res3)
        {
            res3 = a[i].basicProgamming;
            position3 = i;
        }
    }
    printf("The student with the highest Basic Programming grade is: %s with Basic Programming grade is %.2f\n", a[position3].fullName, res3);
}

//function to sort GPA in descending order

int cmp(const void *a, const void *b){
    student *x = (student*)a;
    student *y = (student*)b;
    if(x->GPA<y->GPA) return 1;
    else return -1;    
}

//function to print the GPA in descending order 
void printDescending(student a[], int number){
    for(int i=0;i<number; i++){
        printf("%s %.2f\n", a[i].fullName,a[i].GPA);
    }
}
// main function to run main action 
int main()
{

    // Task 1: Enter the number of student
    int number;
    printf("Enter number of student: ");
    scanf("%d", &number);
    getchar();
    struct studentInfo student[number];
    // loop for enter the number again if too high
    while (number > 1000)
    {
        printf("Invalid number. Please enter again: ");
        scanf("%d", &number);
    }

    // Task 2: Input the student information: ID, full name, birthdate, grade of 3 subjects
    for (int i = 0; i < number; i++)
    {
        printf("Enter student %d name: ", i + 1);
        gets(student[i].fullName); // gets func to read string with whitespace

        // fgets(student[i].fullName,sizeof(student[i].fullName),stdin);
        // student[i].fullName[strlen(student[i].fullName)] = '\0';

        printf("Enter student %d ID: ", i + 1);
        scanf("%s", student[i].ID);

        printf("Enter student %d birthdate (dd/mm/yyyy): ", i + 1);
        scanf("%s", student[i].birthDate);

        printf("Enter student %d Linear Algebra score: ", i + 1);
        scanf("%f", &student[i].algebra);

        printf("Enter student %d Calculus score: ", i + 1);
        scanf("%f", &student[i].calculus);

        printf("Enter student %d Basic Programming score: ", i + 1);
        scanf("%f", &student[i].basicProgamming);

        // print the information after getting input to check if the input is correct or not
        printf("\n--------------------\n");

        printf("Student %d name: %s\n", i + 1, student[i].fullName);

        printf("Student %d ID: %s\n", i + 1, student[i].ID);

        printf("Student %d birthdate: %s\n", i + 1, student[i].birthDate);

        printf("Student %d Linear Algebra: %.2f\n", i + 1, student[i].algebra);

        printf("Student %d Calculus: %.2f\n", i + 1, student[i].calculus);

        printf("Student %d Basic Programming: %.2f\n", i + 1, student[i].basicProgamming);

        printf("--------------------\n");

        getchar();
        getLastName(student[i].fullName);
        printf("The GPA of student is: %.2f\n", caculateGPA(&student[i].algebra, &student[i].calculus, &student[i].basicProgamming));
        printf("--------------------\n");
    }

    // Task3 - print student list
    printf("| %-10s | %-20s | %-10s | %-7s | %-8s | %-16s | %-5s |\n",
           "ID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
    printf("|%s|\n", "-------------------------------------------------------------------------------------------------");

    for (int i = 0; i < number; i++)
    {
        student[i].GPA = caculateGPA(&student[i].algebra, &student[i].calculus, &student[i].basicProgamming);
        printf("| %10s | %-20s | %10s | %7.2f | %8.2f | %17.2f | %4.2f |\n",
               student[i].ID,
               student[i].fullName,
               student[i].birthDate,
               student[i].algebra,
               student[i].calculus,
               student[i].basicProgamming,
               student[i].GPA);
    }

    printf("\n--------------------\n");

    highestGPA(student, number);
    lowestGPA(student, number);
    highestBP(student, number);

    printf("\n--------------------\n");
    
    qsort(student,number,sizeof(student),cmp);
    printf("The GPA of student in descending order is: \n");
    printDescending(student,number);

    printf("\n--------------------\n");



    return 0;
}
