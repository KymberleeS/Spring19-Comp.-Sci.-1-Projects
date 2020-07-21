/* Project 5
   Name: Kymberlee Sables
   Date: 4-14-19 */

//preprocessor directrives
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//functions
void overallFile(int* totalChar, int* letters, int* whiteSpaces, int* nums, int* other);    //subFunc1
void letterStats(int* upperCase, int* lowerCase, int alpha[26]);    //subFunc2
void numStats(int* wholeNum, int* sum, float* average);   //subFunc3

//main (where everything will also be printed)
int main(void) 
{
  //variable initialization
    FILE* spOut;

    //overallFile
    int totalChar;
    int letters;
    int whiteSpaces;
    int nums;
    int other;

    //letterStats
    int upperCase;
    int lowerCase;
    int alpha[26];
    int i;

    //numStats
    int wholeNum;
    int sum;
    float average;

  //statements
    //Opening File: Error Checking
    if((spOut = fopen("report.txt", "w")) == NULL)
    {
      printf("file cannot be made\n");
      exit(0);    
    }

    //Function Calls
    overallFile(&totalChar, &letters, &whiteSpaces, &nums, &other);
    letterStats(&upperCase, &lowerCase, alpha);
    numStats(&wholeNum, &sum, &average);

    //Print Statements to report.txt
    fprintf(spOut, "Statistics for file: input.txt\n");
    fprintf(spOut, "----------------------------------------------------\n\n");

    fprintf(spOut, "Total # of characters in file:\t\t\t%d\n", totalChar);
    fprintf(spOut, "\n");

    fprintf(spOut, "Category\t\t\t\t\tHow many in file\t\t\t\t\t%% of file\n");
    fprintf(spOut, "-----------------------------------------------------------------\n");

    fprintf(spOut, "Letters\t\t\t\t\t\t\t\t\t\t\t\t%3d", letters);
    fprintf(spOut, "\t\t\t\t\t\t\t\t%5.2f %%\n", (letters / (float)totalChar) * 100);

    fprintf(spOut, "White Space\t\t\t\t\t\t\t\t\t\t%3d", whiteSpaces);
    fprintf(spOut, "\t\t\t\t\t\t\t\t%5.2f %%\n", (whiteSpaces / (float)totalChar) * 100);

    fprintf(spOut, "Digits\t\t\t\t\t\t\t\t\t\t\t\t%3d", nums);
    fprintf(spOut, "\t\t\t\t\t\t\t\t%5.2f %%\n", (nums / (float)totalChar) * 100);

    fprintf(spOut, "Other Characters\t\t\t\t\t\t\t%3d", other);
    fprintf(spOut, "\t\t\t\t\t\t\t\t%5.2f %%\n", (other / (float)totalChar) * 100);

    fprintf(spOut, "\n\n");
    fprintf(spOut, "LETTER STATISTICS\n");

    fprintf(spOut, "\n");
    fprintf(spOut, "Category\t\t\t\t\tHow many in file\t\t\t\t\t%% of all letters\n");
    fprintf(spOut, "-----------------------------------------------------------------\n");

    fprintf(spOut, "UpperCase\t\t\t\t\t\t\t\t\t\t\t%3d", upperCase);
    fprintf(spOut, "\t\t\t\t\t\t\t\t%5.2f %%\n", (upperCase / (float)letters) * 100);

    fprintf(spOut, "LowerCase\t\t\t\t\t\t\t\t\t\t\t%3d", lowerCase);
    fprintf(spOut, "\t\t\t\t\t\t\t\t%5.2f %%\n", (lowerCase / (float)letters) * 100);

    for(i = 0; i < 26; i++)
    {
      fprintf(spOut, "%c\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%3d", ('a' + i), alpha[i]);
      fprintf(spOut, "\t\t\t\t\t\t\t\t%5.2f %%\n", (alpha[i] / (float)letters) * 100);
    }

    fprintf(spOut, "\n\n");
    fprintf(spOut, "NUMBER ANALYSIS\n");

    fprintf(spOut, "\n");
    fprintf(spOut, "Number of integers in the file:\t\t\t%d\n", wholeNum);
    fprintf(spOut, "Their sum:\t\t\t\t\t\t\t\t\t\t\t\t\t%d\n", sum);
    fprintf(spOut, "Their average:\t\t\t\t\t\t\t\t\t\t\t%.2f", average);

    //Closing File: Error Checking
    if(fclose(spOut) == EOF)
    {
      printf("file cannot be closed\n");
      exit(0);
    }
  return 0;
}
//subFunc1
void overallFile(int* totalChar, int* letters, int* whiteSpaces, int* nums, int* other)
{
  //variable initialization
    FILE* spIn;
    char c;
    int ch = 0;
    int le = 0;
    int ws = 0;
    int n = 0;
    int o = 0;

  //statements
    //Opening File: Error Checking
    if((spIn = fopen("input.txt", "r")) == NULL)
    {
      printf("file does not exist\n");
      exit(0);
    }

    //General File Analysis
    while((c = fgetc(spIn)) != EOF)
    {
      *totalChar = ++ch;

      if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
      {
        *letters = ++le;
      }
      else if(isspace(c))
      {
        *whiteSpaces = ++ws;
      }
      else if(isdigit(c))
      {
        *nums = ++n;
      }
      else 
      {
        *other = ++o;
      }
    }

    //Closing File: Error Checking
    if(fclose(spIn) == EOF)
    {
      printf("file cannot be closed\n");
      exit(0);
    }
  return;
}
//subFunc2
void letterStats(int* upperCase, int* lowerCase, int alpha[26])
{
  //variable initialization
    FILE* spIn;
    char c;
    int u = 0;
    int l = 0;
    int i;
  
  //statements
    //Opening File: Error Checking
    if((spIn = fopen("input.txt", "r")) == NULL)
    {
      printf("file does not exist\n");
      exit(0);
    }

    //setting array equal to 0
    for(i = 0; i <= 26; i++)
    {
      alpha[i] = 0;
    }

    //counting alphabet letters and case-sensitive letters
    while((c = fgetc(spIn)) != EOF)
    {
      if(c >= 'A' && c <= 'Z')
      {
        *upperCase = ++l;
        alpha[c - 'A']++;
      }
      else if(c >= 'a' && c <= 'z')
      {
        *lowerCase = ++u;
        alpha[c - 'a']++;
      }
    }  

    //Closing File: Error Checking
    if(fclose(spIn) == EOF)
    {
      printf("file cannot be closed\n");
      exit(0);
    }
  return;
}
//subFunc3
void numStats(int* wholeNum, int* sum, float* average)
{
  //variable initialization
    FILE* spIn;
    char c;
    int s;
    int n = 0;

  //statements
    //Opening File: Error Checking
    if((spIn = fopen("input.txt", "r")) == NULL)
    {
      printf("file does not exist\n");
      exit(0);
    }

    //counting integers, calculating sum and average
     while((c = fgetc(spIn)) != EOF) 
    {
      if(fscanf(spIn, "%d", &s) == 1)
      {
        *wholeNum = ++n;
        *sum += s;
      }
    }

    *average = (float)*sum / (float)*wholeNum;

    //Closing File: Error Checking
    if(fclose(spIn) == EOF)
    {
      printf("file cannot be closed\n");
      exit(0);
    }
  return;
}