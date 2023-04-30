#include <stdio.h> 
struct Student{
	 
    int StudentID;
    
};

void Enter(Student stu[], int n){ //function to enter information of students
    for(int i=0; i<n; i++){
        printf("\nEnter information of student number %d:",i);
         printf("\nEnter Student ID:");
        scanf("%d", &stu[i].StudentID);
       
    }
}

void Print(Student stu[], int n){ //function to print out student information
    printf("\n-----STUDENT INFORMATION-----\n");
    printf(" StudentID \t  \n");
    for(int i=0; i<n; i++){
        printf(" %d \t  \n",stu[i].StudentID);
    }
}

int main(){
      Student stu[1000]; // Enter number of students with maximum 1000 elements
    int n; // enter the number of students
    printf("Enter the number of students:");
    scanf("%d",&n);
    
    Enter(stu,n);
    Print(stu,n);

}