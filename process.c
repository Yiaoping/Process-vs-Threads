#include "process.h"
#include "prime.h"
/*---------------------------------------------------------------------------------------
--  SOURCE FILE:    processWorker.cpp
--
--  PROGRAM:        processWorker
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
--  This function is called from main when user tells program that it wants to run
--  tasks using multi-process. It gets the current time then forks the amount of process
--  and calculates the prime factors from 0-50000, then gets the current time and calculates
--  how long the process took to complete the job.
---------------------------------------------------------------------------------------*/
int processWorker(int processes)
{
    int pid = 0;
    int num = 0;
    int val = 0;
    struct timeval start;
    struct timeval end;

    gettimeofday(&start, NULL);

    for (num = 0; num < processes; num++)
    {
        

        if ((pid = fork()) == 0)	
        {
            val = prime('p', num, 50000);

            if (val == -1)	
            {
                printf("Error in Process\n");
                return -1;
            }

            gettimeofday(&end, NULL);
            printf("Microseconds:");
            printf("%ld\n", (end.tv_sec - start.tv_sec)*1000000 + end.tv_usec- start.tv_usec);                

            return 0;
        }

        else if (pid == -1)
        {
            printf("error in fork\n");
            return 1;
        }
    }

    return 0;
}
