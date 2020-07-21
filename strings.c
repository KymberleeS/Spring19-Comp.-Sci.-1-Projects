/* Project 6
   Name: Kymberlee Sables
   Date: 4-18-19 */

//preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//functions
int replaceAll(char* str, char* old, char* replace);   //subFunc1

//main
int main(void) 
{
  //variable initialization
    char filename[100];
    char word[100];
    char replacement[100];
    char buffer[1000];

    int s = 0;

    FILE* spIn;
    FILE* spOut;

  //statements
    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter the word you want to find: ");
    scanf("%s", word);

    printf("Enter a replacement for that word: ");
    scanf("%s", replacement);

    //file opening error checking
    if((spIn = fopen("myfile.txt", "r")) == NULL)
    {
      printf("file cannot be made\n");
      exit(0);
    }

    if((spOut = fopen("myfile.output", "w")) == NULL)
    {
      printf("file cannot be made\n");
      exit(0);
    }

    //putting all of input into output
    while(fgets(buffer, sizeof(buffer), spIn) != NULL)
    {
      s += replaceAll(buffer, word, replacement);
      fputs(buffer, spOut);
    }

    printf("\n%d instances were found and replaced", s);

  //file closing error checking
    if(fclose(spIn) == EOF)
    {
      printf("file cannot be closed\n");
      exit(0);
    }

    if(fclose(spOut) == EOF)
    {
      printf("file cannot be closed\n");
      exit(0);
    }

  return 0;
}
//subFunc1
int replaceAll(char* str, char* old, char* replace)
{
  //variable initialization
    char* pos;
    char tmp[1000];
    int length = strlen(old); 
    int index = 0;
    int count = 0; 

  //statements
    while((pos = strstr(str, old)) != NULL) 
    { 
      count++;  
      strcpy(tmp, str);            
      index = pos - str;        
      str[index] = '\0';           
      strcat(str, replace);       
      strcat(str, tmp + index + length);   
    }
 return count;
}