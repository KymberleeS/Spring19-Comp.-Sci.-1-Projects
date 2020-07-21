/* Project 1
	Name: Kymberlee Sables
	Date: 2-8-19 */
	
#include <stdio.h>

int main(void)
{
//variable initialization
	int population;
	int shareToilet;
	int flushAmount;
	int newToilet = 2;
	int cost = 150;
	
	float toiletsNeeded;
	float litersUsed;
	float litersPerFlush;
	float saved;
	float total;
  
 //statements
	printf("Welcome to FlushSave!!\n");
  
	printf("\nWhat is the population of the community?  ");
	scanf("%d", &population);
  
	printf("How many persons will share a toilet?  ");
	scanf("%d", &shareToilet);

	printf("How much water(liters) do the existing toilets use for each flush?  ");
	scanf("%f", &litersPerFlush);

	printf("How many times on average a toilet is flushed per day?  ");
	scanf("%d", &flushAmount);

  
	printf("\n--------------------------------------------------\n");
	
	
	printf("\nThere are %d people in your community", population);

	toiletsNeeded = (float)population / (float)shareToilet;
	printf("\nYou need %.2f toilets.", toiletsNeeded);

	litersUsed = (float)toiletsNeeded * (float)litersPerFlush * (float)flushAmount;
	printf("\nYour community uses %.2f liters of water per day just for using the toilet!", litersUsed);

	saved = litersUsed - ((float)toiletsNeeded * (float)flushAmount * (float)newToilet);
	printf("\nYour community can save %.2f liters of water per day just by switching to our toilets!", saved);

	total = (float)cost * (float)toiletsNeeded;
	printf("\nThis will only cost you $%.2f\n\n", total);


  return 0;
}
	
	
	
	
	
	