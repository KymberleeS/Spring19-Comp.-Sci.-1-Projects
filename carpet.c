/* Project 2
   Name: Kymberlee Sables
   Date: 2-26-19 */

//preprocessor directives
#include <stdio.h>
#include <stdlib.h>

//functions
void getData(int* length, int* width, float* discount, float* costSqrFt);   //subFunc 1
void calculate(float iP, float sT, float t);    //subFunc 2
void printRes(float iP, float sT, float t);    //subFunc 3

//main
int main(void) 
{
  //variable initalization
    float installPrice;
    float subTotal;
    float total;

  //statements
    calculate(installPrice, subTotal, total);
    printRes(installPrice, subTotal, total);

  return 0;
}
//subFunc 1
void getData(int* length, int* width, float* discount, float* costSqrFt)
{
  //statements
    printf("Length of room (feet): ");
    scanf("%d", length);
    printf("\n\nWidth of room (feet): ");
    scanf("%d", width);
    printf("\n\nCustomer discount (percent): ");
    scanf("%f", discount);
    printf("\n\nCost per square foot (dollars): ");
    scanf("%f", costSqrFt);
    return;
}
//subFunc 2
  //functions 2
    float installPrice(int* L, int* W, float* costSqrFt);   //subFunc 2.1
    float subTotal(float* discount, float iP, float* amt);    //subFunc 2.2
    float total(float* T, float sT);    //subFunc 2.3

//main 2
void calculate(float iP, float sT, float t)
{
  //variable initialization
    int length;
    int width;
    float discount;
    float costSqrFt;
    float T;
    float amt;

  //statements
    iP = installPrice(&length, &width, &costSqrFt);
    sT = subTotal(&discount, iP, &amt);
    t = total(&T, sT);
    return;
}
//subFunc 2.1
float installPrice(int* L, int* W, float* costSqrFt)
{
  //statements
  return((*L * *W * 0.55) + (*L * *W * *costSqrFt));
}
//subFunc 2.2
float subTotal(float* discount, float iP, float* amt)
{
  //statements
    *amt = (*discount / 100) * iP;
    return(iP - *amt);
}
//subFunc 2.3
float total(float* T, float sT)
{
  //variable initialization
    float tax;

  //statements
    tax = 0.06 * sT;
    return(*T = tax + sT);
}
//subFunc 3
void printRes(float iP, float sT, float t)
{
  //variable initialization
    int length;
    int width;
    float costSqrFt;
    float discount;
    float T;
    float amt;

  //statements
    getData(&length, &width, &discount, &costSqrFt);

    iP = installPrice(&length, &width, &costSqrFt);
    sT = subTotal(&discount, iP, &amt);
    t = total(&T, sT);

    printf("\n\n\n---------------------------------------------------------");

    printf("\n\t\tMEASUREMENT");

    printf("\n\nLength");
    printf("\t\t\t\t %d ft", length);

    printf("\nWidth");
    printf("\t\t\t\t %d ft", width);

    printf("\nArea");
    printf("\t\t\t\t %d square ft", (length * width));

    printf("\n\n\n\t\t  CHARGES");

    printf("\n\n\nDESCRIPTION");
    printf("\t\tCOST/SQ FT");
    printf("\t\t   CHARGE");

    printf("\n\n---------------------------------------------------------");
    
    printf("\n\nCarpet%20c %5.2f %16c %6.2f",'$' , costSqrFt, '$', (costSqrFt * length * width));

    printf("\nLabor%21c %5.2f %16c %7.2f", '$', 0.55, '$', (0.55 * length * width));

    printf("\n---------------------------------------------------------");

    printf("\nInstalled Price%34c %5.2f", '$', (length * width * 0.55) + (length * width * costSqrFt));
    
    printf("\nDiscount%24.2f%% %15c %7.2f", discount, '$', amt);

    printf("\n---------------------------------------------------------");

    printf("\nSubtotal%41c %1.2f", '$', sT);

    printf("\nTax%46c %7.2f", '$', (sT * 0.06));
   
    printf("\nTotal%44c %.2f", '$', t);
	
	printf("\n");
    return;
}

