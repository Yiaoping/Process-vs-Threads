#include "thread.h"
#include "pthread.h"
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
--  tasks using multi-threading. It gets the current time then creates thread based on
--  how many threads user wanted. It runs the function through the thread then joins
--  the thread to wait for the thread to complete and to get the return value of the time.
--  It then displays the time it took to the user and frees the resources.
---------------------------------------------------------------------------------------*/
int threadWorker(int threadNum)
{
    
    long num = 0;

    struct timeval *start = malloc(threadNum * sizeof(struct timeval));

    long int *end = malloc(threadNum * sizeof(long int));    

    pthread_t *threads = malloc(threadNum * sizeof(pthread_t));
    
    
    //create threads
    for (num = 0; num < threadNum; num++)
    {
        gettimeofday(&start[num], NULL);
        pthread_create(&threads[num], NULL, threadFunc, (void *)num);
    }

    

    for (num = 0; num < threadNum; num++)
    {
        pthread_join(threads[num], (void*)&end[num]);
    }

    for (num = 0; num < threadNum; num++)
    {
    	    printf("Microseconds:");
            printf("%ld\n", end[num] - (start[num].tv_sec * 1000000 + start[num].tv_usec));
        
    }
    
    free(threads);
    free(start);
    free(end);
    
    return 0;
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: threadFunc
--
-- DATE: January 21 2018
--
--
-- DESIGNER: Yiaoping Shu
--
-- PROGRAMMER: Yiaoping Shu
--
-- INTERFACE: void *threadFunc(void *number)
--
-- RETURN: value of time is made available from succcessful pthread_join
--
-- NOTES:
-- This method is used to call the prime function to calculate the prime factors of a range of numbers from 0 to 50000.
-- It gets the current time of day and sends this back to pthread_join to display the time to the user.
----------------------------------------------------------------------------------------------------------------------*/
void *threadFunc(void *number)
{
    struct timeval endTime;
    long int time = 0;


    prime('t', (long)number, 50000);

    gettimeofday(&endTime, NULL);
    time = endTime.tv_sec * 1000000 + endTime.tv_usec; 
    
    //return value of time
    pthread_exit((void*)time);
}
