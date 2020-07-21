/* Project 4
   Name: Kymberlee Sables
   Date: 4-2-19 */

//preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//main
int main(void) 
{
  //variable initialization
    int x;
    int y;
    int i;
    int j;
    int range;
    int sum = 0;
    int product = 1;
    float invSum;
    float average;
    float gRange;
    float geometricMean;
    float harmonicMean;

  //statements
    printf("Input two integers: ");
    scanf("%d %d", &x, &y);

    //range
      if(x < y)
      {
        range = y - x + 1;
        gRange = (1 / (float)range);
      }
      else
      {
        range = x - y + 1;
        gRange = (1 / (float)range);
      }

    //sum
      if(x < y)
      {
        for(i = x; i <= y; i++)
        {
          sum += i;
          invSum += 1 / (float)i;
        }
      }
      else if(y < x)
      {
        for(i = y; i <= x; i++)
        {
          sum += i;
          invSum += 1 / (float)i;
        }
      }
      printf("\nSum: %d\n", sum);
  
    //product
      if(x < y)
      {
        for(j = x; j <= y; j++)
        {
          product *= j;
        }
      }
      else if(y < x)
      {
        for(j = y; j <= x; j++)
        {
          product *= j;
        }
      }
      printf("Product: %d\n", product);

    //average
      if(x < y)
      {
        average = (float)sum / (float)range;
        printf("Average: %.2f\n", average);
      }
      else
      {
        average = (float)sum / (float)range;
        printf("Average: %.2f\n", average);
      }

    //geometric mean
      if(x < y)
      {
        geometricMean = pow(product, gRange);
        printf("Geometric Mean: %.2f\n", geometricMean);
      }
      else
      {
        geometricMean = pow(product, gRange);
        printf("Geometric Mean: %.2f\n", geometricMean);
      }
    
    //harmonic mean
      if(x < y)
      {
        harmonicMean = range / invSum;
        printf("Harmonic Mean: %.2f", harmonicMean);
      }
      else
      {
        harmonicMean = range / invSum;
        printf("Harmonic Mean: %.2f", harmonicMean);
      }
      printf("\n\n");

  return 0;
}