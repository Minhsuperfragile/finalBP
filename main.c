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
    int studentNum;
    printf("Enter the number of students: ");
    scanf("%d", &studentNum);

    while(studentNum > 1000) {
        printf("Your number is too high. Maximum number of student is 1000. Please enter again: ");
        scanf("%d", &studentNum);
    }

	return 0;
}