/*Troy Ricks: cssc1101
*Sydney Blackburn: cssc1112
*
*Class: CS570, Professor Leonard, Summer 2017
*Due: June 5, 2017
*Project: Assignment #1, Thread Simulator
*File: bots.h
*/

#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
void processID(void);
void create_threads(void);
void join_threads(void);
void *thread_execute(void* thrd);