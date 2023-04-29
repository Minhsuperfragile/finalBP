#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct studentInfo{
	char fullName[20];
	char ID[10];
	char birthDate[11];
	float algebra;
	float calculus;
	float basicProgramming;
	float GPA;
};
// Task 5 - Highest, lowest GPA student and highest basic programming point 
struct studentInfo highest_gpa(struct studentInfo students[], int number) {
    struct studentInfo highest = students[0];
    for (int i = 1; i < number; i++) {
        if (students[i].GPA > highest.GPA) {
            highest = students[i];
        }
    }
    return highest;
}
struct studentInfo lowest_gpa(struct studentInfo students[], int number) {
    struct studentInfo lowest = students[0];
    for (int i = 1; i < number; i++) {
        if (students[i].GPA < lowest.GPA) {
            lowest = students[i];
        }
    }
    return lowest;
}
struct studentInfo bp_Point(struct studentInfo students[], int number) {
    struct studentInfo highest_bp_Point = students[0];
    for (int i = 1; i < number; i++) {
        if (students[i].basicProgramming > highest_bp_Point.basicProgramming) {
            highest_bp_Point = students[i];
        }
    }
    return highest_bp_Point;
}
int main(){
	// Task1 - Enter student number
    int number;
    printf("Enter the number of students: ");
    scanf("%d", &number);
    getchar();

    while(number > 1000) {
        printf("Your number is too high. Maximum number of student is 1000. Please enter again: ");
        scanf("%d", &number);
    }

	//Task2 - Get student info
	struct studentInfo students[number];
    
    for (int i = 0; i < number; i++) {
		printf("\nEnter data for student %d:\n", i+1);
        printf("Enter student %d name: ", i+1);
		getchar(); // consume the newline character left in the input stream
        fgets(students[i].fullName, sizeof(students[i].fullName), stdin); //use fgets instead of scanf
        students[i].fullName[strcspn(students[i].fullName, "\n")] = 0; // Remove trailing newline
 
        printf("Enter student %d ID: ", i+1);
        scanf("%s", students[i].ID);
        
        printf("Enter student %d birthdate: ", i+1);
        scanf("%s", students[i].birthDate);
       
        printf("Enter student %d Linear Algebra point: ", i+1);
        scanf("%f", &students[i].algebra);
        
        printf("Enter student %d Calculus point: ", i+1);
        scanf("%f", &students[i].calculus);
        
        printf("Enter student %d Basic Programming point: ", i+1);
        scanf("%f", &students[i].basicProgramming);
    }

	//Task3 - print student list
    printf("| %-10s | %-20s | %-10s | %-7s | %-8s | %-16s | %-5s |\n",
           "ID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
    printf("|%s|\n", "-------------------------------------------------------------------------------------------------");

    for (int i = 0; i < number; i++) {
        students[i].GPA = (students[i].algebra + students[i].calculus + students[i].basicProgramming)/3;
        printf("| %10s | %-20s | %10s | %7.2f | %8.2f | %17.2f | %4.2f |\n",
               students[i].ID,
               students[i].fullName,
               students[i].birthDate,
               students[i].algebra,
               students[i].calculus,
               students[i].basicProgramming,
               students[i].GPA);
    }
    // Task 5
    struct studentInfo highest_gpa_student = highest_gpa(students, number);
    printf("Student with highest GPA:\n %s\t%s\t%2.1f", highest_gpa_student.fullName, highest_gpa_student.ID, highest_gpa_student.GPA);
    struct studentInfo lowest_gpa_student = lowest_gpa(students, number);
    printf("\nStudent with lowest GPA:\n %s\t%s\t%2.1f", lowest_gpa_student.fullName, lowest_gpa_student.ID, lowest_gpa_student.GPA);
    struct studentInfo highest_bp_student = bp_Point(students, number);
    printf("\nStudent with highest BP mark:\n %s\t%s\t%2.1f", highest_bp_student.fullName, highest_bp_student.ID, highest_bp_student.basicProgramming);
	return 0;
}