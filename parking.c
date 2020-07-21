/* Project 3
   Name: Kymberlee Sables
   Date: 3-12-19 */

//preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//functions
void getData(char* vehicle, int* hourEnt, int* minEnt, int* hourLeft, int* minLeft ); //subFunc1
int calcTime(int hourStart, int minStart, int hourEnd, int minEnd, int* hours, int* minutes); //subFunc2
void calcCost(float* fare, int totalTime, char vehicle); //subFunc3
void prinRes(float fare, int totalHours, int totalMinutes); //subFunc4

//main
int main(void) 
{
  //variable initialization
    char vehicle;
    float fare;
    int hourEnt;
    int minEnt;
    int hourLeft;
    int minLeft;
    int totalHours;
    int totalMinutes;
    int wholeHour;

  //statements
    getData(&vehicle, &hourEnt, &minEnt, &hourLeft, &minLeft);
    wholeHour = calcTime(hourEnt, minEnt, hourLeft, minLeft, &totalHours, &totalMinutes);
    calcCost(&fare, wholeHour, vehicle);
    prinRes(fare, totalHours, totalMinutes);
    return 0;
}
//subFunc1
void getData(char* vehicle, int* hourEnt, int* minEnt, int* hourLeft, int* minLeft )
{
  //statements
    printf("Type of vehicle (C for car, T for truck, B for bus): ");
    scanf("%c", vehicle);
    switch(*vehicle)
      {
        case 'C':
        case 'c': 
        break;

        case 'B':
        case 'b': 
        break;

        case 'T':
        case 't': 
        break;

        default: printf("\nINVALID INPUT\n\n");
        exit(0);
      }

    printf("Time when vehicle will enter the lot (h:m): ");
    scanf("%d:%d", hourEnt, minEnt);
    if ((*hourEnt <= 24 && *hourEnt >= 0) && (*minEnt <= 60 && *minEnt >=0))
      ;
    else
    {
      printf("\nINVALID INPUT\n\n");
      exit(0);
    }
    
    printf("Time when vehicle will leave the lot (h:m): ");
    scanf("%d:%d", hourLeft, minLeft);
    if ((*hourLeft <= 24 && *hourLeft >= 0) && (*minLeft <= 60 && *minLeft >=0))
      ;
    else
    {
      printf("\nINVALID INPUT\n\n");
      exit(0);
    }
    return;
}
//subFunc2
int calcTime(int hourStart, int minStart, int hourEnd, int minEnd, int* hours, int* minutes)
{
  //variable initialization
    int wholeHour;

  //statements
    *hours = hourEnd - hourStart;
    *minutes = minEnd - minStart;

    if ((*hours > 0) && (*minutes > 0))
    {
      ;
    }
    else if ((*hours > 0) && (*minutes < 0))
    {
      *minutes = 60 + *minutes;
      *hours = *hours - 1;
    }
    else if ((*hours < 0) && (*minutes > 0))
    {
      *hours = *hours + 24;
    }
    else if ((*hours < 0) && (*minutes < 0))
    {
      *minutes = 60 + *minutes;
      *hours = *hours - 1;
      *hours = *hours + 24;
      printf("\nWARNING: Vehicles on the parking lot past midnight will be towed. Please try again.\n\n");
      exit(0);
    }
    else
      ;

    return (wholeHour = *hours + 1);
}
//subFunc3
void calcCost(float* fare, int totalTime, char vehicle)
{
  //statements
    if ((vehicle == 'c' || vehicle == 'C') && (totalTime <= 3))
      *fare = totalTime * 0.00;
    else if ((vehicle == 'c' || vehicle == 'C') && (totalTime > 3))
      *fare = (totalTime - 3) * 1.50;
    else if ((vehicle == 't' || vehicle == 'T') && (totalTime <= 2))
      *fare = totalTime * 1.00;
    else if ((vehicle == 't' || vehicle == 'T') && (totalTime > 2))
      *fare = ((totalTime - 2) * 2.30) + 2.00;
    else if ((vehicle == 'b' || vehicle == 'B') && (totalTime <= 1))
      *fare = totalTime * 2.00;
    else if ((vehicle == 'b' || vehicle == 'B') && (totalTime > 1))
      *fare = ((totalTime - 1) * 3.70) + 2.00;
    else
      ;

    return;
}
//subFunc4
void prinRes(float fare, int totalHours, int totalMinutes)
{
  //statements
  printf("\nParking Time: %d:%d", totalHours, totalMinutes);
  printf("\nCost: $%.2f", fare);
  printf("\n\n");
  return;
}