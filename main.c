#include "thread.h"
#include "process.h"
/*---------------------------------------------------------------------------------------
--  SOURCE FILE:    Main.cpp
--
--  PROGRAM:        Main
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
--  This program is the start of the program. It will take in user input
--  and based on what the user input will either go to the process worker
--  or the thread worker. If user types in incorrect arguments in the command
--  line, the program will tell the user the correct usage.
---------------------------------------------------------------------------------------*/
int main (int argc, char **argv)
{
    int opt = 0;
    int numbOfMechanisms = MECHANISM;

    
    while ((opt = getopt(argc, argv, "p:t:")) != -1)
    {
        switch (opt)
    	  {
            case 'p':
                numbOfMechanisms = atol(optarg);
                printf("Number of processes %i\n", numbOfMechanisms);

                if (processWorker(numbOfMechanisms) != 0){
                    printf("Unable to fork process");
                }

                break;

            case 't':
                numbOfMechanisms = atol(optarg);
                printf("Number of threads %i\n", numbOfMechanisms);
                if (threadWorker(numbOfMechanisms) !=0){
                    printf("Unable to fork process");
                }
                    		
                break;

            case '?':
            default:
                fprintf(stderr, "Usage: %s -p [number of processes] -t [number of"
            " threads]\n", argv[0]);
        }
    }
    
    return 0;
}
