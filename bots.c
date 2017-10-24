/*Troy Ricks: cssc1101
*Sydney Blackburn: cssc1112
*
*Class: CS570, Professor Leonard, Summer 2017
*Due: June 5, 2017
*Project: Assignment #1, Process Manager
*File: bots.c
*/

#include "bots.h"

#define Num_Threads 7
FILE *fptr;
sem_t FLAG;
pthread_t threads[Num_Threads];

void main()
{
	processID(); /* Create QUOTE.txt & write pid to file */
	sem_init(&FLAG, 0, 1);
	create_threads(); /* Create 7 threads */
	join_threads(); /* Wait for threads to finish before continuing */
	sem_destroy(&FLAG);
	printf("Friendly message to the console\n");
	exit(0);
}

void processID(void) {
	fptr = fopen("QUOTE.txt", "w");
	fprintf(fptr, "%d\r\n", getpid());
	fclose(fptr);
}

void create_threads(void) {
	int status, i;
	for(i=0; i<Num_Threads; i++){
		status = pthread_create (&threads[i], NULL, (void *) &thread_execute, (void *)i);
		if(status != 0) /* Check that thread created successfully */
		{
			printf("pthread_create returned error code %d0", status);
			exit(-1);
		}
	}
}

void join_threads(void) {
	int j;
	for (j=0; j<Num_Threads; j++) {
		pthread_join(threads[j],NULL);
	}
}

void *thread_execute(void * thrd) {
	int tid = (int*) thrd; /* Gives thread ID # between 0 and 6 */
	int i, j;
	if (tid % 2 == 0) { /* Even numbered thread */
		for(i=0; i<8; i++){
			sleep(2); /* Run thread every 2 seconds */
			sem_wait(&FLAG); /* Wait for flag to be available */
			printf("Thread %d is running\n", pid);
			fptr = fopen("QUOTE.txt", "a");
			fprintf(fptr, "%u Controlling complexity is the essence of computer programming. --Brian Kernigan\r\n", pthread_self());
			fclose(fptr);
			sem_post(&FLAG); /* Release flag */
		}
	}
	else { /* Odd numbered thread */
		for(j=0; j<8; j++){
			sleep(3); /* Run thread every 3 seconds */
			sem_wait(&FLAG); /* Wait for flag to be available */
			printf("Thread %d is running\n", pid);
			fptr = fopen("QUOTE.txt", "a");
			fprintf(fptr, "%u Computer science is no more about computers than astronomy is about telescopes. --Edsger Dijkstra\r\n", pthread_self());
			fclose(fptr);
			sem_post(&FLAG); /* Release flag */
		}
	}
	pthread_exit(NULL); /* terminate thread */
}