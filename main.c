#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "findAge.h"

struct studentInfo //initiate studentInfo structure
{
    char name[20]; // name of student, max 19 char (last space for null char)
    char ID[10]; // ID of student, max 9 char (last space for null char)
    char birthdate[11]; // birthdate in format DD/MM/YYYY (last space for null char)
    float linearAlgebra;
    float calculus;
    float basicProgramming;
    float GPA;
};

//swap for student info structures
void swap(struct studentInfo *a, struct studentInfo *b) {
    struct studentInfo t = *a; //temporary var
    *a = *b;
    *b = t;
} // this function is made for later sort function

//start quick sort gpa
/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, 
and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
int partitionGPA(struct studentInfo *studentArray, int start, int end, bool ascending){
    float pivot = studentArray[end].GPA;
    int i = start - 1; // Index of smaller element and indicates the 
    // right position of pivot found so far

    for (int j = start; j <= end-1; j++){ 
        if (studentArray[j].GPA <= pivot && ascending){ // If current element is smaller than the pivot
            i++;
            swap(&studentArray[i],&studentArray[j]);
        }
        if (studentArray[j].GPA > pivot && !ascending){ // If current element is greater than the pivot
            i++;
            swap(&studentArray[i],&studentArray[j]);
        }
    }
    i++;
    swap(&studentArray[i],&studentArray[end]);
    return i;
}

void quickSortGPA(struct studentInfo *studentArray, int start, int end,bool ascending){
    if (end <= start) {return;}
    
    float pivot = partitionGPA(studentArray,start,end,ascending);
    quickSortGPA(studentArray, 0, pivot - 1,ascending); // sort the left side of pivot
    quickSortGPA(studentArray, pivot + 1, end,ascending); // sort the right side of pivot
}
//end quick sort gpa

//start bubble sort basic programming score
void bubbleSort(struct studentInfo *studentArray, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (studentArray[j].basicProgramming > studentArray[j + 1].basicProgramming)
                swap(&studentArray[j], &studentArray[j + 1]);
}
//end bubble sort for basic programming score

void displayStudentInfo(int n,struct studentInfo *studentArray){
    printf("%20s|%15s|%15s|%10s|%10s|%20s|%10s\n","Name","ID","Date of Birth","Linear","Calculus","Basic Programming","GPA");
    printf("===============================================================================================================\n");
    for(int i=0;i<n;i++){
        printf("%20s|%15s|%15s|%10f|%10f|%20f|%10f\n", //20s is space pre-defined for table            
            studentArray[i].name,
            studentArray[i].ID,
            studentArray[i].birthdate,
            studentArray[i].linearAlgebra,
            studentArray[i].calculus,
            studentArray[i].basicProgramming,
            studentArray[i].GPA);
    }
}

void writeToFile(int n,struct studentInfo *studentArray){
    FILE *filePointer;
    filePointer = fopen("dataBase.txt","w"); //open file

    if(filePointer == NULL){
      printf("Error!");   
      exit(1);             
    }        
// similar to display function above, just use fprintf to print to file
    fprintf(filePointer,"%20s|%15s|%15s|%10s|%10s|%20s|%10s\n","Name","ID","Date of Birth","Linear","Calculus","Basic Programming","GPA");
    fprintf(filePointer,"===============================================================================================================\n");
    for(int i=0;i<n;i++){
        fprintf(filePointer,"%20s|%15s|%15s|%10f|%10f|%20f|%10f\n",            
            studentArray[i].name,
            studentArray[i].ID,
            studentArray[i].birthdate,
            studentArray[i].linearAlgebra,
            studentArray[i].calculus,
            studentArray[i].basicProgramming,
            studentArray[i].GPA);       
    }
    fclose(filePointer); // close file
}

void highestGPA(int n, struct studentInfo *studentArray){
    quickSortGPA(studentArray,0,n-1,false);
    printf("%s has the highest GPA\n",studentArray[0].name);
}

void lowestGPA(int n, struct studentInfo *studentArray){
    quickSortGPA(studentArray,0,n-1,true);
    printf("%s has the lowest GPA\n",studentArray[0].name);
}

void highestBP(int n,struct studentInfo *studentArray){
    struct studentInfo max = studentArray[0]; // set max to first student
    for (int i=0;i<n;i++){
        if (max.basicProgramming < studentArray[i].basicProgramming){ // if current student has higher grade than max
            max = studentArray[i]; // set max to current student
        }
    }
    printf("%s has the highest BP point",max.name); // we actually able to access other information in this way
}

char *getLastName(char *fullName){
    char *lastName = (char*) malloc(10*sizeof(char)); 
    char *lastSpace = strrchr(fullName, ' '); // find the last space character and words behind it
    if (lastSpace != NULL) {
        strcpy(lastName, lastSpace + 1); //copy to lastName
        free(lastSpace); // no use lastSpace anymore
    }        
    printf("student's last name is %s", lastName);
    return lastName;
}

void getOldest(int n, struct studentInfo *studentArray){ //similar to above function
    struct studentInfo max = studentArray[0];
    for (int i=0;i<n;i++){
        if (getAge(max.birthdate) < getAge(studentArray[i].birthdate)){
            max = studentArray[i];
        }
    }
    printf("%s is the oldest",max.name);
}

void getYoungest(int n, struct studentInfo *studentArray){
    struct studentInfo min = studentArray[0];
    for (int i=0;i<n;i++){
        if (getAge(min.birthdate) > getAge(studentArray[i].birthdate)){
            min = studentArray[i];
        }
    }
    printf("%s is the oldest",min.name);
}

struct studentInfo search(struct studentInfo *studentArray,int n){
    int i=0;
    char target[10];

    printf("Enter ID of student you want to find: ");
    getchar();
    fgets(target,10,stdin);
    target[strcspn(target,"\n")] = '\0'; //remove trailing newline from target

    for (i=0;i<n;i++){ //search all elements to find target
        if (strcasecmp(studentArray[i].ID,target)==0){// compare 2 string without case-sensitve, if equal -> print student
            printf("Name: %s\nID: %s\nDate of birth: %s\nLinear Algebra: %f\nCalculus: %f\nBasic Programming: %f\nGPA: %f\n ",
            studentArray[i].name,studentArray[i].ID,studentArray[i].birthdate,
            studentArray[i].linearAlgebra,studentArray[i].calculus,studentArray[i].basicProgramming,studentArray[i].GPA);
            break;
        }
    }
    if (strcasecmp(studentArray[i].ID,target)!=0){
        printf("There is no matched ID");
    }
    return studentArray[i];
}
int main (){
//get number of student:
    int numberOfStudent;
    printf("enter number of student: ");
    scanf("%d",&numberOfStudent);
//get student info:
    struct studentInfo studentArray[numberOfStudent];
    for (int i=0;i<numberOfStudent;i++){
        
        printf("Type in student's name: ");
        getchar();
        fgets(studentArray[i].name,20,stdin);
        studentArray[i].name[strcspn(studentArray[i].name,"\n")] = '\0';

        printf("Type in student's ID: ");
        fgets(studentArray[i].ID,10,stdin);
        getchar();
        studentArray[i].ID[strcspn(studentArray[i].ID,"\n")] = '\0';

        printf("Type in student's birthdate: ");
        fgets(studentArray[i].birthdate,11,stdin);
        studentArray[i].birthdate[strcspn(studentArray[i].birthdate,"\n")] = '\0';

        printf("Type in student's linear grade: ");
        scanf("%f", &studentArray[i].linearAlgebra);

        printf("Type in student's calculus grade: ");
        scanf("%f", &studentArray[i].calculus);

        printf("Type in student's basic programming grade: ");
        scanf("%f", &studentArray[i].basicProgramming);     

        studentArray[i].GPA = (studentArray[i].linearAlgebra + studentArray[i].calculus + studentArray[i].basicProgramming)/3;
    }
    // highestBP(numberOfStudent,studentArray);
//display student info
    // displayStudentInfo(numberOfStudent,studentArray);
//write to file
    // writeToFile(numberOfStudent,studentArray);
    // search(studentArray,numberOfStudent);
    for(int i=0; i<numberOfStudent;i++){
        printf("student's last name is %s", getLastName(studentArray[i].name));
    }
    return 0;
}