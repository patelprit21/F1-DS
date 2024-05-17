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
void printFlightInfo(FlightInfo flightInfo[]);

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

        fillFlightInfo(&flightInfo[9-flights], destination, date);
    }

    // print flight data
    printFlightInfo(flightInfo);

    // Free allocated memory
    free(destination);
    free(date);
    flights = MAX_FLIGHTS;
    while(flights--){
        free(flightInfo[9-flights].destination);
        free(flightInfo[9-flights].date);
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

void printFlightInfo(FlightInfo flightInfo[]){
    printf("--------------- Flights Information ---------------\n", flightInfo[0].date);
    for(int i=0;i<MAX_FLIGHTS;i++){
        printf("%-35s %-35s\n", flightInfo[i].destination, flightInfo[i].date);
    }
}