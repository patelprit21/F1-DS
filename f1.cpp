/*
* FILE: f1.cpp
* PROJECT: Focus assignment 1
* PROGRAMMER: Prit Patel
* FIRST VERSION: 17-05-2024
* DESCRIPTION: This program takes the input of 10 flight details from a user and displays it in each line in specified format.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_LENGTH 30
#define MAX_FLIGHTS 10

// struct of FlightInfo
typedef struct {
    char* destination;
    char* date;
}FlightInfo;

// function declarations
void fillFlightInfo(FlightInfo* flightInfo, char* destination, char* date);
void printFlightInfo(FlightInfo flightInfo[]);

int main(){
    // initialization of necessary variables
    FlightInfo flightInfo[MAX_FLIGHTS];
    char* destination = (char*)malloc(MAX_INPUT_LENGTH + 1);
    char* date = (char*)malloc(MAX_INPUT_LENGTH + 1);
    int flights = MAX_FLIGHTS;

    // take input of date and destination
    printf("Hello User, Enter the destinations and dates for  each flights as specified below.\n\n");

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

        // fill data
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

/*
Function: fillFlightInfo()
Parameters: FlightInfo* flightInfo: struct of flight information
            char* destination: pointer to destination string
            char* date: pointer to date string
Description: This fuction fills up the two parameters for the given struct element.
Return values: void
*/
void fillFlightInfo(FlightInfo * flightInfo, char* destination, char* date){
    
    // allocate memory
    flightInfo->destination = (char*)malloc(strlen(destination)+1);
    flightInfo->date = (char*)malloc(strlen(date)+1);

    // set fields
    strcpy(flightInfo->destination, destination);
    strcpy(flightInfo->date, date);

}

/*
Function: printFlightInfo()
Parameters: FlightInfo flightInfo[]: array of struct of flight information
Description: This fuction prints the flight information in a specific systematic manner.
Return values: void
*/
void printFlightInfo(FlightInfo flightInfo[]){
    printf("--------------- Flights Information ---------------\n", flightInfo[0].date);
    for(int i=0;i<MAX_FLIGHTS;i++){
        printf("%-35s %-35s\n", flightInfo[i].destination, flightInfo[i].date);
    }
}