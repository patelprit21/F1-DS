#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_LENGTH 30
#define MAX_FLIGHTS 10

typedef struct {
    char* destination;
    char* date;
}FlightInfo;


void fillFlightInfo(FlightInfo* flightInfo, char* destination, char* date);

int main(){
    FlightInfo flightInfo[MAX_FLIGHTS];
    char* destination = (char*)malloc(MAX_INPUT_LENGTH + 1);
    char* date = (char*)malloc(MAX_INPUT_LENGTH + 1);

    // take input of date and destination
    printf("Hello User, Enter the destinations and dates for  each flights as specified below.\n\n");

    int flights = MAX_FLIGHTS;

    while(flights--){

        printf("--------------- Flight %d ---------------\n", 10 - flights);

        // take destination input
        printf("Destination: ");
        if(fgets(destination, MAX_INPUT_LENGTH, stdin) == NULL){
            printf("Error in reading destination\n");
        }
        destination[strlen(destination)-1] ='\0';

        // take date input
        printf("Date: ");
        if(fgets(date, MAX_INPUT_LENGTH, stdin) == NULL){
            printf("Error in reading date\n");
        }
        date[strlen(date)-1] ='\0';

        fillFlightInfo(&flightInfo[10-flights], destination, date);
        printf("%s %s\n", flightInfo[10-flights].destination, flightInfo[10-flights].date);
    }

    
    return 0;
}

void fillFlightInfo(FlightInfo * FlightInfo, char* destination, char* date){
    
    // allocate memory
    FlightInfo->destination = (char*)malloc(strlen(destination)+1);
    FlightInfo->date = (char*)malloc(strlen(date)+1);

    // set fields
    strcpy(FlightInfo->destination, destination);
    strcpy(FlightInfo->date, date);

}