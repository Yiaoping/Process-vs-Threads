#ifndef THREAD_H
#define THREAD_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

int threadWorker(int threadNum);
void *threadFunc();

#endif
