#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_LENGTH 30

typedef struct {
    char* destination;
    char* date;
}FlightInfo;

int main(){
    FlightInfo flightInfo[10];
    char* destination = (char*)malloc(MAX_INPUT_LENGTH + 1);
    char* date = (char*)malloc(MAX_INPUT_LENGTH + 1);

    // take input of date and destination
    printf("Hello User, Enter the destinations and dates for  each flights as specified below.\n\n");


    // take destination input
    if(fgets(destination, MAX_INPUT_LENGTH, stdin) == NULL){
        printf("Error in reading destination\n");
    }
    destination[strlen(destination)-1] ='\0';

    // // take date input
    if(fgets(date, MAX_INPUT_LENGTH, stdin) == NULL){
        printf("Error in reading date\n");
    }
    date[strlen(date)-1] ='\0';
    


    return 0;
}