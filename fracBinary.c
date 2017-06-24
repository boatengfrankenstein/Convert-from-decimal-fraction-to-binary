/********************************************************************
* fracBinary.c
*
* A program to convert decimal fraction to binary
*
* Author: Richard T. Ahuakli
*
* Email: tsaatey@gmail.com
*
* Index Num: 5131040294
*
*********************************************************************/

#include <stdio.h>

int main()
{
    //Variable defintions
    int counter1 = 0;
    int counter2 = 0;
    int index = 0;
    int binaryA[100]; //An array to store the converted bits of the whole number
    int binaryB[100]; //An array to store the converted bits of the remainder
    long double breaker[100]; //An array to keep track of the old fraction values
    
    long double fullFraction = 0.0;
    long int wholeNumber;
    long int wholePart;
    long double remainingFraction = 0.0;
    
    //Accept user input
    do
    {
    printf("Enter positive decimal fraction here: ");
    scanf("%Lf", &fullFraction);
    }
    while (fullFraction < 0.0);
    
    //Find the whole number aspect of the fraction
    wholeNumber = (int)fullFraction;
    
    //Find the remainder of the full fractionS
    remainingFraction = fullFraction - wholeNumber;
    
    //Convert the whole number part to binary
    if (wholeNumber == 0)
    {
        printf("%ld", wholeNumber);
    }
    else
    {
        //Do if the whole number is greater than zero
        while (wholeNumber > 0)
        {
            counter1++;
            binaryA[counter1] = wholeNumber % 2;
            wholeNumber = wholeNumber / 2;
        }  
    }
    
    
    //Convert remaining fraction to binary
    do
    {
        remainingFraction = remainingFraction * 2;
        breaker[++index] = remainingFraction;
     
        //Convert the fraction to an integer
        wholePart = (int)remainingFraction;
        
        //Store the converted integer in array
        binaryB[counter2++] = wholePart;
        remainingFraction = remainingFraction - wholePart;
        
        //Check for repeated values in the fraction list and break
        if (counter2 > 4)
        {
            if (breaker[counter2] == remainingFraction)
            {
                break;
            }
        }
        else if(remainingFraction == 0){
            break;      //Remaining fraction becomes zero
        }
    }
    while (counter2 < 10);
    
   
    //Print the contents of the whole number array
    for (int j = counter1; j > 0; j--)
    {
        printf("%d", binaryA[j]);
    }
    
    //Print dot separator between the whole number and the fraction
    printf(".");
    
    //Print content of fraction array
    for (int k = 0; k < counter2; k++)
    {
        printf("%d", binaryB[k]);
    }
    //Print a new line
    printf("\n");
    
    return 0;
}
