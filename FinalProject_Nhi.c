#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct studentInfo{
	char fullName[60];
    char lastName[20];
	char ID[10];
	char birthDate[11];
	float algebra;
	float calculus;
	float basicProgramming;
	float GPA;
};

//print student info
void print_studentinfo (struct studentInfo *students, int i) {
    printf("| %10s | %-30s | %10s | %7.2f | %8.2f | %17.2f | %4.2f |\n",
               students[i].ID,
               students[i].fullName,
               students[i].birthDate,
               students[i].algebra,
               students[i].calculus,
               students[i].basicProgramming,
               students[i].GPA);
}

//print table
void print_table (struct studentInfo *students, int number) {
    printf("| %-10s | %-30s | %-10s | %-7s | %-8s | %-16s | %-5s |\n",
           "ID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
    printf("|%s|\n", "-----------------------------------------------------------------------------------------------------------");

    for (int i = 0; i < number; i++) {
        print_studentinfo (students, i);
    }
}

//highest GPA score
void highest_GPA (struct studentInfo *students, int number) {
    int kh;
    float highestGPA = 0;
    for (int i = 0; i < number; i++) {
        if (highestGPA < students[i].GPA) {
            highestGPA = students[i].GPA;
            kh = i;
        }
    }
    printf("\nThe student with the highest GPA:\n");
    print_studentinfo(students, kh);
}

// lowest GPA score
void lowest_GPA (struct studentInfo *students, int number) {
    int kl; 
    float lowestGPA = 20;
    for (int i = 0; i < number; i++) {
        if (lowestGPA > students[i].GPA) {
            lowestGPA = students[i].GPA;
            kl = i;
        }
    }
    printf("The student with the lowest GPA:\n");
    print_studentinfo(students, kl);
}

//highest BP score
void highest_BP (struct studentInfo *students, int number) {
    int kh; 
    float highestBP = 0;
    for (int i = 0; i < number; i++) {
        if (highestBP < students[i].basicProgramming) {
            highestBP = students[i].basicProgramming;
            kh = i;
        }
    }
    printf("The student with the highest Basic Programming score:\n");
    print_studentinfo(students, kh);
}

//print last name
void print_lastname (struct studentInfo *students, int number) {
    for (int i = 0; i < number; i++) {
        char *last_space = strrchr(students[i].fullName, ' ');
        if (last_space != NULL) {
            strcpy(students[i].lastName, last_space + 1);
        }
    }
    for (int i = 0; i < number; i++) {
        printf("%s's last name is %s\n", students[i].fullName, students[i].lastName);
    }   
}

//swap structure
void swap_students(struct studentInfo *students, int i, int p) {
    struct studentInfo temp = students[i];
    students[i] = students[p];
    students[p] = temp;
}

//selection sort GPA 
void sort_GPA(struct studentInfo *students, int number) {
    for (int step = 0; step < (number - 1); step++)
    {
        float max = students[step].GPA;
        int p = step;
        for (int j = (step+1); j < number; j++)
        {
            if (max < students[j].GPA)
            {
                max = students[j].GPA;
                p = j;
            }
        }
        if (p != step)
            {
                swap_students(students, step, p);
            }
    }
}

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

        students[i].GPA = (students[i].algebra + students[i].calculus + students[i].basicProgramming)/3;
    }

    //Task3 - print student list
    printf("\nStudents list: \n");
    print_table(students, number);

    //Task4 - print in text file
    FILE *studentList = fopen("D:\\Nhi Ari\\Code\\C\\Uni\\Final\\studentList.txt", "w");
    fprintf(studentList, "| %-10s | %-20s | %-10s | %-7s | %-8s | %-16s | %-5s |\n",
           "ID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
    fprintf(studentList, "|%s|\n", "-------------------------------------------------------------------------------------------------");

    for (int i = 0; i < number; i++) {
        fprintf(studentList, "| %10s | %-20s | %10s | %7.2f | %8.2f | %17.2f | %4.2f |\n",
               students[i].ID,
               students[i].fullName,
               students[i].birthDate,
               students[i].algebra,
               students[i].calculus,
               students[i].basicProgramming,
               students[i].GPA);
    }
    fclose(studentList);

    //Task5 - highest, lowest GPA, highest BP
    int kh, kl;
    printf("\n");    
    highest_GPA(students, number);
    lowest_GPA(students, number);
    highest_BP(students, number);

    //Task6 - print last name
    printf("\n");
    print_lastname (students, number);

    //Task10 - sort GPA (selection sort)
    sort_GPA(students, number);
    printf("\nStudents list in GPA decreasing order: \n");
    print_table (students, number);
}