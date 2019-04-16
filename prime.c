#include "prime.h"

/*---------------------------------------------------------------------------------------
--  SOURCE FILE:    prime.cpp
--
--  PROGRAM:        prime
--
--  FUNCTIONS:      
--
--  DATE:           January 21 2018
--
--  REVISIONS:      
--
--  DESIGNERS:          Yiaoping Shu
--
--  PROGRAMMERS:        Yiaoping Shu
--
--  NOTES:
--  This program is called from the thread and process workers. When called, 
--  it will take the range of numbers as an argument and process it checking whether
--  it is divisible by y, a number that is used then incremented to check whether
--  the number is divisible or not to see if it's a prime number. It will then 
--  print out the prine number to file and continue calculating the prime factors of the
--  next number.
---------------------------------------------------------------------------------------*/

int prime(char type, int number, int end)
{
    int y = 2;
    char *name = malloc((sizeof(char) * 8) + sizeof(int));
    FILE *file;
    sprintf(name, "%c%i", type, number);
    
    if ((file = fopen(name, "a+")) == NULL)
    {
        return -1;
    }
    for (; y < end; y++)
    {
        factor(y, file);
    }
    if (fclose(file))
    {
        return -1;
    }
    free(name);
    return 0;
}


/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: factor
--
-- DATE: January 21 2018
--
--
-- DESIGNER: Yiaoping Shu
--
-- PROGRAMMER: Yiaoping Shu
--
-- INTERFACE: void factor (long n, FILE *file)
--
-- RETURN: void
--
-- NOTES:
--  This method is used to calculate the prime factors of a given number. The prime factor is calculated by 
--  checking whether or not it's modulo or remainder is 0 against a number y which starts at 2, and if it is 0
--  we print y out to the screen meaning it's a prime number and a factor. We then increase y to 3 (another prime number)
--  and check it against that. From here on, we check it against only all odd numbers, and if it's modulo is 0
--  then we can confirm that y is a prime number and a factor of the given number. Y will only work as a prime number
--  because all previous numbers if not a prime number would have been factored already. We write this to file displaying
--  all prime factors of a given number. 
----------------------------------------------------------------------------------------------------------------------*/
void factor (long n, FILE *file)
{
    long y = 2;


    
    while(y<n)
    {
        if (n % y == 0)
        {
            fprintf(file, "%lu x ", y);
            n /= y;
        }

        else
        {
            if(y==2)
            {
                y=3;
            }
            else
                y+=2;
        }
    }
    
    fprintf(file, "%lu\n", y);
}


