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

// Initialize the bounded buffer
//Memory should be allocated for the bounded buffer using malloc()
void initbuff(int nslots, buffer_t *buff, char * n)
{
  buff->buffer = malloc(sizeof(int) * nslots);
  buff->maxSlots = nslots;
  buff->use_ptr = 0;
  buff->fill_ptr = 0;
  buff->count = 0;
  buff->name = n;
  //initialize the mutex and condition variables
  pthread_mutex_init(&buff->mutex, NULL);
  pthread_cond_init(&buff->cond, NULL);

}
//method to release memory resources used by the bounded buffer using free()
void freebuff(int nslots, buffer_t *buff, char * n)
{
  free(buff->buffer);
  pthread_mutex_destroy(&buff->mutex);
  pthread_cond_destroy(&buff->cond);

}
//method used to load a new value into the bounded buffer
void put(int value, buffer_t *buff)
{
  //lock the mutex 
  pthread_mutex_lock(&buff->mutex);
  //wait until there is space in the buffer
  while(buff->count == buff->maxSlots)
  {
    pthread_cond_wait(&buff->cond, &buff->mutex);
  }
  //put the item in the buffer
  buff->buffer[buff->fill_ptr] = value;
  //increment the fill pointer
  buff->fill_ptr = (buff->fill_ptr + 1) % buff->maxSlots;
  //increment the count
  buff->count++;
  //signal that the buffer is no longer empty
  pthread_cond_signal(&buff->cond);
  //unlock the mutex
  pthread_mutex_unlock(&buff->mutex);
  
}
//method used to get a value from the bounded buffer
int get(buffer_t *buff)
{
  //lock the mutex
  pthread_mutex_lock(&buff->mutex);
  //wait until there is something in the buffer
  while(buff->count == 0)
  {
    pthread_cond_wait(&buff->cond, &buff->mutex);
  }
  //get the item from the buffer
  int value = buff->buffer[buff->use_ptr];
  //increment the use pointer
  buff->use_ptr = (buff->use_ptr + 1) % buff->maxSlots;
  //decrement the count
  buff->count--;
  //signal that the buffer is no longer full
  pthread_cond_signal(&buff->cond);
  //unlock the mutex
  pthread_mutex_unlock(&buff->mutex);
  //return the item
  return value;
  
}

