#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void fillTime(char * , int);
void fillDate(char*);
int inputFormat();
void clearScreen(); 

int main () {
    char time[50] , date[100]; // string to display formatted time...
    int timeFormat = inputFormat();

    while (1) {
        fillTime(time , timeFormat);
        fillDate(date);
        clearScreen();

        printf("Current time is : %s \n" , time);
        printf("Date : %s \n" , date);

        sleep(1); // Sleep for 1 second...
    }

    return 0;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");  
    #endif  
}

void fillTime(char *buffer , int timeFormat) {
    // String format time -> strftime()...
    // %H -> Hours(24 hour clock format) , %M -> Minutes , %S -> Seconds...
    // %I -> Hours(12 hour clock format) , %p -> AM , PM ...
    time_t rawTime;  // raw time...   

    struct tm *currentTime; // structure to display current time or local time...

    time(&rawTime); // time function fills the current time...

    currentTime = localtime(&rawTime); // to convert time acc to India time...

    if (timeFormat == 1) {
        strftime(buffer , 50 , "%H : %M : %S %p" , currentTime);
    }
    else {
        strftime(buffer , 50 , "%I : %M : %S %p" , currentTime);
    }
}

void fillDate(char *buffer) {
    time_t rawTime;  // raw time...   

    struct tm *currentTime; // structure to display current time or local time...
    

    time(&rawTime); // time function fills the current time...

    currentTime = localtime(&rawTime);

    strftime(buffer , 100 , "%A , %B - %d - %Y" , currentTime);

}

int inputFormat() {
    int timeFormat;

    printf("Choose the time format : \n");
    printf("1. 24 Hour Format \n");
    printf("2. 12 Hour Format (default) \n");

    printf("Make a choice(1 / 2) : ");
    scanf("%d" , &timeFormat);

    return timeFormat;  
}