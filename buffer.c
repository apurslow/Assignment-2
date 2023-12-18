/*
 *  Bounded buffer skeleton for Sieve of Erathosthenes primes program
 *  Based on Operating Systems: Three Easy Pieces by R. Arpaci-Dusseau and A. Arpaci-Dusseau
 * 
 *  This example uses locks and a condition to synchronize a child thread and
 *  the parent.  The child generates matricies and the parent computes the
 *  average when the matrix is ready for processing.
 *
 *  Wes J. Lloyd
 *  University of Washington, Tacoma
 *  TCSS 422 - Operating Systems
 *  Spring 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>
#include "buffer.h"

//define the struct for the bounded buffer
//implmentation using pthreads and bounded buffers
//actually looked at buffer.h......



// Initialize the bounded buffer
//Memory should be allocated for the bounded buffer using malloc()
void initbuff(int nslots, buffer_t *buff, char * n)
{ 
  //pointer to contents of bounded buffer
  buff ->buffer = (int *) malloc(nslots * sizeof(int));
  //size of bounded buffer
  buff-> maxSlots = nslots;
  buff ->use_ptr = 0;
  buff ->fill_ptr = 0;
  buff ->name = n;
  //initialize mutex
  pthread_mutex_init(&buff->mutex, NULL);
  //initialize condition variables
  pthread_cond_init(&buff->cond, NULL);

}

//method to release memory resources used by the bounded buffer using free()
void freebuff(int nslots, buffer_t *buff, char * n)
{

}

//method used to load a new value into the bounded buffer
//combines put() and producer() into one method
void put(int value, buffer_t *buff)
{
  
}

//method used to retrieve a value from the bounded buffer
int get(buffer_t *buff)
{
  return -1; 
}

