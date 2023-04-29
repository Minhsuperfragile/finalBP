#include<stdio.h>
#include<conio.h>


typedef struct{
	char fullName[20];
	char ID[10];
	char birthdate[11];
	float algebra;
	float calculus;
	float basicProgramming;
	float GPA;
}Studentinfo;



void Enter(int *n,Studentinfo students[]) {
    printf("Enter number of students: ");
    scanf("%d",n);
    getchar(); // consume the newline character left in the input stream


    for (int i = 0; i < *n; i++) {
        printf("Enter student %d name: ", i+1);
        fgets(students[i].fullName, sizeof(students[i].fullName), stdin); //use fgets instead of scanf
        students[i].fullName[strcspn(students[i].fullName, "\n")] = 0; // Remove trailing newline

        printf("Enter student %d ID: ", i+1);
        scanf("%s", students[i].ID);
        getchar(); // consume the newline character left in the input stream

        printf("Enter student %d birthdate: ", i+1);
        scanf("%s", students[i].birthdate);
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
}



void Print(int n, Studentinfo students[]){
    int i;
    printf("\nName            ID\t        birthdate\talgebra  \tcalculus  \tbasicProgramming\tGPA\n");
    for(i=0;i<n;i++){
        printf("%-15s\t%-9s\t%-11s\t%-8.2f\t%-8.2f\t%-16.2f\t%-3.2f\n",students[i].fullName,students[i].ID,students[i].birthdate,students[i].algebra,students[i].calculus,students[i].basicProgramming,students[i].GPA);
	}
}

void Print_text(int n,Studentinfo students[]){
    char *filename ="table.txt";
    FILE *fp = fopen(filename,"w+");
    int i;
    fprintf(fp,"\nName            ID\t        birthdate\talgebra  \tcalculus  \tbasicProgramming\tGPA\n");
    for(i=0;i<n;i++){
        fprintf(fp,"%-15s\t%-9s\t%-11s\t%-8.2f\t%-8.2f\t%-16.2f\t%-3.2f\n",students[i].fullName,students[i].ID,students[i].birthdate,students[i].algebra,students[i].calculus,students[i].basicProgramming,students[i].GPA);
	}
	fclose(fp);
}


int main(){

    Studentinfo students[100];
    int n;
    int choice;

    do{
        printf("\n\n    MENU  \nPress 1 or 2 or 3\n\n");
        printf("1. Enter number of students and their information\n");
        printf("2. Print all students information\n");
        printf("3. Print into text file\n");
        printf("What do you want to do: ");scanf("%d", &choice);
        switch(choice){
            case 1:
                Enter(&n,students);
                break;
            case 2:
                Print(n,students);
                break;
            case 3:
                Print_text(n,students);
                break;
            default:
                printf("Enter 1 or 2 or 3 only\n");
                break;
        }
    }while(choice!=0);
    return 0;
}
