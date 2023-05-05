#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// struct to store information
typedef struct studentInfo
{
    char fullName[20], ID[11], birthDate[11];
    float algebra, calculus, basicProgramming, GPA;
} student;

// function to calculate GPA
float calculateGPA(float *algebra, float *calculus, float *basicProgramming)
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

// function to print the student list
void printTable(student *a, int number)
{
    printf("| %-10s | %-20s | %-10s | %-7s | %-8s | %-16s | %-5s |\n",
           "ID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
    printf("|%s|\n", "-------------------------------------------------------------------------------------------------");

    for (int i = 0; i < number; i++)
    {
        a[i].GPA = calculateGPA(&a[i].algebra, &a[i].calculus, &a[i].basicProgramming);
        printf("| %10s | %-20s | %10s | %7.2f | %8.2f | %17.2f | %5.2f |\n",
               a[i].ID,
               a[i].fullName,
               a[i].birthDate,
               a[i].algebra,
               a[i].calculus,
               a[i].basicProgramming,
               a[i].GPA);
    }
}

// function to write table to text file
void writeToFile(int n, struct studentInfo *student)
{
    FILE *filePointer;
    filePointer = fopen("studentInfo.txt", "w");

    if (filePointer == NULL)
    {
        printf("Error!");
        exit(1);
    }

    fprintf(filePointer, "%20s|%15s|%15s|%10s|%10s|%20s|%10s\n", "Name", "ID", "Date of Birth", "Linear", "Calculus", "Basic Programming", "GPA");
    fprintf(filePointer, "===============================================================================================================\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(filePointer, "%20s|%15s|%15s|%10.2f|%10.2f|%20.2f|%10.2f\n",
                student[i].fullName,
                student[i].ID,
                student[i].birthDate,
                student[i].algebra,
                student[i].calculus,
                student[i].basicProgramming,
                student[i].GPA);
    }
    fclose(filePointer);
}

// function to print out the student with the highest GPA
void highestGPA(student *a, int number)
{
    float max = a[0].GPA;
    int highest_position = 0;
    for (int i = 0; i < number; i++)
    {
        if (a[i].GPA > max)
        {
            max = a[i].GPA;
            highest_position = i;
        }
    }
    printf("The student with the highest GPA is: %s with GPA is %.2f\n", a[highest_position].fullName, max);
}

// function to print out the student with the lowest GPA
void lowestGPA(student *a, int number)
{
    float min = a[0].GPA;
    int lowest_position = 0;
    for (int i = 0; i < number; i++)
    {
        if (a[i].GPA < min)
        {
            min = a[i].GPA;
            lowest_position = i;
        }
    }
    printf("The student with the lowest GPA is: %s with GPA is %.2f\n", a[lowest_position].fullName, min);
}

// function to print out the student with the highest Basic Programming grade
void highestBP(student *a, int number)
{
    float maxBP = a[0].basicProgramming;
    int position = 0;
    for (int i = 0; i < number; i++)
    {
        if (a[i].basicProgramming > maxBP)
        {
            maxBP = a[i].basicProgramming;
            position = i;
        }
    }
    printf("The student with the highest BP is: %s with Basic Programming grade is %.2f\n", a[position].fullName, maxBP);
}



// start function to sort GPA in descending order

// function to swap information
void swap(struct studentInfo *a, struct studentInfo *b)
{
    struct studentInfo t = *a; // temporary var
    *a = *b;
    *b = t;
}
//start sorting

int partitionGPA(student *a, int start, int end, bool descending){
    float pivot = a[end].GPA;
    int i = start - 1; // Index of smaller element and indicates the right position of pivot found so far

    for (int j = start; j <= end-1; j++){ 
        if (a[j].GPA >= pivot && descending){ // swap current element if it is bigger than the pivot 
            i++;
            swap(&a[i],&a[j]);
        }
        if (a[j].GPA < pivot && !descending){ //  swap if current element is smaller than the pivot
            i++;
            swap(&a[i],&a[j]);
        }
    }
    i++;
    swap(&a[i],&a[end]);
    return i;
}

void quickSortGPA(student *a, int start, int end,bool descending){
    if (end <= start) {return;}

    float pivot = partitionGPA(a,start,end,descending);
    quickSortGPA(a, 0, pivot - 1,descending); // sort the left side of pivot
    quickSortGPA(a, pivot + 1, end,descending); // sort the right side of pivot
    
}
//end sorting

// main function to perform main task
int main()
{

    // Task 1: Enter student number
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

    // Task 2: Enter students' information: ID, full name, birthdate, grade of 3 subjects
    for (int i = 0; i < number; i++)
    {
        printf("Enter student %d name: ", i + 1);
        fgets(student[i].fullName, 20, stdin);
        student[i].fullName[strcspn(student[i].fullName, "\n")] = '\0';

        printf("Enter student %d ID: ", i + 1);
        fgets(student[i].ID, 20, stdin);
        student[i].ID[strcspn(student[i].ID, "\n")] = '\0';

        printf("Enter student %d birthdate (dd/mm/yyyy): ", i + 1);
        fgets(student[i].birthDate, 20, stdin);
        student[i].birthDate[strcspn(student[i].birthDate, "\n")] = '\0';

        printf("Enter student %d Linear Algebra score: ", i + 1);
        scanf("%f", &student[i].algebra);

        printf("Enter student %d Calculus score: ", i + 1);
        scanf("%f", &student[i].calculus);

        printf("Enter student %d Basic Programming score: ", i + 1);
        scanf("%f", &student[i].basicProgramming);

        // print the information after getting input to check if the input is correct or not
        printf("\n--------------------\n");

        printf("Student %d name: %s\n", i + 1, student[i].fullName);

        printf("Student %d ID: %s\n", i + 1, student[i].ID);

        printf("Student %d birthdate: %s\n", i + 1, student[i].birthDate);

        printf("Student %d Linear Algebra: %.2f\n", i + 1, student[i].algebra);

        printf("Student %d Calculus: %.2f\n", i + 1, student[i].calculus);

        printf("Student %d Basic Programming: %.2f\n", i + 1, student[i].basicProgramming);

        printf("--------------------\n");

        getchar();

        printf("The GPA of student is: %.2f\n", calculateGPA(&student[i].algebra, &student[i].calculus, &student[i].basicProgramming));
        printf("--------------------\n");
    }

    // Task3 - print student list as a table to screen
    printf("Table of information\n");
    printTable(student, number);
    printf("\n--------------------\n");

    // Task 4: print student list as a table to a texxt file
    writeToFile(number, student);

    // Task 5: Process grades
    highestGPA(student, number);
    lowestGPA(student, number);
    highestBP(student, number);
    printf("\n--------------------\n");

    // Task 6: Print out student lastName
    printf("LastName of students:\n");
    for (int i = 0; i < number; i++)
    {
        getLastName(student[i].fullName);
    }
    printf("\n--------------------\n");

    // Task 10: Sort the student list by GPA in descending order
    printf("GPA of students in descending order: \n");
    quickSortGPA(student,0, number-1,1);
    printTable(student, number);
    printf("\n--------------------\n");

    return 0;
}
