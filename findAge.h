#include <stdlib.h>
#include <stdio.h>

int getAge(char *birthDate){
    char year[4] = "\0";
    int i = 0, j =0;
    for (i=6;i<11;i++){ // because 4 last characters are year
        year[j++]= birthDate[i];
    }
    int age = 2023 - atoi(year); //atoi is used to convert string year to int
    return age;
}