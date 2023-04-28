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

int main(){
	// Task1 - Enter student number
    int number;
    printf("Enter the number of students: ");
    scanf("%d", &number);

    while(number > 1000) {
        printf("Your number is too high. Maximum number of student is 1000. Please enter again: ");
        scanf("%d", &number);
    }

	//Task2 - get student info
	struct studentInfo students[number];
    
    for (int i = 0; i < number; i++) {
        printf("Enter student %d name: ", i+1);
        fgets(students[i].fullName, sizeof(students[i].fullName), stdin); //use fgets instead of scanf
        students[i].fullName[strcspn(students[i].fullName, "\n")] = 0; // Remove trailing newline
 
        printf("Enter student %d ID: ", i+1);
        scanf("%s", students[i].ID);
        getchar(); // consume the newline character left in the input stream

        printf("Enter student %d birthdate: ", i+1);
        scanf("%s", students[i].birthDate);
        getchar();

        printf("Enter student %d Linear Algebra point: ", i+1);
        scanf("%f", &students[i].algebra);
        getchar();

        printf("Enter student %d Calculus point: ", i+1);
        scanf("%f", &students[i].calculus);
        getchar();
        
        printf("Enter student %d Basic Programming point: ", i+1);
        scanf("%f", &students[i].basicProgramming);
        getchar(); // consume the newline character left in the input stream
        
        printf("Enter student %d GPA: ", i+1);
        scanf("%f", &students[i].GPA);
        getchar(); // consume the newline character left in the input stream
    }
	return 0;
}