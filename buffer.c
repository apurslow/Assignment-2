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

void initbuff(int nslots, buffer_t *buff, char * n)
{

}

void freebuff(int nslots, buffer_t *buff, char * n)
{

}

void put(int value, buffer_t *buff)
{
  
}

int get(buffer_t *buff)
{
  return -1; 
}

